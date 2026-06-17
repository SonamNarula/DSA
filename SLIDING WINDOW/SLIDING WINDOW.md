# Complete Sliding Window Roadmap

> Follow this order.
>
> Goal: Pattern Recognition → Problem Solving → Revision

---

# Level 0 — Prerequisite

Before Sliding Window:

- [ ] Arrays
- [ ] Strings
- [ ] Two Pointers

Important:

text Sliding Window is basically Two Pointers + Window Management 

---

# Level 1 — Fixed Size Window

Window size is already given.

## Pattern

text Window Length = k 

Template:

cpp // first window  // slide  add incoming remove outgoing 

Problems:

- [ ] 643. Maximum Average Subarray I
- [ ] 1456. Maximum Number of Vowels in a Substring of Given Length
- [ ] Defuse the Bomb (LC 1652)

---

# Level 2 — Fixed Window + Frequency

Learn frequency tracking.

## Pattern

text Fixed Window + HashMap / Frequency Array 

Problems:

- [ ] 567. Permutation in String
- [ ] 438. Find All Anagrams in a String

Observation:

text Window size fixed  Character frequencies matter 

---

# Level 3 — Variable Window Basics

Window size changes dynamically.

## Pattern

cpp int left = 0;  for(int right=0; right<n; right++) {     acquire      while(window invalid)     {         release         left++;     } } 

Problems:

- [ ] 3. Longest Substring Without Repeating Characters
- [ ] 904. Fruit Into Baskets

---

# Level 4 — Longest Valid Window

Most important Sliding Window category.

## Pattern

text Expand aggressively  Shrink only when invalid 

Problems:

- [ ] 1004. Max Consecutive Ones III
- [ ] 424. Longest Repeating Character Replacement
- [ ] 904. Fruit Into Baskets

---

# Level 5 — Minimum / Shortest Window

## Pattern

text Shrink whenever valid 

Problems:

- [ ] 209. Minimum Size Subarray Sum
- [ ] 713. Subarray Product Less Than K

Observation:

text Longest Problems  → Expand more  Shortest Problems  → Shrink more 

---

# Level 6 — Frequency Heavy Sliding Window

Learn advanced hashmap usage.

Problems:

- [ ] 1248. Count Number of Nice Subarrays
- [ ] 992. Subarrays with K Different Integers
- [ ] 1358. Number of Substrings Containing All Three Characters

---

# Level 7 — Advanced Interview Favorites

Problems:

- [ ] 76. Minimum Window Substring
- [ ] 239. Sliding Window Maximum

These are must-know interview questions.

---

# Core Sliding Window Patterns

---

## Pattern 1: Fixed Window

Used When:

text Length = k 

Examples:

- Maximum Average Subarray
- Maximum Number of Vowels
- Find All Anagrams

Template:

cpp Build first window  Slide window  Add incoming element Remove outgoing element 

Complexity:

text O(n) 

---

## Pattern 2: Variable Window

Used When:

text Longest Shortest At Most K At Least K 

Examples:

- Longest Substring Without Repeating Characters
- Fruit Into Baskets

Template:

cpp left = 0  for(right) {     acquire      while(invalid)     {         release     }      update answer } 

---

## Pattern 3: Frequency Window

Used When:

text Characters Distinct Elements Anagrams Permutations 

Tools:

cpp unordered_map  vector<int>(26) 

Examples:

- Permutation in String
- Find All Anagrams
- Minimum Window Substring

---

## Pattern 4: Longest Window

Rule:

text Expand first  Shrink only when invalid 

Examples:

- Longest Repeating Character Replacement
- Max Consecutive Ones III

---

## Pattern 5: Minimum Window

Rule:

text Shrink whenever valid 

Examples:

- Minimum Size Subarray Sum
- Minimum Window Substring

---

# Most Important Observations

---

## Fixed Window

text Window size never changes. 

---

## Variable Window

text Window size changes dynamically. 

---

## Longest Problems

text Expand aggressively.  Shrink only when invalid. 

---

## Minimum Problems

text Shrink aggressively.  Keep smallest valid window. 

---

## Frequency Problems

text Track counts  Not positions. 

---

## Distinct Character Problems

text Use HashMap  freq.size() 

is usually important.

---

# Common Mistakes

---

## Fixed Window

❌ Recalculate sum every time

text O(nk) 

Use:

text Incoming - Outgoing 

---

## Longest Substring Without Repeating Characters

❌ Clear entire hashmap

Instead:

text Move left pointer 

---

## Frequency Problems

❌ Forgetting to decrease frequency

---

## Minimum Window Substring

❌ Shrinking before window becomes valid

---

## Character Replacement

❌ Recomputing everything every iteration

---

# Complete Question List

---

## Easy

- [ ] 643. Maximum Average Subarray I
- [ ] 1456. Maximum Number of Vowels in a Substring
- [ ] 1652. Defuse the Bomb

---

## Easy-Medium

- [ ] 567. Permutation in String
- [ ] 438. Find All Anagrams in a String

---

## Medium

- [ ] 3. Longest Substring Without Repeating Characters
- [ ] 904. Fruit Into Baskets
- [ ] 1004. Max Consecutive Ones III
- [ ] 424. Longest Repeating Character Replacement
- [ ] 209. Minimum Size Subarray Sum
- [ ] 713. Subarray Product Less Than K

---

## Medium-Hard

- [ ] 1248. Count Number of Nice Subarrays
- [ ] 1358. Number of Substrings Containing All Three Characters
- [ ] 992. Subarrays with K Different Integers

---

## Hard

- [ ] 76. Minimum Window Substring
- [ ] 239. Sliding Window Maximum

---

# Blind Revision Set

Must solve without hints.

## Fixed Window

- [ ] Maximum Average Subarray I
- [ ] Maximum Number of Vowels

---

## Frequency Window

- [ ] Permutation in String
- [ ] Find All Anagrams

---

## Variable Window

- [ ] Longest Substring Without Repeating Characters
- [ ] Fruit Into Baskets

---

## Important Medium

- [ ] Max Consecutive Ones III
- [ ] Longest Repeating Character Replacement
- [ ] Minimum Size Subarray Sum

---

## Advanced

- [ ] Minimum Window Substring
- [ ] Sliding Window Maximum

---

# CRT / Placement Priority

If placements started tomorrow:

1. Maximum Average Subarray I
2. Permutation in String
3. Longest Substring Without Repeating Characters
4. Fruit Into Baskets
5. Max Consecutive Ones III
6. Longest Repeating Character Replacement
7. Minimum Size Subarray Sum
8. Minimum Window Substring

---

# Final Mastery Checklist

## Fixed Window

- [ ] Maximum Average Subarray I
- [ ] Maximum Number of Vowels
- [ ] Defuse the Bomb

---

## Frequency Window

- [ ] Permutation in String
- [ ] Find All Anagrams

---

## Variable Window

- [ ] Longest Substring Without Repeating Characters
- [ ] Fruit Into Baskets

---

## Longest Window

- [ ] Max Consecutive Ones III
- [ ] Longest Repeating Character Replacement

---

## Minimum Window

- [ ] Minimum Size Subarray Sum
- [ ] Minimum Window Substring

---

## Advanced

- [ ] Sliding Window Maximum
- [ ] Subarrays with K Different Integers

---

# Final Mental Model

text Fixed Window ↓ Frequency Window ↓ Variable Window ↓ Longest Window ↓ Minimum Window ↓ Minimum Window Substring ↓ Sliding Window Maximum 

Master these problems and you will have a strong Sliding Window foundation for interviews, online assessments, and competitive programming.
