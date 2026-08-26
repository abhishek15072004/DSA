class Solution {
public:
int solve(vector<int>a,int sum){
    int n=a.size();
    vector<vector<int>>dp(n+1,vector<int>(sum+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                dp[i][j]=0;
            }
            if(j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(a[i-1]<=j){
          dp[i][j]=max(a[i-1]+dp[i-1][j-a[i-1]],dp[i-1][j]);
            }else{
              dp[i][j]=dp[i-1][j];  
            }
        }
    }
    return dp[n][sum];
}
    int lastStoneWeightII(vector<int>& stones) {
        int sum=accumulate(stones.begin(),stones.end(),0);
        int s1=solve(stones,sum/2);
        return sum-2*s1;
    }
};