# Two Pointers

> Pattern Category: Arrays & Strings
>
> Difficulty: Easy → Hard
>
> Importance: ⭐⭐⭐⭐⭐
>
> Time Complexity Goal: Usually O(n)

---

# Table of Contents

1. What is Two Pointers?
2. Why Do We Use It?
3. Pattern Recognition
4. Types of Two Pointers
5. Core Templates
6. Problem Roadmap
7. Common Observations
8. Common Mistakes
9. Interview Notes
10. Revision Checklist

---

# 1. What is Two Pointers?

Two Pointers is a technique where two indices move through an array or string in a controlled way to reduce unnecessary work.

Instead of:

for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
    }
}

we intelligently move two pointers and often reduce complexity from:

O(n²)
↓
O(n)

---

# 2. Why Do We Use It?

Two Pointers helps when:

- Array is sorted
- String needs comparison from both ends
- Pair/Triplet sum is required
- In-place modification is needed
- Window boundaries need tracking
- Greedy pairing is involved

---

# 3. Pattern Recognition

Whenever you see:

### Sorted Array

Find pair
Find triplet
Target sum

Think:

Two Sum II

which usually means:

Two Pointers

---

### Palindrome

Compare first and last character

Think:

Left + Right Pointer

---

### Remove Duplicates

Modify array in-place

Think:

Slow Fast Pointer

---

### Pairing Problems

Weights
Boats
People
Capacity

Think:

Greedy + Two Pointers

---

# 4. Types of Two Pointers

---

## Type 1: Opposite Ends

Pointers start from opposite ends.

int left = 0;
int right = n - 1;

Move inward.

---

### Visual

1 2 3 4 5

↑       ↑
L       R 

---

### Used In

- Two Sum II
- Valid Palindrome
- Valid Palindrome II
- Reverse String
- Squares of Sorted Array
- Container With Most Water
- Trapping Rain Water

---

## Type 2: Slow Fast Pointer

One pointer traverses.

Another stores answer.

int slow = 0;

for(int fast=0; fast<n; fast++)
{
}

---

### Visual

1 1 2 2 3

S
F

---

### Used In

- Remove Duplicates
- Move Zeroes
- Remove Element
- Sort Array by Parity

---

## Type 3: Sort + Two Pointers

Sort first.

Fix one element.

Apply Two Sum.

---

### Visual

Fix i

i L       R
↓ ↓       ↓
1 2 3 4 5 6

---

### Used In

- 3Sum
- 3Sum Closest
- 4Sum
- Sum of Three Values (CSES)

---

## Type 4: Greedy + Two Pointers

Sort.

Pair:

Lightest + Heaviest

---

### Used In

- Ferris Wheel
- Boats to Save People

---

# 5. Core Templates

---

## Template 1: Opposite Ends

int left = 0;
int right = n - 1;

while(left < right)
{
    if(condition)
    {
        left++;
    }
    else
    {
        right--;
    }
}

---

## Template 2: Slow Fast

int slow = 0;

for(int fast = 0; fast < n; fast++)
{
    if(condition)
    {
        nums[slow] = nums[fast];
        slow++;
    }
}

---

## Template 3: Sort + Two Sum

sort(nums.begin(), nums.end());

for(int i=0;i<n;i++)
{
    int left = i + 1;
    int right = n - 1;

    while(left < right)
    {
    }
}

---

# 6. Problem Roadmap

---

## Level 0: Warmup

### Reverse String

Concept:

Swap from both ends.

---

### Palindrome Number

Concept:

Compare mirrored positions.

---

## Level 1: Basic Opposite Ends

### Two Sum II

Observation:

Array sorted.

Rule:

sum < target → left++

sum > target → right--

---

### Valid Palindrome

Observation:

text Mismatch → false 

---

### Valid Palindrome II

Observation:

Mismatch → false

Rule:

Skip left
OR
Skip right

---

## Level 2: Slow Fast Pointer

### Remove Duplicates

Concept:

text slow = position of next unique element 

---

### Move Zeroes

Concept:

Bring all non-zero elements forward.

---

### Remove Element

Concept:

Keep valid elements only.

---

## Level 3: Advanced Opposite Ends

### Squares of Sorted Array

Observation:

Largest square always comes from ends.

Technique:

Fill answer from back.

---

### Container With Most Water

Observation:

Move smaller height pointer.

Reason:

Area depends on minimum height.

---

## Level 4: Greedy + Two Pointers

### Ferris Wheel (CSES)

Observation:

Heavy child is hardest to place.

Rule:

Lightest + Heaviest

If not possible:

Heaviest goes alone.

---

### Boats to Save People

Same pattern.

---

## Level 5: Sort + Two Pointers

### Sum of Three Values (CSES)

Concept:


Fix One

Apply Two Sum II


---

### 3Sum

Concept:

Fix One

Find remaining two

---

### 3Sum Closest

Concept:

Track nearest answer.

---

### 4Sum

Concept:

Fix Two

Apply Two Sum

---

## Level 6: Advanced

### Trapping Rain Water

Observation:

Water depends on smaller boundary.

---

### Valid Triangle Number

Observation:

Sort + Two Pointers

---

# 7. Common Observations

---

## Two Sum II

Sorted array
↓
Two Pointers

---

## Valid Palindrome

Compare from ends

---

## Valid Palindrome II

First mismatch

Skip left
OR
Skip right

---

## Squares of Sorted Array

Largest square
=
Either end

---

## Container With Most Water

text Move smaller height. 

---

## Ferris Wheel

Move smaller height.

---

## 3Sum

text Fix One + Two Sum II 

---

# 8. Common Mistakes

---

### Two Sum II

❌ Using HashMap

Array already sorted.

---

### Remove Duplicates

❌ Returning wrong pointer.

---

### Valid Palindrome

❌ Forgetting special character handling.

---

### Valid Palindrome II

❌ Skipping both characters together.

---

### 3Sum

❌ Forgetting duplicate skipping.

---

### Ferris Wheel

❌ Trying all pairs.

---

# 9. Interview Notes

Most interview questions are combinations of:

text Opposite Ends + Slow Fast + Sorting 

Important progression:

text Two Sum II ↓ Valid Palindrome ↓ Move Zeroes ↓ Squares of Sorted Array ↓ Container With Most Water ↓ 3Sum ↓ Trapping Rain Water 

---

# 10. Revision Checklist

## Must Solve Without Help

### Basics

- [ ] Reverse String
- [ ] Valid Palindrome
- [ ] Two Sum II

### Slow Fast

- [ ] Remove Duplicates
- [ ] Move Zeroes
- [ ] Remove Element

### Medium

- [ ] Valid Palindrome II
- [ ] Squares of Sorted Array
- [ ] Container With Most Water

### Greedy

- [ ] Ferris Wheel
- [ ] Boats to Save People

### Advanced

- [ ] Sum of Three Values
- [ ] 3Sum
- [ ] 3Sum Closest
- [ ] Trapping Rain Water

---

# Final Mental Model

text Two Sum II ↓ Valid Palindrome ↓ Move Zeroes ↓ Squares of Sorted Array ↓ Container With Most Water ↓ Ferris Wheel ↓ 3Sum ↓ Trapping Rain Water 

If you can solve all of these without hints, your Two Pointers foundation is strong.
