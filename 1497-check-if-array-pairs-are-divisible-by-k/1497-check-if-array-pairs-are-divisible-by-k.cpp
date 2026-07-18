class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        bool flag=true;
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            int x=((arr[i]%k)+k)%k;
            arr[i]=x;
            freq[x]++;
        }
        for(auto ele:arr){ 
            int rem=(k-ele)%k;
            if(rem==0 || (k % 2 == 0 && rem == k / 2)){
                if(freq[rem]%2!=0) return false;
            }
            if(freq.find(rem)!=freq.end()){
                if(freq[rem]!=freq[ele]) return false;
            }
            else return false;
        }
        return flag;
    }
};