---
title: "Day 1 — Foundations & Hashing: The Flagship Workbook"
subtitle: "28 Days to Pattern Fluency"
subject: "DSA foundations, hashing, frequency counting, index-as-hash, and in-place array patterns"
lang: en
---

28 DAYS TO PATTERN FLUENCY — DAY 01

# FOUNDATIONS & HASHING

“Learn the clue. Understand the pattern. Build the solution.”

**PROBLEM → BRUTE FORCE → BOTTLENECK → PATTERN → OPTIMISATION → PROOF**

Complexity analysis · Hashing and STL · Frequency counting · Index-as-hash  
Sign marking · Counting arrays and prefix sums · Two pointers and in-place compaction  
Majority element · 24 linked practice problems · C++ solutions, dry runs, interview preparation

A print-friendly, handwritten-inspired study workbook. Make the thinking yours.

> **How to use this `.md` file:** read it in VS Code, Obsidian, Typora, GitHub, or any Markdown viewer. Code is kept as fenced C++ blocks; LeetCode problem names are clickable. You can edit the file directly and print/export it from your Markdown editor if needed.

## Contents

- [How to use this workbook](#how-to-use-this-workbook)
- [Problem-solving fundamentals](#problem-solving-fundamentals)
- [Big-O and online-assessment constraints](#big-o-and-online-assessment-constraints)
- [Hashing deep dive and C++ STL](#hashing-deep-dive-and-c-stl)
- [Pattern radar](#pattern-radar)
- [Six reusable C++ templates](#six-reusable-c-templates)
- [Deep dive: index-as-hash — 448 versus 41](#deep-dive-index-as-hash--448-versus-41)
- [Deep dive: counting arrays — 1365](#deep-dive-counting-arrays--leetcode-1365)
- [Deep dive: read/write pointers](#deep-dive-readwrite-pointers)
- [Edge-case lab](#edge-case-lab)
- [Debugging clinic](#debugging-clinic)
- [Interview answer framework](#interview-answer-framework)
- [Revision register & spaced repetition](#revision-register--spaced-repetition)
- [Attempt-first problem ladder — no spoilers](#attempt-first-problem-ladder--no-spoilers)
- [Worked solutions](#worked-solutions--open-only-after-your-attempt)
  - [01 Contains Duplicate](#01-contains-duplicate) · [02 Missing Number](#02-missing-number) · [03 Find All Numbers Disappeared](#03-find-all-numbers-disappeared-in-an-array)
  - [04 Two Sum](#04-two-sum) · [05 Final Value of Variable](#05-final-value-of-variable-after-performing-operations) · [06 Numbers Smaller Than Current](#06-how-many-numbers-are-smaller-than-the-current-number)
  - [07 Valid Anagram](#07-valid-anagram) · [08 Majority Element](#08-majority-element) · [09 Move Zeroes](#09-move-zeroes)
  - [10 Remove Duplicates](#10-remove-duplicates-from-sorted-array) · [11 Remove Element](#11-remove-element) · [12 First Missing Positive](#12-first-missing-positive)
  - [13 Intersection of Two Arrays](#13-intersection-of-two-arrays) · [14 Intersection II](#14-intersection-of-two-arrays-ii) · [15 Ransom Note](#15-ransom-note)
  - [16 First Unique Character](#16-first-unique-character-in-a-string) · [17 Contains Duplicate II](#17-contains-duplicate-ii) · [18 Unique Number of Occurrences](#18-unique-number-of-occurrences)
  - [19 Isomorphic Strings](#19-isomorphic-strings) · [20 Word Pattern](#20-word-pattern) · [21 Happy Number](#21-happy-number)
  - [22 Valid Sudoku](#22-valid-sudoku) · [23 Longest Consecutive Sequence](#23-longest-consecutive-sequence) · [24 Group Anagrams](#24-group-anagrams)
- [Closed-notes retrieval test](#closed-notes-retrieval-test)
- [Final page — the Day 1 promise](#final-page--the-day-1-promise)

---

## How to use this workbook

**Struggle-first workflow**

1. Read the problem statement and restate it in your own words.
2. Identify input, output, constraints, and edge cases.
3. Attempt independently for 15–20 minutes.
4. Write brute force before optimising.
5. Name the bottleneck.
6. Choose a candidate pattern and test whether it fits.
7. Implement, dry-run manually, and test edge cases.
8. Consult a verified solution only after a genuine attempt.
9. Close it and reimplement from a blank editor.
10. Record mistakes in the revision register.

Reading a solution builds recognition; independently producing one builds retrieval and implementation skill. They are related, but not interchangeable.

**Two-part layout:** use the attempt-first ladder near the front without pattern labels or hints. The fully worked solutions come later, so you can cover them during your attempt.

## Problem-solving fundamentals

First clarify what is being asked. State the input and output, then rewrite the requirement as a condition you can test. Read constraints before selecting a data structure: they often determine whether quadratic work is plausible.

Construct a small normal example, then a boundary example. Try brute force because it gives a correctness baseline. Next ask: what work repeats? Can a set remember membership, a map remember a count/index, or sorted order make equal values adjacent?

A proof usually names an invariant: what is true before and after every loop iteration? Complexity then follows from the number of operations and the memory retained beyond the input/output.

### Worked example: Contains Duplicate

Brute force checks all pairs i<j. It is correct because any duplicate forms a matching pair, but takes O(n^2) comparisons. For n=100,000, pair checks are about 5,000,000,000.

```cpp
for (int i = 0; i < n; ++i)
  for (int j = i + 1; j < n; ++j)
    if (nums[i] == nums[j]) return true;
return false;
```

The hash-set version remembers each prior value. For [4,1,4], the set evolves {} → {4} → {4,1}; the final 4 is found and the function returns true.

```cpp
unordered_set seen;
for (int x : nums) {
    if (seen.find(x) != seen.end()) return true;
    seen.insert(x);
}
return false;
```

**Invariant:** before processing each value, seen contains exactly the distinct values in the processed prefix. Average time O(n), auxiliary space O(n). Hash lookup is average O(1), not a guaranteed worst-case bound.

## Big-O and online-assessment constraints

| Growth | Typical example | Intuition |
| --- | --- | --- |
| O(1) | Array index access | Does not grow with n |
| O(log n) | Binary search | Problem size shrinks by a factor |
| O(n) | One array scan | Work grows linearly |
| O(n log n) | Comparison sorting | Logarithmic work per level/element |
| O(n^2) | All pairs | Nested full scans |
| O(n^3) | All triples | Three nested dimensions |
| O(2^n) | Enumerate subsets | Each item has two choices |
| O(n!) | Enumerate permutations | Choice count multiplies rapidly |

Time complexity measures operation growth. Auxiliary space measures extra memory used by the algorithm, excluding the input and normally excluding the required output. Output space is reported separately. Best, average, and worst cases describe different input/behavior scenarios; state which one applies.

Drop constant factors and lower-order terms for asymptotic growth: 3n²+8n+10 is O(n²). Recursion may use stack space proportional to depth. Sorting is usually O(n log n), but the exact bound depends on the algorithm and library guarantees.

| n | n² | n log2 n (approx.) | 2^n |
| --- | --- | --- | --- |
| 1,000 | 1,000,000 | ~9,966 | not shown |
| 100,000 | 10,000,000,000 | ~1,660,964 | not shown |
| 20 | 400 | ~86 | 1,048,576 |

Rule-of-thumb only: n≈1,000 may permit O(n²); n≈100,000 usually calls for near-linear or n log n; n≈20 can make some O(2^n) methods plausible. Runtime depends on constants, language, pruning, and time limits. 2^20 = 1,048,576.

## Hashing deep dive and C++ STL

A hash function maps a key to a hash value used to choose a bucket. Different keys can collide; a hash table must resolve collisions. Load factor is the number of elements divided by bucket count. Rehashing changes bucket layout as the table grows and can cost linear time for that operation.

**unordered\_set** stores distinct keys for membership. **unordered\_map** stores key/value associations such as value→count or value→index. Both provide average O(1) lookup/insertion, but worst-case operations can be O(n). Ordered **set** and **map** use tree-like structures and generally provide O(log n) operations.

`seen.find(x) != seen.end()` means “the lookup did not return the past-the-end iterator, so x exists.” `end()` is not the final element; it marks the position just beyond the range. Member `unordered_set::find` uses hashing on average; generic `std::find(begin,end,x)` linearly scans a range.

| Structure | Typical operation | Use it when… |
| --- | --- | --- |
| vector | Index O(1), search O(n) | Order/indexing and compact storage matter |
| unordered\_set | Average membership O(1) | Only need distinct keys / seen-before |
| unordered\_map | Average lookup/update O(1) | Need key→count/index/value |
| set | O(log n) | Need sorted unique keys |
| map | O(log n) | Need sorted key→value mapping |
| Bounded counting array | O(1) per domain value | Keys come from a small known range |

**STL reference shelf:** unordered\_set · unordered\_map · std::find · std::vector · std::map · std::set · std::string · std::sort

## Pattern radar

| Problem clue | Candidate pattern |
| --- | --- |
| Has any value appeared before? | Hash set |
| How many times does each value occur? | Frequency map / counting array |
| Two values sum to target | Complement lookup |
| Small bounded value domain | Counting array |
| Values in [1,n], some missing | Index-as-hash / sign marking |
| First missing positive in O(n), O(1) extra space | Index placement |
| Remove values in-place | Read/write pointers |
| Remove duplicates from sorted array | Read/write pointers |
| Frequency > n/2 | Boyer–Moore voting |
| Longest consecutive run in O(n) average | Hash set + sequence starts |
| Group anagrams | Canonical key + hash map |

**Decision tree:** Need membership? → set. Need count/index/value? → map. Tiny bounded domain? → counting array. Values encode valid indices? → sign marking or placement. Must mutate in-place? → read/write or cyclic placement. Need majority? → Boyer–Moore. Need equivalence groups? → canonical key.

These clues are hypotheses, not magic keywords. Validate the preconditions and complexity against the full statement.

## Six reusable C++ templates

### T1 — Membership / seen-before

```cpp
unordered_set seen;
for (int x : nums) {
    if (seen.count(x)) return true;
    seen.insert(x);
}
return false;
```

Assumption: equality and hashing are defined for the key type. Average O(n) time, O(n) auxiliary space. Mini-run [2,5,2]: insert 2, insert 5, then 2 is found.

### T2 — Frequency counting

```cpp
unordered_map freq;
for (int x : nums) ++freq[x];
```

Average O(n) time and O(u) space for u distinct values. If values are in a small fixed domain such as [0,100], an array of 101 counters is usually simpler and more cache-friendly.

### T3 — Complement lookup

```cpp
unordered_map index;
for (int i = 0; i < (int)nums.size(); ++i) {
    int need = target - nums[i];
    auto it = index.find(need);
    if (it != index.end()) return {it->second, i};
    index[nums[i]] = i;
}
```

Lookup first means the map contains only earlier indices. For [3,3], target 6, the second 3 finds the first index instead of pairing the first element with itself.

### T4 — Read/write pointer

```cpp
int write = 0;
for (int read = 0; read < (int)nums.size(); ++read) {
    if (keep(nums[read])) nums[write++] = nums[read];
}
```

Invariant: nums[0..write-1] contains exactly the kept values from the processed prefix, in the order encountered. O(n) time, O(1) extra space.

### T5 — Sign marking / index-as-hash

```cpp
for (int i = 0; i < (int)nums.size(); ++i) {
    int idx = abs(nums[i]) - 1;
    if (nums[idx] > 0) nums[idx] = -nums[idx];
}
```

Requires every value in [1,n]. Value v maps to index v-1. abs() recovers the original value after its slot has been marked. Negativity means seen; a still-positive slot means missing. O(n) time and O(1) auxiliary space, with input mutation.

### T6 — Counting array + prefix sums

```cpp
int freq[101] = {};
for (int x : nums) ++freq[x];
for (int x = 1; x <= 100; ++x) freq[x] += freq[x - 1];
```

After prefixing, freq[x] is count(values ≤ x). Therefore freq[x-1] is count(values < x) for x>0. For x=0, answer 0. O(n+101) time, O(101) auxiliary storage.

## Deep dive: index-as-hash — 448 versus 41

| Property | 448: sign marking | 41: index placement |
| --- | --- | --- |
| Goal | Return every missing value in [1,n] | Return smallest missing positive |
| Mapping | Value v marks slot v-1 negative | Value v is swapped into slot v-1 |
| Preconditions | Every input value lies in [1,n] | Any values allowed; only values in [1,n] are placed |
| Duplicates | Only negate a positive slot | Swap only if destination does not already equal x |
| Mutation | Yes | Yes |
| Auxiliary space | O(1), excluding returned list | O(1) |

Sign-marking answers “which in-range values appeared?” Index placement answers “which positive number belongs at each index?” In cyclic placement, the **while** loop is essential because a swap can bring another placeable value into the current slot. The duplicate guard prevents an infinite loop.

## Deep dive: counting arrays — LeetCode 1365

Input: [8,1,2,2,3]. The bounded domain is 0..100, so a fixed counter array avoids sorting.

| Value x | Exact frequency | Prefix count ≤ x | Strictly smaller count |
| --- | --- | --- | --- |
| 0 | 0 | 0 | 0 (special case) |
| 1 | 1 | 1 | freq[0] = 0 |
| 2 | 2 | 3 | freq[1] = 1 |
| 3 | 1 | 4 | freq[2] = 3 |
| 8 | 1 | 5 | freq[7] = 4 |

Final lookup in original order: 8→4, 1→0, 2→1, 2→1, 3→3. Correct output: **[4,0,1,1,3]**. Sorting costs O(n log n); counting costs O(n+101), with O(101) auxiliary storage plus O(n) output.

## Deep dive: read/write pointers

**read** explores every original position; **write** marks the next place to put a retained value. They are not the conventional slow/fast pointer pattern used for linked lists or cycle detection: here their roles are specifically scan and compact.

| Task | Keep condition | After scan |
| --- | --- | --- |
| Move Zeroes | nums[read] != 0, then fill suffix with zero | Stable nonzeros, zeros at end |
| Remove Element | nums[read] != val | First k slots contain retained values |
| Remove Duplicates | write==0 or nums[read] != nums[write-1] | First k slots contain unique sorted values |

The valid-prefix invariant is the proof: after each read step, the first write elements are exactly the retained items seen so far.

## Edge-case lab

| Test | Bug it can expose |
| --- | --- |
| Empty array | Invalid indexing, wrong initial answer |
| One element | Off-by-one loops |
| All equal / all distinct | Duplicate logic and uniqueness assumptions |
| Negative values and zero | Unsafe index mapping or sign assumptions |
| Two Sum duplicate values | Reusing the same index |
| Missing first or last value | Boundary errors in range/index mapping |
| Repeated values targeting same index | Accidental sign restoration or infinite swap loop |
| Domain boundary 0 and 100 | Counting-array bounds and x=0 case |
| Every string character repeated | Failure to return -1 for no unique character |
| Single-element majority | Incorrect candidate initialization |

**Regression worksheet:** Input: \_\_\_\_\_\_\_\_\_\_ Expected output: \_\_\_\_\_\_\_\_\_\_ Actual output: \_\_\_\_\_\_\_\_\_\_ Failed assumption: \_\_\_\_\_\_\_\_\_\_ Fix: \_\_\_\_\_\_\_\_\_\_ Regression test: \_\_\_\_\_\_\_\_\_\_

## Debugging clinic

| Mistake | Why it fails / correction |
| --- | --- |
| 1. Wrong hash iterator comparison | Compare iterator with that container's end(): it != seen.end(). |
| 2. Confusing member find and std::find | unordered\_set::find is average O(1); generic std::find scans linearly. |
| 3. Forgetting seen.insert(x) | The set never records prior values; [1,1] is missed. Insert after checking. |
| 4. Insert before Two Sum lookup | Can match the current index to itself; [3], target 6 is a counterexample. Lookup first. |
| 5. Indexing without checking constraints | nums[x-1] is unsafe if x is outside [1,n]. Check the range first. |
| 6. Reversing a sign-marked value | Only negate when nums[idx] > 0; abs() the current value to recover its value. |
| 7. if instead of while in 41 | A swap may bring another placeable number to i; continue until it is placed or invalid. |
| 8. No duplicate guard in cyclic placement | [1,1] can swap forever. Require nums[x-1] != x. |
| 9. Forgetting x=0 in 1365 | freq[x-1] would index -1. Explicitly return 0 for x=0. |
| 10. Exact frequency vs prefix count | After prefixing, freq[x] means ≤x, not exactly x. Strictly smaller is freq[x-1]. |
| 11. Calling total space O(1) | Separate auxiliary storage from output: a returned vector may be O(k) or O(n). |
| 12. Assuming unordered order | Hash containers do not promise sorted/stable order; sort if needed. |
| 13. Set for multiplicity | A set collapses [2,2] to {2}; use a frequency map when copies matter. |
| 14. Not verifying Boyer–Moore | If majority is not guaranteed, count the candidate in a second pass and verify >n/2. |

## Interview answer framework

**Use this exact order:** Brute force → bottleneck → optimisation → correctness invariant → time complexity → auxiliary-space complexity → edge cases.

**Contains Duplicate:** Pairwise comparison is O(n²). Repeated comparisons are unnecessary, so use a hash set. Before each iteration it contains all distinct prior values. A hit means duplicate. Average O(n) time, O(n) auxiliary space. Test empty, singleton, and repeated values.

**Two Sum:** Pairwise search is O(n²). For each x, look up target-x among prior values and then store x→index. The map only contains earlier indices, preventing self-use. Average O(n) time and O(n) auxiliary space.

**448:** Search each candidate repeatedly, or use in-place sign marking because values are guaranteed in [1,n]. Value v marks index v-1; positive slots identify missing values. O(n) time, O(1) auxiliary space excluding output. Test duplicates and values at 1 and n.

**1365:** Pairwise counting is O(n²); sorting is O(n log n). Since values are in [0,100], count frequencies and prefix them. For x>0, freq[x-1] is the strict-smaller count; x=0 gives zero. O(n+101) time, O(101) auxiliary and O(n) output.

**First Missing Positive:** A set is O(n) extra space. Place each value x in slot x-1 while 1≤x≤n and the destination differs from x. The first mismatch gives the answer. The while loop plus duplicate guard ensures each placement progresses. O(n) amortised time and O(1) auxiliary space.

**Move Zeroes:** A second vector costs O(n) space. Read scans and write compacts nonzeros; the suffix is filled with zeros. The valid prefix preserves encounter order. O(n) time and O(1) extra space.

**Remove Element:** Repeated erasure may shift the suffix O(n) times. Copy each non-val item to write. The prefix is exactly the retained items. O(n) time, O(1) auxiliary space; only first k positions matter.

**Majority Element:** Counting each candidate naïvely is O(n²). Boyer–Moore cancels unlike votes; a true majority outnumbers all other values combined and survives. O(n) time, O(1) space. Verify the candidate if existence is not guaranteed.

### Rapid follow-ups — model answers

- **Set vs map?** Set for membership; map when a key needs count, index, or associated value.
- **Why average O(1) hashing?** Expected bucket access stays constant under suitable hash distribution and load factor; worst-case collisions can make operations O(n).
- **Why sign marking O(1) auxiliary?** It reuses the input array as the marker storage; the returned missing-values vector is output space and should be reported separately.
- **Why counting faster than sorting for 1365?** The value domain has only 101 possibilities, so O(n+101) beats O(n log n) asymptotically for the stated bounded domain.
- **Why while in cyclic placement?** A swap can place a new value at the current index, which may need another swap.
- **Why lookup before Two Sum insertion?** The map must represent earlier indices only; otherwise an element may pair with itself.
- **Why does set fail for Intersection II?** It removes duplicates, but the answer must preserve minimum multiplicities.
- **When is sorting preferable to hashing?** When sorted output/order is needed, memory is constrained, or deterministic O(n log n) behavior is preferred.
- **What if majority is not guaranteed?** Count the final candidate and verify its frequency is greater than n/2.
- **Why both isomorphic mappings?** One direction prevents a source mapping to multiple targets; the reverse prevents two sources mapping to one target.

## Revision register & spaced repetition

### Six-template checklist

| Template | Can I write it from memory? | Recall date |
| --- | --- | --- |
| T1 Membership | ☐ Yes ☐ Not yet | \_\_\_\_\_\_\_\_ |
| T2 Frequency | ☐ Yes ☐ Not yet | \_\_\_\_\_\_\_\_ |
| T3 Complement lookup | ☐ Yes ☐ Not yet | \_\_\_\_\_\_\_\_ |
| T4 Read/write | ☐ Yes ☐ Not yet | \_\_\_\_\_\_\_\_ |
| T5 Sign marking | ☐ Yes ☐ Not yet | \_\_\_\_\_\_\_\_ |
| T6 Counting + prefix | ☐ Yes ☐ Not yet | \_\_\_\_\_\_\_\_ |

### Pattern recall

Clue I noticed: \_\_\_\_\_\_\_\_\_\_ Candidate pattern: \_\_\_\_\_\_\_\_\_\_ Preconditions: \_\_\_\_\_\_\_\_\_\_ Counterexample that breaks it: \_\_\_\_\_\_\_\_\_\_ Proof invariant: \_\_\_\_\_\_\_\_\_\_

### Mistake log

| Problem / date | Mistake | Root cause | Correction rule | Retest |
| --- | --- | --- | --- | --- |
|  |  |  |  |  |
|  |  |  |  |  |

### Complexity revision

| Pattern | Time | Auxiliary space |
| --- | --- | --- |
| Hash membership | Average O(n) | O(n) |
| Bounded counting | O(n+R) | O(R) |
| Read/write compaction | O(n) | O(1) |
| Sign marking | O(n) | O(1), output separate |
| Cyclic placement | O(n) amortised | O(1) |

**Next day:** 10-minute recall of all six templates; re-solve two mistakes without notes; explain 1365 and 41 aloud.  
**Day 3:** Re-solve 448, Two Sum, Move Zeroes, and First Missing Positive from a blank editor; compare invariants.  
**Day 7:** Run the closed-notes retrieval test, then reattempt every failed question after a short break.

## Attempt-first problem ladder — no spoilers

Do not scroll to worked solutions until you have made a genuine attempt.

**1. [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)**

Return true if any integer appears at least twice; otherwise return false.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**2. [Missing Number](https://leetcode.com/problems/missing-number/)**

An array contains n distinct values from 0 through n. Return the missing value.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**3. [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)**

Return all values from 1 through n that do not occur in the length-n array.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**4. [Two Sum](https://leetcode.com/problems/two-sum/)**

Return indices of two distinct elements whose sum equals target.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**5. [Final Value of Variable After Performing Operations](https://leetcode.com/problems/final-value-of-variable-after-performing-operations/)**

Start at X=0, apply all given increment/decrement operations, and return X.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**6. [How Many Numbers Are Smaller Than the Current Number](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/)**

For each element, count the array elements strictly smaller than it.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**7. [Valid Anagram](https://leetcode.com/problems/valid-anagram/)**

Return true if one string is a rearrangement of the other.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**8. [Majority Element](https://leetcode.com/problems/majority-element/)**

Return the value occurring more than floor(n/2) times.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**9. [Move Zeroes](https://leetcode.com/problems/move-zeroes/)**

Move zeros to the end while preserving nonzero order, in-place.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**10. [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)**

Keep one copy of each value in a sorted array and return the new length.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**11. [Remove Element](https://leetcode.com/problems/remove-element/)**

Remove all occurrences of val in-place and return the retained length.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**12. [First Missing Positive](https://leetcode.com/problems/first-missing-positive/)**

Return the smallest positive integer absent from an unsorted array.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**13. [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/)**

Return the distinct values shared by two arrays.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**14. [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/)**

Return the shared values, including multiplicity.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**15. [Ransom Note](https://leetcode.com/problems/ransom-note/)**

Determine whether one string can be built from the characters of another, each used at most once.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**16. [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/)**

Return the index of the first character that appears once, or -1.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**17. [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/)**

Return true if equal values occur at indices no more than k apart.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**18. [Unique Number of Occurrences](https://leetcode.com/problems/unique-number-of-occurrences/)**

Return true if every distinct value has a unique frequency.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**19. [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/)**

Check whether two strings have a consistent one-to-one character mapping.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**20. [Word Pattern](https://leetcode.com/problems/word-pattern/)**

Check whether whitespace-separated words follow a one-to-one pattern.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**21. [Happy Number](https://leetcode.com/problems/happy-number/)**

Repeatedly sum squared decimal digits; decide whether the process reaches 1.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**22. [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/)**

Check whether a partially filled Sudoku board violates row, column, or box uniqueness.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**23. [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)**

Return the length of the longest consecutive-value sequence in an unsorted array.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**24. [Group Anagrams](https://leetcode.com/problems/group-anagrams/)**

Group strings that are anagrams of one another.

☐ Solved independently   Brute-force idea: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Bottleneck: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

My predicted pattern: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Time: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ Auxiliary space: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

# Worked solutions — open only after your attempt

Each entry includes the key idea, a complete LeetCode-style C++17 solution, dry run, proof, complexity, edge cases, and one follow-up. Add `#include <bits/stdc++.h>` and `using namespace std;` when compiling snippets locally.

## 01. Contains Duplicate

**Statement:** Given an integer array, return true if any value appears at least twice; otherwise return false.

**Constraints / assumptions:** Assume the input is a vector of integers; values may be negative and the vector may be empty.

**Pattern:** Membership / hash set

### Brute force and bottleneck

Compare every pair i < j. If nums[i] == nums[j], return true; if no pair matches, return false.

Nested pair comparisons repeat work: each value may be compared with many earlier values.

### Optimised intuition

Scan once while remembering values already seen. A value found in the set has appeared before; otherwise insert it.

### Complete C++ solution

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int x : nums) {
            if (seen.find(x) != seen.end()) return true;
            seen.insert(x);
        }
        return false;
    }
};
```

### Dry run

nums = [4, 1, 4]. Read 4: not seen, insert {4}. Read 1: not seen, insert {4,1}. Read 4: find succeeds, return true immediately. Output: true.

### Why it works

Before each iteration, seen contains exactly the distinct values from the already-processed prefix. Therefore a successful lookup is exactly evidence of a duplicate; if the scan finishes, none exists.

**Time:** Average O(n); worst-case hash-table behavior can degrade to O(n^2).  
**Auxiliary space:** O(n) auxiliary space for the set; O(1) output space.

### Edge cases and common mistakes

**Test:** [] -> false; [7] -> false; [7,7] -> true; negatives work normally.

**Trap:** Forgetting seen.insert(x) means the set never learns earlier values. Do not assume unordered\_set preserves iteration order.

**Interview follow-up:** Q: Why not use a map? A: We only need membership, not an associated count or index, so a set expresses the requirement more directly.

## 02. Missing Number

**Statement:** nums contains n distinct values chosen from [0,n]. Return the one missing value.

**Constraints / assumptions:** The values are distinct and each lies in the inclusive range 0..n.

**Pattern:** Arithmetic sum or XOR

### Brute force and bottleneck

For each candidate from 0 through n, search the array for it. This costs O(n^2).

Repeatedly rescanning the array for each possible value.

### Optimised intuition

Method A: expected sum n(n+1)/2 minus actual sum. Method B: XOR all numbers 0..n and all array values; equal values cancel because a^a=0 and a^0=a.

### Complete C++ solution

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long n = nums.size();
        long long expected = n * (n + 1) / 2;
        long long actual = 0;
        for (int x : nums) actual += x;
        return static_cast<int>(expected - actual);
    }
};

// Alternative XOR method:
// int ans = nums.size();
// for (int i = 0; i < (int)nums.size(); ++i)
//     ans ^= i ^ nums[i];
// return ans;
```

### Dry run

nums = [3,0,1], n=3. Expected sum = 3\*4/2 = 6. Actual sum = 3+0+1 = 4. Missing = 6-4 = 2. XOR alternative: 3^0^1^2^3^0^1 leaves 2 after equal terms cancel.

### Why it works

The complete range has exactly one value absent. The expected sum contains every value once; subtracting the actual sum leaves only the missing value. XOR works by pairwise cancellation of all present values.

**Time:** O(n) for either method.  
**Auxiliary space:** O(1) auxiliary space; O(1) output space.

### Edge cases and common mistakes

**Test:** Missing 0: [1,2]; missing n: [0,1,...,n-1]; n=0 gives answer 0.

**Trap:** Use a wide integer for the sum to avoid overflow in generalized constraints. The XOR loop must include n, which is initialized with nums.size().

**Interview follow-up:** Q: Which method is safer from overflow? A: XOR has no arithmetic-sum overflow; a long long sum is also sufficient for the problem's constraints.

## 03. Find All Numbers Disappeared in an Array

**Statement:** An array of length n contains values in [1,n]. Return every value in that range that does not appear.

**Constraints / assumptions:** Each nums[i] is between 1 and n inclusive; duplicates may occur.

**Pattern:** Index-as-hash / sign marking

### Brute force and bottleneck

For every value 1..n, search the array to see whether it occurs: O(n^2).

Repeatedly searching the same array and allocating a separate set is unnecessary.

### Optimised intuition

Value v maps to index v-1. Negate nums[v-1] to mark that value as seen. Use abs() because an earlier mark may have made the current value negative. Positive slots after marking identify missing values.

### Complete C++ solution

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) nums[idx] = -nums[idx];
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) ans.push_back(i + 1);
        }
        return ans;
    }
};
```

### Dry run

nums=[4,3,2,7,8,2,3,1]. Values mark indices 3,2,1,6,7,1,2,0 respectively. Each target slot is negated only if still positive. Final positive slots are indices 4 and 5, representing values 5 and 6. Output: [5,6].

### Why it works

Every occurrence of value v marks slot v-1 negative. Duplicate occurrences cannot undo the mark because only positive slots are negated. A slot remains positive exactly when its corresponding value never appeared.

**Time:** O(n): two linear passes.  
**Auxiliary space:** O(1) auxiliary space excluding the returned vector; output space O(k), where k is the number of missing values. The input is modified.

### Edge cases and common mistakes

**Test:** No missing values -> []; [1,1] -> [2]; all values missing is impossible for a nonempty array under the given length/range setup, but duplicates can make many missing.

**Trap:** Do not use nums[i]-1 without abs(); an already-marked value can be negative. Do not negate an already-negative target slot, or duplicate processing could restore positivity.

**Interview follow-up:** Q: Why is the input mutation allowed? A: The standard problem permits modifying nums; if the caller needs the original array, make a copy, which costs O(n) extra space.

## 04. Two Sum

**Statement:** Return indices of two distinct elements whose values sum to target. Exactly one solution is guaranteed.

**Constraints / assumptions:** Indices must differ; the same array element cannot be used twice.

**Pattern:** Complement lookup with hash map

### Brute force and bottleneck

Try every pair i

For each value, brute force scans many other values to find its complement.

### Optimised intuition

For current x, the needed value is target-x. Store earlier value -> index. Look up the complement before inserting x so the current element cannot match itself.

### Complete C++ solution

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        for (int i = 0; i < (int)nums.size(); ++i) {
            int need = target - nums[i];
            auto it = index.find(need);
            if (it != index.end()) return {it->second, i};
            index[nums[i]] = i;
        }
        return {};
    }
};
```

### Dry run

nums=[2,7,11,15], target=9. i=0, need=7 absent; store 2->0. i=1, need=2 found at 0; return [0,1]. Output: [0,1].

### Why it works

At index i, the map contains values from indices strictly less than i. If need is present, its stored index and i are distinct and their values sum to target. The guaranteed-solution condition ensures a pair is returned.

**Time:** Average O(n); worst-case O(n^2) under pathological hashing.  
**Auxiliary space:** O(n) auxiliary map; output vector contains two indices, O(1) output space.

### Edge cases and common mistakes

**Test:** Duplicate values such as [3,3], target 6 must return two different indices. Negative values and zero are valid.

**Trap:** Checking after insertion can pair an element with itself. Use find()!=end(), not a value comparison on an iterator.

**Interview follow-up:** Q: Why store index instead of just using a set? A: The answer requires the original positions, so each value needs its index.

## 05. Final Value of Variable After Performing Operations

**Statement:** Start X at 0 and apply each operation: one form increments X and the other decrements X. Return the final value.

**Constraints / assumptions:** Operations are from the problem's four fixed strings: X++, ++X, X--, --X.

**Pattern:** Direct simulation

### Brute force and bottleneck

There is no meaningful expensive brute-force method; directly process each operation.

Hashing would add overhead and complexity without solving any lookup problem.

### Optimised intuition

The position of ++ or -- does not matter: if an operation contains '+', increment; otherwise decrement.

### Complete C++ solution

```cpp
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (const string& op : operations) {
            if (op.find('+') != string::npos) ++x;
            else --x;
        }
        return x;
    }
};
```

### Dry run

operations=["--X","X++","X++"]. Start 0. --X -> -1. X++ -> 0. X++ -> 1. Output: 1.

### Why it works

Each valid operation changes X by exactly +1 or -1. The loop applies that change once per operation, so after all operations x equals the specified final value.

**Time:** O(m), where m is the number of operations; each operation string has constant bounded length.  
**Auxiliary space:** O(1) auxiliary space; O(1) output space.

### Edge cases and common mistakes

**Test:** No operations -> 0; all increments -> positive count; all decrements -> negative count.

**Trap:** Do not parse the position of X. Hashing is unnecessary because the operation itself directly tells the update.

**Interview follow-up:** Q: Could we count plus and minus operations instead? A: Yes; the result is (#increments)-(#decrements), still O(m) time.

## 06. How Many Numbers Are Smaller Than the Current Number

**Statement:** For every nums[i], count how many array elements are strictly smaller than it.

**Constraints / assumptions:** For the standard problem, 0 <= nums[i] <= 100.

**Pattern:** Bounded counting array + prefix sums

### Brute force and bottleneck

For each element, scan all n elements and count values less than it: O(n^2). Sorting can solve it in O(n log n).

Repeated comparisons ignore the tiny bounded domain of only 101 possible values.

### Optimised intuition

Count each value in freq. Prefix-sum the counts so freq[x] becomes the number of elements <= x. Then for x>0, freq[x-1] counts values strictly smaller than x. For x=0 the answer is 0.

### Complete C++ solution

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int freq[101] = {};
        for (int x : nums) ++freq[x];
        for (int x = 1; x <= 100; ++x)
            freq[x] += freq[x - 1];

        vector<int> ans;
        ans.reserve(nums.size());
        for (int x : nums)
            ans.push_back(x == 0 ? 0 : freq[x - 1]);
        return ans;
    }
};
```

### Dry run

nums=[8,1,2,2,3]. Counts: freq[1]=1, freq[2]=2, freq[3]=1, freq[8]=1. Prefix counts: <=1 is 1, <=2 is 3, <=3 is 4, <=7 is 4. Lookups: 8 -> freq[7]=4; 1 -> 0; each 2 -> freq[1]=1; 3 -> freq[2]=3. Output: [4,0,1,1,3].

### Why it works

After prefix accumulation, freq[t] equals the number of input values <= t. For x>0, values strictly smaller than x are exactly values <= x-1, counted by freq[x-1]. Zero has no smaller allowed value, so its answer is zero.

**Time:** O(n + 101), effectively O(n) for this fixed domain.  
**Auxiliary space:** O(101) auxiliary storage plus O(n) returned output vector.

### Edge cases and common mistakes

**Test:** x=0 must return 0; repeated values get the same answer; x=100 uses freq[99] to count values strictly below 100.

**Trap:** Do not use freq[x] as the answer: it counts values <=x after prefixing, including equal values. Do not forget the zero special case.

**Interview follow-up:** Q: Why can this beat sorting? A: With a fixed domain of 101 values, counting and prefixing cost O(n+101), whereas comparison sorting costs O(n log n).

## 07. Valid Anagram

**Statement:** Return true if t can be formed by rearranging all characters of s.

**Constraints / assumptions:** The usual problem uses lowercase English letters; the solution below uses a 26-slot array under that assumption.

**Pattern:** Frequency counting

### Brute force and bottleneck

Sort both strings and compare: O(n log n).

Sorting establishes order even though only character multiplicities matter.

### Optimised intuition

Increment counts for s and decrement for t. All counts must return to zero. Equal lengths are required.

### Complete C++ solution

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int freq[26] = {};
        for (char c : s) ++freq[c - 'a'];
        for (char c : t) --freq[c - 'a'];
        for (int count : freq)
            if (count != 0) return false;
        return true;
    }
};
```

### Dry run

s="anagram", t="nagaram". Both lengths are 7. Add counts for a,n,a,g,r,a,m; subtract counts for n,a,g,a,r,a,m. Every slot ends at zero. Output: true.

### Why it works

The frequency difference for each character is zero exactly when s and t contain the same number of occurrences of every allowed character.

**Time:** O(n + 26), effectively O(n).  
**Auxiliary space:** O(26)=O(1) auxiliary space under the lowercase-English assumption; O(1) output space.

### Edge cases and common mistakes

**Test:** Different lengths -> false; empty strings -> true; repeated letters are handled by counts.

**Trap:** The array-index formula is valid only for the stated alphabet. For arbitrary Unicode or unrestricted bytes, choose a suitable map/array representation.

**Interview follow-up:** Q: Why is length checked first? A: Anagrams must have equal length, so it rejects impossible cases early.

## 08. Majority Element

**Statement:** Return the element that appears more than floor(n/2) times.

**Constraints / assumptions:** LeetCode guarantees a majority element exists.

**Pattern:** Boyer–Moore voting

### Brute force and bottleneck

Count every candidate with a nested scan: O(n^2), O(1) extra space.

Recounting each candidate repeats the same work.

### Optimised intuition

Maintain a candidate and a vote balance. A matching value adds a vote; a different value cancels one. A true majority cannot be fully cancelled by all non-majority elements.

### Complete C++ solution

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, votes = 0;
        for (int x : nums) {
            if (votes == 0) candidate = x;
            votes += (x == candidate) ? 1 : -1;
        }
        return candidate; // majority is guaranteed by the problem
    }
};
```

### Dry run

nums=[2,2,1,1,1,2,2]. x=2 -> candidate 2, votes 1; 2 -> 2; 1 cancels to 1; 1 cancels to 0; next 1 becomes candidate 1, votes 1; 2 cancels to 0; final 2 becomes candidate 2, votes 1. Output: 2.

### Why it works

Pair each non-candidate occurrence with one candidate vote to cancel it. Since the majority occurs more than all other elements combined, at least one vote for it survives. The problem guarantees existence.

**Time:** O(n).  
**Auxiliary space:** O(1) auxiliary and output space.

### Edge cases and common mistakes

**Test:** Single element returns that element. If majority is not guaranteed, perform a second pass to count the candidate and verify count > n/2.

**Trap:** The candidate alone is not proof when the input has no guaranteed majority. Do not confuse the vote balance with the candidate's actual frequency.

**Interview follow-up:** Q: What changes if a majority is not guaranteed? A: Count the final candidate in a second pass and return failure if its count is <= n/2.

## 09. Move Zeroes

**Statement:** Move all zeros to the end while preserving the relative order of nonzero elements; modify nums in-place.

**Constraints / assumptions:** The order of nonzero elements must remain stable.

**Pattern:** Read/write pointers

### Brute force and bottleneck

Build a second vector of nonzero values and append zeros: O(n) time and O(n) extra space.

A second vector is unnecessary when the output must be written into the same array.

### Optimised intuition

write marks the next slot for a nonzero. read scans every element. Copy each nonzero forward, then fill the remaining suffix with zeros.

### Complete C++ solution

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0;
        for (int read = 0; read < (int)nums.size(); ++read) {
            if (nums[read] != 0) nums[write++] = nums[read];
        }
        while (write < (int)nums.size()) nums[write++] = 0;
    }
};
```

### Dry run

nums=[0,1,0,3,12]. read 0: skip. read 1: write nums[0]=1, write=1. read 2: skip. read 3: write nums[1]=3, write=2. read 12: write nums[2]=12, write=3. Fill indices 3,4 with 0. Output array: [1,3,12,0,0].

### Why it works

After each read step, nums[0..write-1] contains exactly the nonzero values encountered so far in original order. Filling the suffix with zeros completes the required stable arrangement.

**Time:** O(n), with at most one scan and one suffix fill.  
**Auxiliary space:** O(1) auxiliary space; modification is in-place; no returned output vector.

### Edge cases and common mistakes

**Test:** No zeros -> unchanged; all zeros -> unchanged; empty vector -> no work.

**Trap:** Do not increment write for zeros during the first pass. A swap-based variant is possible, but the invariant should remain clear.

**Interview follow-up:** Q: Why is the order stable? A: Nonzero values are copied in the same order that read encounters them.

## 10. Remove Duplicates from Sorted Array

**Statement:** Given a sorted array, keep one copy of each distinct value in-place and return the new length k.

**Constraints / assumptions:** The input is sorted in non-decreasing order. Only the first k positions are meaningful after the call.

**Pattern:** Read/write pointers

### Brute force and bottleneck

Create a separate unique vector, then copy it back: O(n) time and O(n) extra space.

Sorting has already placed equal values together, so a set or second vector is unnecessary.

### Optimised intuition

The first write positions hold unique values. Keep nums[read] only when it differs from the last value written.

### Complete C++ solution

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write = 0;
        for (int read = 0; read < (int)nums.size(); ++read) {
            if (write == 0 || nums[read] != nums[write - 1]) {
                nums[write++] = nums[read];
            }
        }
        return write;
    }
};
```

### Dry run

nums=[1,1,2,2,3]. read=0: write 1, k=1. read=1: equals last kept 1, skip. read=2: 2 differs from nums[0], write at index 1, k=2. read=3: duplicate 2, skip. read=4: write 3 at index 2, k=3. Valid prefix [1,2,3], return 3.

### Why it works

Because the array is sorted, any duplicate of a value appears adjacent to its earlier copies. Comparing each read value with the last retained value keeps exactly one copy of each distinct value.

**Time:** O(n).  
**Auxiliary space:** O(1) auxiliary space; in-place modification. The returned integer is O(1) output space.

### Edge cases and common mistakes

**Test:** [] -> 0; [5] -> 1; all equal -> 1; all distinct -> original length.

**Trap:** Do not compare against nums[read-1] alone if using a different compaction structure; the reliable reference is the last kept value nums[write-1]. Only the first k positions matter.

**Interview follow-up:** Q: Why is sorting essential? A: It groups duplicates together; in an unsorted array, adjacent comparison cannot detect all duplicates.

## 11. Remove Element

**Statement:** Remove all occurrences of val in-place and return k, the number of retained elements.

**Constraints / assumptions:** The order of retained elements does not need to be preserved by the problem.

**Pattern:** Read/write pointers

### Brute force and bottleneck

Erase each matching value from a vector while iterating; repeated shifting can cost O(n^2).

Erasing in the middle shifts the remaining suffix repeatedly.

### Optimised intuition

Read every value; copy it to nums[write] only if it is not val. The first write positions form the retained prefix.

### Complete C++ solution

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int write = 0;
        for (int read = 0; read < (int)nums.size(); ++read) {
            if (nums[read] != val) nums[write++] = nums[read];
        }
        return write;
    }
};
```

### Dry run

nums=[3,2,2,3], val=3. read 3 skip; read 2 -> nums[0]=2, write=1; read 2 -> nums[1]=2, write=2; read 3 skip. Return 2; valid prefix [2,2].

### Why it works

After processing each read position, the prefix nums[0..write-1] contains exactly the non-val elements seen so far, in their original order. The final write is their count.

**Time:** O(n).  
**Auxiliary space:** O(1) auxiliary space; in-place; O(1) output space.

### Edge cases and common mistakes

**Test:** All values equal val -> 0; no values equal val -> n; empty -> 0.

**Trap:** Do not shift elements manually for every deletion. Do not assume positions after k have any required value.

**Interview follow-up:** Q: What if order does not matter? A: A two-ended swap strategy can reduce writes, but the read/write stable compaction is simpler and still O(n).

## 12. First Missing Positive

**Statement:** Return the smallest positive integer absent from an unsorted integer array.

**Constraints / assumptions:** Values may be negative, zero, duplicated, or much larger than n.

**Pattern:** Index placement / cyclic placement

### Brute force and bottleneck

Put positive values in a set and test 1,2,...: O(n) expected time and O(n) extra space.

The problem asks for constant auxiliary space, so a separate set is not allowed in the optimal solution.

### Optimised intuition

For array length n, value v belongs at index v-1 when 1<=v<=n. Repeatedly swap a value into its home slot while it is in range and the destination does not already contain it. Then the first index i where nums[i]!=i+1 gives i+1.

### Complete C++ solution

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int x = nums[i];
            if (x >= 1 && x <= n && nums[x - 1] != x) {
                swap(nums[i], nums[x - 1]);
            } else {
                ++i;
            }
        }
        for (int j = 0; j < n; ++j)
            if (nums[j] != j + 1) return j + 1;
        return n + 1;
    }
};
```

### Dry run

nums=[3,4,-1,1]. i=0, 3 belongs at 2: swap -> [-1,4,3,1]. Still i=0, -1 invalid, advance. i=1, 4 belongs at 3: swap -> [-1,1,3,4]. Still i=1, 1 belongs at 0: swap -> [1,-1,3,4]. Now -1 invalid, advance. Positions 0=1, 1!=-2, so answer 2. Output: 2.

### Why it works

Each valid value is moved to its home index unless that home already contains the same value. The duplicate guard prevents endless swaps. When placement finishes, index i contains i+1 if that value exists; the first mismatch is the smallest missing positive.

**Time:** O(n) amortised: each successful swap places at least one value into its final home; there are O(n) successful placements, plus a linear scan.  
**Auxiliary space:** O(1) auxiliary space; input is modified; O(1) output space.

### Edge cases and common mistakes

**Test:** [] -> 1; [1,2,0] -> 3; [3,4,-1,1] -> 2; [1,1] -> 2.

**Trap:** A single if is not enough because the swapped-in value may also belong at the current index. Use while and guard nums[x-1] != x to handle duplicates.

**Interview follow-up:** Q: Why can values > n be ignored? A: With n slots, the answer is in [1,n+1]; values outside [1,n] cannot occupy any required home slot.

## 13. Intersection of Two Arrays

**Statement:** Return the distinct values present in both arrays; each result value appears once.

**Constraints / assumptions:** Result order does not matter.

**Pattern:** Hash set membership

### Brute force and bottleneck

Compare every value in nums1 against every value in nums2, then deduplicate: O(mn) comparisons plus deduplication.

Repeated membership scans and duplicate result production.

### Optimised intuition

Build a set from one array, scan the other, and use a second set to ensure each shared value is output once.

### Complete C++ solution

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a(nums1.begin(), nums1.end());
        unordered_set<int> result;
        for (int x : nums2)
            if (a.count(x)) result.insert(x);
        return vector<int>(result.begin(), result.end());
    }
};
```

### Dry run

nums1=[1,2,2,1], nums2=[2,2]. Set a={1,2}. Each 2 is found; result set remains {2}. Output may be [2] (order is unspecified).

### Why it works

a contains exactly the distinct values from nums1. A value is inserted into result exactly when it is also found in nums2; the result set guarantees uniqueness.

**Time:** Average O(m+n); worst-case can degrade with pathological hashing.  
**Auxiliary space:** O(m+k) auxiliary storage for sets, where k is result size; returned vector is O(k).

### Edge cases and common mistakes

**Test:** No common values -> []; repeated shared values appear once; output order is unspecified.

**Trap:** Do not promise sorted output. If sorted order is required, sort the result or use ordered sets.

**Interview follow-up:** Q: Why is a set sufficient here? A: The problem asks for distinct intersection values, so multiplicity is irrelevant.

## 14. Intersection of Two Arrays II

**Statement:** Return the intersection including duplicate occurrences, limited by the frequency in each input.

**Constraints / assumptions:** Result order does not matter.

**Pattern:** Frequency map

### Brute force and bottleneck

For each value in one array, find and consume a matching unused value in the other; naïve repeated search is O(mn).

A plain set discards multiplicity: [2,2] becomes {2}, losing the second occurrence.

### Optimised intuition

Count values from nums1. For each x in nums2, if freq[x]>0, append x and decrement its remaining count.

### Complete C++ solution

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        for (int x : nums1) ++freq[x];
        vector<int> ans;
        for (int x : nums2) {
            auto it = freq.find(x);
            if (it != freq.end() && it->second > 0) {
                ans.push_back(x);
                --it->second;
            }
        }
        return ans;
    }
};
```

### Dry run

nums1=[1,2,2,1], nums2=[2,2]. Counts: 1->2, 2->2. First 2 appended, count 2->1. Second 2 appended, count 2->0. Output: [2,2].

### Why it works

Each appended value consumes one available occurrence from nums1. A count never drops below zero, so the output multiplicity is the minimum of the two input frequencies.

**Time:** Average O(m+n).  
**Auxiliary space:** O(u+k) auxiliary map plus output vector O(k), where u is the number of distinct values and k is result size.

### Edge cases and common mistakes

**Test:** Disjoint arrays -> []; one array has fewer copies -> output uses only that many copies.

**Trap:** Do not use a set when duplicates matter. Decrement counts after matching so one occurrence cannot be reused repeatedly.

**Interview follow-up:** Q: What is the difference from Intersection of Two Arrays? A: The first returns distinct values; this version preserves multiplicity.

## 15. Ransom Note

**Statement:** Determine whether ransomNote can be constructed from magazine letters, using each magazine character at most once.

**Constraints / assumptions:** The standard problem uses lowercase English letters.

**Pattern:** Frequency counting

### Brute force and bottleneck

For every ransom character, search and consume a matching magazine character: potentially O(mn).

Repeated searches for the same available character.

### Optimised intuition

Count magazine letters, then consume one count for every letter required by ransomNote. A negative count means the letter is unavailable.

### Complete C++ solution

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26] = {};
        for (char c : magazine) ++freq[c - 'a'];
        for (char c : ransomNote) {
            if (--freq[c - 'a'] < 0) return false;
        }
        return true;
    }
};
```

### Dry run

ransomNote="aa", magazine="aab". Magazine counts a=2,b=1. First a consumes one ->1; second a consumes one ->0. Output: true. If magazine="ab", the second a makes the count -1 and returns false.

### Why it works

The counter records the unused quantity of each character. Each required character consumes one available occurrence; going below zero proves construction impossible.

**Time:** O(m+n), where m and n are string lengths.  
**Auxiliary space:** O(26)=O(1) auxiliary under lowercase-English assumption; O(1) output space.

### Edge cases and common mistakes

**Test:** Empty ransom note -> true; empty magazine with nonempty note -> false; repeated letters test multiplicity.

**Trap:** A set only records whether a character exists, not how many copies are available.

**Interview follow-up:** Q: Why decrement rather than just check presence? A: Repeated letters need separate magazine occurrences.

## 16. First Unique Character in a String

**Statement:** Return the index of the first character that occurs exactly once, or -1 if none exists.

**Constraints / assumptions:** The standard problem uses lowercase English letters.

**Pattern:** Frequency count + second pass

### Brute force and bottleneck

For each index, count occurrences of its character across the whole string: O(n^2).

The same character frequencies are recalculated many times.

### Optimised intuition

Count all letters in one pass, then scan from left to right and return the first index whose count is one.

### Complete C++ solution

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {};
        for (char c : s) ++freq[c - 'a'];
        for (int i = 0; i < (int)s.size(); ++i)
            if (freq[s[i] - 'a'] == 1) return i;
        return -1;
    }
};
```

### Dry run

s="loveleetcode". Counts show l=2, o=2, v=1, e=4, etc. Scan: l not unique; o not unique; v has count 1 at index 2. Output: 2.

### Why it works

The first pass computes exact character frequencies. The second pass visits indices in increasing order, so the first count-one character found is the earliest unique character.

**Time:** O(n + 26), effectively O(n).  
**Auxiliary space:** O(26)=O(1) auxiliary; O(1) output.

### Edge cases and common mistakes

**Test:** Empty string -> -1; all repeated -> -1; first character unique -> 0.

**Trap:** Return the index, not the character. Do not return a unique character encountered during the counting pass because the earliest index is not yet known.

**Interview follow-up:** Q: Why two passes? A: A character's uniqueness is known only after all occurrences have been counted.

## 17. Contains Duplicate II

**Statement:** Return true if there are equal values at indices i and j with |i-j| <= k.

**Constraints / assumptions:** k is a non-negative integer.

**Pattern:** Last-seen index map

### Brute force and bottleneck

Compare every pair and check both equal values and distance: O(n^2).

Only the nearest previous occurrence matters; older occurrences are farther away.

### Optimised intuition

Store the most recent index for each value. Before updating, if the value was seen and i-lastSeen[x] <= k, return true.

### Complete C++ solution

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> last;
        for (int i = 0; i < (int)nums.size(); ++i) {
            auto it = last.find(nums[i]);
            if (it != last.end() && i - it->second <= k) return true;
            last[nums[i]] = i;
        }
        return false;
    }
};
```

### Dry run

nums=[1,2,3,1], k=3. Store 1->0, 2->1, 3->2. At i=3, value 1 was last seen at 0; distance 3 <= k, so true.

### Why it works

For each current index i, last[x] is the closest earlier occurrence of x. If even that occurrence is farther than k, every older occurrence is also too far; otherwise a valid pair exists.

**Time:** Average O(n).  
**Auxiliary space:** O(u) auxiliary map for distinct values; O(1) output.

### Edge cases and common mistakes

**Test:** k=0 -> false for distinct indices; adjacent duplicates with k=1 -> true; duplicates too far apart -> false.

**Trap:** Check the distance before updating last[x]. Updating first would erase the earlier index and make the comparison useless.

**Interview follow-up:** Q: Why only keep the latest index? A: It minimizes distance to the current index, so it is the only previous occurrence that can be the closest valid candidate.

## 18. Unique Number of Occurrences

**Statement:** Return true if every distinct value in the array has a different frequency.

**Constraints / assumptions:** Values may be negative; use a map for arbitrary integer keys.

**Pattern:** Frequency map + set of frequencies

### Brute force and bottleneck

Count frequencies, then compare every pair of distinct values' counts: O(u^2).

The question is whether any frequency value repeats, so a set of seen counts answers it directly.

### Optimised intuition

Build value -> frequency. Insert each frequency into a set; if insertion finds it already present, two values share the same occurrence count.

### Complete C++ solution

```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int x : arr) ++freq[x];
        unordered_set<int> seenCounts;
        for (const auto& entry : freq) {
            if (!seenCounts.insert(entry.second).second) return false;
        }
        return true;
    }
};
```

### Dry run

arr=[1,2,2,1,1,3]. Counts: 1->3, 2->2, 3->1. Insert 3, then 2, then 1; no count repeats. Output: true.

### Why it works

The map gives one frequency per distinct value. The set rejects a frequency the moment a second distinct value has the same count, exactly matching the condition.

**Time:** Average O(n).  
**Auxiliary space:** O(u) auxiliary for the frequency map and frequency set; O(1) output.

### Edge cases and common mistakes

**Test:** [] -> true (vacuously); [1,1,2,2] -> false because both counts are 2.

**Trap:** Do not test whether the original values are unique; the condition concerns their frequencies.

**Interview follow-up:** Q: Why use a second set? A: It tracks whether a frequency has already been assigned to another distinct value.

## 19. Isomorphic Strings

**Statement:** Two strings are isomorphic if each character in s maps consistently to one character in t and no two distinct s characters map to the same t character.

**Constraints / assumptions:** Strings have equal length; mapping is character-based and preserves positions.

**Pattern:** Bidirectional mapping

### Brute force and bottleneck

For every pair of positions, verify that equal characters in one string correspond to equal characters in the other: O(n^2).

Pairwise consistency checks repeat the same mapping facts.

### Optimised intuition

Maintain s->t and t->s maps. Every position must agree with both existing directions; otherwise mapping is inconsistent or many-to-one.

### Complete C++ solution

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        int st[256], ts[256];
        fill(begin(st), end(st), -1);
        fill(begin(ts), end(ts), -1);
        for (int i = 0; i < (int)s.size(); ++i) {
            unsigned char a = s[i], b = t[i];
            if (st[a] != -1 && st[a] != b) return false;
            if (ts[b] != -1 && ts[b] != a) return false;
            st[a] = b;
            ts[b] = a;
        }
        return true;
    }
};
```

### Dry run

s="egg", t="add". e->a and a->e; g->d and d->g. Second g repeats the same mapping. Output: true. For s="ab", t="aa", a->a is set, then b would also map to a, but reverse map a->a conflicts; false.

### Why it works

The forward table enforces one target per source character; the reverse table enforces that each target belongs to at most one source character. Both are necessary for a one-to-one mapping.

**Time:** O(n + 256), effectively O(n).  
**Auxiliary space:** O(256)=O(1) auxiliary for byte characters; O(1) output.

### Edge cases and common mistakes

**Test:** Different lengths -> false; identical strings -> true; repeated source with inconsistent target -> false.

**Trap:** A one-way map incorrectly accepts "ab" and "aa". This byte-array version is for byte/ASCII-style inputs; Unicode code points need a different representation.

**Interview follow-up:** Q: Why two directions? A: Forward mapping prevents one source mapping to multiple targets; reverse mapping prevents multiple sources mapping to one target.

## 20. Word Pattern

**Statement:** Check whether each pattern character maps bijectively to one whitespace-separated word in s.

**Constraints / assumptions:** The sentence must be tokenized into words separated by whitespace; do not compare raw characters of s.

**Pattern:** Tokenisation + bidirectional mapping

### Brute force and bottleneck

Split into words, then compare every pair of positions for consistency: O(n^2).

Pairwise comparisons repeat mapping information.

### Optimised intuition

Tokenize s using stringstream, check the word count matches pattern length, then enforce character->word and word->character mappings.

### Complete C++ solution

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream in(s);
        vector<string> words;
        string word;
        while (in >> word) words.push_back(word);
        if (words.size() != pattern.size()) return false;

        unordered_map<char, string> p2w;
        unordered_map<string, char> w2p;
        for (int i = 0; i < (int)pattern.size(); ++i) {
            char c = pattern[i];
            const string& w = words[i];
            if (p2w.count(c) && p2w[c] != w) return false;
            if (w2p.count(w) && w2p[w] != c) return false;
            p2w[c] = w;
            w2p[w] = c;
        }
        return true;
    }
};
```

### Dry run

pattern="abba", s="dog cat cat dog". Tokens are [dog,cat,cat,dog]. a->dog, b->cat, b repeats cat, a repeats dog. Output: true. For "abba" and "dog cat cat fish", final a conflicts with dog vs fish -> false.

### Why it works

Tokenization aligns one word with each pattern character. Forward and reverse maps enforce a bijection at every position; equal token counts prevent unmatched positions.

**Time:** O(L), where L is the sentence length, assuming average constant-time hash operations; string hashing adds work proportional to word lengths.  
**Auxiliary space:** O(L) for tokenized words and maps; output is O(1).

### Edge cases and common mistakes

**Test:** Repeated spaces are handled by stringstream; mismatched token count -> false; same word assigned to two pattern letters -> false.

**Trap:** Do not split by individual spaces manually without handling repeated whitespace. Do not omit the reverse map.

**Interview follow-up:** Q: Why check word count first? A: A one-to-one positional mapping is impossible if the number of words differs from the number of pattern characters.

## 21. Happy Number

**Statement:** Repeatedly replace n with the sum of squares of its decimal digits. Return true if the sequence reaches 1, false if it loops elsewhere.

**Constraints / assumptions:** n is a positive integer in the standard problem.

**Pattern:** Digit processing + cycle detection

### Brute force and bottleneck

Keep generating values until 1; without cycle detection, a non-happy number could loop forever.

The transformation is deterministic, so a repeated value guarantees the future sequence repeats.

### Optimised intuition

Store each value in a visited set. If it becomes 1, happy; if it has already appeared, a cycle exists.

### Complete C++ solution

```cpp
class Solution {
    int digitSquareSum(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = digitSquareSum(n);
        }
        return n == 1;
    }
};
```

### Dry run

n=19. 1^2+9^2=82; 8^2+2^2=68; 6^2+8^2=100; 1^2+0^2+0^2=1. Output: true.

### Why it works

Each next value is determined solely by the current value. Reaching 1 proves happiness; revisiting a non-1 value means the deterministic sequence will repeat forever, so it cannot newly reach 1.

**Time:** O(t\*d), where t is the number of generated values before termination and d is the number of decimal digits per value; typically very small.  
**Auxiliary space:** O(t) auxiliary for visited values; O(1) output.

### Edge cases and common mistakes

**Test:** n=1 -> true; values in a non-1 cycle -> false.

**Trap:** Do not omit cycle detection if using a set-based loop; otherwise the loop may never terminate for unhappy numbers.

**Interview follow-up:** Q: Could Floyd's cycle detection avoid the set? A: Yes, tortoise-and-hare can detect the cycle in O(1) auxiliary space.

## 22. Valid Sudoku

**Statement:** Determine whether a partially filled 9x9 Sudoku board violates any row, column, or 3x3-box uniqueness rule.

**Constraints / assumptions:** Cells contain '1'..'9' or '.'. Empty cells are ignored.

**Pattern:** Row/column/box tracking

### Brute force and bottleneck

For each filled cell, scan its row, column, and box for duplicates; repeated scans are still bounded but less tidy.

The same row, column, and box are repeatedly inspected.

### Optimised intuition

Maintain 9 row sets, 9 column sets, and 9 box sets. For cell (r,c), box id is (r/3)\*3 + c/3.

### Complete C++ solution

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {}, col[9][9] = {}, box[9][9] = {};
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char ch = board[r][c];
                if (ch == '.') continue;
                int d = ch - '1';
                int b = (r / 3) * 3 + c / 3;
                if (row[r][d] || col[c][d] || box[b][d]) return false;
                row[r][d] = col[c][d] = box[b][d] = true;
            }
        }
        return true;
    }
};
```

### Dry run

At a filled cell board[0][0]='5', d=4 and box=0. If row[0][4], col[0][4], or box[0][4] is already true, return false; otherwise mark all three. Continue through every non-dot cell. A board with no duplicate digit in any row/column/box returns true.

### Why it works

Each filled cell is checked against all three constraint groups before being recorded. Any duplicate triggers rejection; if none triggers, every Sudoku uniqueness constraint is satisfied.

**Time:** O(9\*9)=O(1) for fixed-size Sudoku.  
**Auxiliary space:** O(9\*9\*3)=O(1) auxiliary for fixed dimensions; O(1) output.

### Edge cases and common mistakes

**Test:** All dots -> true; duplicate in row, column, or box -> false; same digit in unrelated boxes is allowed.

**Trap:** The box formula is (r/3)\*3 + c/3. Do not treat '.' as a digit.

**Interview follow-up:** Q: Why are there three trackers? A: A digit must be unique independently within its row, column, and 3x3 box.

## 23. Longest Consecutive Sequence

**Statement:** Return the length of the longest run of consecutive integer values, in O(n) average time.

**Constraints / assumptions:** Input is unsorted; duplicates do not extend a sequence.

**Pattern:** Hash set + sequence starts

### Brute force and bottleneck

Sort and scan: O(n log n), or compare all possible sequences with repeated work.

Starting expansion from every value repeats work for values inside an already-counted run.

### Optimised intuition

Put all values in a set. Only expand from x if x-1 is absent; then x is a sequence start. Count x, x+1, ... while present.

### Complete C++ solution

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> values(nums.begin(), nums.end());
        int best = 0;
        for (int x : values) {
            if (values.count(x - 1)) continue;
            int len = 1;
            int cur = x;
            while (values.count(cur + 1)) {
                ++cur;
                ++len;
            }
            best = max(best, len);
        }
        return best;
    }
};
```

### Dry run

nums=[100,4,200,1,3,2]. Set contains these values. 100 starts length 1; 4 is not a start because 3 exists; 200 length 1; 1 is a start and expansion finds 2,3,4 for length 4. Output: 4.

### Why it works

Every consecutive run has exactly one start whose predecessor is absent. Expanding only from starts counts each run once; the maximum run length is the answer.

**Time:** Average O(n): each value participates in at most one forward expansion across all sequence starts; hash operations are average O(1).  
**Auxiliary space:** O(n) auxiliary set; O(1) output.

### Edge cases and common mistakes

**Test:** [] -> 0; duplicates are removed by set; negative consecutive values work.

**Trap:** Do not expand from every value; that can repeat work and undermine the linear-time argument. Hashing gives average, not guaranteed worst-case, bounds.

**Interview follow-up:** Q: Why only start at values whose predecessor is absent? A: Otherwise the value is inside an earlier sequence and expanding from it would recount a suffix.

## 24. Group Anagrams

**Statement:** Group strings that contain the same characters with the same frequencies.

**Constraints / assumptions:** The standard version uses lowercase English letters; output group order is not important.

**Pattern:** Canonical key + hash map

### Brute force and bottleneck

Compare every string against every other string for anagram equivalence; costly repeated comparisons.

Anagrams have the same sorted characters, so a canonical representation avoids pairwise comparison.

### Optimised intuition

Sort each word to form a canonical key, then append the original word to the vector stored under that key. A 26-count signature is an alternative for lowercase letters.

### Complete C++ solution

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string& word : strs) {
            string key = word;
            sort(key.begin(), key.end());
            groups[key].push_back(word);
        }
        vector<vector<string>> ans;
        for (auto& entry : groups) ans.push_back(move(entry.second));
        return ans;
    }
};
```

### Dry run

strs=["eat","tea","tan","ate","nat","bat"]. Keys: eat/tea/ate -> "aet"; tan/nat -> "ant"; bat -> "abt". Groups are {eat,tea,ate}, {tan,nat}, {bat}; outer group order is unspecified.

### Why it works

Two strings are anagrams exactly when sorting their characters yields the same key. Therefore each map bucket contains precisely strings sharing the same character multiset.

**Time:** O(sum |word| log |word|) for sorting each word, plus average hash-map work.  
**Auxiliary space:** O(total characters) auxiliary for keys and grouped strings; output itself also stores all input strings in groups.

### Edge cases and common mistakes

**Test:** Empty strings share the empty key; repeated identical words stay in the same group; output order is unspecified.

**Trap:** Do not use the original word as the key. If using a frequency signature, encode counts unambiguously and respect the alphabet assumption.

**Interview follow-up:** Q: When is a frequency signature preferable? A: For a fixed small alphabet, counting 26 letters per word can achieve O(total characters + 26\*number\_of\_words) rather than sorting each word.

## Closed-notes retrieval test

**Honest label:** this is a retrieval test, not an unseen-problem exam, because the problems appear in the workbook.

**Suggested time:** 75 minutes. No notes, no solution section, no web search. Write complete logic, invariant, time complexity, auxiliary space, and two edge cases.

| Problem | Time | Invariant / correctness idea | Edge cases |
| --- | --- | --- | --- |
| 3. Find All Numbers Disappeared in an Array [leetcode.com/problems/find-all-numbers-disappeared-in-an-array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) |  |  |  |
| 8. Majority Element [leetcode.com/problems/majority-element](https://leetcode.com/problems/majority-element/) |  |  |  |
| 6. How Many Numbers Are Smaller [leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/) |  |  |  |
| 11. Remove Element [leetcode.com/problems/remove-element](https://leetcode.com/problems/remove-element/) |  |  |  |
| 10. Remove Duplicates from Sorted Array [leetcode.com/problems/remove-duplicates-from-sorted-array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) |  |  |  |
| 12. First Missing Positive [leetcode.com/problems/first-missing-positive](https://leetcode.com/problems/first-missing-positive/) |  |  |  |
| 17. Contains Duplicate II [leetcode.com/problems/contains-duplicate-ii](https://leetcode.com/problems/contains-duplicate-ii/) |  |  |  |
| 23. Longest Consecutive Sequence [leetcode.com/problems/longest-consecutive-sequence](https://leetcode.com/problems/longest-consecutive-sequence/) |  |  |  |

### Scoring rubric — 100 points

| Category | Points |
| --- | --- |
| Correct algorithm and preconditions | 32 |
| Correct implementation and edge cases | 28 |
| Correctness invariant / explanation | 20 |
| Time and auxiliary-space analysis | 12 |
| Readable code and tests | 8 |

### Post-test mistake review

Question: \_\_\_\_\_\_\_\_\_\_ What I wrote: \_\_\_\_\_\_\_\_\_\_ Expected behaviour: \_\_\_\_\_\_\_\_\_\_ Root cause: \_\_\_\_\_\_\_\_\_\_ Corrected invariant: \_\_\_\_\_\_\_\_\_\_ Re-solve date: \_\_\_\_\_\_\_\_\_\_

## Final page — the Day 1 promise

**Do not measure today only by how many solutions you read.**  
Measure it by how many patterns you can recognise, explain, implement, and retrieve without looking.

☐ I attempted before reading. ☐ I can explain my invariants. ☐ I can distinguish auxiliary space from output space. ☐ I tested edge cases. ☐ I recorded mistakes. ☐ I scheduled retrieval practice.

**Primary roadmap anchor:** [Stoney Codes — Introduction, Big O, Problem Solving Techniques](https://youtu.be/lvO88XxNAzs)

Keep one anchor resource. Let deliberate practice, not resource hopping, do the work.