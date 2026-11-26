class Solution {
	public:
	bool isPalindrome(string& s) {
		// code here
		int n = s.size();
		
		int i = 0;
		int j = n - 1;
		
		while(i < j)
{
    if(s[i] != s[j])
        return false;

    i++;
    j--;
}

return true;
	}
		
	};
