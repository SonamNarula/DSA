class Solution {
public:
    int findGCD(vector<int>& nums) {

        // Find the smallest element in the array.
        // min_element() iterator return karta hai,
        // isliye '*' laga ke actual value le rahe hain.
        int mn = *min_element(nums.begin(), nums.end());

        // Find the largest element in the array.
        // Same yaha bhi, iterator ko dereference karke value nikaal rahe hain.
        int mx = *max_element(nums.begin(), nums.end());

        // Ab smallest aur largest element ka GCD return kar do.
        // __gcd() internally Euclidean Algorithm use karta hai.
        return __gcd(mn, mx);
    }
};