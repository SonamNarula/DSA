class Solution {
public:

    // Returns true if vector a is lexicographically smaller than b
    bool lexicographicallySmaller(const vector<int>& a,
                                  const vector<int>& b) {
        return a < b;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        /*
            Store:
            {left, right, weight, original_index}
        */
        vector<array<long long, 4>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by right endpoint
        sort(arr.begin(), arr.end(),
             [](const auto& a, const auto& b) {
                 if (a[1] != b[1])
                     return a[1] < b[1];

                 // Tie-break doesn't affect correctness,
                 // but gives deterministic ordering.
                 return a[0] < b[0];
             });

        /*
            rights[i] = right endpoint of i-th interval
            after sorting.

            0-indexed.
        */
        vector<long long> rights(n);

        for (int i = 0; i < n; i++)
            rights[i] = arr[i][1];

        /*
            p[i] = index of the LAST interval before i
                   whose right endpoint < arr[i].left

            Because intervals sharing a boundary overlap.

            Example:

                previous = [1,5]
                current  = [5,7]

            5 < 5 is false,
            so they overlap.
        */
        vector<int> p(n);

        for (int i = 0; i < n; i++) {

            long long left = arr[i][0];

            // First right >= left
            int pos = lower_bound(
                rights.begin(),
                rights.begin() + i,
                left
            ) - rights.begin();

            // We need last right < left
            p[i] = pos - 1;
        }

        /*
            dp[i][k]:

            Best result using the FIRST i intervals
            and choosing at most k intervals.

            Each state stores:
                score
                indices
        */

        struct State {
            long long score = 0;
            vector<int> indices;
        };

        // dp[i][k]
        vector<vector<State>> dp(
            n + 1,
            vector<State>(5)
        );

        /*
            Compare two states.

            Higher score is better.

            If score is equal,
            lexicographically smaller index array is better.
        */
        auto better = [&](const State& a, const State& b) {

            if (a.score != b.score)
                return a.score > b.score;

            return a.indices < b.indices;
        };

        /*
            Process intervals one by one.

            i = number of intervals considered
        */
        for (int i = 1; i <= n; i++) {

            // Current interval is arr[i-1]
            int idx = i - 1;

            long long weight = arr[idx][2];
            int originalIndex = (int)arr[idx][3];

            for (int k = 1; k <= 4; k++) {

                // OPTION 1:
                // Don't take current interval
                State skip = dp[i - 1][k];

                // OPTION 2:
                // Take current interval
                State take;

                /*
                    p[idx] is 0-indexed index of the previous
                    compatible interval.

                    dp[p[idx] + 1][k-1]
                    represents all intervals up to that point.
                */
                take = dp[p[idx] + 1][k - 1];

                take.score += weight;

                take.indices.push_back(originalIndex);

                /*
                    We need the final answer to be sorted by
                    ORIGINAL indices.

                    So insert current original index and sort.
                */
                sort(take.indices.begin(), take.indices.end());

                // Pick maximum score.
                // On tie, pick lexicographically smaller indices.
                if (better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }

        /*
            We need AT MOST 4 intervals.

            dp[n][4] already means "at most 4",
            because our recurrence allows using fewer than k.

            Return the stored indices.
        */
        return dp[n][4].indices;
    }
};