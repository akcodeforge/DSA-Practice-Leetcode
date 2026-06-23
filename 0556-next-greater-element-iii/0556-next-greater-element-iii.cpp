class Solution {
public:
    int nextGreaterElement(int n) {
      string st=to_string(n);   //// integer to string
      if(!next_permutation(st.begin(),st.end())) return -1;
      long long ans=stoll(st);   /// string to integer  
      if(ans>INT_MAX) return -1;
      return ans;
    }
};