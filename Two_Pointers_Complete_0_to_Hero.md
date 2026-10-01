# TWO POINTERS — COMPLETE MASTER REVISION
## DSA | 0 → Hero | Interview Ready

---

# 1. What is Two Pointers?

Two Pointers is a technique where we use **two indices/pointers** to traverse an array, string, or data structure intelligently.

Instead of checking every possible pair using nested loops:

```cpp
for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
        // check pair
    }
}
```

we try to use two pointers so that each pointer moves in a meaningful direction.

### Main idea

```text
Brute Force:
O(n²)

Two Pointer:
Often O(n)
Sometimes O(n²) for problems such as 3Sum
```

The important part is NOT simply using two variables called `left` and `right`.

The important part is:

> **Using the relationship/order of the data to eliminate unnecessary possibilities.**

---

# 2. When Should I Think of Two Pointers?

Use this recognition checklist.

## Pattern 1 — Sorted Array + Pair + Target

Example:

- Two Sum II

Think:

```text
SORTED + TWO NUMBERS + TARGET
            ↓
       LEFT + RIGHT
```

---

## Pattern 2 — Palindrome

Example:

- Valid Palindrome

Think:

```text
Compare beginning and ending
            ↓
        LEFT + RIGHT
```

---

## Pattern 3 — Remove / Compress / Keep Elements In-Place

Examples:

- Remove Duplicates
- Move Zeroes
- Remove Element

Think:

```text
FAST = scans
SLOW = writes
```

---

## Pattern 4 — Three Numbers

Example:

- 3Sum

Think:

```text
3 numbers
   ↓
Fix one number
   ↓
Find remaining two
   ↓
Two Pointers
```

---

## Pattern 5 — Container / Boundary Problem

Example:

- Container With Most Water

Think:

```text
LEFT + RIGHT
```

and move the **limiting/shorter boundary**.

---

## Pattern 6 — Water Trapped Between Boundaries

Example:

- Trapping Rain Water

Think:

```text
LEFT + RIGHT
+
LEFT MAX / RIGHT MAX
```

---

## Pattern 7 — Sorted Array + Squares

Example:

- Squares of a Sorted Array

Think:

```text
Largest square must come from one of the two ends.
```

Compare absolute values.

---

## Pattern 8 — Merge Sorted Arrays

Example:

- Merge Sorted Array

Think:

```text
Two sorted sequences
        ↓
Two pointers
```

If there is empty space at the end, merge **from the back**.

---

## Pattern 9 — 0 / 1 / 2 Partition

Example:

- Sort Colors

Think:

```text
3 categories
    ↓
3 pointers
```

---

# 3. Main Types of Two Pointers

## A. Opposite Direction

```text
L → → →     ← ← ← R
```

Pointers start from opposite ends.

Used in:

- Two Sum II
- Valid Palindrome
- Container With Most Water
- Trapping Rain Water
- Sorted Squares

---

## B. Same Direction / Read-Write

```text
slow →
fast → → → →
```

Used in:

- Remove Duplicates
- Move Zeroes
- Remove Element

Mental model:

> **Fast scans. Slow creates the correct output area.**

---

## C. Fix One + Two Pointers

```text
        i = fixed

L →                 ← R
```

Used in:

- 3Sum
- 4Sum

---

## D. Three Pointers

```text
low    mid       high
 ↓      ↓          ↓
```

Used in:

- Sort Colors

---

## E. Reverse / Backward Two Pointers

Used when merging into an array that already has empty space at the end.

Example:

- Merge Sorted Array

---

# 4. Universal Opposite-End Template

```cpp
int left = 0;
int right = n - 1;

while(left < right) {

    // calculate / compare

    if(condition) {
        left++;
    }
    else {
        right--;
    }
}
```

### Why `left < right`?

When:

```text
left == right
```

both pointers are at the same element.

When:

```text
left > right
```

they have crossed.

There is no useful pair left to process.

---

# 5. QUESTION 1 — Two Sum II
## LeetCode 167

### Problem

Given a **sorted** array, find two numbers whose sum equals `target`.

Example:

```text
numbers = [2,7,11,15]
target = 9
```

Output:

```text
[1,2]
```

---

## Pattern Recognition

```text
SORTED
+
PAIR
+
TARGET
        ↓
TWO POINTERS
```

---

## Logic

Start:

```text
2   7   11   15
↑             ↑
L             R
```

Calculate:

```cpp
sum = numbers[left] + numbers[right];
```

### Case 1

```text
sum == target
```

Pair found.

### Case 2

```text
sum < target
```

Need a bigger sum.

Because the array is sorted:

```cpp
left++;
```

### Case 3

```text
sum > target
```

Need a smaller sum.

```cpp
right--;
```

---

## Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int left = 0;
        int right = numbers.size() - 1;

        while(left < right) {

            int sum = numbers[left] + numbers[right];

            if(sum == target) {
                return {left + 1, right + 1};
            }

            else if(sum < target) {
                // Need a bigger value
                left++;
            }

            else {
                // Need a smaller value
                right--;
            }
        }

        return {};
    }
};
```

### Complexity

```text
Time  = O(n)
Space = O(1)
```

### Interview line

> Since the array is sorted, if the current sum is too small I move left forward, and if it is too large I move right backward.

---

# 6. QUESTION 2 — Remove Duplicates from Sorted Array
## LeetCode 26

### Problem

Remove duplicates **in-place** from a sorted array.

Example:

```text
[1,1,2,2,3]
```

Unique part:

```text
[1,2,3]
```

Return:

```text
3
```

---

## Pattern Recognition

```text
SORTED
+
REMOVE DUPLICATES
+
IN-PLACE
        ↓
SLOW + FAST
```

### Mental Model

> **Fast dekhega, slow jagah banayega.**

- `j` = read/scanning pointer
- `i` = write pointer / last unique element

---

## Code

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // i = position of the last unique element
        int i = 0;

        // j = scanner
        // Start from 1 because nums[0] is already unique
        for(int j = 1; j < nums.size(); j++) {

            // Found a new unique value
            if(nums[i] != nums[j]) {

                // Move write pointer forward
                i++;

                // Put the new unique value there
                nums[i] = nums[j];
            }
        }

        // Number of unique elements
        return i + 1;
    }
};
```

### Why `i + 1`?

If:

```text
i = 2
```

valid positions are:

```text
0, 1, 2
```

So count = `3`.

Therefore:

```text
i + 1
```

---

## Common mistakes

### Mistake 1

Do NOT manually write:

```cpp
j++;
```

inside the loop if the `for` loop already increments `j`.

### Mistake 2

Start from:

```cpp
j = 1
```

because the first element is already unique.

---

# 7. QUESTION 3 — Move Zeroes
## LeetCode 283

### Problem

Move all zeroes to the end while maintaining the relative order of non-zero elements.

Example:

```text
[0,1,0,3,12]
```

Output:

```text
[1,3,12,0,0]
```

---

## Pattern Recognition

```text
MOVE VALID ELEMENTS FORWARD
+
IN-PLACE
        ↓
SLOW + FAST
```

---

## Mental Model

- `fast` = scans every element
- `slow` = next position where a non-zero should go

If:

```text
nums[fast] == 0
```

ignore it.

If:

```text
nums[fast] != 0
```

put it at `slow`.

---

## Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        // slow = next position for a non-zero value
        int slow = 0;

        // fast scans the entire array
        for(int fast = 0; fast < nums.size(); fast++) {

            // Only non-zero values need to be moved
            if(nums[fast] != 0) {

                // Put the non-zero at the correct position
                swap(nums[slow], nums[fast]);

                // Next non-zero will go here
                slow++;
            }
        }
    }
};
```

### Memory

```text
0 → ignore

non-zero → swap with slow + slow++
```

### Complexity

```text
Time  = O(n)
Space = O(1)
```

---

# 8. QUESTION 4 — Container With Most Water
## LeetCode 11

### Problem

Given heights of vertical lines, find the maximum amount of water a pair of lines can contain.

---

## Formula

```text
Area = height × width
```

where:

```text
height = min(height[left], height[right])
width  = right - left
```

Therefore:

```cpp
area = min(height[left], height[right])
       * (right - left);
```

---

## Pattern Recognition

```text
Two boundaries
+
maximum area
        ↓
LEFT + RIGHT
```

---

## The Most Important Concept

### Which pointer moves?

**The shorter wall.**

If:

```cpp
height[left] < height[right]
```

then:

```cpp
left++;
```

Otherwise:

```cpp
right--;
```

### WHY?

Suppose:

```text
left height  = 2
right height = 8
```

Current water is limited by `2`.

If you move the taller wall:

```text
8 → another position
```

the width becomes smaller but the limiting height can still be `2`.

So there is no reason to keep the shorter wall fixed and move the taller one.

To possibly improve the area, we need a taller version of the **shorter boundary**.

Therefore:

> **Move the shorter wall.**

---

## Code

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int maxWater = 0;

        while(left < right) {

            // The shorter wall limits the water height
            int h = min(height[left], height[right]);

            // Distance between the walls
            int width = right - left;

            // Current area
            int area = h * width;

            // Update answer
            maxWater = max(maxWater, area);

            // Move the shorter wall
            if(height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return maxWater;
    }
};
```

### Complexity

```text
Time  = O(n)
Space = O(1)
```

### Interview one-liner

> The shorter line limits the current area, so I move the shorter pointer to potentially find a taller boundary.

---

# 9. QUESTION 5 — 3Sum
## LeetCode 15

### Problem

Find all unique triplets such that:

```text
a + b + c = 0
```

Example:

```text
[-1,0,1,2,-1,-4]
```

Output:

```text
[[-1,-1,2],[-1,0,1]]
```

---

## Pattern Recognition

```text
3 NUMBERS
    ↓
FIX ONE
    ↓
FIND TWO
    ↓
TWO POINTERS
```

---

## Step 1 — Sort

```text
[-4,-1,-1,0,1,2]
```

---

## Step 2 — Fix one element

```cpp
for(int i = 0; i < n - 2; i++)
```

Then:

```cpp
left = i + 1;
right = n - 1;
```

---

## Step 3 — Calculate

```cpp
sum = nums[i] + nums[left] + nums[right];
```

### If:

```text
sum < 0
```

Need bigger sum:

```cpp
left++;
```

### If:

```text
sum > 0
```

Need smaller sum:

```cpp
right--;
```

### If:

```text
sum == 0
```

Store triplet, then move both pointers.

---

## Duplicate handling

Because output must contain **unique triplets**.

Skip duplicate fixed elements:

```cpp
if(i > 0 && nums[i] == nums[i - 1])
    continue;
```

After finding a valid triplet, skip duplicate left/right values.

---

## Code

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        int n = nums.size();

        // Sorting allows us to use two pointers
        sort(nums.begin(), nums.end());

        // Fix one element
        for(int i = 0; i < n - 2; i++) {

            // Skip duplicate fixed values
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            // Two pointer search
            while(left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0) {

                    // Valid triplet
                    ans.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });

                    left++;
                    right--;

                    // Skip duplicate left values
                    while(left < right &&
                          nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // Skip duplicate right values
                    while(left < right &&
                          nums[right] == nums[right + 1]) {
                        right--;
                    }
                }

                else if(sum < 0) {

                    // Need a bigger sum
                    left++;
                }

                else {

                    // Need a smaller sum
                    right--;
                }
            }
        }

        return ans;
    }
};
```

### Complexity

```text
Sorting = O(n log n)
For every i, two pointers = O(n)

Total = O(n²)
```

---

# 10. QUESTION 6 — Sort Colors
## LeetCode 75

### Problem

Array contains only:

```text
0, 1, 2
```

Sort it in-place.

Example:

```text
[2,0,2,1,1,0]
```

Output:

```text
[0,0,1,1,2,2]
```

---

## Pattern Recognition

```text
3 categories
+
in-place partition
        ↓
3 POINTERS
```

Pointers:

```text
low
mid
high
```

Maintain:

```text
[ 0s ][ 1s ][ unknown ][ 2s ]
        ↑      ↑          ↑
       low    mid        high
```

More precisely:

```text
0 ... low-1       → all 0
low ... mid-1     → all 1
mid ... high      → unknown
high+1 ... n-1    → all 2
```

---

## Rules

### If `nums[mid] == 0`

Send it left:

```cpp
swap(nums[low], nums[mid]);
low++;
mid++;
```

### If `nums[mid] == 1`

It is already in the middle:

```cpp
mid++;
```

### If `nums[mid] == 2`

Send it right:

```cpp
swap(nums[mid], nums[high]);
high--;
```

### VERY IMPORTANT

When we process `2`, **do NOT increment `mid`**.

Why?

Because the element coming from `high` is still unprocessed.

---

## Code

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while(mid <= high) {

            if(nums[mid] == 0) {

                swap(nums[low], nums[mid]);

                low++;
                mid++;
            }

            else if(nums[mid] == 1) {

                // 1 belongs in the middle
                mid++;
            }

            else {

                // nums[mid] == 2
                swap(nums[mid], nums[high]);

                high--;

                // Do NOT increment mid
                // The new nums[mid] must be checked
            }
        }
    }
};
```

### Memory trick

```text
0 → LEFT
1 → MIDDLE
2 → RIGHT
```

---

# 11. QUESTION 7 — Trapping Rain Water
## LeetCode 42

This is a more advanced Two Pointer problem.

### Basic idea

At index `i`:

```text
water[i] =
min(leftMax, rightMax) - height[i]
```

---

## What is `leftMax`?

The tallest wall encountered on the left side.

```text
leftMax =
maximum height from left up to current position
```

---

## What is `rightMax`?

The tallest wall encountered from the right.

```text
rightMax =
maximum height from right up to current position
```

---

## Why `min(leftMax, rightMax)`?

Water can only rise up to the shorter boundary.

Example:

```text
Left wall  = 5
Right wall = 3
```

Water can only reach height `3`.

Therefore:

```text
water = 3 - currentHeight
```

---

## Two Pointer Logic

Maintain:

```cpp
left
right
leftMax
rightMax
water
```

If:

```cpp
height[left] <= height[right]
```

process the left side.

Otherwise:

```cpp
process right
```

### Why?

The smaller current boundary determines which side is safe to resolve.

---

## Code

```cpp
class Solution {
public:
    int trap(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        // Tallest wall seen from the left
        int leftMax = 0;

        // Tallest wall seen from the right
        int rightMax = 0;

        int water = 0;

        while(left < right) {

            // Left boundary is smaller/equal,
            // so process the left side
            if(height[left] <= height[right]) {

                // Current wall becomes the new maximum
                if(height[left] >= leftMax) {

                    leftMax = height[left];
                }

                // Current wall is lower than leftMax,
                // so water can be stored here
                else {

                    water += leftMax - height[left];
                }

                left++;
            }

            // Right boundary is smaller
            else {

                // Update right maximum
                if(height[right] >= rightMax) {

                    rightMax = height[right];
                }

                // Current wall is lower than rightMax,
                // so water can be stored
                else {

                    water += rightMax - height[right];
                }

                right--;
            }
        }

        return water;
    }
};
```

### Complexity

```text
Time  = O(n)
Space = O(1)
```

### Core memory

> **Smaller boundary side ko process karo.**

---

# 12. QUESTION 8 — Valid Palindrome
## LeetCode 125

### Problem

Check whether a string is a palindrome after:

- ignoring spaces
- ignoring punctuation
- ignoring case

Example:

```text
"A man, a plan, a canal: Panama"
```

is:

```text
true
```

---

## Pattern Recognition

```text
PALINDROME
    ↓
Compare both ends
    ↓
LEFT + RIGHT
```

---

## Logic

```text
L → → →       ← ← ← R
```

### If characters don't match:

```cpp
return false;
```

### If they match:

```cpp
left++;
right--;
```

---

## Code

```cpp
class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.length() - 1;

        while(left < right) {

            // Ignore non-alphanumeric character on left
            if(!isalnum(s[left])) {
                left++;
                continue;
            }

            // Ignore non-alphanumeric character on right
            if(!isalnum(s[right])) {
                right--;
                continue;
            }

            // Compare ignoring case
            if(tolower(s[left]) != tolower(s[right])) {

                return false;
            }

            // Characters matched
            left++;
            right--;
        }

        return true;
    }
};
```

### Memory

```text
same → both move
different → false
```

---

# 13. QUESTION 9 — Squares of a Sorted Array
## LeetCode 977

### Problem

Given a sorted array, return squares in sorted order.

Example:

```text
[-4,-1,0,3,10]
```

Output:

```text
[0,1,9,16,100]
```

---

## Why normal traversal doesn't work

Because:

```text
-4 < -1
```

but:

```text
(-4)² > (-1)²
```

The largest square can come from either end.

Example:

```text
[-4,-1,0,3,10]
 ↑                 ↑
 L                 R
```

Compare:

```text
abs(-4) = 4
abs(10) = 10
```

The right side produces the larger square.

---

## Trick

Fill answer from:

```text
right → left
```

because we find the largest square first.

---

## Code

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n);

        int left = 0;
        int right = n - 1;

        // Fill the answer from largest to smallest
        for(int i = n - 1; i >= 0; i--) {

            // Compare absolute values
            if(abs(nums[left]) > abs(nums[right])) {

                // Left produces the larger square
                ans[i] = nums[left] * nums[left];

                left++;
            }

            else {

                // Right produces the larger square
                ans[i] = nums[right] * nums[right];

                right--;
            }
        }

        return ans;
    }
};
```

### Complexity

```text
Time  = O(n)
Space = O(n)
```

The O(n) space is for the output array.

---

# 14. QUESTION 10 — Merge Sorted Array
## LeetCode 88

### Problem

Given:

```text
nums1 = [1,2,3,0,0,0]
m = 3

nums2 = [2,5,6]
n = 3
```

Merge into `nums1`:

```text
[1,2,2,3,5,6]
```

---

## Why merge from the back?

`nums1` already contains actual data:

```text
[1,2,3,0,0,0]
```

The zeroes are empty space.

If we merge from the front, we can overwrite useful values.

Instead:

```text
largest → last position
```

---

## Three pointers

```cpp
i = m - 1;
j = n - 1;
k = m + n - 1;
```

Meaning:

```text
i → last actual element in nums1
j → last element in nums2
k → last position in nums1
```

---

## Code

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m,
               vector<int>& nums2, int n) {

        // Last actual element in nums1
        int i = m - 1;

        // Last element in nums2
        int j = n - 1;

        // Last position in nums1
        int k = m + n - 1;

        // Compare from the back
        while(i >= 0 && j >= 0) {

            if(nums1[i] > nums2[j]) {

                nums1[k] = nums1[i];
                i--;
            }

            else {

                nums1[k] = nums2[j];
                j--;
            }

            // Move final position backward
            k--;
        }

        // If nums2 still has elements,
        // copy them into nums1
        while(j >= 0) {

            nums1[k] = nums2[j];

            j--;
            k--;
        }

        // If nums1 has remaining elements,
        // they are already in the correct place.
    }
};
```

### Complexity

```text
Time  = O(m+n)
Space = O(1)
```

---

# 15. Master Decision Tree

Use this in interviews.

```text
                    TWO POINTERS
                         |
       +-----------------+------------------+
       |                 |                  |
   Opposite          Same Direction      3 Pointers
       |                 |                  |
       |             slow + fast         Sort Colors
       |
       +---- Sorted + pair
       |          ↓
       |      Two Sum II
       |
       +---- Palindrome
       |          ↓
       |      Valid Palindrome
       |
       +---- 3 numbers
       |          ↓
       |       3Sum
       |
       +---- Container
       |          ↓
       |   Move shorter wall
       |
       +---- Rain Water
       |          ↓
       | leftMax/rightMax
       |
       +---- Sorted Squares
       |          ↓
       | compare abs ends
       |
       +---- Merge Sorted Arrays
                  ↓
             Merge from back
```

---

# 16. Most Important Pointer Movement Rules

| Problem | Pointer Rule |
|---|---|
| Two Sum II | `sum < target → L++`, `sum > target → R--` |
| Remove Duplicates | New element → write pointer moves |
| Move Zeroes | Non-zero → swap with slow + slow++ |
| Container With Most Water | Move shorter wall |
| 3Sum | `sum < 0 → L++`, `sum > 0 → R--` |
| Sort Colors | `0 → left`, `1 → mid`, `2 → right` |
| Trapping Rain Water | Process smaller boundary side |
| Valid Palindrome | Match → both pointers move |
| Sorted Squares | Larger absolute value gets larger answer slot |
| Merge Sorted Array | Larger value goes to the back |

---

# 17. Common Mistakes

## Mistake 1 — Blindly applying Two Pointers

Two pointers are not magic.

There must be a reason pointer movement lets us eliminate possibilities.

---

## Mistake 2 — Ignoring sorting

For many Two Pointer problems, sorted order is what makes pointer movement possible.

Example:

```text
sum < target
```

Because the array is sorted, we know moving `left` is the useful move.

---

## Mistake 3 — 3Sum duplicates

Always handle:

```cpp
if(i > 0 && nums[i] == nums[i-1])
    continue;
```

and skip duplicate `left` / `right` values after finding a valid triplet.

---

## Mistake 4 — Sort Colors

After:

```cpp
swap(nums[mid], nums[high]);
```

do NOT:

```cpp
mid++;
```

because the incoming element is unprocessed.

---

## Mistake 5 — Container With Most Water

Do not automatically move the taller wall.

The **shorter wall limits the area**.

---

## Mistake 6 — Merge Sorted Array

Do not merge from the front when `nums1` has empty spaces at the back.

Use:

```cpp
i = m - 1;
j = n - 1;
k = m + n - 1;
```

---

# 18. Complexity Cheat Sheet

| Problem | Time | Extra Space |
|---|---:|---:|
| Two Sum II | O(n) | O(1) |
| Remove Duplicates | O(n) | O(1) |
| Move Zeroes | O(n) | O(1) |
| Container With Most Water | O(n) | O(1) |
| 3Sum | O(n²) | O(1) auxiliary* |
| Sort Colors | O(n) | O(1) |
| Trapping Rain Water | O(n) | O(1) |
| Valid Palindrome | O(n) | O(1) |
| Sorted Squares | O(n) | O(n) output |
| Merge Sorted Array | O(m+n) | O(1) |

`3Sum` may use output storage, but the algorithm itself uses constant auxiliary space apart from the returned answer.

---

# 19. Final Important Problem Set

## MUST KNOW ⭐⭐⭐

### 1. Two Sum II
LeetCode 167

Pattern:

```text
Sorted + Pair + Target
→ L/R
```

### 2. Remove Duplicates from Sorted Array
LeetCode 26

Pattern:

```text
Sorted + In-place
→ Read/Write pointers
```

### 3. Move Zeroes
LeetCode 283

Pattern:

```text
Move valid elements
→ Read/Write pointers
```

### 4. Container With Most Water
LeetCode 11

Pattern:

```text
Boundary / Area
→ Move shorter wall
```

### 5. 3Sum
LeetCode 15

Pattern:

```text
3 numbers
→ Fix one + L/R
```

### 6. Sort Colors
LeetCode 75

Pattern:

```text
0/1/2
→ 3 pointers
```

### 7. Trapping Rain Water
LeetCode 42

Pattern:

```text
Boundaries
→ L/R + leftMax/rightMax
```

### 8. Valid Palindrome
LeetCode 125

Pattern:

```text
Palindrome
→ L/R
```

### 9. Squares of a Sorted Array
LeetCode 977

Pattern:

```text
Sorted + squares
→ Compare absolute values
```

### 10. Merge Sorted Array
LeetCode 88

Pattern:

```text
Two sorted arrays + empty space
→ Merge from back
```

---

# 20. Separate Pattern — Fast & Slow Pointers

Do NOT mix this with the main Two Pointer revision.

It is a related pointer technique.

Important questions:

### Middle of Linked List
LeetCode 876

```text
slow → 1 step
fast → 2 steps
```

### Linked List Cycle
LeetCode 141

```text
slow → 1 step
fast → 2 steps
```

### Happy Number
LeetCode 202

Uses cycle detection.

These can be studied as a separate:

> **Fast & Slow Pointers chapter**

---

# 21. FINAL INTERVIEW RECOGNITION CHEAT SHEET

Write this at the end of the chapter:

```text
SORTED + PAIR
        ↓
LEFT + RIGHT

PALINDROME
        ↓
LEFT + RIGHT

REMOVE / COMPRESS IN-PLACE
        ↓
SLOW + FAST

3 NUMBERS
        ↓
FIX ONE + LEFT + RIGHT

0 / 1 / 2
        ↓
LOW + MID + HIGH

CONTAINER
        ↓
MOVE SHORTER WALL

RAIN WATER
        ↓
SMALLER BOUNDARY + MAX

SORTED SQUARES
        ↓
COMPARE ABSOLUTE VALUES

MERGE SORTED ARRAYS
        ↓
MERGE FROM BACK
```

---

# 22. Golden Rule

> **Two Pointers is not about having two variables. It is about using the structure of the problem to safely eliminate possibilities.**

If you can answer these three questions, you understand the problem:

```text
1. Where do my pointers start?

2. What does each pointer represent?

3. WHY is it safe to move this pointer?
```

That **WHY** is the actual interview-level understanding.

---

# TWO POINTERS — DONE ✅

### Final Core Set

```text
✓ Two Sum II
✓ Remove Duplicates
✓ Move Zeroes
✓ Container With Most Water
✓ 3Sum
✓ Sort Colors
✓ Trapping Rain Water
✓ Valid Palindrome
✓ Sorted Squares
✓ Merge Sorted Array
```

**Goal:** Don't memorize 10 codes independently.

Recognize the pattern:

```text
Problem
   ↓
Pointer type
   ↓
Pointer invariant
   ↓
Movement rule
   ↓
Code
```

That is how Two Pointers becomes an interview pattern instead of a collection of LeetCode questions.
