# DSA Flagship Revision and Problem-Solving Register

> Personal revision register and problem-solving workbook covering: problem-solving framework, Big-O, arrays, read–write pointers, strings, two pointers, sliding window, and HashMaps/HashSets.
> Language: C++17. Status checkboxes and trackers are intentionally **blank**: nothing here is pre-marked as solved.

**Scope note.** *Count Subarrays with Exactly K Distinct Integers* was intentionally skipped in my syllabus. It is not in the mandatory list and nothing in this document depends on it.

**Link policy (read once).** Problem links use LeetCode's standard problem-slug URL pattern. I have **not** live-verified every URL from this environment. If a link fails, search the problem name on LeetCode. Difficulty labels follow LeetCode's usual labelling and are a guide only.

---

## Table of Contents

1. [How to Use This Register](#1-how-to-use-this-register)
2. [Problem-Solving Framework](#2-problem-solving-framework)
3. [Big-O and Complexity Analysis](#3-big-o-and-complexity-analysis)
4. [Arrays](#4-arrays)
5. [Read–Write Pointers](#5-readwrite-pointers)
6. [Strings](#6-strings)
7. [Two Pointers](#7-two-pointers)
8. [Sliding Window](#8-sliding-window)
9. [HashMaps and HashSets](#9-hashmaps-and-hashsets)
10. [Master Pattern Recognition and Decision Tables](#10-master-pattern-recognition-and-decision-tables)
11. [Flagship Problem Bank](#11-flagship-problem-bank)
12. [Five-to-Six-Hour Problem-Solving Day](#12-five-to-six-hour-problem-solving-day)
13. [Light Revision Plan (60–90 Minutes)](#13-light-revision-plan-6090-minutes)
14. [Problem-Solving Worksheet and Mistake Log](#14-problem-solving-worksheet-and-mistake-log)
15. [Progress Tracker](#15-progress-tracker)
16. [Revision Schedule](#16-revision-schedule)

---

## 1. How to Use This Register

1. Read the notes for one pattern (sections 2–9).
2. Close the notes and solve that pattern's problems from section 11, **core first, optional last**.
3. Fill the worksheet (section 14) for any problem you could not solve cleanly.
4. Update the tracker (section 15) and the mistake log.
5. Revisit on the schedule in section 16.

Every pattern section uses the same eight-part structure: Concept, Recognition clues, When to use / not, Algorithm and invariant, C++ implementation, Complexity, Common mistakes, Mini dry run.

Common header for all C++ snippets:

```cpp
#include <bits/stdc++.h>
using namespace std;
```

---

## 2. Problem-Solving Framework

### 2.1 Concept

A repeatable process that prevents jumping to code too early. Five steps:

| Step | What to do | Output |
|---|---|---|
| 1. Understand | Restate the problem, inputs, outputs. Ask about duplicates, negatives, empty input, sorted or not, in-place or not, character set. | Clear restatement + examples |
| 2. Constrain | Read constraints; infer the target complexity. | Target like O(n) or O(n log n) |
| 3. Brute force | State the simplest correct solution and its complexity. | Baseline + bottleneck |
| 4. Optimize | Find the repeated or wasted work; map to a pattern. | Chosen pattern + invariant |
| 5. Verify and code | Dry run on a small case plus edge cases; code; state complexity. | Tested solution |

### 2.2 Constraint-to-pattern mapping

Constraints suggest the *intended* complexity, which narrows the candidates. Treat as a heuristic.

| n (typical limit) | Intended complexity | Typical techniques |
|---|---|---|
| n ≤ 20 | O(2ⁿ) or O(n·2ⁿ) | Enumeration / backtracking (not in this syllabus) |
| n ≤ 500 | O(n³) | Triple loops |
| n ≤ 5,000 | O(n²) | Double loops, expand around center |
| n ≤ 10⁵ | O(n log n) or O(n) | Sorting, two pointers, sliding window, prefix sums, hashing |
| n ≤ 10⁶–10⁷ | O(n) | Single pass, counting arrays |
| n ≤ 10¹⁸ or huge | O(log n) or O(1) | Math, binary search |

(Rough guide: about 10⁸ simple operations per second in C++.)

### 2.3 Translating statements into approaches

| Statement fragment | First idea |
|---|---|
| "contiguous subarray/substring" | Prefix sums, sliding window, Kadane |
| "pair / triplet with sum" | Sorted → two pointers; unsorted → HashMap |
| "in-place, preserve order" | Read–write pointers |
| "count / frequency / anagram" | Frequency array or HashMap |
| "exists / seen before / unique" | HashSet |
| "group by property" | HashMap from canonical key to vector |
| "longest/shortest valid window" | Sliding window (check monotonic validity) |
| "range queries, many of them" | Prefix sums; range updates → difference array |

### 2.4 Interview communication strategy

1. Clarify, then restate in your own words.
2. Give brute force first, with complexity. Name the bottleneck.
3. Propose the optimization and state the **invariant** aloud.
4. Dry run a tiny example before coding.
5. Code with meaningful names; narrate decisions, not syntax.
6. Test edge cases explicitly: empty, size 1, all equal, negatives, duplicates, overflow.
7. State time and auxiliary space; mention trade-offs.

---

## 3. Big-O and Complexity Analysis

### 3.1 Concept

Big-O describes how cost grows with input size, ignoring constants and lower-order terms. It is an upper bound on growth; in interviews it usually means worst-case unless stated otherwise.

| Class | Name | Example |
|---|---|---|
| O(1) | Constant | Array index, HashMap average lookup |
| O(log n) | Logarithmic | Halving loop, binary search |
| O(n) | Linear | Single scan |
| O(n log n) | Linearithmic | Comparison sort |
| O(n²) | Quadratic | Nested loops over the same input |
| O(2ⁿ) | Exponential | Naive Fibonacci recursion, subsets |

### 3.2 Loop analysis

| Code shape | Cost |
|---|---|
| Two sequential loops of n | O(n + n) = O(n) |
| Nested loops, both to n | O(n²) |
| `for (i=1; i<n; i*=2)` | O(log n) |
| `for (i=0;i<n;i++) for (j=i;j<n;j++)` | n(n+1)/2 → O(n²) |
| Outer n × inner log n | O(n log n) |
| Outer loop n, inner `while` that only moves a shared pointer forward | O(n) total (amortized, see 3.4) |

### 3.3 Recursion fundamentals

- Cost ≈ (number of calls) × (work per call).
- Naive `fib(n) = fib(n-1) + fib(n-2)` makes about φⁿ calls → exponential (commonly stated as O(2ⁿ) upper bound).
- Halving recursion (`pow(x, n/2)` once per level) → O(log n).
- Recursion stack counts as auxiliary space: depth × frame size.

### 3.4 Amortized analysis

Some single operations are expensive but the **total** over a sequence is small. Sliding window is the standard example: `j` advances n times and `i` advances at most n times in total, so the double-loop structure is O(n), not O(n²). Another: `vector::push_back` is amortized O(1) even though occasional reallocation is O(size).

### 3.5 Space: auxiliary vs output

- **Auxiliary space** = extra memory beyond input and output.
- Output space is reported separately: returning a vector of n results is O(n) *output*, not necessarily O(n) auxiliary.
- Group Anagrams: the answer itself is O(total characters); the auxiliary map is also proportional, so state both clearly.

### 3.6 Average vs worst case for hashing

`unordered_map` / `unordered_set` operations are **O(1) on average** and **O(n) worst case** per operation (heavy collisions). Never say "guaranteed O(1)". In adversarial settings (e.g., Codeforces anti-hash tests) a custom hash may be needed.

### 3.7 Brute force vs optimized: reference table

| Task | Brute force | Optimized | Idea that removes the waste |
|---|---|---|---|
| Range sum queries (q queries) | O(n·q) | O(n + q) | Prefix sums |
| Pair with target (sorted) | O(n²) | O(n) | Two pointers |
| Pair with target (unsorted) | O(n²) | O(n) avg | HashMap complement |
| Longest substring w/o repeat | O(n³) or O(n²) | O(n) | Sliding window |
| Subarray sum = K | O(n²) | O(n) avg | Prefix freq HashMap |
| Max subarray | O(n²) | O(n) | Kadane |

### 3.8 Common mistakes

- Counting only the visible loop and ignoring hidden costs (`s.substr`, `s + t`, `erase` from a vector's front are O(n)).
- Calling a sliding window O(n²) because of the nested `while`.
- Claiming O(1) space while building a frequency map that grows with input.
- Ignoring that sorting costs O(n log n).
- Saying HashMap is always O(1).
- Treating `string` concatenation in a loop as O(1) per step.

---

## 4. Arrays

### 4.1 Memory layout and operations

A C++ `vector<int>` stores elements contiguously: indexing is O(1), cache-friendly traversal is fast.

| Operation | Cost |
|---|---|
| Access `a[i]` | O(1) |
| Append (`push_back`) | Amortized O(1) |
| Insert/erase in the middle or front | O(n) (shifts elements) |
| Search unsorted | O(n) |
| Search sorted | O(log n) |

**Edge cases and pitfalls:** empty array; single element; all negative; all equal; integer overflow of sums (use `long long`); off-by-one at `n-1`; `size()` is unsigned (`a.size() - 1` underflows when empty).

### 4.2 Prefix sums

**Concept.** `pre[i]` = sum of the first `i` elements. Then `sum(l..r) = pre[r+1] - pre[l]` in O(1) after O(n) preprocessing.

**Recognition clues.** "Many range sum queries", "sum between indices", "pivot index where left sum equals right sum", "count subarrays with target sum" (with HashMap, see 4.6).

**Use when:** array is static between queries. **Avoid when:** frequent point updates (consider other structures, outside this syllabus).

**Invariant.** `pre[i] = a[0] + ... + a[i-1]`, `pre[0] = 0`.

```cpp
vector<long long> buildPrefix(const vector<int>& a) {
    vector<long long> pre(a.size() + 1, 0);
    for (size_t i = 0; i < a.size(); ++i) pre[i + 1] = pre[i] + a[i];
    return pre;
}
// sum of a[l..r] inclusive: pre[r + 1] - pre[l]
```

**Complexity.** Build O(n) time, O(n) space; each query O(1).

**Dry run.** `a = [3, 1, 4, 1, 5]`

| i | 0 | 1 | 2 | 3 | 4 | 5 |
|---|---|---|---|---|---|---|
| pre[i] | 0 | 3 | 4 | 8 | 9 | 14 |

`sum(1..3) = pre[4] - pre[1] = 9 - 3 = 6` (1+4+1).

**Mistakes.** Using `pre` of size n (loses the `pre[0]=0` anchor); `int` overflow; mixing 0-based and 1-based indices.

### 4.3 Suffix sums and "except self"

`suf[i]` = sum of `a[i..n-1]`. Same idea mirrored. The product-except-self pattern combines a prefix product and suffix product:

```cpp
vector<int> productExceptSelf(const vector<int>& a) {
    int n = a.size();
    vector<int> res(n, 1);
    int prefix = 1;
    for (int i = 0; i < n; ++i) { res[i] = prefix; prefix *= a[i]; }   // product of left side
    int suffix = 1;
    for (int i = n - 1; i >= 0; --i) { res[i] *= suffix; suffix *= a[i]; } // times right side
    return res;
}
```

Time O(n); auxiliary space O(1) excluding the output array. No division needed (division fails with zeros).

### 4.4 Difference arrays (range updates)

**Concept.** To add `v` to every element of `[l, r]` many times, record `diff[l] += v; diff[r+1] -= v`; one prefix-sum pass at the end reconstructs the final array.

**Recognition.** "Add value to a range, many updates, then read final array." Examples: flight bookings, car pooling.

```cpp
vector<long long> applyRangeUpdates(int n, const vector<array<int, 3>>& updates) {
    // each update = {l, r, v}, 0-indexed inclusive
    vector<long long> diff(n + 1, 0);
    for (const auto& [l, r, v] : updates) {
        diff[l] += v;
        diff[r + 1] -= v;          // cancels the effect after r
    }
    vector<long long> result(n);
    long long running = 0;
    for (int i = 0; i < n; ++i) {
        running += diff[i];
        result[i] = running;
    }
    return result;
}
```

**Complexity.** O(n + q) time, O(n) space. Brute force is O(n·q).

**Dry run.** n=5, updates (1,3,+2), (2,4,+3):

| index | 0 | 1 | 2 | 3 | 4 | 5 |
|---|---|---|---|---|---|---|
| diff | 0 | +2 | +3 | 0 | -2 | -3 |
| running sum | 0 | 2 | 5 | 5 | 3 | |

Result: `[0, 2, 5, 5, 3]`.

**Mistakes.** Forgetting size `n+1` (so `r+1 == n` is safe); reading final values before the prefix pass; 1-based vs 0-based mismatch.

### 4.5 Kadane's Algorithm

**Concept.** Maximum sum of a non-empty contiguous subarray. At each element decide: extend the previous subarray or start fresh.

**Invariant.** After processing index `i`, `cur` = best sum of a subarray **ending exactly at i**; `best` = best seen anywhere so far.

```cpp
int maxSubarray(const vector<int>& a) {
    int cur = a[0], best = a[0];            // initialise from a[0], NOT 0
    for (size_t i = 1; i < a.size(); ++i) {
        cur = max(a[i], cur + a[i]);        // restart if the past hurts
        best = max(best, cur);
    }
    return best;
}
```

**All-negative arrays.** Initialising `best = 0` returns 0 (an empty subarray) which is wrong when the problem requires non-empty. Initialising from `a[0]` handles `[-3, -1, -2]` → `-1`.

**Complexity.** O(n) time, O(1) space.

**Dry run.** `[-2, 1, -3, 4, -1, 2, 1, -5, 4]`

| x | -2 | 1 | -3 | 4 | -1 | 2 | 1 | -5 | 4 |
|---|---|---|---|---|---|---|---|---|---|
| cur | -2 | 1 | -2 | 4 | 3 | 5 | 6 | 1 | 5 |
| best | -2 | 1 | 1 | 4 | 4 | 5 | 6 | 6 | 6 |

Answer 6 (`[4, -1, 2, 1]`). To return the subarray itself, record the start when `cur` restarts.

**Mistakes.** `best = 0` init; `INT_MIN` plus addition overflow; returning `cur` instead of `best`.

### 4.6 Subarray Sum Equals K (prefix-sum frequencies)

**Concept.** A subarray `(l..r]` sums to `K` iff `pre[r] - pre[l] = K`, i.e. `pre[l] = pre[r] - K`. While scanning, count how many earlier prefixes equal `pre[r] - K`.

**Why it works with negatives.** It makes no monotonicity assumption, unlike a sliding window.

```cpp
int subarraySum(const vector<int>& a, int k) {
    unordered_map<long long, int> freq;
    freq[0] = 1;                       // empty prefix: lets subarrays starting at index 0 count
    long long prefix = 0;
    int count = 0;
    for (int x : a) {
        prefix += x;
        auto it = freq.find(prefix - k);   // look up BEFORE recording current prefix
        if (it != freq.end()) count += it->second;
        ++freq[prefix];
    }
    return count;
}
```

**Why `freq[0] = 1`.** Without it, a subarray starting at index 0 whose sum equals `K` has `prefix - K = 0` but 0 was never recorded → missed.

**Why lookup before insert.** If you insert the current prefix first and `K = 0`, the current prefix would match itself, counting an empty subarray.

**Complexity.** O(n) average time, O(n) space (worst-case time O(n²) with pathological hashing).

**Dry run.** `a = [1, 2, 3], K = 3`

| x | prefix | look up (prefix−3) | found | count | freq after |
|---|---|---|---|---|---|
| start | 0 | | | 0 | {0:1} |
| 1 | 1 | -2 | 0 | 0 | {0:1, 1:1} |
| 2 | 3 | 0 | 1 | 1 | {0:1, 1:1, 3:1} |
| 3 | 6 | 3 | 1 | 2 | {0:1, 1:1, 3:1, 6:1} |

Answer 2: `[1,2]` and `[3]`.

### 4.7 In-place array rotation (reversals)

Rotate right by `k`: reverse all, reverse first `k`, reverse remaining `n-k`.

```cpp
void rotateRight(vector<int>& a, int k) {
    int n = a.size();
    if (n == 0) return;
    k %= n;                                  // k may exceed n
    reverse(a.begin(), a.end());
    reverse(a.begin(), a.begin() + k);
    reverse(a.begin() + k, a.end());
}
```

**Dry run.** `[1,2,3,4,5,6,7], k=3` → full reverse `[7,6,5,4,3,2,1]` → first 3 reversed `[5,6,7,4,3,2,1]` → rest reversed `[5,6,7,1,2,3,4]`.

**Complexity.** O(n) time, O(1) space. **Mistakes.** Forgetting `k %= n`; confusing left and right rotation; negative `k`.

### 4.8 Arrays: summary of when to use what

| Need | Tool |
|---|---|
| Many range-sum queries | Prefix sum |
| Many range additions, one read at end | Difference array |
| Best contiguous sum | Kadane |
| Count subarrays with sum K (negatives allowed) | Prefix sum + HashMap |
| Rotate without extra memory | Three reversals |

---

## 5. Read–Write Pointers

### 5.1 Concept

Same-direction pointers where `i` **reads** every element and `j` marks the next position to **write**. It compacts an array in place in one pass.

### 5.2 Recognition clues

- "Modify the array in-place", "O(1) extra space"
- "Preserve relative order"
- "Return the new length" / "first k elements are the answer"
- Remove or filter elements by a condition; keep at most k duplicates

### 5.3 When to use / not

- **Use:** filtering, deduplicating sorted data, partitioning with stable order.
- **Not:** when order does not matter and few elements move (a swap-with-end approach does fewer writes); when extra space is allowed and simplicity matters; for unsorted deduplication (needs a set or sort first).

### 5.4 Invariant

> `a[0..j-1]` is the finished, valid output of everything read so far (`a[0..i-1]`). `j ≤ i` always.

**Logical length vs allocated size.** After compaction the answer is `a[0..j-1]`. The vector may still hold stale values after `j`; the return value `j` is the logical length. Use `a.resize(j)` only if you must shrink the container.

### 5.5 C++ implementations

```cpp
// Move Zeroes: stable, in place
void moveZeroes(vector<int>& a) {
    int j = 0;                                   // next write slot for a non-zero
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] != 0) swap(a[i], a[j++]);       // swap keeps zeros flowing to the back
}

// Remove Element: returns new logical length
int removeElement(vector<int>& a, int val) {
    int j = 0;
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] != val) a[j++] = a[i];
    return j;
}

// Remove Duplicates from Sorted Array (keep one copy)
int removeDuplicates(vector<int>& a) {
    if (a.empty()) return 0;
    int j = 1;                                   // a[0] always kept
    for (int i = 1; i < (int)a.size(); ++i)
        if (a[i] != a[j - 1]) a[j++] = a[i];     // compare with last KEPT value
    return j;
}

// Remove Duplicates II (keep at most k copies); k = 2 for the classic problem
int removeDuplicatesAtMostK(vector<int>& a, int k) {
    int j = 0;
    for (int i = 0; i < (int)a.size(); ++i)
        if (j < k || a[i] != a[j - k]) a[j++] = a[i];  // a[j-k] is the k-th last kept
    return j;
}
```

**Why `a[j - k]` works.** The array is sorted, so if `a[i]` differs from the element `k` positions back in the kept region, fewer than `k` copies of `a[i]` have been kept.

### 5.6 Complexity

| Problem | Time | Aux space |
|---|---|---|
| Move Zeroes | O(n) | O(1) |
| Remove Element | O(n) | O(1) |
| Remove Duplicates I / II | O(n) | O(1) |

Brute force (erase one by one from a vector) is O(n²).

### 5.7 Common mistakes

- Comparing `a[i]` with `a[i-1]` instead of the last **kept** element (differs once overwrites happen).
- Starting `j` at 0 for sorted dedup and reading `a[j-1]` out of bounds.
- Returning `i` instead of `j`.
- Using `erase` inside a loop (O(n²), iterator invalidation).
- Assuming the tail beyond `j` is meaningful.

### 5.8 Mini dry run

Remove Duplicates II, `a = [1,1,1,2,2,3]`, k=2:

| i | a[i] | condition (`j<2` or `a[i]!=a[j-2]`) | action | j after | kept prefix |
|---|---|---|---|---|---|
| 0 | 1 | j<2 | write | 1 | [1] |
| 1 | 1 | j<2 | write | 2 | [1,1] |
| 2 | 1 | 1 == a[0] | skip | 2 | [1,1] |
| 3 | 2 | 2 != a[0]=1 | write | 3 | [1,1,2] |
| 4 | 2 | 2 != a[1]=1 | write | 4 | [1,1,2,2] |
| 5 | 3 | 3 != a[2]=2 | write | 5 | [1,1,2,2,3] |

Return 5.

---

## 6. Strings

### 6.1 Fundamentals

- A C++ `std::string` is a mutable contiguous sequence of `char`.
- `s[i]` O(1); `s.substr(a, len)` O(len) (copies); `s + t` O(|s|+|t|).
- Strings are often arrays in disguise: apply array patterns (two pointers, windows, prefix counts).
- **State assumptions:** lowercase letters only? ASCII? case-sensitive? Unicode? Spaces and punctuation ignored?

### 6.2 Palindrome detection

**Concept.** A string equals its reverse. Check with opposite-direction pointers, skipping irrelevant characters if required.

```cpp
bool isPalindromeAlnum(const string& s) {
    int i = 0, j = (int)s.size() - 1;
    while (i < j) {
        while (i < j && !isalnum((unsigned char)s[i])) ++i;   // skip non-alphanumerics
        while (i < j && !isalnum((unsigned char)s[j])) --j;
        if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[j])) return false;
        ++i; --j;
    }
    return true;
}
```

Time O(n), space O(1). **Mistakes:** forgetting `i < j` in the inner skips; passing a negative `char` to `isalnum` without casting to `unsigned char`; empty string (should be true).

### 6.3 Expand Around Center (Longest Palindromic Substring)

**Concept.** Every palindrome is centered at a character (odd length) or between two characters (even length). There are `2n - 1` centers; expand outward while characters match.

**Invariant.** While expanding, `s[l..r]` is a palindrome.

```cpp
string longestPalindrome(const string& s) {
    int n = s.size(), bestStart = 0, bestLen = 0;
    auto expand = [&](int l, int r) {
        while (l >= 0 && r < n && s[l] == s[r]) { --l; ++r; }
        int len = r - l - 1;                       // loop exits one step past the palindrome
        if (len > bestLen) { bestLen = len; bestStart = l + 1; }
    };
    for (int c = 0; c < n; ++c) {
        expand(c, c);        // odd length, center at c
        expand(c, c + 1);    // even length, center between c and c+1
    }
    return s.substr(bestStart, bestLen);
}
```

**Complexity.** O(n²) time worst case (e.g., `aaaa...`), O(1) auxiliary space. Better algorithms exist (Manacher) but are outside this syllabus.

**Dry run.** `s = "babad"`

| center | expand | result |
|---|---|---|
| (0,0) | b | len 1 |
| (1,1) | a → b..b? `s[0]=b, s[2]=b` | "bab" len 3 |
| (1,2) | a≠b | len 0 |
| (2,2) | b → a..a | "aba" len 3 (not longer) |

Answer `"bab"` (or `"aba"`).

**Mistakes.** Forgetting even-length centers; wrong length formula `r - l - 1`; returning the wrong start.

### 6.4 Anagram detection

**Concept.** Two strings are anagrams iff they have identical character frequencies.

```cpp
bool isAnagram(const string& s, const string& t) {
    if (s.size() != t.size()) return false;
    array<int, 26> cnt{};                         // assumes lowercase a-z
    for (char c : s) ++cnt[c - 'a'];
    for (char c : t) if (--cnt[c - 'a'] < 0) return false;
    return true;
}
```

Time O(n), space O(1) (26 fixed). For arbitrary Unicode, use `unordered_map<char32_t,int>` or sort (O(n log n)).

### 6.5 Group Anagrams

**Concept.** Map each word to a canonical key shared by all its anagrams, then group.

```cpp
vector<vector<string>> groupAnagrams(const vector<string>& words) {
    unordered_map<string, vector<string>> groups;
    for (const string& w : words) {
        string key = w;
        sort(key.begin(), key.end());              // canonical form: sorted letters
        groups[key].push_back(w);
    }
    vector<vector<string>> result;
    for (auto& [key, bucket] : groups) result.push_back(move(bucket));
    return result;
}
```

Time O(N · L log L) (N words of length ≤ L). With a 26-count signature as the key it is O(N · L) (build the key from counts, e.g., a string of 26 counts separated by delimiters). Space O(N · L).

### 6.6 Frequency array vs HashMap

| | `array<int,26>` / `array<int,128>` | `unordered_map<char,int>` |
|---|---|---|
| Alphabet | Small, known, fixed | Large, unknown, sparse |
| Speed | Faster, cache-friendly | Slower constant factors |
| Space | O(1) | O(distinct) |
| Iteration order | Deterministic | Unspecified |
| Pitfall | Index out of range if input has unexpected chars | None, but heavier |

### 6.7 String edge cases checklist

Empty string; single character; all the same character; uppercase vs lowercase; spaces/punctuation; very long strings (avoid O(n²) concatenation); `char` signedness when indexing arrays.

---

## 7. Two Pointers

### 7.1 Concept

Use two indices to scan a sequence, replacing a nested loop. Two flavors:

| Flavor | Movement | Used for |
|---|---|---|
| **Opposite direction** | `i` from left, `j` from right, move inward | Sorted pair sum, palindrome, container with most water |
| **Same direction** | both move left→right at different speeds/roles | Read–write pointers, windows, merge-like scans |

### 7.2 Recognition clues

- "Sorted array" + "pair/triplet with target sum"
- "Palindrome", "reverse", "symmetric"
- "Maximize area/distance between two ends"
- "Return indices" with sorted input (Two Sum II)

### 7.3 When to use / not; Two Pointers vs HashMap

| Situation | Better choice | Reason |
|---|---|---|
| Sorted array, find pair, O(1) space wanted | Two pointers | Sorted order lets you discard candidates |
| Unsorted, must return **original indices** | HashMap | Sorting loses indices (unless you sort pairs, O(n log n)) |
| Unsorted, only need existence/values and sorting is OK | Sort + two pointers | O(n log n), O(1) extra |
| Need to count all pairs with duplicates | Depends | HashMap frequencies or careful duplicate skipping |
| Many queries on a static array | Preprocess (prefix, map) | Reuse work |

**Why sortedness matters.** If `a[i] + a[j] < target`, then `a[i]` with any `a[k]` for `k ≤ j` is also too small, so `i` can be safely discarded; symmetrically for `j`. Without order that argument fails.

### 7.4 Two Sum II (sorted input)

**Invariant.** If a valid pair exists, it lies within `[i, j]`.

```cpp
vector<int> twoSumSorted(const vector<int>& a, int target) {
    int i = 0, j = (int)a.size() - 1;
    while (i < j) {
        long long sum = (long long)a[i] + a[j];
        if (sum == target) return {i + 1, j + 1};   // 1-indexed in the classic problem
        if (sum < target) ++i;                      // need a larger sum
        else --j;                                   // need a smaller sum
    }
    return {};                                      // problem usually guarantees an answer
}
```

Time O(n), space O(1).

### 7.5 Container With Most Water

**Concept.** Area = `min(h[i], h[j]) * (j - i)`. Start with the widest container; the only way to improve is to find a taller wall, so move the **shorter** side inward.

**Why moving the taller side is useless.** Width shrinks and the height is capped by the shorter wall, so the area cannot improve.

```cpp
int maxArea(const vector<int>& h) {
    int i = 0, j = (int)h.size() - 1, best = 0;
    while (i < j) {
        best = max(best, min(h[i], h[j]) * (j - i));
        if (h[i] < h[j]) ++i; else --j;             // discard the limiting wall
    }
    return best;
}
```

Time O(n), space O(1). Brute force O(n²).

**Dry run.** `h = [1,8,6,2,5,4,8,3,7]`

| i | j | min h | width | area | move |
|---|---|---|---|---|---|
| 0 | 8 | 1 | 8 | 8 | i |
| 1 | 8 | 7 | 7 | 49 | j |
| 1 | 7 | 3 | 6 | 18 | j |
| 1 | 6 | 8 | 5 | 40 | j |
| ... | | | | | |

Best 49.

### 7.6 Three Sum

**Concept.** Sort, fix `a[k]`, then solve Two Sum II on the suffix for `-a[k]`. Skip duplicates at all three positions to avoid repeated triplets.

```cpp
vector<vector<int>> threeSum(vector<int> a) {
    sort(a.begin(), a.end());
    int n = a.size();
    vector<vector<int>> res;
    for (int k = 0; k < n - 2; ++k) {
        if (a[k] > 0) break;                              // smallest already positive: no triplet
        if (k > 0 && a[k] == a[k - 1]) continue;          // skip duplicate anchors
        int i = k + 1, j = n - 1;
        while (i < j) {
            long long sum = (long long)a[k] + a[i] + a[j];
            if (sum < 0) ++i;
            else if (sum > 0) --j;
            else {
                res.push_back({a[k], a[i], a[j]});
                ++i; --j;
                while (i < j && a[i] == a[i - 1]) ++i;    // skip duplicate left values
                while (i < j && a[j] == a[j + 1]) --j;    // skip duplicate right values
            }
        }
    }
    return res;
}
```

Time O(n²) (sort O(n log n) is dominated), auxiliary space O(1) excluding output (plus sort's internal stack/copy depending on implementation).

**Dry run.** `[-1,0,1,2,-1,-4]` → sorted `[-4,-1,-1,0,1,2]`

| k | a[k] | i,j path | found |
|---|---|---|---|
| 0 | -4 | sums too small until pointers meet | none |
| 1 | -1 | (2,5): -1-1+2=0 ✔ → then (3,4): -1+0+1=0 ✔ | [-1,-1,2], [-1,0,1] |
| 2 | -1 | duplicate of k=1 | skipped |
| 3 | 0 | 0+1+2 > 0 | none |

### 7.7 Common mistakes (two pointers)

- Skipping duplicates **before** recording the first valid triplet (loses valid answers).
- Duplicate skipping conditions using `a[i] == a[i+1]` in the wrong direction after moving.
- Applying opposite-direction pair-sum logic to unsorted arrays.
- Using `int` for sums that can overflow.
- Infinite loops from forgetting to move a pointer after a match.
- Returning sorted-order indices when original indices are required.

---

## 8. Sliding Window

### 8.1 Concept

Maintain a contiguous window `[i, j]` and update its summary (sum, counts, distinct count) incrementally by **adding** `a[j]` and **removing** `a[i]`, instead of recomputing from scratch. Each index enters and leaves the window at most once → O(n) total.

### 8.2 Recognition clues

- "Contiguous subarray/substring" + "longest / shortest / maximum / minimum"
- Fixed length `k` given → fixed window
- A condition that stays true or becomes false **monotonically** as the window grows (e.g., all positives with sum ≤ K; no repeated characters)
- "At most K ..." conditions on counts

### 8.3 When to use / not

- **Needs monotonicity:** growing the window can only make the condition "more violated" (or "more satisfied"), and shrinking does the opposite.
- **Fails with negative numbers for sum conditions.** Example: `a = [2, -1, 2]`, target ≥ 3. Extending the window can *lower* the sum, so "shrink when sum is too large" or "stop growing when sum is big enough" is no longer justified. Use prefix sums + HashMap (section 4.6) for exact-sum counting with negatives.
- Not for non-contiguous selections (subsequences), and not for "exactly K" conditions without further transformation (skipped topic).

### 8.4 Fixed-size window template

**Invariant.** After processing index `j ≥ k-1`, `windowSum` equals the sum of `a[j-k+1..j]`.

```cpp
long long maxSumSizeK(const vector<int>& a, int k) {
    int n = a.size();
    if (k <= 0 || k > n) return 0;                     // define behaviour for invalid k explicitly
    long long window = 0;
    for (int j = 0; j < k; ++j) window += a[j];        // first window
    long long best = window;
    for (int j = k; j < n; ++j) {
        window += a[j];                                // add entering element
        window -= a[j - k];                            // remove leaving element
        best = max(best, window);
    }
    return best;
}
```

Time O(n), space O(1). Works with negatives (the window size is fixed, so no shrink decision exists).

**Dry run.** `a = [2,1,5,1,3,2], k = 3`

| window | sum |
|---|---|
| [2,1,5] | 8 |
| [1,5,1] | 7 |
| [5,1,3] | 9 |
| [1,3,2] | 6 |

Best 9.

### 8.5 Variable window: longest valid

**Pattern.** Expand `j` each step; while the window becomes invalid, shrink from `i`; then record the length.

**Invariant.** After the inner `while`, `[i, j]` is valid and is the longest valid window **ending at j** (for monotonic conditions).

```cpp
// Longest subarray with sum <= K, all elements positive (or non-negative)
int longestSubarraySumAtMostK(const vector<int>& a, long long K) {
    int i = 0, best = 0;
    long long sum = 0;
    for (int j = 0; j < (int)a.size(); ++j) {
        sum += a[j];                                   // add
        while (sum > K && i <= j) sum -= a[i++];       // shrink until valid
        best = max(best, j - i + 1);                   // length 0 if window emptied
    }
    return best;
}
```

Why positives are required: removing an element strictly lowers the sum, so shrinking always moves toward validity.

### 8.6 Variable window: shortest valid

**Pattern.** Expand until valid; then shrink while it **stays** valid, recording the minimum.

```cpp
// Minimum length subarray with sum >= target, positive integers
int minSubarrayLen(const vector<int>& a, long long target) {
    int i = 0, best = INT_MAX;
    long long sum = 0;
    for (int j = 0; j < (int)a.size(); ++j) {
        sum += a[j];
        while (sum >= target) {                        // window is valid: try to shrink
            best = min(best, j - i + 1);
            sum -= a[i++];
        }
    }
    return best == INT_MAX ? 0 : best;
}
```

### 8.7 Longest Substring Without Repeating Characters

**Invariant.** `[i, j]` contains no duplicate characters.

```cpp
int lengthOfLongestSubstring(const string& s) {
    array<int, 256> lastSeen;
    lastSeen.fill(-1);                                 // -1 = never seen
    int i = 0, best = 0;
    for (int j = 0; j < (int)s.size(); ++j) {
        unsigned char c = s[j];
        if (lastSeen[c] >= i) i = lastSeen[c] + 1;     // jump past the earlier duplicate
        lastSeen[c] = j;
        best = max(best, j - i + 1);
    }
    return best;
}
```

The `>= i` check matters: an old occurrence left of `i` is outside the window and must be ignored. Time O(n), space O(1) (fixed 256 alphabet).

**Dry run.** `s = "abcabcbb"`

| j | char | lastSeen before | i after | window | best |
|---|---|---|---|---|---|
| 0 | a | -1 | 0 | a | 1 |
| 1 | b | -1 | 0 | ab | 2 |
| 2 | c | -1 | 0 | abc | 3 |
| 3 | a | 0 ≥ 0 | 1 | bca | 3 |
| 4 | b | 1 ≥ 1 | 2 | cab | 3 |
| 5 | c | 2 ≥ 2 | 3 | abc | 3 |
| 6 | b | 4 ≥ 3 | 5 | cb | 3 |
| 7 | b | 6 ≥ 5 | 7 | b | 3 |

### 8.8 Minimum Window Substring

**Goal.** Smallest window of `s` containing all characters of `t` (with multiplicity).

**State.** `need[c]` = how many more of `c` the window still requires (negative = surplus). `missing` = total required characters not yet covered.

**Validity invariant.** Window is valid iff `missing == 0`.

```cpp
string minWindow(const string& s, const string& t) {
    if (t.empty() || s.size() < t.size()) return "";
    array<int, 128> need{};                            // assumes ASCII
    for (char c : t) ++need[(unsigned char)c];
    int missing = t.size();
    int bestLen = INT_MAX, bestStart = 0, i = 0;
    for (int j = 0; j < (int)s.size(); ++j) {
        if (need[(unsigned char)s[j]]-- > 0) --missing;      // add s[j]; counts only if it was still needed
        while (missing == 0) {                               // valid: shrink as far as possible
            if (j - i + 1 < bestLen) { bestLen = j - i + 1; bestStart = i; }
            if (++need[(unsigned char)s[i]] > 0) ++missing;  // removing s[i] breaks validity?
            ++i;
        }
    }
    return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
}
```

Time O(|s| + |t|), space O(1) for a fixed alphabet. Brute force O(|s|² · |alphabet|) or worse.

**Dry run.** `s = "ADOBECODEBANC", t = "ABC"` → answer `"BANC"`. Key moments: the first valid window is `ADOBEC` (length 6); shrinking removes `A`, which breaks validity, so expansion continues. Later windows such as `CODEBA` (length 6) and `BANC` (length 4) become valid; `BANC` is the minimum.

**Mistakes.** Treating duplicates in `t` as a set; decrementing `missing` when the character was a surplus; shrinking only once instead of `while`; updating the best answer outside the valid state; using `char` index negative.

### 8.9 Sliding window common mistakes

- Using sliding window for sums with negatives.
- `if` instead of `while` for shrinking.
- Not updating state when removing `a[i]`.
- Recording the answer before the window is valid / after shrinking too far.
- Off-by-one in length (`j - i + 1`).
- Mixing "longest valid" and "shortest valid" templates (record inside vs after the loop).

---

## 9. HashMaps and HashSets

### 9.1 Hashing fundamentals

A hash function maps a key to a bucket index. `unordered_map<K,V>` stores key→value pairs; `unordered_set<K>` stores keys only.

| | HashSet | HashMap |
|---|---|---|
| Stores | Keys | Key → value |
| Typical use | Membership, deduplication | Counting, indexing, grouping |
| Question answered | "Have I seen x?" | "What do I know about x?" |

**Collisions.** Different keys can share a bucket; they are chained or probed. With a good hash and bounded load factor, operations are **O(1) on average**; with many collisions a single operation degrades to **O(n)**. Do not claim guaranteed O(1).

C++ ordered alternatives: `map` / `set` are balanced trees with O(log n) guaranteed and sorted iteration.

### 9.2 Core API and traps

| Operation | Code | Notes |
|---|---|---|
| Insert | `mp.insert({k, v})` / `st.insert(x)` | Does **not** overwrite an existing key |
| Assign/overwrite | `mp[k] = v` | Inserts if missing |
| Existence | `mp.count(k)` / `mp.find(k) != mp.end()` | `count` is 0 or 1 for unique-key containers |
| Lookup without inserting | `auto it = mp.find(k)` | Prefer in lookups |
| Erase | `mp.erase(k)` | Returns number erased |
| Size | `mp.size()` | |

**The `operator[]` trap.** `mp[key]` **inserts** `key` with a value-initialized value (0 for `int`) if missing. Using it just to *check* a key grows the map and can change later `size()` results or iteration.

```cpp
unordered_map<int,int> mp;
if (mp[5] == 0) { /* ... */ }      // mp now contains {5, 0}!
bool present = mp.count(5);        // true now — surprising
```

Safe check:

```cpp
auto it = mp.find(5);
if (it != mp.end()) { /* use it->second */ }
```

Also: erasing while iterating requires `it = mp.erase(it)`; `unordered_map` iteration order is unspecified.

### 9.3 Frequency counting

```cpp
unordered_map<int,int> buildFreq(const vector<int>& a) {
    unordered_map<int,int> freq;
    for (int x : a) ++freq[x];          // here operator[] insertion is intentional
    return freq;
}
```

Use a fixed array instead when keys are small bounded integers or letters (faster, deterministic).

### 9.4 Value-to-index mapping: Two Sum

**Recognition.** "Find two numbers adding to target; return indices; array unsorted." Complement lookup: for `x`, look for `target - x`.

**Invariant.** `seen` maps each value in `a[0..j-1]` to an index.

```cpp
vector<int> twoSum(const vector<int>& a, int target) {
    unordered_map<int, int> seen;                       // value -> index
    for (int j = 0; j < (int)a.size(); ++j) {
        auto it = seen.find(target - a[j]);             // look up complement BEFORE inserting a[j]
        if (it != seen.end()) return {it->second, j};
        seen[a[j]] = j;                                 // insert after, so an element never pairs with itself
    }
    return {};
}
```

Time O(n) average, space O(n). **Duplicates:** `[3,3], target=6` works because the first 3 is stored before the second 3 looks for its complement. Brute force O(n²), O(1) space.

**Dry run.** `a = [2,7,11,15], target=9`

| j | a[j] | complement | seen before | result |
|---|---|---|---|---|
| 0 | 2 | 7 | {} | insert 2→0 |
| 1 | 7 | 2 | {2:0} | return {0,1} |

### 9.5 Membership and deduplication

```cpp
bool containsDuplicate(const vector<int>& a) {
    unordered_set<int> seen;
    for (int x : a)
        if (!seen.insert(x).second) return true;        // insert returns {iterator, inserted?}
    return false;
}

vector<int> dedupePreserveOrder(const vector<int>& a) {
    unordered_set<int> seen;
    vector<int> out;
    for (int x : a)
        if (seen.insert(x).second) out.push_back(x);    // first occurrence only
    return out;
}
```

Alternatives: sort + unique (O(n log n), O(1) extra beyond sort, loses original order); `set` for sorted output.

### 9.6 Grouping by property

Map a **canonical key** to a `vector` of elements (Group Anagrams, section 6.5). The key must be identical for all equivalent items and different otherwise. Common keys: sorted string, count signature, tuple of properties.

### 9.7 First Unique Element

Two passes: count frequencies, then find the first element with count 1 in original order.

```cpp
int firstUniqueIndex(const string& s) {
    array<int, 256> freq{};
    for (unsigned char c : s) ++freq[c];
    for (int i = 0; i < (int)s.size(); ++i)
        if (freq[(unsigned char)s[i]] == 1) return i;   // first in ORIGINAL order
    return -1;
}
```

For integers use `unordered_map<int,int>`. **Mistake:** iterating the map to find the first unique (unordered!) instead of the original array.

### 9.8 Longest Consecutive Sequence

**Concept.** Put all values in a set. Only start counting from a number `x` where `x - 1` is **not** in the set (a sequence start). Then walk `x+1, x+2, ...`.

**Why O(n).** Each sequence is walked exactly once from its start, so total work across all starts is n.

```cpp
int longestConsecutive(const vector<int>& a) {
    unordered_set<long long> values(a.begin(), a.end());   // long long avoids x-1 / x+1 overflow
    int best = 0;
    for (long long x : values) {
        if (values.count(x - 1)) continue;                 // not a start: skip
        long long y = x;
        int length = 1;
        while (values.count(y + 1)) { ++y; ++length; }
        best = max(best, length);
    }
    return best;
}
```

Time O(n) average, space O(n). Sorting alternative O(n log n). **Mistakes:** starting a walk from every element (O(n²)); iterating the raw array with duplicates and re-walking; forgetting empty array → 0.

**Dry run.** `[100, 4, 200, 1, 3, 2]`

| x | x−1 in set? | action | length |
|---|---|---|---|
| 100 | no | start; 101 absent | 1 |
| 4 | yes (3) | skip | |
| 200 | no | start; 201 absent | 1 |
| 1 | no | start; 2,3,4 present | 4 |
| 3 | yes | skip | |
| 2 | yes | skip | |

Answer 4.

### 9.9 Common mistakes (hashing)

- `mp[key]` for existence checks.
- Claiming guaranteed O(1).
- Using a HashMap when a 26-slot array suffices.
- Relying on iteration order.
- Not handling duplicates (Two Sum with equal values; set vs multiset).
- Hashing `pair` or `vector` keys directly (no default `std::hash`; build a string/`long long` key or custom hash).
- Storing the key in the map before looking up the complement.

---

## 10. Master Pattern Recognition and Decision Tables

### 10.1 Clue → Pattern → Conditions

| Clue in problem | Candidate pattern | Valid only if | Alternative when invalid |
|---|---|---|---|
| Pair sum, sorted array | Two pointers (opposite) | Array sorted (or sort acceptable) | HashMap |
| Pair sum, unsorted, indices needed | HashMap complement | Any array | Sort pairs + two pointers |
| Triplet sum zero, no duplicate triplets | Sort + two pointers + dedup skip | Order of output not important | |
| In-place filter, keep order | Read–write pointers | | Swap-with-end if order is irrelevant |
| Longest valid contiguous window | Variable window (longest) | Validity is monotonic | Prefix sum + HashMap for sums with negatives |
| Shortest valid window | Variable window (shortest) | Positive values / monotonic coverage | |
| Fixed-length window statistic | Fixed window | Always | |
| Count subarrays with sum K | Prefix sum + HashMap | Any integers | Sliding window only for non-negative with care |
| Max contiguous sum | Kadane | Non-empty subarray; any signs | |
| Many range sums | Prefix sums | Static array | |
| Many range updates, final read | Difference array | Updates before reads | |
| Count/compare characters | Frequency array / HashMap | Alphabet known for arrays | HashMap |
| Seen-before / duplicates | HashSet | | Sort + scan |
| Group equivalent items | Map canonical key → vector | Canonical key well-defined | |
| Longest consecutive values | HashSet with start-of-sequence check | Order not required | Sort |
| Palindromic substring | Expand around center | n ≤ ~5000 for O(n²) | Manacher (outside syllabus) |

### 10.2 Decision flow for "find pair/subarray with sum"

| Question | Yes → | No → |
|---|---|---|
| Is it a **pair** of elements (not contiguous)? | Sorted? Two pointers. Unsorted? HashMap. | Continue |
| Is the target about a **contiguous** subarray? | Continue | Reconsider problem type |
| Are all elements non-negative / positive? | Sliding window works (for ≤ K / ≥ K) | Prefix sum + HashMap |
| Need exact count of subarrays? | Prefix sum + HashMap | |

### 10.3 Complexity cheat table

| Technique | Time | Aux. space |
|---|---|---|
| Prefix sums (build / query) | O(n) / O(1) | O(n) |
| Difference array | O(n + q) | O(n) |
| Kadane | O(n) | O(1) |
| Subarray Sum = K | O(n) avg | O(n) |
| Read–write pointers | O(n) | O(1) |
| Two pointers (sorted pair) | O(n) | O(1) |
| Three Sum | O(n²) | O(1) excluding output |
| Fixed / variable window | O(n) | O(1) or O(alphabet) |
| Expand around center | O(n²) | O(1) |
| Group Anagrams (sorted key) | O(N · L log L) | O(N · L) |
| Longest Consecutive Sequence | O(n) avg | O(n) |

---

## 11. Flagship Problem Bank

**Size.** 29 distinct problems (A2 through H7) plus 3 labelled re-solve rows in Table H. Every one is a classic, frequently asked interview question; all are **Core**. The `Recommended Order` column gives the order within each table. Status boxes are blank.

**Selection rules applied.**
- Only the canonical, most commonly asked interview problems for each learned pattern. Competitive-programming sets and platform-specific extras were removed. Most GeeksforGeeks and InterviewBit interview problems are the same questions as the ones listed here.
- Foundational first, then medium. One Hard (Minimum Window Substring) because it is in the syllabus.
- No unlearned pattern is mandatory. Exactly K Distinct Integers is deliberately absent.
- Difference arrays are in the notes (section 4.4) but are rarely asked as a standalone interview question, so no problem is listed for them. Practice the template from the notes if you want it.
- A problem is repeated only when the second attempt adds something: Table H re-solves Valid Anagram (HashMap version), First Unique Character (map instead of array) and Group Anagrams (count-signature key instead of sorting).
- Difficulty follows LeetCode's labels. Links use the standard LeetCode problem-slug pattern and are not live-verified; if one fails, search the problem name.

**Syllabus gap.** *Longest Subarray with Sum ≤ K (positives)* is a learned problem but not a famous standalone question. Implement the section 8.5 template yourself and test it on hand-made arrays, including one where every element exceeds K (answer 0). F2 uses the same shrink logic.

### Table A — Big-O and Complexity Analysis

| ID | Problem Name | Platform | Difficulty | Primary Pattern | Secondary Pattern | Key Skill Tested | Recommended Order | Estimated Time | Problem Link | Status |
|---|---|---|---|---|---|---|---|---|---|---|
| A2 | [Missing Number](https://leetcode.com/problems/missing-number/) | LeetCode | Easy | Complexity comparison | HashSet, math | Brute O(n²) vs set O(n) vs sum formula O(1) space | 1 · Core | 15 min | [Open](https://leetcode.com/problems/missing-number/) | ☐ |

### Table B — Prefix Sum, Suffix Sum, and Difference Arrays

| ID | Problem Name | Platform | Difficulty | Primary Pattern | Secondary Pattern | Key Skill Tested | Recommended Order | Estimated Time | Problem Link | Status |
|---|---|---|---|---|---|---|---|---|---|---|
| B2 | [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/) | LeetCode | Easy | Prefix sum | Class design | O(1) range queries via `pre[r+1]-pre[l]` | 1 · Core | 15 min | [Open](https://leetcode.com/problems/range-sum-query-immutable/) | ☐ |
| B3 | [Find Pivot Index](https://leetcode.com/problems/find-pivot-index/) | LeetCode | Easy | Prefix sum | Total-sum trick | Left sum vs right sum, edge indices | 2 · Core | 15 min | [Open](https://leetcode.com/problems/find-pivot-index/) | ☐ |
| B4 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | LeetCode | Medium | Prefix/suffix products | In-place output | Two-pass prefix/suffix without division | 3 · Core | 25 min | [Open](https://leetcode.com/problems/product-of-array-except-self/) | ☐ |

### Table C — Kadane and Subarray Problems

| ID | Problem Name | Platform | Difficulty | Primary Pattern | Secondary Pattern | Key Skill Tested | Recommended Order | Estimated Time | Problem Link | Status |
|---|---|---|---|---|---|---|---|---|---|---|
| C1 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) | LeetCode | Medium | Kadane | DP intuition | Extend-or-restart; all-negative arrays | 1 · Core | 20 min | [Open](https://leetcode.com/problems/maximum-subarray/) | ☐ |
| C2 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | LeetCode | Easy | Running minimum | Kadane-style scan | Single pass tracking best so far | 2 · Core | 15 min | [Open](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | ☐ |
| C3 | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | LeetCode | Medium | Prefix sum + HashMap | Frequency map | `freq[0]=1`; lookup before insert; negatives | 3 · Core | 30 min | [Open](https://leetcode.com/problems/subarray-sum-equals-k/) | ☐ |
| C4 | [Rotate Array](https://leetcode.com/problems/rotate-array/) | LeetCode | Medium | In-place reversal | Modulo arithmetic | Three reversals; `k %= n` | 4 · Core | 20 min | [Open](https://leetcode.com/problems/rotate-array/) | ☐ |

### Table D — Read–Write Pointers

| ID | Problem Name | Platform | Difficulty | Primary Pattern | Secondary Pattern | Key Skill Tested | Recommended Order | Estimated Time | Problem Link | Status |
|---|---|---|---|---|---|---|---|---|---|---|
| D1 | [Move Zeroes](https://leetcode.com/problems/move-zeroes/) | LeetCode | Easy | Read–write pointers | In-place swap | Stable compaction, O(1) space | 1 · Core | 10 min | [Open](https://leetcode.com/problems/move-zeroes/) | ☐ |
| D2 | [Remove Element](https://leetcode.com/problems/remove-element/) | LeetCode | Easy | Read–write pointers | — | Logical length vs array size | 2 · Core | 10 min | [Open](https://leetcode.com/problems/remove-element/) | ☐ |
| D3 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | LeetCode | Easy | Read–write pointers | Sorted property | Compare with last kept value | 3 · Core | 15 min | [Open](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | ☐ |
| D4 | [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) | LeetCode | Medium | Read–write pointers | Generalize to at most k | `a[i] != a[j-k]` invariant | 4 · Core | 25 min | [Open](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) | ☐ |

### Table E — Two Pointers

| ID | Problem Name | Platform | Difficulty | Primary Pattern | Secondary Pattern | Key Skill Tested | Recommended Order | Estimated Time | Problem Link | Status |
|---|---|---|---|---|---|---|---|---|---|---|
| E1 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) | LeetCode | Easy | Opposite two pointers | String cleaning | Skip non-alphanumerics, case-insensitive compare | 1 · Core | 15 min | [Open](https://leetcode.com/problems/valid-palindrome/) | ☐ |
| E3 | [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | LeetCode | Medium | Opposite two pointers | — | Why sortedness allows discarding | 2 · Core | 15 min | [Open](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | ☐ |
| E4 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) | LeetCode | Medium | Opposite two pointers | Greedy argument | Move the shorter wall; justify it | 3 · Core | 25 min | [Open](https://leetcode.com/problems/container-with-most-water/) | ☐ |
| E5 | [3Sum](https://leetcode.com/problems/3sum/) | LeetCode | Medium | Sort + two pointers | Duplicate skipping | Skip duplicates at all three positions | 4 · Core | 40 min | [Open](https://leetcode.com/problems/3sum/) | ☐ |

### Table F — Sliding Window

| ID | Problem Name | Platform | Difficulty | Primary Pattern | Secondary Pattern | Key Skill Tested | Recommended Order | Estimated Time | Problem Link | Status |
|---|---|---|---|---|---|---|---|---|---|---|
| F1 | [Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/) | LeetCode | Easy | Fixed window | Running sum | Add entering / remove leaving element | 1 · Core | 15 min | [Open](https://leetcode.com/problems/maximum-average-subarray-i/) | ☐ |
| F2 | [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) | LeetCode | Medium | Variable window (shortest) | Positive integers | Shrink while still valid; record inside loop | 2 · Core | 25 min | [Open](https://leetcode.com/problems/minimum-size-subarray-sum/) | ☐ |
| F3 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | LeetCode | Medium | Variable window (longest) | HashMap / last-seen array | Window invariant: no duplicates | 3 · Core | 30 min | [Open](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | ☐ |
| F5 | [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) | LeetCode | Hard | Variable window (shortest) | Frequency map, `missing` counter | Validity tracking with multiplicity | 4 · Core | 50 min | [Open](https://leetcode.com/problems/minimum-window-substring/) | ☐ |

### Table G — Strings and Palindromes

| ID | Problem Name | Platform | Difficulty | Primary Pattern | Secondary Pattern | Key Skill Tested | Recommended Order | Estimated Time | Problem Link | Status |
|---|---|---|---|---|---|---|---|---|---|---|
| G1 | [Valid Anagram](https://leetcode.com/problems/valid-anagram/) | LeetCode | Easy | Frequency array | HashMap (Unicode follow-up) | Character counting, length check | 1 · Core | 10 min | [Open](https://leetcode.com/problems/valid-anagram/) | ☐ |
| G2 | [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/) | LeetCode | Easy | Frequency counting | Two-pass scan | Return first in original order | 2 · Core | 15 min | [Open](https://leetcode.com/problems/first-unique-character-in-a-string/) | ☐ |
| G3 | [Group Anagrams](https://leetcode.com/problems/group-anagrams/) | LeetCode | Medium | HashMap grouping | Canonical key | Map of vectors; sorted-key or count-key | 3 · Core | 30 min | [Open](https://leetcode.com/problems/group-anagrams/) | ☐ |
| G4 | [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) | LeetCode | Medium | Expand around center | Two pointers | Odd and even centers; start/length bookkeeping | 4 · Core | 35 min | [Open](https://leetcode.com/problems/longest-palindromic-substring/) | ☐ |

### Table H — HashMap and HashSet

| ID | Problem Name | Platform | Difficulty | Primary Pattern | Secondary Pattern | Key Skill Tested | Recommended Order | Estimated Time | Problem Link | Status |
|---|---|---|---|---|---|---|---|---|---|---|
| H1 | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) | LeetCode | Easy | HashSet | Sorting alternative | `insert().second` membership/dedup | 1 · Core | 10 min | [Open](https://leetcode.com/problems/contains-duplicate/) | ☐ |
| H2 | [Two Sum](https://leetcode.com/problems/two-sum/) | LeetCode | Easy | HashMap complement | Value-to-index map | Lookup complement before inserting | 2 · Core | 15 min | [Open](https://leetcode.com/problems/two-sum/) | ☐ |
| H3 | [Ransom Note](https://leetcode.com/problems/ransom-note/) | LeetCode | Easy | Frequency counting | Array vs map | Count then consume, early exit | 3 · Core | 10 min | [Open](https://leetcode.com/problems/ransom-note/) | ☐ |
| H5 | [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/) | LeetCode | Easy | HashSet | Set intersection | Deduplicated membership checks | 4 · Core | 15 min | [Open](https://leetcode.com/problems/intersection-of-two-arrays/) | ☐ |
| H-G1 | [Valid Anagram (re-solve; see G1)](https://leetcode.com/problems/valid-anagram/) | LeetCode | Easy | Frequency counting | HashMap<char,int> | Re-solve with a HashMap to handle the Unicode follow-up | 5 · Core | 10 min | [Open](https://leetcode.com/problems/valid-anagram/) | ☐ |
| H-G2 | [First Unique Character (re-solve; see G2)](https://leetcode.com/problems/first-unique-character-in-a-string/) | LeetCode | Easy | Frequency map | Two-pass scan | Re-solve with `unordered_map`; do not iterate the map for order | 6 · Core | 10 min | [Open](https://leetcode.com/problems/first-unique-character-in-a-string/) | ☐ |
| H-G3 | [Group Anagrams (re-solve; see G3)](https://leetcode.com/problems/group-anagrams/) | LeetCode | Medium | HashMap grouping | Canonical key | Re-solve with the 26-count key instead of sorting | 7 · Core | 25 min | [Open](https://leetcode.com/problems/group-anagrams/) | ☐ |
| H7 | [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) | LeetCode | Medium | HashSet | Sequence-start check | Walk only from `x` where `x-1` is absent | 8 · Core | 35 min | [Open](https://leetcode.com/problems/longest-consecutive-sequence/) | ☐ |

**Table H note.** Rows `H-G1` to `H-G3` are not new problems; they are deliberate re-solves with a different data-structure choice. You can do them as the end-of-session re-solve (section 12).

---


## 12. Five-to-Six-Hour Problem-Solving Day

Total length: **5 h 30 min including breaks** (about 4 h 15 min of actual problem-solving). HashMap/HashSet gets the largest share because it is the area being consolidated. IDs refer to section 11.

If you are unwell, short on sleep, or just drained, **use the light plan in section 13 instead** or stop early. Finishing every block is not the goal; consistent, clear thinking is.

| Time Block | Duration | Pattern | Selected Problems | Expected Outcome | Break / Recovery Notes |
|---|---|---|---|---|---|
| 0:00–0:15 | 15 min | Recall warm-up (no notes) | Write from memory: Two Sum map loop, Kadane, fixed-window template, Longest Consecutive Sequence start-check | Spot which templates are shaky before solving | Drink water before starting |
| 0:15–1:30 | 75 min | HashMap/HashSet A: frequency, membership, dedup | **Core:** H1 Contains Duplicate, H3 Ransom Note, H5 Intersection of Two Arrays, H2 Two Sum, H-G1 Valid Anagram (map version) | Fluent frequency counting, `find` vs `[]`, set-based dedup | |
| 1:30–1:45 | 15 min | Break | — | — | Stand up, water, short walk, no screens if possible |
| 1:45–2:55 | 70 min | HashMap/HashSet B: grouping, first unique, sequences | **Core:** H-G2 First Unique Character, H-G3 Group Anagrams, H7 Longest Consecutive Sequence. | Canonical keys, order-preserving uniqueness, O(n) sequence starts | Longest Consecutive Sequence is the hardest here; give it 30+ min before reading hints |
| 2:55–3:25 | 30 min | Meal break | — | — | Eat properly, hydrate, rest your eyes |
| 3:25–4:25 | 60 min | Arrays / pointers / window revision | **Core:** C3 Subarray Sum Equals K, D4 Remove Duplicates II, F3 Longest Substring Without Repeating Characters. **Optional:** E5 3Sum, F2 Minimum Size Subarray Sum | Keep non-hash patterns warm; practice choosing between prefix+map, pointers, windows | |
| 4:25–4:35 | 10 min | Break | — | — | Stretch, water |
| 4:35–5:15 | 40 min | Re-solve and mistake analysis | Re-solve from a blank file: H7 Longest Consecutive Sequence, G3 Group Anagrams, C3 Subarray Sum Equals K | Confirms you can reproduce the invariants without notes | If one fails, write the cause in the mistake log instead of re-reading everything |
| 5:15–5:30 | 15 min | Wrap-up | Update tracker (section 15), mistake log, set revisit dates (section 16) | Clear next actions | Stop here; finish with water and rest |

**Mandatory set:** H1, H3, H5, H2, H-G1, H-G2, H-G3, H7, C3, D4, F3 (11 problems; re-solves are shorter than first attempts).
**Optional:** E5, F2 (only if you are energetic and ahead of schedule).

**Rules of the session**
1. Per problem: 10–15 min of honest independent attempt before looking at a hint; hints first, full solutions last.
2. Always write brute force and invariant before coding (worksheet in section 14, abbreviated is fine).
3. If a problem exceeds 1.5× its estimated time, log it, move on, and revisit later.
4. Take the breaks even when you feel fine.

---

## 13. Light Revision Plan (60–90 Minutes)

For low-energy days or when time is short.

| Time Block | Duration | Pattern | Selected Problems | Expected Outcome | Break / Recovery Notes |
|---|---|---|---|---|---|
| 0:00–0:10 | 10 min | Template recall | Write Two Sum (map), prefix sum + map for K, fixed window from memory | Identify one weak template | Water |
| 0:10–0:40 | 30 min | HashMap/HashSet | H1 Contains Duplicate, H3 Ransom Note, H-G2 First Unique Character (any two, plus one re-solve) | Fluent counting/membership | |
| 0:40–0:45 | 5 min | Break | — | — | Stand and stretch |
| 0:45–1:15 | 30 min | One harder item | **Pick one:** H7 Longest Consecutive Sequence (re-solve) or G3 Group Anagrams | One reliable pattern reproduced | |
| 1:15–1:30 | 15 min | Log | Tracker and mistake log, choose tomorrow's first problem | Clear next step | End here; sleep and rest matter |

If you only have 60 minutes: skip the optional re-solve in block 2 and shorten the log to 5 minutes. If you feel unwell, stopping entirely is the right call.

---

## 14. Problem-Solving Worksheet and Mistake Log

### 14.1 Blank worksheet (copy per problem)

````markdown
#### Problem: <ID and name>

1. **Problem name and link:**
2. **Problem restatement (own words):**
3. **Input constraints:**
4. **Pattern clues:**
5. **Brute-force approach:**
6. **Brute-force complexity:**
7. **Optimization observation:**
8. **Optimized approach:**
9. **Invariant:**
10. **C++17 solution:**

    ```cpp
    // code here
    ```

11. **Dry run:**
12. **Time complexity:**
13. **Auxiliary space:**
14. **Edge cases tested:** (empty / size 1 / duplicates / negatives / overflow / all same)
15. **Mistake or insight:**
16. **Can I solve it again without notes?** ☐ Yes ☐ Not yet — revisit on: ____
````

### 14.2 Mistake log

| Date | Problem ID | Mistake / Wrong assumption | Root cause | Correct idea | Rule for next time | Fixed on retry? |
|---|---|---|---|---|---|---|
| | | | | | | ☐ |
| | | | | | | ☐ |
| | | | | | | ☐ |
| | | | | | | ☐ |
| | | | | | | ☐ |

Typical root-cause categories: **misread statement**, **wrong pattern choice**, **invariant not stated**, **off-by-one**, **duplicate handling**, **overflow**, **forgot edge case**, **complexity miscalculated**, **language/API trap** (e.g., `mp[key]` inserting).

---

## 15. Progress Tracker

All boxes start empty. Tick them only when true.

### 15.1 Problem tracker

| Problem ID | Problem name | Attempted independently? | Brute force understood? | Optimized approach understood? | C++ accepted? | Dry run completed? | Pattern recognized independently? | Revisit date | Notes |
|---|---|---|---|---|---|---|---|---|---|
| A2 | Missing Number | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| B2 | Range Sum Query - Immutable | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| B3 | Find Pivot Index | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| B4 | Product of Array Except Self | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| C1 | Maximum Subarray | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| C2 | Best Time to Buy and Sell Stock | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| C3 | Subarray Sum Equals K | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| C4 | Rotate Array | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| D1 | Move Zeroes | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| D2 | Remove Element | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| D3 | Remove Duplicates from Sorted Array | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| D4 | Remove Duplicates from Sorted Array II | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| E1 | Valid Palindrome | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| E3 | Two Sum II - Input Array Is Sorted | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| E4 | Container With Most Water | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| E5 | 3Sum | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| F1 | Maximum Average Subarray I | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| F2 | Minimum Size Subarray Sum | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| F3 | Longest Substring Without Repeating Characters | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| F5 | Minimum Window Substring | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| G1 | Valid Anagram | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| G2 | First Unique Character in a String | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| G3 | Group Anagrams | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| G4 | Longest Palindromic Substring | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| H1 | Contains Duplicate | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| H2 | Two Sum | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| H3 | Ransom Note | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| H5 | Intersection of Two Arrays | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |
| H7 | Longest Consecutive Sequence | ☐ | ☐ | ☐ | ☐ | ☐ | ☐ | | |

### 15.2 Pattern mastery

Fill the confidence columns with your own rating (for example 1–5) after practice. They are blank on purpose.

| Pattern | Recognition confidence | Implementation confidence | Revision needed? | Next action |
|---|---|---|---|---|
| Problem-solving framework | | | ☐ | |
| Big-O and complexity analysis | | | ☐ | |
| Prefix / suffix sums | | | ☐ | |
| Difference arrays | | | ☐ | |
| Kadane's Algorithm | | | ☐ | |
| Subarray Sum Equals K (prefix + map) | | | ☐ | |
| In-place array rotation | | | ☐ | |
| Read–write pointers | | | ☐ | |
| Strings, palindromes, expand around center | | | ☐ | |
| Anagram detection and Group Anagrams | | | ☐ | |
| Two pointers (opposite / same direction) | | | ☐ | |
| Three Sum and duplicate handling | | | ☐ | |
| Sliding window (fixed) | | | ☐ | |
| Sliding window (variable, longest / shortest) | | | ☐ | |
| Minimum Window Substring | | | ☐ | |
| HashMap: frequency counting | | | ☐ | |
| HashMap: value-to-index / complement lookup | | | ☐ | |
| HashMap: grouping | | | ☐ | |
| HashSet: membership and deduplication | | | ☐ | |
| First Unique Element | | | ☐ | |
| Longest Consecutive Sequence | | | ☐ | |

---

## 16. Revision Schedule

Spaced revisiting works best when each review is a **blind re-solve**, not a re-read.

| Review | When | What to do |
|---|---|---|
| R1 | Next day | Re-solve problems you needed hints for |
| R2 | After 3 days | Re-solve from a blank file; write the invariant first |
| R3 | After 1 week | Mixed set: 1 hash, 1 window, 1 pointer problem; identify the pattern before coding |
| R4 | After 2–3 weeks | Timed attempt at the Core problems you found hardest |

Always review the mistake log (section 14.2) before each session. Anything that repeats twice becomes a one-line rule at the top of the log.

---

*End of register. Remember the link policy at the top: verify any link that fails by searching the problem name on the platform.*
