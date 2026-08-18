class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0;
        double ans=0;
        double maxi=INT_MIN;
        int sum=0;
        
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
               if(r-l+1==k){
               //int sum=accumulate(nums.begin()+l,nums.begin()+r+1,0);
               ans=sum/(double)k;
               maxi=max(ans,maxi);
               sum-=nums[l];
               l++;
               }
        }
        return maxi;
    }
};