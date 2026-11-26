/*
    ======================================================================
    SLIDING WINDOW — COMPLETE TEMPLATE LIBRARY (C++)
    ======================================================================

    CONTENTS
        PART 1 : FIXED SIZE WINDOW  (k is given, constant)
            Template A — Fixed window sum / max-sum / average
            Template B — Fixed window maximum, every window (Monotonic Deque)

        PART 2 : VARIABLE / DYNAMIC SIZE WINDOW  (size adapts to a condition)
            Template C — LONGEST window satisfying a condition
            Template D — SMALLEST window satisfying a condition
            Template E — EXACTLY K distinct  (atMost(K) - atMost(K-1) trick)
            Template F — Longest unique substring (last-seen-index optimization)

    HOW TO USE
        - Every template is a standalone, copy-pasteable function.
        - Every template follows the SAME 4-step skeleton:
              1. Init window pointers (l = 0) + window state (sum/map/deque)
              2. for r in [0, n):  EXPAND -> bring arr[r] into the window
              3. while (window invalid) SHRINK from left, l++
                 (or: while (window valid) SHRINK, for "smallest window" type)
              4. UPDATE answer — timing of this step is what differs between
                 "longest", "smallest", and "count" style problems.
        - Read README.md for the theory, the decision tree (which template
          to pick while reading a problem), complexity proofs, and a mapped
          practice list.

    NOTE ON HEADERS
        Explicit standard headers used on purpose instead of <bits/stdc++.h>
        for faster compiles and to know exactly what's being pulled in.
    ======================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;


// ======================================================================
// PART 1 : FIXED SIZE WINDOW
// ======================================================================

/*
    TEMPLATE A : FIXED SIZE WINDOW — SUM / AVERAGE / MAX-SUM
    ---------------------------------------------------------
    Problem shape : "subarray of size EXACTLY k" -> sum, average, max-sum.
    Idea          : Maintain a running sum of the last k elements. Slide
                    by adding the new right element and removing the
                    element that just fell off the left. Never recompute
                    the whole window from scratch.
    Complexity    : O(n) time, O(1) extra space
    Example use   : Maximum sum of any subarray of size k.
*/
int maxSumFixedWindow(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;   // not enough elements to even form one window

    int windowSum = 0;

    // Step 1: build the very first window [0, k-1]
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    // Step 2: slide one position at a time.
    // r        = new element entering the window (right edge)
    // r - k    = old element leaving the window (left edge)
    for (int r = k; r < n; r++) {
        windowSum += arr[r];        // expand: add new element
        windowSum -= arr[r - k];    // shrink: remove element leaving on the left
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}


/*
    TEMPLATE B : FIXED SIZE WINDOW — MAXIMUM IN EVERY WINDOW (Monotonic Deque)
    ---------------------------------------------------------------------
    Problem shape : "max/min of every window of size k" (LeetCode 239).
    Idea          : Keep a deque of INDICES whose corresponding values are
                    in strictly decreasing order from front to back.
                      - Before pushing arr[r], pop from the BACK every
                        index whose value <= arr[r]. Those values can
                        never become the max again while arr[r] is alive
                        in the window, so they're useless to keep.
                      - Pop from the FRONT any index that has fallen
                        outside the window (index <= r - k).
                      - front() of the deque = index of the current
                        window's maximum.
    Complexity    : O(n) time — each index is pushed once and popped at
                    most once across the whole run. O(k) space.
    Adapt for MIN : flip the comparison in the "maintain decreasing order"
                    step to "arr[dq.back()] >= arr[r]".
*/
vector<int> maxOfAllWindows(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> result;
    deque<int> dq;   // stores INDICES; values strictly decreasing l -> r

    for (int r = 0; r < n; r++) {
        // 1. Drop indices that have slid out of the current window
        if (!dq.empty() && dq.front() <= r - k) {
            dq.pop_front();
        }

        // 2. Maintain decreasing order: pop smaller/equal values from back
        while (!dq.empty() && arr[dq.back()] <= arr[r]) {
            dq.pop_back();
        }

        // 3. Push current index
        dq.push_back(r);

        // 4. First full window forms at r == k-1; record answer from there
        if (r >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }

    return result;
}


// ======================================================================
// PART 2 : VARIABLE / DYNAMIC SIZE WINDOW
// ======================================================================

/*
    TEMPLATE C : LONGEST WINDOW SATISFYING A CONDITION
    ----------------------------------------------------
    Problem shape : "Find the LONGEST subarray/substring such that
                    <condition>" — e.g. longest substring with at most K
                    distinct characters (used here), longest subarray
                    with sum <= target, etc.
    Idea          : Two pointers l, r both start at 0.
                      - EXPAND by moving r forward, adding arr[r]/s[r].
                      - If the window becomes INVALID, SHRINK from the
                        left (move l forward) — only until it's valid
                        again (minimal shrink), because we want the
                        window as large as possible.
                      - After every expansion, update the answer with
                        the CURRENT window size (r - l + 1). At this
                        exact point the window is guaranteed valid.
    Invariant     : Whenever we update the answer, [l, r] is valid.
    Complexity    : O(n) — l and r each move forward at most n times
                    total across the whole loop (amortized O(1) per step).
*/
int longestSubstringAtMostKDistinct(string s, int k) {
    int n = s.size();
    unordered_map<char, int> freq;   // frequency of chars in current window
    int l = 0, maxLen = 0;

    for (int r = 0; r < n; r++) {
        // 1. EXPAND: bring s[r] into the window
        freq[s[r]]++;

        // 2. SHRINK: while invalid (too many distinct chars), pull left in
        while ((int)freq.size() > k) {
            freq[s[l]]--;
            if (freq[s[l]] == 0) {
                freq.erase(s[l]);   // remove entirely once count hits 0
                                     // (critical — otherwise freq.size()
                                     //  stays wrong forever)
            }
            l++;
        }

        // 3. UPDATE: [l, r] is guaranteed valid right here
        maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
}


/*
    TEMPLATE D : SMALLEST WINDOW SATISFYING A CONDITION
    -------------------------------------------------------
    Problem shape : "Find the SMALLEST subarray/substring such that
                    <condition>" — e.g. minimum size subarray with
                    sum >= target (LeetCode 209).
    Idea          : Same two pointers, but the shrink direction/timing
                    flips vs Template C:
                      - EXPAND (move r, add arr[r]) until window is VALID.
                      - Once valid, SHRINK from the left AS MUCH AS
                        POSSIBLE while it stays valid — i.e. maximal
                        shrink — updating the answer at EVERY successful
                        shrink step, not just once.
    Key contrast with Template C:
                      - Template C: shrink only until INVALID -> VALID
                        (minimal shrink) because it wants window LARGE.
                      - Template D: shrink while VALID -> stays VALID
                        (maximal shrink) because it wants window SMALL.
    Complexity    : O(n)
*/
int smallestSubarrayWithSumAtLeast(vector<int>& arr, int target) {
    int n = arr.size();
    int l = 0, windowSum = 0;
    int minLen = INT_MAX;

    for (int r = 0; r < n; r++) {
        // 1. EXPAND
        windowSum += arr[r];

        // 2. SHRINK while the window stays valid, recording answer each time
        while (windowSum >= target) {
            minLen = min(minLen, r - l + 1);   // record BEFORE shrinking more
            windowSum -= arr[l];
            l++;
        }
    }

    return (minLen == INT_MAX) ? 0 : minLen;   // 0 -> no valid window exists
}


/*
    TEMPLATE E : EXACTLY K DISTINCT  (atMost(K) - atMost(K-1) trick)
    ---------------------------------------------------------------
    Problem shape : "Count subarrays/substrings with EXACTLY K distinct
                    elements" (LeetCode 992: Subarrays with K Different
                    Integers).
    Idea          : "Exactly K" is awkward to maintain directly — the
                    shrink condition for "exactly" isn't monotonic in a
                    single pass. The standard trick:
                        exactly(K) = atMost(K) - atMost(K - 1)
                    atMost(K) = count of subarrays with AT MOST K distinct
                    elements, which IS a clean Template-C-style shrink:
                    for every r, every subarray ending at r and starting
                    anywhere in [l, r] has at most K distinct elements,
                    so it contributes (r - l + 1) valid subarrays.
    Complexity    : O(n) — atMost() is O(n), called twice -> still O(n)
*/
int atMostKDistinct(vector<int>& arr, int k) {
    if (k == 0) return 0;
    int n = arr.size();
    unordered_map<int, int> freq;
    int l = 0;
    long long count = 0;

    for (int r = 0; r < n; r++) {
        freq[arr[r]]++;

        while ((int)freq.size() > k) {
            freq[arr[l]]--;
            if (freq[arr[l]] == 0) freq.erase(arr[l]);
            l++;
        }

        // every subarray [x, r] for x in [l, r] has <= k distinct elements
        count += (r - l + 1);
    }

    return (int)count;
}

int exactlyKDistinct(vector<int>& arr, int k) {
    return atMostKDistinct(arr, k) - atMostKDistinct(arr, k - 1);
}


/*
    TEMPLATE F : LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS
    ---------------------------------------------------------------
    Problem shape : classic variable window, condition = "no duplicate
                    characters in the window" (LeetCode 3).
    Idea          : Optimization layered on top of Template C. Instead of
                    a frequency map + one-step-at-a-time shrink, keep a
                    map of LAST SEEN INDEX per character. This lets l jump
                    directly to (duplicate's last index + 1) in O(1)
                    instead of shrinking character by character.
    Complexity    : O(n) time, O(min(n, charset size)) space
*/
int longestUniqueSubstring(string s) {
    int n = s.size();
    unordered_map<char, int> lastSeen;   // char -> last index it appeared at
    int l = 0, maxLen = 0;

    for (int r = 0; r < n; r++) {
        char c = s[r];

        // If c was seen before AND that occurrence lies inside the
        // current window, jump l past it directly.
        if (lastSeen.count(c) && lastSeen[c] >= l) {
            l = lastSeen[c] + 1;
        }

        lastSeen[c] = r;
        maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
}


// ======================================================================
// DRIVER — quick sanity checks for every template above
// ======================================================================
int main() {
    // Template A
    vector<int> a = {2, 1, 5, 1, 3, 2};
    cout << "A) Max sum, window k=3: " << maxSumFixedWindow(a, 3) << endl; // 9

    // Template B
    vector<int> b = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> resB = maxOfAllWindows(b, 3);
    cout << "B) Max of every window k=3: ";
    for (int x : resB) cout << x << " ";
    cout << endl; // 3 3 5 5 6 7

    // Template C
    cout << "C) Longest substr, at most 2 distinct (\"eceba\"): "
         << longestSubstringAtMostKDistinct("eceba", 2) << endl; // 3 ("ece")

    // Template D
    vector<int> d = {2, 3, 1, 2, 4, 3};
    cout << "D) Smallest subarray, sum >= 7: "
         << smallestSubarrayWithSumAtLeast(d, 7) << endl; // 2 ("4 3")

    // Template E
    vector<int> e = {1, 2, 1, 2, 3};
    cout << "E) Subarrays with exactly 2 distinct: "
         << exactlyKDistinct(e, 2) << endl; // 7

    // Template F
    cout << "F) Longest unique substring (\"abcabcbb\"): "
         << longestUniqueSubstring("abcabcbb") << endl; // 3 ("abc")

    return 0;
}
