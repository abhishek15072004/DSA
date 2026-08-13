class Solution {
public:
    long long maximumSubarraySum(vector<int>& a, int k) {
        // sliding window i=right
        long long sum=0;
        int left=0;
        long long ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<a.size();i++){
            sum+=a[i];
            mp[a[i]]++;
            if(i-left+1==k){
                if(mp.size()==k){
                    ans=max(ans,sum);
                }
                 sum-=a[left];
                mp[a[left]]--;
                if(mp[a[left]]==0){
                    mp.erase(a[left]);
                }
                left++;
            }
        }
        return ans;
        
    }
};