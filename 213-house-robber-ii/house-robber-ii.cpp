class Solution {
public:
inline static int t[101];
int solve(vector<int>& a,int i,int end){
    if(i>end){
        return 0;
    }
    if(t[i]!=-1){
        return t[i];
    }
    int take=a[i]+solve(a,i+2,end);
    int not_take=solve(a,i+1,end);
    return t[i]= max(take,not_take);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
       if(n==1){
        return nums[0];
       }
       memset(t,-1,sizeof(t));
       int case1=solve(nums,0,n-2);
       memset(t,-1,sizeof(t));
       int case2=solve(nums,1,n-1);
       return max(case1,case2);
    }
};