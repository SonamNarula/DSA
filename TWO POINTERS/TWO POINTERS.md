# Complete Two Pointers Roadmap

> Follow this order.
>
> Goal: Pattern Recognition → Problem Solving → Revision

---

# Level 0 — Warmup

These build basic left-right pointer intuition.

- [ ] 344. Reverse String
- [ ] 125. Valid Palindrome
- [ ] 9. Palindrome Number
- [ ] 167. Two Sum II - Input Array Is Sorted

---

# Level 1 — Slow & Fast Pointer

Learn in-place array modification.

## Pattern

text slow = answer position  fast = traversal pointer 

Problems:

- [ ] 26. Remove Duplicates from Sorted Array
- [ ] 27. Remove Element
- [ ] 283. Move Zeroes
- [ ] 905. Sort Array By Parity

---

# Level 2 — Opposite Ends

Learn pointer movement logic.

## Pattern

text left = 0  right = n-1 

Problems:

- [ ] 680. Valid Palindrome II
- [ ] 977. Squares of a Sorted Array
- [ ] 11. Container With Most Water
- [ ] 881. Boats to Save People

---

# Level 3 — Greedy + Two Pointers

## Pattern

text Sort  Lightest + Heaviest 

Problems:

- [ ] CSES Ferris Wheel
- [ ] 881. Boats to Save People

Observation:

text If lightest + heaviest cannot fit, heaviest must go alone. 

---

# Level 4 — Sort + Two Pointers

## Pattern

text Fix One Element  Apply Two Sum II 

Problems:

- [ ] CSES Sum of Two Values
- [ ] CSES Sum of Three Values
- [ ] 15. 3Sum
- [ ] 16. 3Sum Closest

---

# Level 5 — Advanced Sort + Two Pointers

## Pattern

text Fix Two Elements  Apply Two Sum 

Problems:

- [ ] 18. 4Sum
- [ ] 611. Valid Triangle Number

---

# Level 6 — Advanced Interview Problems

Problems:

- [ ] 42. Trapping Rain Water
- [ ] 986. Interval List Intersections
- [ ] 1498. Number of Subsequences That Satisfy the Given Sum Condition

---

# Pattern Cheat Sheet

## Opposite Ends

Problems:

- Reverse String
- Valid Palindrome
- Valid Palindrome II
- Squares of Sorted Array
- Container With Most Water
- Trapping Rain Water

Template:

cpp int left = 0; int right = n - 1;  while(left < right) {     // process      left++;     right--; } 

---

## Slow Fast Pointer

Problems:

- Remove Duplicates
- Remove Element
- Move Zeroes

Template:

cpp int slow = 0;  for(int fast = 0; fast < n; fast++) {     if(condition)     {         nums[slow] = nums[fast];         slow++;     } } 

---

## Sort + Two Pointers

Problems:

- Sum of Three Values
- 3Sum
- 3Sum Closest
- 4Sum

Template:

cpp sort(nums.begin(), nums.end());  for(int i = 0; i < n; i++) {     int left = i + 1;     int right = n - 1;      while(left < right)     {     } } 

---

# Most Important Observations

## Two Sum II

text sum < target → left++  sum > target → right-- 

---

## Valid Palindrome

text Mismatch → false 

---

## Valid Palindrome II

text First mismatch  Skip left OR Skip right 

---

## Squares of Sorted Array

text Largest square always comes from ends. 

---

## Container With Most Water

text Move the smaller height pointer. 

---

## Ferris Wheel

text Lightest + Heaviest 

---

## 3Sum

text Fix One + Two Sum II 

---

## Trapping Rain Water

text Water depends on smaller boundary. 

---

# Blind Revision Set

These must be solvable without hints.

## Core

- [ ] Two Sum II
- [ ] Valid Palindrome
- [ ] Remove Duplicates
- [ ] Move Zeroes
- [ ] Valid Palindrome II
- [ ] Squares of Sorted Array

---

## Medium

- [ ] Container With Most Water
- [ ] Ferris Wheel
- [ ] Boats to Save People

---

## Advanced

- [ ] Sum of Three Values
- [ ] 3Sum
- [ ] 3Sum Closest
- [ ] Trapping Rain Water

---

# CRT / Placement Priority

If placements started tomorrow:

1. Two Sum II
2. Valid Palindrome
3. Remove Duplicates
4. Move Zeroes
5. Valid Palindrome II
6. Squares of Sorted Array
7. Container With Most Water
8. Ferris Wheel
9. Sum of Three Values
10. 3Sum
11. Trapping Rain Water

---

# Final Mastery Checklist

## Opposite Ends

- [ ] Reverse String
- [ ] Valid Palindrome
- [ ] Valid Palindrome II
- [ ] Squares of Sorted Array
- [ ] Container With Most Water

## Slow Fast Pointer

- [ ] Remove Duplicates
- [ ] Remove Element
- [ ] Move Zeroes

## Greedy + Two Pointers

- [ ] Ferris Wheel
- [ ] Boats to Save People

## Sort + Two Pointers

- [ ] Sum of Three Values
- [ ] 3Sum
- [ ] 3Sum Closest
- [ ] 4Sum

## Advanced

- [ ] Trapping Rain Water
- [ ] Valid Triangle Number

---

# Final Mental Model

text Two Sum II ↓ Valid Palindrome ↓ Move Zeroes ↓ Squares of Sorted Array ↓ Container With Most Water ↓ Ferris Wheel ↓ 3Sum ↓ Trapping Rain Water 

Master these problems and you will have a strong Two Pointers foundation for interviews, online assessments, and competitive programming.
