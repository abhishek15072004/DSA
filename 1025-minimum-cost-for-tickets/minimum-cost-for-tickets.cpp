class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n=days.size();
        vector<int>dp(n+1,0);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
             int j=i;
            //  by using one day cost we can travel for 1 day for free,here j will be the index just greater than the free day
             while(j<n && days[j]<days[i]+1){
                j++;
             }
            int oneday=cost[0]+dp[j];
            // 7 day cost
            while(j<n && days[j]<days[i]+7){
                j++;
            }
            int sevenday=cost[1]+dp[j];
            j=i;
            // 30 day cost
            while(j<n && days[j]<days[i]+30){
                j++;
            }
            int thirtyday=cost[2]+dp[j];
            dp[i]=min({thirtyday,sevenday,oneday});

        }
        return dp[0];
    }
};