class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
         int lo=1,ans=0;
           int hi=*max_element(candies.begin(),candies.end());
           while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            long long sum=0;
            for(int it:candies){
               sum+=(it)/mid;
            }
            if(sum<k){
                hi=mid-1;
            }else{
                ans=mid;
                lo=mid+1;
            }
           }
           return ans;
    }
};