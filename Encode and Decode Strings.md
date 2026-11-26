## 01. Encode and Decode Strings

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/encode-and-decode-strings/1)

### Problem Description

**Task:** Given an array of strings arr[], implement an algorithm in the encode() function that can convert the given strings into a single encoded string, which can be transmitted over the network and then decoded back into the original array of strings from the encoded string. The decoding will happen in the decode() function.The encoding rule used here is:Each string is stored as length + "/:" + actual string.During decoding, we first read the length before the delimiter "/:", and then extract that many characters as the original string.This approach works for all ASCII characters since the length ensures correct parsing regardless of string content.Note: You are not allowed to use any inbuilt serialize method. Examples:Input: arr[] = ["Hello", "World"]Output: ["Hello","World"]Explanation: The encode() function converts the array into a single string by storing each word as length + "/:" + string.
For the given input, "Hello" becomes "5/:Hello", "World" becomes "5/:World". These are concatenated to form "5/:Hello5/:World", which is transmitted.
During decoding, we read the length before "/:", then extract that many characters:
Read 5 then extract "Hello"
Read 5 then extract "World"
Thus, the original array ["Hello", "World"] is reconstructed.Input: arr[] = ["abc", "!@"]Output: ["abc","!@"]Explanation: The encode() function converts each string into length + "/:" + string and concatenates them. Here: "abc" becomes "3/:abc", "!@" becomes "2/:!@" then encoded string = "3/:abc2/:!@".
During decoding, lengths are read to extract exact substrings, reconstructing ["abc","!@"].

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-14 18:54:29
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
	public:
	string encode(vector<string>& arr) {
		// write your logic to encode the strings
		string ans = "";
		
		for (string s : arr) {
			
			// Add length of string
			ans += to_string(s.size());
			
			// Add delimiter
			ans += '#';
			
			// Add actual string
			ans += s;
		}
		
		return ans;
	}
	
	vector<string> decode(string& s) {
		// write your logic to decode the string\
		
		vector<string> ans;
		
		int i = 0;
		
		while (i < s.size()) {
			
			// Step 1: Find delimiter '#'
			int j = i;
			
			while (s[j] != '#') {
				j++;
			}
			
			// Step 2: Extract string length
			int len = stoi(s.substr(i, j - i));
			
			// Step 3: Move to beginning of actual string
			i = j + 1;
			
			// Step 4: Extract exactly 'len' characters
			string word = s.substr(i, len);
			
			ans.push_back(word);
			
			// Step 5: Move to next encoded string
			i = i + len;
		}
		
		return ans;
		
	}
};
```

*Generated on: 14/11/2026, 18:54:45*