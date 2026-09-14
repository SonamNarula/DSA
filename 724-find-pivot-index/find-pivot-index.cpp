class Solution {
public:
    int pivotIndex(vector<int>& a) {
        int n = a.size(); // Vector ki size/length nikaali
        
        int i;
        int sum = 0;
        
        // Step 1: Array ke saare elements ka total sum calculate karenge
        for (i = 0; i < n; i++)
            sum += a[i];
            
        int left = 0; // Current index se pehle ke elements ka sum track karne ke liye variable
        
        // Step 2: Array par traverse karenge aur check karenge ki pivot index milta hai ya nahi
        for (i = 0; i < n; i++) {
            // Right sum = Total Sum - Left Sum - Current Element
            int right = sum - left - a[i];
            

            if (left == right)
                return i;
                
            // Agle element par jaane se pehle current element ko left sum me add krenge
            left = left + a[i];
        }
        
        // Agar koi bhi pivot index nahi mila toh -1 return karenge
        return -1;
    }
};