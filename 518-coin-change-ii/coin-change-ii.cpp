class Solution {
public:
    long long solve(vector<int>& coin ,int sum){
        int n=coin.size();
        long long t[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0){
                    t[i][j]=0;
                }
                if(j==0){
                    t[i][j]=1;
                }
            }
        }
        t[0][0]=1;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(coin[i-1]<=j){
                    // t[i][j]=t[i-1][j]+t[i][j-coin[i-1]]; this line is true to avoid overflow beside line is written only otherwise above line is also true
                   long long ways=1LL*t[i][j-coin[i-1]]+t[i-1][j];
                //    prevent overflow in intemediate states
                t[i][j]=min(ways,1LL*INT_MAX);
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }

    int change(int amount, vector<int>& coins) {
       // base problem subset sum and count of subset sum gfg problem
        return solve(coins,amount);
    }
};