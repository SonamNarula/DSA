# Two Pointers

> Pattern Level: Fundamental
>
> Difficulty Range: Easy → Hard
>
> Importance: ⭐⭐⭐⭐⭐

---

# Why Learn Two Pointers?

Two Pointers is one of the most frequently used patterns in:

- Coding Interviews
- Online Assessments
- LeetCode
- Codeforces
- CSES

Many medium problems are simply extensions of Two Sum II.

---

# Prerequisites

Before learning Two Pointers:

- Arrays
- Strings
- Sorting
- Time Complexity

---

# Pattern Recognition

If you see:

### Sorted Array

text Array is sorted Find pair/triplet Target sum given 

Think:

text Two Pointers 

---

### Palindrome

text Compare from both ends 

Think:

text Left + Right Pointer 

---

### In-place Modification

text Move zeroes Remove duplicates Remove elements 

Think:

text Slow Fast Pointer 

---

### Pairing Problems

text People Boats Weights Capacity 

Think:

text Sort + Greedy + Two Pointers 

---

# Pattern 1: Opposite Ends

## Idea

Start from both ends.

text left = 0 right = n-1 

Move pointers according to condition.

---

## Generic Template

cpp int left = 0; int right = n - 1;  while(left < right) {     if(condition)         left++;     else         right--; } 

---

## Common Problems

### Two Sum II

Observation:

text sum < target 

Need larger sum.

text Move left 

---

text sum > target 

Need smaller sum.

text Move right 

---

### Valid Palindrome

Observation:

text Mismatch 

Immediately:

text return false 

---

### Valid Palindrome II

Observation:

text One deletion allowed 

At first mismatch:

text Skip Left OR Skip Right 

---

### Squares of Sorted Array

Observation:

text Largest square always comes from ends. 

Technique:

text Fill answer array from back. 

---

### Container With Most Water

Golden Rule:

text Move smaller height pointer. 

Reason:

Moving larger height never increases area.

---

# Pattern 2: Slow Fast Pointer

## Idea

One pointer traverses.

Another pointer stores answer.

---

## Template

cpp int slow = 0;  for(int fast = 0; fast < n; fast++) {     if(condition)     {         nums[slow] = nums[fast];         slow++;     } } 

---

## Common Problems

### Remove Duplicates

text slow = unique position fast = traversal 

---

### Move Zeroes

text slow = next non-zero position fast = traversal 

---

### Remove Element

text Copy valid elements forward 

---

# Pattern 3: Sort + Two Pointers

## Idea

Fix one element.

Apply Two Sum II on remaining array.

---

## Template

cpp sort(nums.begin(), nums.end());  for(int i = 0; i < n; i++) {     int left = i + 1;     int right = n - 1;      while(left < right)     {     } } 

---

# Why It Works

Example:

text Target = 10  Fix 3  Need = 7 

Now problem becomes:

text Find two numbers with sum = 7 

Which is exactly:

text Two Sum II 

---

# Problems

### Sum of Three Values (CSES)

Pattern:

text Fix One + Two Sum II 

---

### 3Sum

Pattern:

text Fix One + Two Sum II + Duplicate Handling 

---

### 3Sum Closest

Pattern:

text Fix One + Two Sum II Track nearest answer 

---

### 4Sum

Pattern:

text Fix Two Apply Two Sum 

---

# Pattern 4: Greedy + Two Pointers

## Idea

Sort.

Pair:

text Lightest + Heaviest 

---

# Ferris Wheel

Observation:

If:

text Lightest + Heaviest > Limit 

Then:

text Heaviest cannot pair with anyone. 

Therefore:

text Send heaviest alone. 

---

# Boats To Save People

Exactly same pattern.

---

# Mistakes To Avoid

## Two Sum II

❌ Using HashMap

text Array already sorted. 

---

## Remove Duplicates

❌ Returning j

text Return unique count. 

---

## Valid Palindrome

❌ Forgetting isalnum()

---

## 3Sum

❌ Forgetting duplicate skipping

---

## Ferris Wheel

❌ Trying all pairs

text Use lightest + heaviest. 

---

# Question Roadmap

## Beginner

- Two Sum
- Two Sum II
- Reverse String
- Valid Palindrome

---

## Easy

- Remove Duplicates
- Remove Element
- Move Zeroes
- Valid Palindrome II
- Squares of Sorted Array

---

## Medium

- Container With Most Water
- Boats To Save People
- Ferris Wheel
- Sum of Three Values

---

## Harder Medium

- 3Sum
- 3Sum Closest
- 4Sum

---

## Advanced

- Trapping Rain Water
- Valid Triangle Number
- Number of Subsequences That Satisfy the Given Sum Condition

---

# Blind Revision Set

Must be solvable without hints:

- [ ] Two Sum II
- [ ] Valid Palindrome
- [ ] Remove Duplicates
- [ ] Move Zeroes
- [ ] Valid Palindrome II
- [ ] Squares of Sorted Array
- [ ] Container With Most Water
- [ ] Ferris Wheel
- [ ] Sum of Three Values
- [ ] 3Sum

---

# Final Mental Model

text Two Sum II ↓ Valid Palindrome ↓ Move Zeroes ↓ Squares of Sorted Array ↓ Container With Most Water ↓ Ferris Wheel ↓ 3Sum ↓ Trapping Rain Water 

If you can solve all of the above without help, your Two Pointers foundation is strong.
