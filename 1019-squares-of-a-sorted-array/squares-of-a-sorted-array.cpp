// O(n) approach

// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int n = nums.size();
        
//         vector<int> result(n);
        
//         int i = 0, j = n-1;
//         int k = n-1;
        
//         while(k >= 0) {
//             int a = nums[i]*nums[i];
//             int b = nums[j]*nums[j];
            
//             if(a > b) {
//                 result[k] = a;
//                 i++;
//             } else {
//                 result[k] = b;
//                 j--;
//             }
//             k--;
//         }
//         return result;
//     }
// };



// merge 2 sorted arrays using 2 pointers wala approach

// 977. Squares of a Sorted Array
// Approach: Merge Two Sorted Arrays (O(n))

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();

        // ------------------------------------------------------------
        // Step 1:
        // First non-negative element (>= 0) find karo.
        //
        // Example:
        // nums = [-7, -3, 2, 3, 11]
        //                  ^
        //                  j
        //
        // Iske left me saare negative numbers hain.
        // Iske right me saare positive (ya zero) numbers hain.
        // ------------------------------------------------------------
        int j = 0;
        while (j < n && nums[j] < 0) {
            j++;
        }

        // i = last negative element
        // Example:
        // nums = [-7, -3, 2, 3, 11]
        //             ^
        //             i
        int i = j - 1;

        vector<int> ans;

        // Negative Part:
        // [-7, -3]
        // Squares -> [49, 9]
        //
        // Agar RIGHT se chalenge (-3 -> -7),
        // toh squares milenge:
        // [9, 49]  (Sorted)
        //
        // Positive Part:
        // [2, 3, 11]
        // Squares:
        // [4, 9, 121] (Already Sorted)
        //
        // Ab basically humare paas 2 sorted arrays hain:
        //
        // 9 49
        // 4 9 121
        //
        // Bas Merge Two Sorted Arrays jaisa merge karna hai.


        while (i >= 0 && j < n) {

            // Current negative square
            int leftSquare = nums[i] * nums[i];

            // Current positive square
            int rightSquare = nums[j] * nums[j];

            // Jo square chhota hoga, wahi answer me pehle aayega
            if (leftSquare <= rightSquare) {

                ans.push_back(leftSquare);

                // Negative side me reverse direction me move karna hai
                i--;
            }
            else {

                ans.push_back(rightSquare);

                // Positive side normal direction me move karegi
                j++;
            }
        }


        // Agar negative side ke elements bach gaye

        while (i >= 0) {

            ans.push_back(nums[i] * nums[i]);
            i--;
        }


        // Agar positive side ke elements bach gaye

        while (j < n) {

            ans.push_back(nums[j] * nums[j]);
            j++;
        }

        return ans;
    }
};