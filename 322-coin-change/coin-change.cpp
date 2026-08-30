class Solution {
public:
    int solve(vector<int>& coin ,int sum){
      int n=coin.size();
    //   initialization
      vector<vector<int>>t(n+1,vector<int>(sum+1,INT_MAX-1));
      for(int j=0;j<n+1;j++){
        t[j][0]=0;
      }
    //   logical part
      for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]<=j){
                t[i][j]=min(t[i-1][j],1+t[i][j-coin[i-1]]);
            }else{
                t[i][j]=t[i-1][j];
            }
        }
      }
    //   i am checking int_max -1 bcz i initialized the vector with int_max -1
      return t[n][sum]==INT_MAX-1 ? -1:t[n][sum];
    }
    int coinChange(vector<int>& coins, int amount) {
        
        return solve(coins,amount);
    }
};