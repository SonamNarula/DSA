class Solution {
  public:
    string reverseString(string& s) {
        // code here
         // method 1 : stl
        // reverse(s.begin(), s.end());


        // method 2 : 2 pointers
        int start = 0; int end = s.size() - 1;

        while(start<end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
        return s;
    }
};
