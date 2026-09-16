#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        // Outer loop: Subarray ka start index track karne ke liye (0 se n-1 tak)
        for (int i = 0; i < n; i++) {
            int current_sum = 0; // Har naye starting point 'i' ke liye sum reset karein
            
            // Inner loop: Subarray ka end index track karne ke liye (i se n-1 tak)
            for (int j = i; j < n; j++) {
                current_sum += nums[j]; // Naya element add karke continuous sum update karein
                
                // Agar index i se j tak ka sum 'k' ke barabar mil jaye
                if (current_sum == k) {
                    count++; // Valid subarray mil gaya, count badhayein
                }
            }
        }

        return count; // Total matching subarrays return karein
    }
};