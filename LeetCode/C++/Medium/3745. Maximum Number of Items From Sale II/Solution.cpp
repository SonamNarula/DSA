class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<long long> freq(n + 1, 0);

        long long minPrice = LLONG_MAX;

        for (auto &it : items) {
            freq[it[0]]++;
            minPrice = min(minPrice, (long long)it[1]);
        }

        vector<long long> cnt(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                cnt[i] += freq[j];
            }
            cnt[i]--;
        }

        map<long long, long long> mp;

        for (auto &it : items) {
            long long factor = it[0];
            long long price = it[1];

            if (price < 2 * minPrice && cnt[factor] > 0) {
                mp[price] += cnt[factor];
            }
        }

        vector<long long> prefixCount, prefixSaving;

        long long totalCount = 0;
        long long totalSaving = 0;

        for (auto &[price, count] : mp) {
            totalCount += count;
            totalSaving += count * (2 * minPrice - price);

            prefixCount.push_back(totalCount);
            prefixSaving.push_back(totalSaving);
        }

        auto minCost = [&](long long k) -> long long {
            long long baseCost = k * minPrice;

            long long take = min(k / 2, totalCount);

            if (take == 0) return baseCost;

            int idx = lower_bound(
                prefixCount.begin(),
                prefixCount.end(),
                take
            ) - prefixCount.begin();

            long long previousCount =
                (idx == 0 ? 0 : prefixCount[idx - 1]);

            long long previousSaving =
                (idx == 0 ? 0 : prefixSaving[idx - 1]);

            long long remaining = take - previousCount;

            auto it = mp.begin();
            advance(it, idx);

            long long saving = previousSaving +
                remaining * (2 * minPrice - it->first);

            return baseCost - saving;
        };

        long long low = 0;
        long long high = 2LL * budget / minPrice;

        while (low < high) {
            long long mid = low + (high - low + 1) / 2;

            if (minCost(mid) <= budget) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        return (int)low;
    }
};