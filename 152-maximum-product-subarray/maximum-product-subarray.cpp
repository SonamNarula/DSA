class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int maxProduct = arr[0];
        int minProduct = arr[0];
        int answer = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            // Negative flips maximum and minimum.
            if (arr[i] < 0)
                swap(maxProduct, minProduct);
            // Start fresh OR extend the previous product.
            maxProduct = max(arr[i], maxProduct * arr[i]);
            minProduct = min(arr[i], minProduct * arr[i]);
            // Save the best product seen so far.
            answer = max(answer, maxProduct);
        }
        return answer;
    }
};