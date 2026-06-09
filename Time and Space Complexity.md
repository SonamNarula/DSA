# ⏱️ Time & Space Complexity — Interview-Ready Deep Notes

---

## PART 1 — FOUNDATIONS

---

### What is Complexity Analysis?

Complexity analysis is how we measure the **efficiency of an algorithm** — how its runtime and memory usage **scale** as the input grows. The goal is NOT to measure exact time in seconds (that depends on hardware, compiler, language) — instead, we measure how the algorithm **behaves as n → ∞**.

Two dimensions we always analyze:

- **Time Complexity** — How many operations does the algorithm perform relative to input size?
- **Space Complexity** — How much memory does it consume relative to input size?

**n** = size of input. For an array of 1000 elements, n = 1000.

---

### Why Not Just Benchmark?

Real timing varies based on CPU speed, OS scheduling, caching, language overhead. Two machines running the same code get different times. Complexity gives a **machine-independent, mathematically rigorous** measure. That's why it's universally used.

---

## PART 2 — ASYMPTOTIC NOTATIONS

These are the mathematical tools for expressing complexity. Interview me puchhte hain "what does Big O mean" — yeh sab clear hona chahiye.

---

### Big O — O(f(n)) → Upper Bound (Worst Case)

This is the most commonly used notation in interviews. It answers: **"In the worst case, how bad can it get?"**

Formally: T(n) = O(f(n)) means there exist constants c > 0 and n₀ such that T(n) ≤ c · f(n) for all n ≥ n₀.

In plain English: After a certain input size, your algorithm's runtime never grows faster than c × f(n). Big O gives a **guarantee ceiling**.

Example: If an algorithm does 3n² + 5n + 7 operations, we say O(n²) because n² is the dominant term that dictates growth.

**Why we drop constants and lower terms:** Because for large n, constants become irrelevant. 3n² vs n² — for n = 1,000,000, both are so large that the constant 3 is negligible compared to the difference between n² and n³. We care about the **shape of growth**, not the multiplier.

---

### Big Omega — Ω(f(n)) → Lower Bound (Best Case)

T(n) = Ω(f(n)) means the algorithm takes **at least** f(n) time. This is the best case floor.

Example: Linear search on an array is Ω(1) — if the element is the first one, you're done in 1 step.

---

### Big Theta — Θ(f(n)) → Tight Bound (Average Case)

T(n) = Θ(f(n)) means the algorithm is **both** O(f(n)) AND Ω(f(n)). The runtime grows exactly as fast as f(n), neither faster nor slower, asymptotically.

Example: Merge Sort is always Θ(n log n) — it takes n log n in best, average, AND worst case. There's no escape.

---

### Interview Trap: "Is Big O always worst case?"

**No.** Big O is an upper bound notation — it CAN be applied to best, average, or worst case. When people say "time complexity is O(n log n)" they're typically referring to worst case Big O. But technically, saying "binary search is O(log n)" is using Big O to describe the worst case scenario. Big O is the notation — worst/best/average is the scenario. These are two different dimensions.

---

### Little o and Little Omega (Less common in interviews but good to know)

Little o — f(n) = o(g(n)) means f grows **strictly slower** than g. Like O but not tight. f(n) / g(n) → 0 as n → ∞.

Little omega — f(n) = ω(g(n)) means f grows **strictly faster** than g.

---

## PART 3 — ORDER OF GROWTH (Most Important)

From fastest to slowest (best to worst for algorithms):

O(1) < O(log log n) < O(log n) < O(√n) < O(n) < O(n log n) < O(n²) < O(n³) < O(2ⁿ) < O(n!)

---

### O(1) — Constant Time

**Does not change with input size.** No matter if n = 10 or n = 10,000,000, the number of operations stays fixed.

Real examples: Array index access arr[i], HashMap get/put (average), Stack push/pop, checking first/last element, arithmetic operations.

Space-wise: An algorithm that uses 3 variables regardless of input is O(1) space.

---

### O(log n) — Logarithmic

**Every step eliminates a fraction of remaining work.** Almost always seen when input is halved each step. log n usually means log base 2 in CS.

Intuition: log₂(1,000,000) ≈ 20. So for a million elements, you only need ~20 steps. Extremely efficient.

Real examples: Binary search, searching in a balanced BST, finding an element in a sorted array, power function with repeated squaring, operations on heaps (percolate up/down).

Interview question: "Why is binary search O(log n)?" — Because each comparison halves the search space. After k comparisons, remaining space = n / 2^k. When n / 2^k = 1, we're done. Solve for k: k = log₂(n).

---

### O(√n) — Square Root

Seen in algorithms like the Sieve of Eratosthenes (inner loop runs √n times), jump search, and checking if a number is prime by testing divisors up to √n.

---

### O(n) — Linear

**Must look at every element at least once.** The work grows proportionally with input.

Real examples: Linear search, traversing a linked list, finding max/min in unsorted array, single pass string operations, BFS/DFS graph traversal is O(V + E).

---

### O(n log n) — Linearithmic

**Divide-and-conquer pattern.** You split into n chunks and do log n work per chunk, or do n work at log n levels.

Real examples: Merge sort, heap sort, quick sort (average), FFT. This is the **theoretical lower bound for comparison-based sorting** — you cannot sort by comparisons faster than O(n log n) in the worst case.

Why can't comparison sorts beat O(n log n)? There are n! possible orderings of n elements. A comparison-based sort is a decision tree with at least n! leaves. The height of a binary tree with n! leaves is at least log₂(n!) = Θ(n log n) by Stirling's approximation.

---

### O(n²) — Quadratic

**Nested iteration over the input.** For every element, you iterate over all elements again.

Real examples: Bubble sort, selection sort, insertion sort (worst case), checking all pairs in an array, naive string matching, generating all pairs.

---

### O(n³) — Cubic

Triple nested loops. Floyd-Warshall shortest path (all pairs), naive matrix multiplication.

---

### O(2ⁿ) — Exponential

**Doubles with each additional element.** Each recursive call often branches into two more.

Real examples: Generating all subsets of a set (there are 2ⁿ subsets), naive recursive Fibonacci, solving Tower of Hanoi, brute-force traveling salesman.

---

### O(n!) — Factorial

**Generating all permutations.** N! grows astronomically. For n = 20, that's 2.4 quintillion operations. Only feasible for very small inputs.

Real examples: Brute-force TSP, generating all permutations.

---

## PART 4 — HOW TO CALCULATE TIME COMPLEXITY

This is where most interview mistakes happen. Let's build a systematic approach.

---

### Rule 1: Drop Constants

5n operations = O(n). 1000n = O(n). Constants don't determine growth shape.

---

### Rule 2: Drop Lower Order Terms

n² + n + 1 = O(n²). For large n, n² dominates completely. n = 1000: n² = 1,000,000, n = 1,000. The n term is 0.1% of n². Negligible.

---

### Rule 3: Addition Rule (Sequential operations)

If algorithm does work A then work B: Total = O(A) + O(B) = O(max(A, B))

Example: A loop of n iterations followed by a loop of n² iterations = O(n) + O(n²) = O(n²)

---

### Rule 4: Multiplication Rule (Nested operations)

If for each iteration of outer loop, you do inner loop: O(outer) × O(inner)

Example: Outer loop n times, inner loop n times = O(n × n) = O(n²)
Outer loop n times, inner loop log n times = O(n log n)

---

### Analyzing Loops — The Core Skill

**Single loop running n times:** O(n)

**Loop that doubles/halves the counter each iteration:** i starts at 1, multiplied by 2 each time (i=1,2,4,8...) — runs log n times → O(log n)

**Nested loop both running n times:** O(n²)

**Loop inside loop where inner depends on outer:**
Outer i from 0 to n, inner j from 0 to i → runs n + (n-1) + (n-2) + ... + 1 = n(n+1)/2 = O(n²)

**Be careful:** Just because there are 2 loops doesn't always mean O(n²). If they're sequential (not nested), it's O(n) + O(n) = O(n).

---

### Analyzing Recursion — Recurrence Relations

For recursive algorithms, write a recurrence relation and solve it.

**T(n) = work done at current level + work delegated to recursive calls**

Example: Binary search → T(n) = T(n/2) + O(1)
At each level, you do O(1) work and recurse on half the input.
Solving: T(n) = O(log n)

Example: Merge sort → T(n) = 2T(n/2) + O(n)
Split into 2 halves, recurse on each, merge takes O(n).
Solving: T(n) = O(n log n)

---

### The Master Theorem

For recurrences of form T(n) = a·T(n/b) + f(n):
- a = number of recursive calls
- b = factor by which input shrinks
- f(n) = work done outside recursive calls

Let critical exponent c = log_b(a)

**Case 1:** If f(n) = O(n^(c-ε)) for some ε > 0 → T(n) = Θ(n^c)
(Recursion dominates)

**Case 2:** If f(n) = Θ(n^c · log^k(n)) → T(n) = Θ(n^c · log^(k+1)(n))
(Both contribute equally)

**Case 3:** If f(n) = Ω(n^(c+ε)) and regularity condition holds → T(n) = Θ(f(n))
(Work outside recursion dominates)

**Quick examples:**
- T(n) = 2T(n/2) + n → a=2, b=2, c=log₂2=1, f(n)=n=n¹ → Case 2 → O(n log n) [Merge sort]
- T(n) = 4T(n/2) + n → a=4, b=2, c=log₂4=2, f(n)=n < n² → Case 1 → O(n²)
- T(n) = T(n/2) + 1 → a=1, b=2, c=0, f(n)=1=n⁰ → Case 2 → O(log n) [Binary search]

---

## PART 5 — SPACE COMPLEXITY

---

### What Counts as Space?

Everything your algorithm allocates in memory:
- Variables (int, bool, etc.) — O(1) each
- Arrays, lists, matrices
- Recursion call stack (very important!)
- Hash maps, sets, queues created during execution
- Output arrays (sometimes counted separately)

---

### Auxiliary Space vs Total Space Complexity

**Auxiliary space** = Extra space used by the algorithm, NOT counting the input itself.

**Total space complexity** = Auxiliary space + Input space.

In interviews, when someone says "space complexity is O(1)", they usually mean **auxiliary space is O(1)** — the algorithm is in-place and doesn't allocate extra memory proportional to n.

Example: Merge sort — input is size n. We create temporary arrays of total size n for merging. Auxiliary space = O(n). Total space = O(n) + O(n) = O(n).

---

### Recursion Stack Space — CRITICAL

Every recursive call adds a frame to the call stack. Each frame stores local variables, parameters, return address.

**Depth of recursion** = O(stack space)

Binary search (iterative) → O(1) space
Binary search (recursive) → O(log n) space (log n stack frames)
Recursive Fibonacci → O(n) space (n stack frames in worst case)
Merge sort → O(log n) recursion depth, but O(n) for temp arrays → O(n) total
DFS on a graph → O(V) stack space in worst case (for a linear chain graph)

This is a common interview question: "What's the space complexity of recursive DFS?" — O(V) for the call stack.

---

### In-Place Algorithms

An algorithm is **in-place** if it uses O(1) auxiliary space. It modifies the input directly without creating proportional extra data structures.

In-place sorts: Bubble sort, Selection sort, Insertion sort, Heap sort, Quick sort
NOT in-place: Merge sort (creates temp arrays), Counting sort (creates count array)

---

## PART 6 — DATA STRUCTURE COMPLEXITIES (Interview Gold)

---

### Arrays

**Access by index:** O(1) — Direct memory address calculation: base_address + index × element_size

**Search (unsorted):** O(n) — Must check every element

**Search (sorted):** O(log n) with binary search

**Insert at end (no resize):** O(1)

**Insert at beginning or middle:** O(n) — Must shift all subsequent elements right

**Delete at end:** O(1)

**Delete at beginning or middle:** O(n) — Must shift all subsequent elements left

**Space:** O(n)

Interview insight: Array deletion doesn't free memory in most implementations — it shifts elements. True memory deallocation depends on language and implementation.

---

### Dynamic Arrays (ArrayList / Python List / C++ vector)

Same as array for most operations, BUT:

**Amortized insert at end:** O(1) — This is the important one!

When the array is full, it doubles in capacity. This copy costs O(n). But it happens so rarely that when you amortize (spread) the cost over all insertions, each insertion costs O(1) amortized.

Proof: For n insertions total, copies happen at sizes 1, 2, 4, 8, ..., n. Total copy cost = 1+2+4+...+n = 2n-1 = O(n). Spread over n insertions: O(1) per insertion.

**Space:** O(n), but may have up to 2× allocated space due to doubling strategy.

---

### Singly Linked List

**Access by index:** O(n) — Must traverse from head

**Search:** O(n)

**Insert at head (prepend):** O(1) — Just update pointers

**Insert at tail:** O(n) if no tail pointer, O(1) if tail pointer maintained

**Insert in middle (given node reference):** O(1) — Just update pointers

**Delete at head:** O(1)

**Delete at tail:** O(n) — Must find second-to-last node (no backward pointer)

**Delete given node reference:** O(1) with a trick — copy next node's data into current, delete next node. But strictly speaking, without predecessor reference, O(n) to find predecessor.

**Space:** O(n) for data + O(n) for pointers

---

### Doubly Linked List

Same as singly, except:

**Delete at tail:** O(1) — Has previous pointer, no traversal needed

**Delete given node reference:** O(1) — Use prev pointer to relink

Extra space: O(n) for prev pointers on top of singly list.

---

### Stack (Array or LL backed)

**Push:** O(1)
**Pop:** O(1)
**Peek (top):** O(1)
**Search:** O(n)
**Space:** O(n)

All primary operations are O(1). This is what makes stacks powerful for things like balanced parentheses, undo operations, DFS.

---

### Queue (Array circular or LL backed)

**Enqueue:** O(1)
**Dequeue:** O(1)
**Peek (front):** O(1)
**Search:** O(n)
**Space:** O(n)

---

### Hash Table / HashMap / HashSet

This is one of the most important data structures for interviews.

**Average case (good hash function, low load factor):**
- Insert: O(1)
- Delete: O(1)
- Search/Get: O(1)

**Worst case (all keys hash to same bucket — collision):**
- Insert: O(n)
- Delete: O(n)
- Search: O(n)

**Load factor (λ) = n / m** where n = number of keys, m = number of buckets

When load factor exceeds threshold (typically 0.75 in Java), the hash table **rehashes** — creates new larger table and reinserts all elements. Rehashing costs O(n) but happens rarely, so amortized insert is still O(1).

**Collision resolution strategies:**
1. Chaining (each bucket is a linked list) — worst case all keys in one chain → O(n)
2. Open addressing (linear probing, quadratic probing, double hashing) — worst case full scan → O(n)

Interview question: "Why is HashMap O(1) but can be O(n)?" — Because hash functions can produce the same bucket for multiple keys. In worst case (adversarial input or terrible hash function), all n keys collide into one bucket, making operations O(n). In practice with good hash functions, distribution is uniform and it's O(1).

Space: O(n) for stored elements + overhead for empty buckets.

---

### Binary Search Tree (BST)

A BST maintains: left subtree values < node value < right subtree values.

**Balanced BST (AVL, Red-Black):**
- Search: O(log n)
- Insert: O(log n)
- Delete: O(log n)
- Space: O(n)

**Unbalanced BST (degenerate / skewed):**
- In the worst case, you insert sorted elements: 1, 2, 3, 4, 5... Each new node becomes the right child of the previous. The tree becomes a linked list.
- Search: O(n)
- Insert: O(n)
- Delete: O(n)

**Why balanced BSTs exist:** To guarantee O(log n) operations by ensuring height stays O(log n).

A balanced BST with n nodes has height Θ(log n). Operations that traverse root-to-leaf cost O(height) = O(log n).

---

### AVL Tree

Self-balancing BST. Maintains the AVL property: for every node, heights of left and right subtrees differ by at most 1.

- Search: O(log n) — always
- Insert: O(log n) — insert + at most O(log n) rotations to rebalance
- Delete: O(log n) — delete + O(log n) rotations
- Height: strictly Θ(log n)

Rotations: Single left, single right, left-right, right-left. Each rotation is O(1) — just pointer manipulation.

AVL vs Red-Black: AVL is more strictly balanced → faster lookups. Red-Black allows more imbalance → fewer rotations on insert/delete → faster writes. Red-Black used in Java TreeMap, C++ std::map.

---

### Red-Black Tree

5 properties that maintain approximate balance:
1. Every node is red or black
2. Root is black
3. Leaves (nil nodes) are black
4. Red node's children must be black (no two consecutive reds)
5. All paths from any node to its descendant nil nodes have same number of black nodes

Height: at most 2 log(n+1) — guaranteed O(log n)

All operations: O(log n)

---

### Heap (Binary Heap)

A complete binary tree (all levels filled except possibly last, filled left to right) stored as an array.

Min-heap: Parent ≤ children. Root = minimum element.
Max-heap: Parent ≥ children. Root = maximum element.

**Get min/max:** O(1) — always at root (index 0)

**Insert:** O(log n) — Add at end, bubble up (sift up) until heap property restored. Traverses at most log n levels.

**Extract min/max:** O(log n) — Remove root, put last element at root, sift down. Traverses at most log n levels.

**Delete arbitrary element:** O(log n) — Decrease key to -∞, then extract min. Or find element O(n) + sift O(log n) = O(n).

**Build heap from array (Heapify):** O(n) — NOT O(n log n) as commonly thought!
Starting from last non-leaf and sifting down each node: sum of sift-down costs at each level = O(n). This is the Floyd's algorithm proof.

**Heap sort:** O(n log n) time, O(1) space (in-place). Build max-heap O(n), then extract max n times each O(log n) → n log n total.

**Array representation:** For node at index i → left child at 2i+1, right child at 2i+2, parent at ⌊(i-1)/2⌋.

---

### Trie (Prefix Tree)

Each node represents a character. Path from root to node = prefix of some string.

**Insert:** O(L) where L = length of string
**Search:** O(L)
**Delete:** O(L)
**Prefix search / autocomplete:** O(P + n) where P = prefix length, n = results

Space: O(total characters across all strings × alphabet size) — can be large if using array nodes with alphabet-size arrays. Compressed tries (Patricia tries) save space.

Interview question: "When would you use a Trie over a HashMap?" — When you need prefix operations (autocomplete, spell check), longest common prefix, pattern matching. HashMap gives exact match in O(1) but can't handle prefix queries efficiently.

---

### Graph Representations and Complexity

**Adjacency Matrix:**
- Space: O(V²) — always, even for sparse graphs
- Check if edge (u,v) exists: O(1)
- Find all neighbors of vertex v: O(V)
- Add edge: O(1)
- Delete edge: O(1)
Best for: Dense graphs (many edges), frequent edge lookup

**Adjacency List:**
- Space: O(V + E)
- Check if edge (u,v) exists: O(degree(v))
- Find all neighbors of vertex v: O(degree(v))
- Add edge: O(1)
- Delete edge: O(degree(v))
Best for: Sparse graphs (few edges), traversal-heavy algorithms

**BFS:** O(V + E) time, O(V) space for queue + visited array
**DFS:** O(V + E) time, O(V) space for stack (implicit recursion stack or explicit)

---

## PART 7 — SORTING ALGORITHMS (Must Know for Interviews)

---

### Bubble Sort
Repeatedly swap adjacent elements if out of order. Bubbles largest element to end each pass.

Time: Best O(n) [already sorted with optimization], Average O(n²), Worst O(n²)
Space: O(1) auxiliary (in-place)
Stable: Yes

---

### Selection Sort
Find minimum element, place at beginning. Repeat for remaining.

Time: Best O(n²), Average O(n²), Worst O(n²) — always n² regardless
Space: O(1) auxiliary (in-place)
Stable: No (in standard implementation)

Why always O(n²)? Even if array is sorted, it still scans for minimum each pass.

---

### Insertion Sort
Build sorted portion one element at a time. Insert each element into its correct position.

Time: Best O(n) [already sorted], Average O(n²), Worst O(n²) [reverse sorted]
Space: O(1) auxiliary (in-place)
Stable: Yes

Best for small arrays or nearly-sorted data. Used as base case in Timsort and Introsort.

---

### Merge Sort
Divide array into two halves, recursively sort both, merge the sorted halves.

Time: Best O(n log n), Average O(n log n), Worst O(n log n) — ALWAYS n log n
Space: O(n) auxiliary (temp arrays for merging)
Stable: Yes

Why O(n log n)? Recursion depth = log n. At each level, merging costs O(n) total across all merges. Total = n log n.

Why O(n) space? The merge step needs temp array of size n. Though recursion depth is O(log n) for stack frames, the dominant cost is the temp array.

Guaranteed O(n log n) makes it preferred when worst-case matters. Java's Arrays.sort for objects uses merge sort (specifically Timsort).

---

### Quick Sort
Choose pivot, partition array (elements less than pivot left, greater right), recursively sort partitions.

Time: Best O(n log n), Average O(n log n), Worst O(n²)
Space: O(log n) average [recursion stack], O(n) worst case
Stable: No (standard implementation)

**Worst case:** O(n²) when pivot is always smallest or largest element (sorted/reverse-sorted input with naive pivot selection). Creates n-1 levels of recursion, each doing O(n) work.

**Why average is O(n log n):** If pivot splits array roughly in half each time, you get balanced recursion tree of depth log n with O(n) work per level.

**Pivot strategies to avoid worst case:**
- Random pivot: reduces probability of worst case to near zero
- Median of three: take first, middle, last elements; use their median as pivot
- Introsort: switches to Heapsort when recursion depth exceeds threshold (used in C++ STL)

**Quick sort vs Merge sort:** Quick sort is faster in practice (better cache behavior, in-place, smaller constant factors) even though both O(n log n) average. But merge sort is preferred when: stability needed, worst-case guarantee needed, or sorting linked lists (merge sort doesn't need random access).

---

### Heap Sort
Build max-heap, repeatedly extract max to end of array.

Time: Best O(n log n), Average O(n log n), Worst O(n log n) — always n log n
Space: O(1) auxiliary (in-place)
Stable: No

Why O(1) space? We use the input array itself as the heap. No extra allocation.

Why not faster than merge sort in practice? Poor cache performance — heap operations jump around memory. Memory locality suffers.

---

### Counting Sort
Count occurrences of each value, reconstruct sorted array from counts.

Time: O(n + k) where k = range of values (max - min)
Space: O(k) for count array
Stable: Yes (with care in implementation)

Limitation: Only works for integers (or items with integer keys). If k >> n, becomes worse than comparison sorts.

---

### Radix Sort
Sort by individual digits, from least significant to most significant (LSD) or most to least (MSD). Uses stable sort (counting sort) at each digit level.

Time: O(d × (n + k)) where d = number of digits, k = digit range (0-9, so k=10)
= O(d × n) practically
Space: O(n + k)
Stable: Yes

For fixed-width integers (32-bit), d is constant → O(n). Can beat O(n log n) comparison sorts!

---

### Timsort (Python's sorted(), Java's Arrays.sort for primitives)

Hybrid of merge sort and insertion sort. Finds natural runs (already sorted sequences), pads small runs with insertion sort to minimum run length, then merges runs.

Time: Best O(n) [already sorted], Average O(n log n), Worst O(n log n)
Space: O(n)
Stable: Yes

This is why Python list.sort() and sorted() are so fast on real-world data — they exploit existing structure.

---

### Comparison-Based Sorting Lower Bound

**You CANNOT sort by comparisons faster than O(n log n) in the worst case.** This is a mathematical theorem, not just an observation.

Proof sketch: There are n! possible orderings of n elements. A comparison-based sort is a decision tree where each internal node is a comparison and each leaf is a sorted order. The tree must have ≥ n! leaves. A binary tree with L leaves has height ≥ log₂(L). So height ≥ log₂(n!) = Θ(n log n) by Stirling's approximation.

Non-comparison sorts (Counting, Radix, Bucket) can beat this because they don't rely solely on comparisons — they exploit structure of the data.

---

## PART 8 — SEARCHING ALGORITHMS

---

### Linear Search
Check every element sequentially.

Time: Best O(1), Average O(n), Worst O(n)
Space: O(1)
Works on: Unsorted arrays, linked lists, any traversable structure

---

### Binary Search
On SORTED array only. Compare with middle element, eliminate half the search space.

Time: Best O(1), Average O(log n), Worst O(log n)
Space: O(1) iterative, O(log n) recursive [call stack]

Why sorted? Because we make the assumption "if target < middle, it must be in the left half." This assumption only holds if array is sorted.

Variants: Lower bound (first occurrence), upper bound (last occurrence), peak finding, search in rotated sorted array — all O(log n).

---

## PART 9 — GRAPH ALGORITHMS

---

### BFS (Breadth-First Search)
Explores level by level using a queue.

Time: O(V + E) — visits each vertex once (V) and processes each edge once (E)
Space: O(V) — queue can hold all vertices in worst case, plus visited array

Applications: Shortest path in unweighted graph, level-order traversal, finding connected components, checking bipartiteness.

---

### DFS (Depth-First Search)
Explores as deep as possible before backtracking.

Time: O(V + E)
Space: O(V) — recursion stack depth equals height of DFS tree, O(V) worst case

Applications: Detecting cycles, topological sort, finding SCCs (Tarjan's), path finding, maze solving.

---

### Dijkstra's Shortest Path
Single-source shortest path for non-negative weighted graphs.

With min-heap: O((V + E) log V)
With Fibonacci heap: O(E + V log V)
With simple array: O(V²)

Space: O(V)

Why doesn't it work with negative weights? The greedy assumption "once a node is extracted from the min-heap, its distance is finalized" fails. A negative edge discovered later could offer a shorter path to an already-processed node.

---

### Bellman-Ford
Single-source shortest path, handles negative weights (but not negative cycles).

Time: O(V × E)
Space: O(V)

Can detect negative cycles: If after V-1 relaxation passes, you can still relax an edge, a negative cycle exists.

---

### Floyd-Warshall
All-pairs shortest paths.

Time: O(V³)
Space: O(V²) for distance matrix

Uses dynamic programming. dp[i][j][k] = shortest path from i to j using only nodes 1...k as intermediates.

---

### Topological Sort (Kahn's Algorithm or DFS-based)
Linear ordering of DAG vertices such that every edge goes from earlier to later in the ordering.

Time: O(V + E)
Space: O(V)

Only defined for DAGs (directed acyclic graphs). If graph has a cycle, topological sort is impossible.

---

### Prim's MST
Greedy algorithm. Grow MST one edge at a time, always adding minimum weight edge connecting tree to non-tree vertex.

Time: O(E log V) with binary heap, O(V²) with simple array (better for dense graphs)
Space: O(V)

---

### Kruskal's MST
Sort all edges by weight, add edge to MST if it doesn't create a cycle. Uses Union-Find.

Time: O(E log E) = O(E log V) for sorting
Space: O(V) for Union-Find

---

## PART 10 — AMORTIZED COMPLEXITY

Amortized analysis spreads the cost of expensive occasional operations over many cheap operations, giving a more accurate picture of per-operation average cost.

---

### Dynamic Array (ArrayList) — Amortized O(1) Append

Each append is O(1) usually. When full, doubles capacity and copies all elements → O(n) copy. But this doubling halves in frequency as array grows.

Total cost for n appends: n (appends) + 1+2+4+...+n (copies) = n + 2n - 1 = O(n)
Per operation amortized: O(n) / n = O(1)

This is the "banker's method" intuition: Each O(1) append "saves up" 2 credits. When resize happens, those saved credits pay for the copy.

---

### Union-Find (Disjoint Set Union) with Path Compression + Union by Rank

Operations: Find (which set does element belong to?) and Union (merge two sets).

Without optimization: O(n) per operation worst case.
With path compression + union by rank: O(α(n)) amortized where α is the inverse Ackermann function. For all practical n (even 10^80), α(n) ≤ 5. Effectively O(1) amortized.

---

## PART 11 — COMMON INTERVIEW QUESTIONS & TRAPS

---

**Q: "What's the worst case for a HashMap get operation?"**
A: O(n). If all n keys hash to the same bucket (adversarial input or poor hash function), the bucket's chain has n elements and searching it is O(n). This is why Java 8+ converts chains to red-black trees when they exceed 8 elements — improving worst case chain search from O(n) to O(log n).

**Q: "Why is heapsort O(1) space but merge sort O(n)?"**
A: Heapsort operates entirely within the input array — it heapifies in-place and sorts by swapping. Merge sort requires additional temp arrays during the merge step because you can't merge two portions of an array into the same array without overwriting elements you still need.

**Q: "Is QuickSort always better than MergeSort?"**
A: No. QuickSort's O(n²) worst case is a real vulnerability (triggered by sorted/reverse-sorted input with naive pivot). MergeSort guarantees O(n log n). For stability requirements, MergeSort wins. For external sorting (data too large for RAM), MergeSort is standard. For in-memory sorting where stability doesn't matter, QuickSort's cache efficiency often wins in practice.

**Q: "What's the space complexity of recursive Fibonacci?"**
A: O(n) time is obvious (exponential 2ⁿ calls), but space is O(n) because the call stack depth is at most n frames at any one time (though 2ⁿ total calls happen, they don't all exist simultaneously).

**Q: "Binary search on a linked list — is it O(log n)?"**
A: No. Binary search requires O(1) random access (index arithmetic). Linked list access is O(n). Finding the midpoint of a linked list itself takes O(n). So binary search on a linked list is O(n log n) — worse than linear search O(n)! This is why linked lists don't benefit from binary search.

**Q: "Can you sort in O(n)?"**
A: Yes, but only under constraints. Comparison sorts have Ω(n log n) lower bound. Non-comparison sorts like Counting Sort O(n+k) and Radix Sort O(dn) can achieve O(n) when k (range) or d (digits) is O(1) or small relative to n.

**Q: "What's the time complexity of finding the kth smallest element?"**
A: Multiple approaches — Sort and index: O(n log n). Min-heap of size k: O(n log k). QuickSelect (randomized): O(n) average, O(n²) worst. Median of medians (deterministic): O(n) guaranteed worst case.

**Q: "Why does BFS find shortest path in unweighted graphs but not DFS?"**
A: BFS explores layer by layer — all nodes at distance d before any node at distance d+1. The first time BFS reaches a node, it must have taken the shortest path. DFS dives deep and might reach a node via a long path before a shorter one.

**Q: "HashMap vs TreeMap — when to use which?"**
A: HashMap: O(1) average get/put, O(n) worst. TreeMap: O(log n) for all operations, maintains sorted order. Use TreeMap when you need range queries, floor/ceiling operations, or sorted iteration. Use HashMap for pure key-value storage where order doesn't matter.

**Q: "What's the complexity of deleting a node from BST?"**
A: O(log n) for balanced BST, O(n) for unbalanced. Three cases: leaf node (just delete), node with one child (replace with child), node with two children (find in-order successor/predecessor, replace, delete successor). The in-order successor find traverses O(height) levels.

**Q: "Stack vs recursion — are they the same?"**
A: Yes in terms of functionality. Recursion uses the system call stack implicitly. An iterative DFS using an explicit stack is equivalent to recursive DFS. Converting recursion to iteration with a stack eliminates the risk of stack overflow for deep recursion.

**Q: "What is the complexity of building a heap?"**
A: O(n), not O(n log n) as most people intuitively think. Using Floyd's algorithm (sift down from last non-leaf): nodes at height h contribute O(h) work each. Summing across all heights: Σ (n/2^h × h) for h from 0 to log n = O(n). This is why we say "heapify is O(n)".

**Q: "Why is the complexity of searching in a trie O(L) and not O(n)?"**
A: In a trie, search depends on the **length of the search string L**, not the number of strings n in the trie. Each character traverses one edge, independent of how many other strings are stored. This is the power of tries — lookup is O(L) regardless of dictionary size.

---

## PART 12 — QUICK REFERENCE TABLE

---

### Data Structures

| Structure       | Access   | Search   | Insert   | Delete   | Space |
|----------------|----------|----------|----------|----------|-------|
| Array           | O(1)     | O(n)     | O(n)     | O(n)     | O(n)  |
| Dynamic Array   | O(1)     | O(n)     | O(1) am. | O(n)     | O(n)  |
| Singly LL       | O(n)     | O(n)     | O(1)*    | O(n)*    | O(n)  |
| Doubly LL       | O(n)     | O(n)     | O(1)*    | O(1)*    | O(n)  |
| Stack           | O(n)     | O(n)     | O(1)     | O(1)     | O(n)  |
| Queue           | O(n)     | O(n)     | O(1)     | O(1)     | O(n)  |
| HashMap         | N/A      | O(1) av  | O(1) av  | O(1) av  | O(n)  |
| BST (balanced)  | O(log n) | O(log n) | O(log n) | O(log n) | O(n)  |
| BST (worst)     | O(n)     | O(n)     | O(n)     | O(n)     | O(n)  |
| Min/Max Heap    | O(1)†    | O(n)     | O(log n) | O(log n) | O(n)  |
| Trie            | O(L)     | O(L)     | O(L)     | O(L)     | O(n·L)|

\* at head/tail with reference
† only for min/max element

---

### Sorting Algorithms

| Algorithm      | Best       | Average    | Worst      | Space    | Stable |
|---------------|------------|------------|------------|----------|--------|
| Bubble Sort   | O(n)       | O(n²)      | O(n²)      | O(1)     | Yes    |
| Selection Sort| O(n²)      | O(n²)      | O(n²)      | O(1)     | No     |
| Insertion Sort| O(n)       | O(n²)      | O(n²)      | O(1)     | Yes    |
| Merge Sort    | O(n log n) | O(n log n) | O(n log n) | O(n)     | Yes    |
| Quick Sort    | O(n log n) | O(n log n) | O(n²)      | O(log n) | No     |
| Heap Sort     | O(n log n) | O(n log n) | O(n log n) | O(1)     | No     |
| Counting Sort | O(n+k)     | O(n+k)     | O(n+k)     | O(k)     | Yes    |
| Radix Sort    | O(dn)      | O(dn)      | O(dn)      | O(n+k)   | Yes    |
| Timsort       | O(n)       | O(n log n) | O(n log n) | O(n)     | Yes    |

---

### Graph Algorithms

| Algorithm        | Time           | Space  |
|-----------------|----------------|--------|
| BFS             | O(V + E)       | O(V)   |
| DFS             | O(V + E)       | O(V)   |
| Dijkstra (heap) | O((V+E) log V) | O(V)   |
| Bellman-Ford    | O(V · E)       | O(V)   |
| Floyd-Warshall  | O(V³)          | O(V²)  |
| Topological Sort| O(V + E)       | O(V)   |
| Prim's MST      | O(E log V)     | O(V)   |
| Kruskal's MST   | O(E log E)     | O(V)   |

---

## PART 13 — COMPLEXITY INTUITIONS TO MEMORIZE

- Anything that **halves the input each step** → O(log n)
- **One pass** through data → O(n)
- **All pairs** → O(n²)
- **All triples** → O(n³)
- **Divide and combine** → O(n log n)
- **All subsets** → O(2ⁿ)
- **All permutations** → O(n!)
- **Balanced tree height** → always O(log n)
- **Recursion stack depth** = O(recursion depth), NOT number of calls
- **Amortized** = total cost / number of operations (spread rare expensive ops)
- When you see **"given a reference to the node"** in insert/delete questions → likely O(1), not O(n)
- **Build heap** from array = O(n), not O(n log n)
- **Heapify down** from root = O(log n); **Build heap** = O(n) using bottom-up approach
- O(1) space almost always means **in-place** — modifying input, no extra allocations proportional to n
