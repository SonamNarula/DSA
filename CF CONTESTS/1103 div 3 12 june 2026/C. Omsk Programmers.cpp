#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        long long a, b, x;
        scanf("%lld %lld %lld", &a, &b, &x);

        vector<long long> va, vb;

        long long cur = a;
        va.push_back(cur);
        while(cur != 0){
            cur /= x;
            va.push_back(cur);
        }

        cur = b;
        vb.push_back(cur);
        while(cur != 0){
            cur /= x;
            vb.push_back(cur);
        }

        long long ans = LLONG_MAX;
        for(int i = 0; i < (int)va.size(); i++){
            for(int j = 0; j < (int)vb.size(); j++){
                long long cost = i + j + abs(va[i] - vb[j]);
                ans = min(ans, cost);
            }
        }

        printf("%lld\n", ans);
    }
}