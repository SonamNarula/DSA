# THE FLAGSHIP: 28 Days to Pattern Fluency

> A video can show you the road. It cannot walk it for you.
> This plan is the walking: one pattern at a time, until the clue and the solution arrive together.

**Anchor:** Stoney Codes, "70 LeetCode problems in 5+ hours" (youtu.be/lvO88XxNAzs)
**Goal:** campus placements: OAs, coding rounds, technical interviews
**Language:** C++ only (explicit headers, readable names)
**Scale:** 257 problems (stretch included) across 28 days, 10-15 a day with revision
**Legend:** `E` easy, `M` medium, `H` hard. **(GFG)** = not on LeetCode.

---

## 1. The Contract

Five promises. Break one and the plan quietly stops working.

1. **Struggle first.** Fifteen to twenty minutes alone with the problem before any hint, any video, any editorial.
2. **Name the pattern before the code.** One line: "This is ___ because ___." If you cannot write that line, you have not understood the problem yet.
3. **Blank file, always.** After watching a solution, close it and rewrite from nothing. Scrolling back to peek does not count.
4. **Log the wounds.** Stuck for 30+ minutes, or needed the solution? It goes into the Mistake Log (Section 8). The log is where the real learning lives.
5. **Respect what you already know.** Easy for you (solved in under 10 minutes, pattern obvious)? Tick it, move on, bank the time for STRETCH and REVISE. Never pad hours on problems you already own.

---

## 2. Dashboard

Fill this in as you go. A plan you can see is a plan you keep.

| Week | Theme | Days done | Problems solved | Checkpoint score | Notes |
|---|---|---|---|---|---|
| 1 | Arrays, pointers, windows, search | /8 | | | |
| 2 | DP, backtracking, lists, stacks | /10 | | | |
| 3 | Trees, heaps, graphs | /6 | | | |
| 4 | Gaps, mocks, consolidation | /4 | | | |

**Streak:** ____ days  **Longest streak:** ____ days

**Graph Refresh tracker:**

| Day | Refreshed | Done |
|---|---|---|
| 3 | BFS + DFS rewrite | [ ] |
| 7 | BFS shortest path | [ ] |
| 10 | Topological sort | [ ] |
| 14 | Dijkstra | [ ] |
| 17 | DSU | [ ] |
| 20 | Multi-source BFS / bipartite | [ ] |

---

## 3. Pattern Radar (self-assessment)

Rate yourself 1-5 now (Day 0) and again on Day 28.
1 = never heard of it, 3 = solve with hints, 5 = can teach it.

| Pattern | Day 0 | Day 28 |
|---|---|---|
| Hashing / prefix sums | | |
| Two pointers | | |
| Sliding window | | |
| Binary search (index + on answer) | | |
| Bit manipulation | | |
| Strings | | |
| DP: 1D / grid / knapsack / strings | | |
| Backtracking | | |
| Linked lists | | |
| Stacks / monotonic stack | | |
| Trees / BST | | |
| Heaps | | |
| Graphs: BFS/DFS | | |
| Graphs: topo / Dijkstra / DSU | | |
| Intervals / greedy | | |
| Trie | | |

Any pattern still at 3 or below on Day 28 is your next two weeks.

---

## 4. Pattern Identification Sheet

This table is the actual skill. Read the problem, find the clue, reach for the pattern.

| The clue in the problem | First thing to try |
|---|---|
| "Does X exist / count / any duplicate" | Hash set or hash map |
| Sorted array + pair or triplet | Two pointers |
| Contiguous subarray/substring + max/min/count, condition is monotonic | Sliding window |
| Subarray sum with **only non-negative** numbers (>= target, shortest/longest) | Sliding window |
| Subarray sum equals K, **negatives allowed** | Prefix sum + hash map (NOT a plain window) |
| Sorted input, or "minimize the maximum / maximize the minimum" | Binary search (index, or on the answer) |
| "Next greater / smaller", spans, histograms | Monotonic stack |
| Brackets, nesting, undo | Stack |
| All combinations / permutations / subsets | Backtracking |
| Min / max / count ways + overlapping subproblems | DP |
| Top K, K-th largest, running median | Heap |
| Shortest path, unweighted | BFS |
| Shortest path, weighted | Dijkstra |
| Groups, components, merging | DSU or DFS |
| Prerequisites, ordering | Topological sort |
| Tree depth / height / path | DFS, return values upward |
| Tree level by level | BFS with a queue |
| List middle / cycle | Slow and fast pointers |
| List reverse / reorder | Rewire prev, curr, next |
| Intervals overlap / merge | Sort by start, sweep |
| Locally best never regrets | Greedy (prove it, or fall back to DP) |
| Appears once, XOR, power of two | Bit manipulation |
| Prefix lookup, word dictionary | Trie |

---

## 5. The Daily Rhythm

- **10 min:** reread yesterday's pattern note
- **2-3 hrs:** VIDEO and EXTRA problems
- **20 min:** REVISE block
- **10 min:** write today's notes (format in Section 9)
- **Every day:** end with one line in the Mistake Log, even if the line is "none today."
- **Graph Refresh (every 3-4 days):** you have already studied graphs, so do not let them go cold until Day 23. On the days marked **GRAPH REFRESH**, re-solve one graph problem you have solved before, cold, in a blank file (about 20 minutes). It is a refresh, not extra new learning, and it does not change the order of this roadmap. Days 23-24 stay as the formal graph days; they should now feel faster.

Each day below follows the same skeleton:
**GOAL** (what you should be able to do by night), **VIDEO**, **EXTRA**, **STRETCH** (optional, harder), **REVISE**, **DONE WHEN**.

---

## 6. The 28 Days

### WEEK 1: Arrays, Pointers, Windows, Search

#### Day 1: Foundations + Hashing
**GOAL:** Look at a problem and say "set, map, or sort?" in ten seconds.
- Watch first: Intro, Big O (0:05:39), Problem Solving Techniques (0:11:57).
- **VIDEO**
  - [ ] `E` 217 Contains Duplicate
  - [ ] `E` 268 Missing Number
  - [ ] `E` 448 Find All Numbers Disappeared in an Array
  - [ ] `E` 1 Two Sum
  - [ ] `E` 2011 Final Value After Operations
  - [ ] `E` 1365 How Many Numbers Are Smaller Than the Current Number
- **EXTRA**
  - [ ] `E` 242 Valid Anagram
  - [ ] `E` 169 Majority Element
  - [ ] `E` 283 Move Zeroes
  - [ ] `E` 26 Remove Duplicates from Sorted Array
  - [ ] `E` 27 Remove Element
- **STRETCH**
  - [ ] `H` 41 First Missing Positive
- **Note:** Running Sum and Find Pivot Index now live on Day 4, where prefix sums are introduced properly.
- **DONE WHEN:** you can explain why hashing trades space for time, in two sentences.

#### Day 2: Matrices + Grid DFS
**GOAL:** Walk a grid without bugs, and recognize "islands" as connected components.
- **VIDEO**
  - [ ] `E` 1266 Minimum Time Visiting All Points
  - [ ] `M` 54 Spiral Matrix
  - [ ] `M` 200 Number of Islands
- **EXTRA**
  - [ ] `M` 49 Group Anagrams
  - [ ] `M` 128 Longest Consecutive Sequence
  - [ ] `M` 238 Product of Array Except Self
  - [ ] `M` 36 Valid Sudoku
  - [ ] `M` 73 Set Matrix Zeroes
  - [ ] `M` 48 Rotate Image
  - [ ] `M` 695 Max Area of Island
  - [ ] `E` 733 Flood Fill
- **STRETCH**
  - [ ] `H` 329 Longest Increasing Path in a Matrix
- **REVISE:** 2 problems from Day 1.
- **DONE WHEN:** a grid DFS/BFS flows out of your fingers without looking at notes.

#### Day 3: Two Pointers
**GOAL:** Know *which* pointer to move and *why* the other one can't improve the answer.
- **VIDEO**
  - [ ] `E` 121 Best Time to Buy and Sell Stock
  - [ ] `E` 977 Squares of a Sorted Array
  - [ ] `M` 15 3Sum
  - [ ] `M` 845 Longest Mountain in Array
- **EXTRA**
  - [ ] `E` 125 Valid Palindrome
  - [ ] `M` 167 Two Sum II - Input Array Is Sorted
  - [ ] `M` 11 Container With Most Water
  - [ ] `M` 75 Sort Colors
  - [ ] `M` 16 3Sum Closest
  - [ ] `H` 42 Trapping Rain Water
- **STRETCH**
  - [ ] `M` 18 4Sum
- **REVISE:** 2 problems from Day 2.
- [ ] **GRAPH REFRESH:** rewrite BFS and DFS on an adjacency list from a blank file. (Refresh log: Day 3)
- **DONE WHEN:** you can prove, not just feel, that the pointer move never skips the best answer.

#### Day 4: Prefix Sums, then Prefix Sums + Hashing (the video's missing pattern)
**GOAL:** See that prefix sums are not a separate topic. They are a way of turning "sum of a range" into a lookup, and hashing is what makes that lookup fast.
- **Part 1: Prefix sums alone** (build the idea first)
  - [ ] `E` 1480 Running Sum of 1d Array
  - [ ] `E` 724 Find Pivot Index
- **Part 2: Prefix sums + hash map** (now combine)
  - [ ] `M` 560 Subarray Sum Equals K
  - [ ] `M` 525 Contiguous Array
  - [ ] `M` 974 Subarray Sums Divisible by K
- **Part 3: Related array tricks**
  - [ ] `M` 189 Rotate Array
  - [ ] `M` 442 Find All Duplicates in an Array
  - [ ] `M` 287 Find the Duplicate Number
  - [ ] `M` 31 Next Permutation
- **STRETCH**
  - [ ] `M` 1248 Count Number of Nice Subarrays
- **REVISE:** 3 problems from Days 1-3.
- **Before Part 2, answer in one line:** "If `prefix[j] - prefix[i] = K`, what do I look up, and where do I store it?" If you cannot answer, redo Part 1 first.
- **DONE WHEN:** `prefix[j] - K` is your instinctive lookup, and you can explain why a plain sliding window fails on Subarray Sum Equals K (negatives).

#### Day 5: Sliding Window
**GOAL:** Tell fixed windows from variable windows, write the shrink condition without thinking, and know when a window is the wrong tool entirely.
- **PREREQUISITE CHECK (do not start until all three are true):**
  - [ ] **Array traversal:** you can loop, index, and handle edges (empty, size 1) without bugs. (Days 1-2)
  - [ ] **Frequency counting:** you can build and update a count map or `int[26]` array on the fly. (Day 1: Valid Anagram, Majority Element; Day 2: Group Anagrams)
  - [ ] **Two pointers, the basic idea:** you can say why moving one pointer never skips the answer. (Day 3)
  - If any box is empty, spend the morning re-solving one problem from that day before Day 5 proper.
- **KNOW YOUR INPUT (the rule that prevents wrong answers):**
  - A sliding window works for subarray-sum problems only when **all numbers are non-negative** (Minimum Size Subarray Sum, 209). Adding an element can only increase the sum, removing one can only decrease it, so the window shrinks and grows predictably.
  - **With negative numbers, a plain sliding window is not a correct solution.** Adding an element can lower the sum, so "shrink when too big" breaks. Use prefix sum + hash map (Day 4), or a monotonic deque for the harder variants.
  - Before writing any window code, ask: *Are values all positive? Is the condition monotonic as the window grows?* If either answer is no, stop and rethink the pattern.
- **VIDEO**
  - [ ] `E` 219 Contains Duplicate II
  - [ ] `E` 1200 Minimum Absolute Difference
  - [ ] `M` 209 Minimum Size Subarray Sum
- **EXTRA**
  - [ ] `E` 643 Maximum Average Subarray I
  - [ ] `M` 3 Longest Substring Without Repeating Characters
  - [ ] `M` 424 Longest Repeating Character Replacement
  - [ ] `M` 567 Permutation in String
  - [ ] `M` 1004 Max Consecutive Ones III
  - [ ] `M` 904 Fruit Into Baskets
  - [ ] `H` 76 Minimum Window Substring
  - [ ] `H` 239 Sliding Window Maximum
- **STRETCH**
  - [ ] `H` 992 Subarrays with K Different Integers
  - [ ] `H` 862 Shortest Subarray with Sum at Least K (the negative-numbers case that breaks a plain window)
- **DONE WHEN:** "expand right, shrink left while invalid" is a reflex, and you can explain in two sentences why Minimum Size Subarray Sum allows a window but Subarray Sum Equals K does not.

#### Day 6: Binary Search I (the video's biggest gap)
**GOAL:** One template, one habit, zero off-by-one bugs.
- **EXTRA**
  - [ ] `E` 704 Binary Search
  - [ ] `E` 35 Search Insert Position
  - [ ] `E` 278 First Bad Version
  - [ ] `E` 69 Sqrt(x)
  - [ ] `M` 34 First and Last Position of Element in Sorted Array
  - [ ] `M` 74 Search a 2D Matrix
  - [ ] `M` 162 Find Peak Element
- **STRETCH**
  - [ ] `H` 4 Median of Two Sorted Arrays
- **REVISE:** 3 problems from Days 3-5.
- **DONE WHEN:** you pick `lo`, `hi`, and the loop condition by logic rather than luck.

#### Day 7: Binary Search II (rotated arrays + searching on the answer)
**GOAL:** Spot "minimize the maximum" and reach for binary search on the answer.
- **EXTRA**
  - [ ] `M` 153 Find Minimum in Rotated Sorted Array
  - [ ] `M` 33 Search in Rotated Sorted Array
  - [ ] `M` 81 Search in Rotated Sorted Array II
  - [ ] `M` 540 Single Element in a Sorted Array
  - [ ] `M` 875 Koko Eating Bananas
  - [ ] `M` 1011 Capacity To Ship Packages Within D Days
  - [ ] `H` 410 Split Array Largest Sum
- **STRETCH**
  - [ ] `H` 719 Find K-th Smallest Pair Distance
- **REVISE:** 3 problems from Days 1-6.
- [ ] **GRAPH REFRESH:** re-solve one BFS shortest-path problem you have done before (for example, a grid shortest path or word-ladder style). (Refresh log: Day 7)
- **DONE WHEN:** you can write a `canDo(mid)` feasibility check before touching the search loop.

#### Day 8: Bit Manipulation + Strings
**GOAL:** Own XOR tricks, and handle string problems as arrays with extra rules.
- **VIDEO**
  - [ ] `E` 136 Single Number
- **EXTRA**
  - [ ] `E` 191 Number of 1 Bits
  - [ ] `E` 231 Power of Two
  - [ ] `E` 190 Reverse Bits
  - [ ] `M` 260 Single Number III
  - [ ] `M` 137 Single Number II
  - [ ] `E` 14 Longest Common Prefix
  - [ ] `M` 5 Longest Palindromic Substring
  - [ ] `M` 647 Palindromic Substrings
  - [ ] `M` 151 Reverse Words in a String
  - [ ] `M` 394 Decode String
- **STRETCH**
  - [ ] `M` 421 Maximum XOR of Two Numbers in an Array
- **REVISE:** 2 problems from Days 4-7.
- **DONE WHEN:** `x & (x - 1)` and `a ^ a = 0` feel obvious.

---

### WEEK 2: DP, Backtracking, Lists, Stacks

#### Day 9: CHECKPOINT 1
**GOAL:** Find out what actually stuck.
- Re-solve every Mistake Log problem from Days 1-8 **without looking**.
- Two fresh mediums, 35 minutes each, one from "window/prefix", one from "binary search on answer".
- Anything failed twice joins the **Weak List** (Section 8).
- Fill the Dashboard and update the Radar for week 1.
- Lighter day. Rest the brain; fix notes.
- **DONE WHEN:** the Weak List is written and you know what Week 2 will revisit.

#### Day 10: DP I (1D)
**GOAL:** Write state, transition, base case, answer cell, in that order, every time.
- **VIDEO**
  - [ ] `E` 70 Climbing Stairs
  - [ ] `M` 322 Coin Change
  - [ ] `M` 53 Maximum Subarray
  - [ ] `E` 338 Counting Bits
  - [ ] `E` 303 Range Sum Query - Immutable
- **EXTRA**
  - [ ] `E` 509 Fibonacci Number
  - [ ] `E` 746 Min Cost Climbing Stairs
  - [ ] `M` 198 House Robber
  - [ ] `M` 213 House Robber II
  - [ ] `M` 91 Decode Ways
  - [ ] `M` 139 Word Break
- **STRETCH**
  - [ ] `M` 918 Maximum Sum Circular Subarray
- [ ] **GRAPH REFRESH:** re-solve a topological sort problem cold (for example, Course Schedule, which also appears in Day 24). (Refresh log: Day 10)
- **DONE WHEN:** you can convert any recursion with memo into a table, and back.

#### Day 11: DP II (grid + knapsack)
**GOAL:** Tell "min coins" from "count ways" by the loop order alone.
- **EXTRA**
  - [ ] `M` 62 Unique Paths
  - [ ] `M` 63 Unique Paths II
  - [ ] `M` 64 Minimum Path Sum
  - [ ] `M` 120 Triangle
  - [ ] `M` 416 Partition Equal Subset Sum
  - [ ] `M` 518 Coin Change II
  - [ ] `M` 152 Maximum Product Subarray
- **STRETCH**
  - [ ] `H` 174 Dungeon Game
- **REVISE:** 3 problems from Days 8-10.
- **DONE WHEN:** you can explain why Coin Change II loops coins on the outside.

#### Day 12: DP III (strings + subsequences)
**GOAL:** See the two-string DP grid (LCS, edit distance) as one family.
- **EXTRA**
  - [ ] `M` 1143 Longest Common Subsequence
  - [ ] `H` 72 Edit Distance
  - [ ] `M` 300 Longest Increasing Subsequence
  - [ ] `E` 392 Is Subsequence
  - [ ] `M` 583 Delete Operation for Two Strings
  - [ ] `M` 931 Minimum Falling Path Sum
  - [ ] `M` 221 Maximal Square
- **STRETCH**
  - [ ] `H` 10 Regular Expression Matching
- **REVISE:** 3 DP problems from Days 10-11, re-solved from scratch.
- **DONE WHEN:** you can draw the `dp[i][j]` grid for LCS and fill it by hand.

#### Day 13: Backtracking I
**GOAL:** Choose, explore, un-choose, with duplicates handled by sorting.
- **VIDEO**
  - [ ] `M` 784 Letter Case Permutation
  - [ ] `M` 78 Subsets
  - [ ] `M` 77 Combinations
  - [ ] `M` 46 Permutations
- **EXTRA**
  - [ ] `M` 90 Subsets II
  - [ ] `M` 47 Permutations II
  - [ ] `M` 39 Combination Sum
  - [ ] `M` 40 Combination Sum II
  - [ ] `M` 17 Letter Combinations of a Phone Number
  - [ ] `M` 22 Generate Parentheses
- **STRETCH**
  - [ ] `H` 37 Sudoku Solver
- **DONE WHEN:** you can draw the recursion tree for Subsets from memory.

#### Day 14: Backtracking II
**GOAL:** Prune early. Backtracking without pruning is just brute force with extra steps.
- **EXTRA**
  - [ ] `M` 79 Word Search
  - [ ] `M` 131 Palindrome Partitioning
  - [ ] `H` 51 N-Queens
  - [ ] `M` 93 Restore IP Addresses
  - [ ] `M` 216 Combination Sum III
- **STRETCH**
  - [ ] `H` 140 Word Break II
- **REVISE:** 5 problems across Days 8-13 (at least 2 from DP).
- [ ] **GRAPH REFRESH:** rewrite Dijkstra with a priority queue from memory, then solve one weighted shortest-path problem you have seen. (Refresh log: Day 14)
- **DONE WHEN:** for each problem you can name the pruning condition.

#### Day 15: Linked List I
**GOAL:** Dummy node and slow/fast pointers, used without hesitation.
- **VIDEO**
  - [ ] `E` 876 Middle of the Linked List
  - [ ] `E` 141 Linked List Cycle
  - [ ] `E` 206 Reverse Linked List
  - [ ] `E` 203 Remove Linked List Elements
  - [ ] `M` 92 Reverse Linked List II
  - [ ] `E` 234 Palindrome Linked List
  - [ ] `E` 21 Merge Two Sorted Lists
- **EXTRA**
  - [ ] `M` 142 Linked List Cycle II
  - [ ] `M` 19 Remove Nth Node From End of List
  - [ ] `E` 160 Intersection of Two Linked Lists
  - [ ] `E` 83 Remove Duplicates from Sorted List
  - [ ] `M` 2 Add Two Numbers
  - [ ] `M` 143 Reorder List
- **STRETCH**
  - [ ] `M` 146 LRU Cache
- **DONE WHEN:** you can reverse a list iteratively with your eyes closed.

#### Day 16: Linked List II + Stack Basics
**GOAL:** Handle k-group reversal and random-pointer copy without losing a node.
- **VIDEO**
  - [ ] `M` 155 Min Stack
  - [ ] `E` 20 Valid Parentheses
  - [ ] `M` 150 Evaluate Reverse Polish Notation
- **EXTRA**
  - [ ] `M` 24 Swap Nodes in Pairs
  - [ ] `H` 25 Reverse Nodes in k-Group
  - [ ] `M` 138 Copy List with Random Pointer
  - [ ] `M` 148 Sort List
  - [ ] `H` 23 Merge k Sorted Lists
  - [ ] `M` 82 Remove Duplicates from Sorted List II
  - [ ] `M` 61 Rotate List
  - [ ] `M` 328 Odd Even Linked List
- **REVISE:** 2 problems from Day 15.
- **DONE WHEN:** you can describe the pointer picture before writing a line.

#### Day 17: Stacks + Queues (monotonic stack)
**GOAL:** Recognize "next greater element" as a stack that keeps itself sorted.
- **VIDEO**
  - [ ] `E` Sort a Stack **(GFG)**
  - [ ] `E` 225 Implement Stack using Queues
  - [ ] `E` 2073 Time Needed to Buy Tickets
  - [ ] `E` Reverse First K Elements of a Queue **(GFG)**
- **EXTRA**
  - [ ] `E` 232 Implement Queue using Stacks
  - [ ] `M` 739 Daily Temperatures
  - [ ] `E` 496 Next Greater Element I
  - [ ] `M` 503 Next Greater Element II
  - [ ] `H` 84 Largest Rectangle in Histogram
  - [ ] `M` 853 Car Fleet
  - [ ] `M` 71 Simplify Path
  - [ ] `M` 622 Design Circular Queue
- **STRETCH**
  - [ ] `H` 85 Maximal Rectangle
- [ ] **GRAPH REFRESH:** rewrite DSU (find with path compression, union by size) and re-solve one connected-components problem. (Refresh log: Day 17)
- **DONE WHEN:** you can draw the stack after each step of Daily Temperatures.

#### Day 18: CHECKPOINT 2
**GOAL:** Prove Week 2 stuck.
- Re-solve the Mistake Log from Days 9-17, no peeking.
- Two fresh mediums, 35 minutes each: one DP, one list/stack.
- **Pattern-ID drill:** pick 8 random problems from Days 1-17, hide the titles, write the pattern in one line each. Check yourself.
- Update the Weak List, Dashboard, and Radar.
- **DONE WHEN:** at least 6 of 8 patterns guessed correctly.

---

### WEEK 3: Trees, Heaps, Graphs

#### Day 19: Binary Trees I
**GOAL:** Ask "what do I return to my parent?" before every recursive tree solution.
- **VIDEO**
  - [ ] `E` 637 Average of Levels in Binary Tree
  - [ ] `E` 111 Minimum Depth of Binary Tree
  - [ ] `E` 104 Maximum Depth of Binary Tree
  - [ ] `E` Min/Max Value in Binary Tree **(GFG)**
  - [ ] `M` 102 Binary Tree Level Order Traversal
  - [ ] `E` 100 Same Tree
  - [ ] `E` 226 Invert Binary Tree
- **EXTRA**
  - [ ] `E` 94 Binary Tree Inorder Traversal
  - [ ] `E` 144 Binary Tree Preorder Traversal
  - [ ] `E` 145 Binary Tree Postorder Traversal
  - [ ] `E` 101 Symmetric Tree
  - [ ] `E` 110 Balanced Binary Tree
  - [ ] `M` 199 Binary Tree Right Side View
  - [ ] `M` 103 Binary Tree Zigzag Level Order Traversal
- **STRETCH**
  - [ ] `H` 987 Vertical Order Traversal of a Binary Tree
- **DONE WHEN:** you can write all three DFS orders recursively and one iteratively.

#### Day 20: Binary Trees II
**GOAL:** Split "path through a node" from "path ending at a node" cleanly.
- **VIDEO**
  - [ ] `E` 112 Path Sum
  - [ ] `E` 543 Diameter of Binary Tree
  - [ ] `M` 236 Lowest Common Ancestor of a Binary Tree
- **EXTRA**
  - [ ] `M` 113 Path Sum II
  - [ ] `M` 437 Path Sum III
  - [ ] `E` 572 Subtree of Another Tree
  - [ ] `M` 1448 Count Good Nodes in Binary Tree
  - [ ] `M` 105 Construct Binary Tree from Preorder and Inorder Traversal
  - [ ] `M` 114 Flatten Binary Tree to Linked List
  - [ ] `H` 124 Binary Tree Maximum Path Sum
  - [ ] `H` 297 Serialize and Deserialize Binary Tree
- **STRETCH**
  - [ ] `H` 968 Binary Tree Cameras
- **REVISE:** 2 problems from Day 19.
- [ ] **GRAPH REFRESH:** re-solve one multi-source BFS or bipartite-check problem you have done before. (Refresh log: Day 20)
- **DONE WHEN:** Diameter, Max Path Sum, and Path Sum III feel like one idea in three costumes.

#### Day 21: Binary Search Trees
**GOAL:** Remember that the inorder of a BST is sorted. That one fact solves half this day.
- **VIDEO**
  - [ ] `E` 700 Search in a Binary Search Tree
  - [ ] `M` 701 Insert into a Binary Search Tree
  - [ ] `E` 108 Convert Sorted Array to Binary Search Tree
  - [ ] `E` 653 Two Sum IV - Input is a BST
  - [ ] `M` 235 Lowest Common Ancestor of a Binary Search Tree
  - [ ] `E` 530 Minimum Absolute Difference in BST
  - [ ] `M` 1382 Balance a Binary Search Tree
  - [ ] `M` 450 Delete Node in a BST
  - [ ] `M` 230 Kth Smallest Element in a BST
- **EXTRA**
  - [ ] `M` 98 Validate Binary Search Tree
  - [ ] `M` 173 Binary Search Tree Iterator
  - [ ] `E` 938 Range Sum of BST
- **STRETCH**
  - [ ] `M` 99 Recover Binary Search Tree
- **DONE WHEN:** you can explain the three cases of BST deletion without notes.

#### Day 22: Heaps
**GOAL:** K largest uses a min-heap of size K. Say it until it stops sounding backwards.
- **VIDEO**
  - [ ] `M` 215 Kth Largest Element in an Array
  - [ ] `M` 973 K Closest Points to Origin
  - [ ] `M` 347 Top K Frequent Elements
  - [ ] `M` 621 Task Scheduler
- **EXTRA**
  - [ ] `E` 703 Kth Largest Element in a Stream
  - [ ] `E` 1046 Last Stone Weight
  - [ ] `H` 295 Find Median from Data Stream
  - [ ] `M` 767 Reorganize String
  - [ ] `M` 451 Sort Characters By Frequency
  - [ ] `M` 355 Design Twitter
- **STRETCH**
  - [ ] `H` 502 IPO
- **REVISE:** 2 problems from Days 19-21.
- **DONE WHEN:** you can write a custom comparator for a priority queue without searching syntax.

#### Day 23: Graphs I (BFS/DFS)
**GOAL:** Model a problem as a graph, then pick BFS or DFS on purpose.
- Since you have refreshed graphs every few days, treat today as consolidation: watch the video at 1.5x if the basics feel familiar, and spend the saved time on EXTRA and STRETCH.
- **VIDEO**
  - [ ] `E` Breadth First and Depth First Traversal (implement both with adjacency lists)
  - [ ] `M` 133 Clone Graph
  - [ ] `E` Core graph operations (watch, then re-implement)
- **EXTRA**
  - [ ] `M` 994 Rotting Oranges
  - [ ] `M` 417 Pacific Atlantic Water Flow
  - [ ] `M` 130 Surrounded Regions
  - [ ] `M` 785 Is Graph Bipartite?
  - [ ] `M` 547 Number of Provinces
  - [ ] `M` 1091 Shortest Path in Binary Matrix
  - [ ] `M` 841 Keys and Rooms
- **STRETCH**
  - [ ] `M` 542 01 Matrix
  - [ ] `H` 1293 Shortest Path in a Grid with Obstacles Elimination
- **DONE WHEN:** multi-source BFS (Rotting Oranges, 01 Matrix) feels like one trick.

#### Day 24: Graphs II (topo sort, Dijkstra, DSU)
**GOAL:** Know which of the three tools each graph problem is asking for.
- Topo sort, Dijkstra, and DSU were each refreshed earlier (Days 10, 14, 17), so this day is about *choosing* the right tool, not relearning it.
- **VIDEO**
  - [ ] `M` 207 Course Schedule
  - [ ] `M` 787 Cheapest Flights Within K Stops
- **EXTRA**
  - [ ] `M` 210 Course Schedule II
  - [ ] `M` 684 Redundant Connection
  - [ ] `M` 721 Accounts Merge
  - [ ] `M` 743 Network Delay Time
  - [ ] `M` 1631 Path With Minimum Effort
  - [ ] `H` 127 Word Ladder
  - [ ] `M` 990 Satisfiability of Equality Equations
  - [ ] `M` 1202 Smallest String With Swaps
- **STRETCH**
  - [ ] `M` 1584 Min Cost to Connect All Points
  - [ ] `H` 332 Reconstruct Itinerary
- **DONE WHEN:** you can write DSU (find with path compression + union by size) from a blank file.

---

### WEEK 4: Gaps, Mocks, Consolidation

#### Day 25: Intervals, Greedy, Trie
**GOAL:** Sort first, then sweep. Prove greedy before you trust it.
- **EXTRA**
  - [ ] `M` 56 Merge Intervals
  - [ ] `M` 57 Insert Interval
  - [ ] `M` 435 Non-overlapping Intervals
  - [ ] `M` 452 Minimum Number of Arrows to Burst Balloons
  - [ ] `M` 986 Interval List Intersections
  - [ ] `M` 55 Jump Game
  - [ ] `M` 45 Jump Game II
  - [ ] `M` 134 Gas Station
  - [ ] `M` 763 Partition Labels
  - [ ] `E` 860 Lemonade Change
  - [ ] `M` 208 Implement Trie (Prefix Tree)
  - [ ] `M` 211 Design Add and Search Words Data Structure
- **STRETCH**
  - [ ] `H` 212 Word Search II
- **DONE WHEN:** for each greedy problem you can say why no later choice can beat the current one.

#### Day 26: CHECKPOINT 3 (Mock Day)
**GOAL:** Learn how you behave when the clock is real.
- One **virtual LeetCode weekly contest** (4 problems, 90 minutes), from a recent past round.
- Re-solve everything on the Weak List.
- Post-mortem, in writing: where did the time go? Reading, pattern spotting, implementation, debugging?
- **DONE WHEN:** you have a one-paragraph diagnosis of your weakest habit under time pressure.

#### Day 27: The Blind Set
**GOAL:** Prove pattern recognition works without hints.
- 12 mediums, no topic tags (use a shuffled list or LeetCode's random pick).
- Before any code, write the pattern in one line. 35-minute cap each.
- Score yourself: pattern guessed right / solved / failed.
- **DONE WHEN:** at least 9 of 12 patterns guessed correctly.

#### Day 28: Consolidate + Decide
**GOAL:** Walk out with a one-page pattern note and a verdict.
- Finalize the one-page cheat sheet (clue, pattern, template).
- Redo 5 Weak List problems one last time.
- Update the Radar, Dashboard, and write the final retro (Section 10).
- **Verdict (based on Day 27):**
  - Below 70% patterns guessed → one more week of mixed mediums before moving on.
  - 70% or above → Phase 2 (Section 12).

---

## 7. Template Vault (C++)

Rewrite each from memory twice. Copying is how you lose them.

**Standard headers**
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <climits>
using namespace std;
```

**Binary search on the answer (minimize the maximum)**
```cpp
int low = lowestPossible, high = highestPossible;
while (low < high) {
    int mid = low + (high - low) / 2;
    if (canDo(mid)) high = mid;
    else low = mid + 1;
}
return low;
```

**Variable sliding window**
```cpp
int left = 0, best = 0;
for (int right = 0; right < (int)nums.size(); right++) {
    // add nums[right] to the window state
    while (/* window is invalid */) {
        // remove nums[left] from the window state
        left++;
    }
    best = max(best, right - left + 1);
}
```

**Prefix sum + hash map (subarray sum equals K)**
```cpp
unordered_map<int, int> seen;
seen[0] = 1;
int runningSum = 0, count = 0;
for (int value : nums) {
    runningSum += value;
    if (seen.count(runningSum - k)) count += seen[runningSum - k];
    seen[runningSum]++;
}
```

**Monotonic stack (next greater element)**
```cpp
vector<int> answer(n, -1);
stack<int> indexStack;
for (int i = 0; i < n; i++) {
    while (!indexStack.empty() && nums[indexStack.top()] < nums[i]) {
        answer[indexStack.top()] = nums[i];
        indexStack.pop();
    }
    indexStack.push(i);
}
```

**Backtracking skeleton (subsets)**
```cpp
void explore(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);
    for (int i = start; i < (int)nums.size(); i++) {
        current.push_back(nums[i]);
        explore(i + 1, nums, current, result);
        current.pop_back();
    }
}
```

**DP skeleton (0/1 knapsack, 1D)**
```cpp
vector<int> dp(capacity + 1, 0);
for (int i = 0; i < n; i++) {
    for (int w = capacity; w >= weight[i]; w--) {
        dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
    }
}
```

**Top K with a heap (K largest, min-heap of size K)**
```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
for (int value : nums) {
    minHeap.push(value);
    if ((int)minHeap.size() > k) minHeap.pop();
}
// minHeap.top() is the K-th largest
```

**BFS on a grid (multi-source friendly)**
```cpp
queue<pair<int, int>> bfsQueue;
// push all sources first, mark visited
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
while (!bfsQueue.empty()) {
    pair<int, int> cell = bfsQueue.front();
    bfsQueue.pop();
    for (int d = 0; d < 4; d++) {
        int nr = cell.first + dr[d], nc = cell.second + dc[d];
        if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
        // skip if visited or blocked, else mark and push
    }
}
```

**Topological sort (Kahn's)**
```cpp
vector<int> indegree(n, 0), order;
// build adjacency list graph[u] = {v...}, count indegree
queue<int> ready;
for (int i = 0; i < n; i++) if (indegree[i] == 0) ready.push(i);
while (!ready.empty()) {
    int node = ready.front();
    ready.pop();
    order.push_back(node);
    for (int next : graph[node]) {
        if (--indegree[next] == 0) ready.push(next);
    }
}
// if order.size() != n, there is a cycle
```

**Dijkstra**
```cpp
vector<long long> dist(n, LLONG_MAX);
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
dist[source] = 0;
pq.push({0, source});
while (!pq.empty()) {
    pair<long long, int> top = pq.top();
    pq.pop();
    long long d = top.first;
    int node = top.second;
    if (d > dist[node]) continue;
    for (pair<int, int> edge : graph[node]) {
        int next = edge.first, weight = edge.second;
        if (dist[node] + weight < dist[next]) {
            dist[next] = dist[node] + weight;
            pq.push({dist[next], next});
        }
    }
}
```

**DSU**
```cpp
struct DSU {
    vector<int> parent, sz;
    DSU(int n) : parent(n), sz(n, 1) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};
```

---

## 8. Mistake Log + Weak List

| Problem | Date | What went wrong | Root cause (pattern missed? edge case? syntax?) | Re-solve date | Fixed? |
|---|---|---|---|---|---|
| | | | | | |

- **Weak List** = anything failed twice. It rotates into every REVISE block until it stops failing.
- Root-cause categories to tag: *pattern not recognized*, *wrong template*, *off-by-one*, *edge case*, *time complexity*, *careless bug*.
- On each checkpoint, count the tags. The most common one is your real enemy.

---

## 9. Note Format (pointwise, five lines)

```
Problem: <number + name>
Pattern: <one line>
Key idea: <why this pattern fits>
Trap: <the bug or edge case that caught me>
Complexity: <time / space>
```

---

## 10. Weekly Retro (every Sunday, 10 minutes)

- What did I solve cleanly this week?
- Which pattern still feels shaky?
- What was my most common mistake tag?
- Did I actually follow the Contract? Which promise did I bend?
- One adjustment for next week (just one).

---

## 11. Spaced Revision

| When | What |
|---|---|
| Same day | Rewrite the solution from a blank file |
| +1 day | Reread the note |
| +3 days | Re-solve if it is in the Mistake Log |
| +7 days | Re-solve, timed |
| Each checkpoint | Entire Weak List, no peeking |

---

## 12. After Day 28 (Phase 2)

Honest priorities, no padding.

- **MUST DO:** Hards in DP and graphs, 3-4 a week. This is where OAs separate people.
- **MUST DO:** Weekly timed contests (LeetCode weekly/biweekly), as a standing habit.
- **SHOULD DO:** Company-tagged problem sets for the companies visiting your campus.
- **SHOULD DO:** Core CS (OOP, DBMS, OS, CN, SQL) in a parallel 30-45 minute slot, three days a week.
- **SHOULD DO:** Aptitude/quant practice for OA rounds.
- **NICE TO HAVE:** Segment trees, Fenwick trees, advanced DP (bitmask, digit DP).
- **SKIP for now:** System design and LLD until DSA is steady.

---

## 13. Skip List (honest calls)

If you fall behind, cut from here first. Never cut REVISE.

- 355 Design Twitter (design-heavy, low pattern value)
- 622 Design Circular Queue
- 297 Serialize and Deserialize Binary Tree (valuable, but cut on a crunch week)
- 1202 Smallest String With Swaps
- Any STRETCH problem on a day you are behind

---

## 14. What this plan will not do

- It will not make you fast. Speed comes from volume and timed practice after the patterns are in your hands.
- It will not replace understanding. If you ticked a box without being able to explain the solution, it does not count.
- It will not cover everything. It covers the patterns that show up most in campus rounds. That is the point.

*The video was the introduction. The 28 days are the education.*
