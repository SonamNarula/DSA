class Solution {
public:
    using ll = long long;
    
    ll base = 91138233, mod = 972663749;
    vector<ll> pref, pw;

    void build(vector<int>& A) {
        int n = A.size();
        pref.assign(n + 1, 0), pw.assign(n + 1, 1);

        for(int i = 0; i < n; i++) {
            pw[i + 1] = (pw[i] * base) % mod;
            pref[i + 1] = (pref[i] * base + A[i] + 1000007) % mod;
        }
    }

    ll getHash(int l, int r) {
        ll res = pref[r + 1] - (pref[l] * pw[r - l + 1]) % mod;
        
        if(res < 0)
            res += mod;
        
        return res;
    }

    bool can(int len) {
        int n = pref.size() - 1;
        unordered_map<ll, int> freq;

        for(int i = 0; i + len <= n; i++) {
            ll h = getHash(i, i + len - 1);
            freq[h]++;
        }

        for(auto [_, cnt] : freq)
            if(cnt == 1)
                return true;
        
        return false;
    }
    
    int smallestUniqueSubarray(vector<int>& A) {
        build(A);
        
        int low = 0, high = A.size(), cur = 0; 
        
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(can(mid)) 
                high = mid - 1, cur = mid;

            else
                low = mid + 1;
        }

        return cur;
    }
};