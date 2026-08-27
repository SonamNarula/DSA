class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        
      // code here
      int low=0,high=0;
      int res=INT_MIN;
      int n=s.size();
      unordered_map<char,int> f;
      for(high=0;high<n;high++)
      {
          f[s[high]]++;
          int siz=f.size();
          while(f.size()>k) // shrink
          {
              f[s[low]]--;
              low++;
              if(f[s[low-1]] == 0)
              f.erase(s[low-1]);
          }

          // now it can be less or equal
          if(f.size()==k)
          {
              int len=high-low+1;
              res=max(res,len);
          }
      }
      if(res==INT_MIN)
      return -1;
      return res;

  
        
    }
};
