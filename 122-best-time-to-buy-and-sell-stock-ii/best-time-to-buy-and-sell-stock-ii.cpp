class Solution {
public:
inline static int t[30001][3];
int solve(vector<int>&a,int i,int k){
    if(i==a.size()){
        return 0;
    }
    if(k==0){
        return 0;
    }
    if(t[i][k]!=-1){
        return t[i][k];
    }
    if(k==2){
        int buy=solve(a,i+1,k-1)-a[i];
        int not_buy=solve(a,i+1,k);
        return t[i][k]= max(buy,not_buy);
    }else{
        int sell=solve(a,i+1,2)+a[i];
        int not_sell=solve(a,i+1,k);
        return t[i][k]= max(sell,not_sell);
    }
}
    int maxProfit(vector<int>& prices) {
        // k represents number of choices
        memset(t,-1,sizeof(t));
        int k=2;
        return solve(prices,0,k);
    }
};