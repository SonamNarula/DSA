# Sliding Window — Complete Reference

Companion doc for `sliding_window_template.cpp`. This covers **why** the technique works, **both families** (fixed and variable size), a **decision tree** to pick the right template while reading a problem statement, and a **mapped practice list**.

---

## 1. Why sliding window exists

Most "subarray" or "substring" problems have a brute-force shape:

```
for i in [0, n):
    for j in [i, n):
        // process arr[i..j]   -> O(n^2) or worse
```

Sliding window exploits one observation: **when you move from window `[i, j]` to `[i, j+1]` or `[i+1, j]`, almost nothing changes.** You don't need to recompute the whole window from scratch — you just add one element and/or remove one element. That turns O(n²) into O(n).

Formally: two pointers `l` (left) and `r` (right) each only ever move **forward**, never backward. Across the entire run, `l` moves at most `n` times and `r` moves at most `n` times — so total work is O(n), even though it looks like a nested loop (`for r` with a `while` inside).

---

## 2. The two families

### Family 1 — Fixed size window
The problem literally gives you a constant `k`: *"subarray of size k"*, *"window of last k days"*, *"every k-length substring"*.

**Pattern:** build the first window once, then slide by exactly one step at a time — add the incoming element, remove the outgoing one.

### Family 2 — Variable / dynamic size window
The window size isn't given — it's determined by a **condition** the problem imposes: *"longest substring such that..."*, *"minimum length subarray such that..."*, *"count subarrays with exactly K..."*.

**Pattern:** expand `r` to bring elements in, shrink `l` to enforce the condition. What differs between problems is **when exactly you record the answer** relative to the shrink — this is the single most important detail to get right, and it's where most bugs come from.

---

## 3. Decision tree — which template do I use?

Read the problem statement and ask, in order:

1. **Is a window size `k` explicitly given as a constant?**
   → Yes: is it asking for a single aggregate (sum/average) or a max-sum-style optimum?
   → **Template A**
   → Is it asking for the max/min *of every window*?
   → **Template B** (monotonic deque)

2. **Does it ask for the LONGEST / MAXIMUM subarray or substring satisfying some condition?**
   → **Template C** — expand freely, shrink only until valid again (minimal shrink), record answer *after* the shrink loop.

3. **Does it ask for the SHORTEST / MINIMUM subarray or substring satisfying some condition?**
   → **Template D** — expand until valid, then shrink as far as possible while staying valid (maximal shrink), recording the answer *inside* the shrink loop, at every step.

4. **Does it ask to COUNT subarrays with an EXACT value** (exactly K distinct, exactly K odd numbers, etc.)?
   → **Template E** — reframe as `atMost(K) - atMost(K-1)`. Don't try to maintain "exactly" directly; it's not monotonic and the shrink logic gets ugly fast.

5. **Is the condition specifically "no duplicates" and you want to avoid a frequency map / one-by-one shrink?**
   → **Template F** — last-seen-index optimization on top of Template C's skeleton. Same idea, O(1) jump instead of a while-loop shrink.

If a problem doesn't cleanly fit any of these, it's often **two windows combined**, or sliding window **plus a prefix-sum / hashmap of running state** (e.g. "subarray sum equals K" is prefix-sum + hashmap, *not* pure sliding window, because negative numbers break the monotonic shrink assumption — worth knowing this boundary).

---

## 4. Template-by-template breakdown

### Template A — Fixed window, aggregate (sum / average / max-sum)
- **State kept:** a single running sum (or count, or whatever aggregates in O(1)).
- **Slide step:** `windowSum += arr[r]; windowSum -= arr[r-k];`
- **Complexity:** O(n) time, O(1) space.
- **Watch out for:** `n < k` (no valid window at all) — always guard this.

### Template B — Fixed window, max/min of every window (monotonic deque)
- **State kept:** a deque of *indices*, values strictly monotonic (decreasing for max, increasing for min).
- **Why a deque and not just recompute max each time:** recomputing max in each window is O(k) per window → O(nk) total. The deque keeps the answer available in O(1) at `front()` because we discard indices that can *never* be the answer again the moment a bigger value enters.
- **Complexity:** O(n) time — each index is pushed once, popped at most once, ever. O(k) space.
- **Watch out for:** popping expired indices from the *front* before reading `front()`, not after.

### Template C — Longest valid window
- **Core loop shape:**
  ```
  for r in [0, n):
      add arr[r]
      while (invalid): shrink from l; l++
      answer = max(answer, r - l + 1)     // AFTER the while loop
  ```
- **Why the answer update goes after the while loop:** the while loop's job is only to *restore validity*, using the minimum shrink necessary. The moment it exits, `[l, r]` is valid and as large as it can currently be — that's exactly when you should measure it.
- **Complexity:** O(n).
- **Watch out for:** using a `unordered_map<char,int>` and forgetting to `erase()` a key once its count hits 0 — `map.size()` will report a distinct-count that's too high forever after that, silently breaking the "invalid" check.

### Template D — Smallest valid window
- **Core loop shape:**
  ```
  for r in [0, n):
      add arr[r]
      while (valid):
          answer = min(answer, r - l + 1)   // INSIDE the while loop, before shrinking further
          shrink from l; l++
  ```
- **Why this is the mirror image of Template C:** here you want the window as *small* as possible, so once it's valid you keep shrinking greedily — as long as it stays valid — checking the answer at every single shrink, not just once.
- **Complexity:** O(n).
- **Watch out for:** initializing the answer to `INT_MAX` and remembering to check for "no valid window found" at the end (return 0 or -1 depending on problem convention).

### Template E — Exactly K (via atMost trick)
- **Why not a direct "exactly K" shrink:** validity isn't monotonic in the way Template C/D need. If you're at exactly K and expand, you're not automatically "more invalid" or "still valid" in a way a single shrink direction handles — you'd need conditional logic that's easy to get subtly wrong.
- **The fix:** `atMost(K)` *is* monotonic (adding elements never decreases distinct count, so once you exceed K you always want to shrink) — so build that cleanly with Template C's shrink logic, then use inclusion-exclusion:
  `exactly(K) = atMost(K) − atMost(K−1)`
- **Complexity:** O(n) (two O(n) passes).
- **General lesson:** this atMost-subtraction trick generalizes to almost any "exactly N of something" sliding window problem — memorize the trick, not just this one instance of it.

### Template F — Longest unique substring (last-seen-index optimization)
- **What's different from a generic Template C with a frequency map:** instead of shrinking one character at a time inside a `while`, you jump `l` directly to `lastSeen[c] + 1` in O(1) the moment a duplicate is found *inside* the current window.
- **The `>= l` check matters:** you must confirm the character's last occurrence is *inside* the current window before jumping — otherwise you can jump `l` backward, which corrupts the window.
- **Complexity:** O(n) time, O(charset) space.

---

## 5. Common mistakes checklist

- [ ] Fixed window: not guarding `n < k`.
- [ ] Variable window: `while` direction flipped (shrinking while invalid vs. while valid) — this is the #1 source of wrong answers when adapting a template to a new problem.
- [ ] Forgetting to `erase()` a zero-count key from a frequency map, corrupting `size()`-based validity checks.
- [ ] Off-by-one on window length — it's always `r - l + 1`, not `r - l`.
- [ ] Template F: jumping `l` backward because the "is this occurrence inside the current window" check (`lastSeen[c] >= l`) was skipped.
- [ ] Template D: forgetting the "no valid window exists" case (`INT_MAX` never updated).
- [ ] Assuming sliding window works with negative numbers for sum-based conditions — it generally doesn't, because shrinking the window doesn't monotonically decrease the sum anymore. That's a prefix-sum + hashmap problem instead (e.g. LC 560: Subarray Sum Equals K).

---

## 6. Practice problems mapped to templates

**Template A (fixed sum/aggregate)**
- Maximum sum subarray of size K
- Average of all subarrays of size K
- LC 643 — Maximum Average Subarray I

**Template B (fixed window max/min, deque)**
- LC 239 — Sliding Window Maximum
- LC 1438 — Longest Continuous Subarray With Absolute Diff <= Limit (deque, but variable window — good stretch problem after B)

**Template C (longest valid window)**
- LC 3 — Longest Substring Without Repeating Characters (also see Template F)
- LC 340 — Longest Substring with At Most K Distinct Characters
- LC 424 — Longest Repeating Character Replacement
- LC 904 — Fruit Into Baskets (= at most 2 distinct, disguised)

**Template D (smallest valid window)**
- LC 209 — Minimum Size Subarray Sum
- LC 76 — Minimum Window Substring (harder variant — condition is "contains all of T", not just a count threshold)

**Template E (exactly K via atMost trick)**
- LC 992 — Subarrays with K Different Integers
- LC 1248 — Count Number of Nice Subarrays (exactly K odd numbers — same trick, different condition)

**Template F (last-seen-index optimization)**
- LC 3 — Longest Substring Without Repeating Characters

---

## 7. Files in this delivery

- `sliding_window_template.cpp` — all 6 templates, each fully commented, plus a `main()` with sanity-checked test cases (compiled and verified with `g++ -std=c++17 -Wall`, zero warnings).
- `README.md` — this file.

Copy the specific template function you need directly into your solution file when solving a problem — don't paste the whole file.
