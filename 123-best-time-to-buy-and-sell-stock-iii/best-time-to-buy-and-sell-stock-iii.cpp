class Solution {
public:
inline static int t[100001][5];
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
    if(!(k%2)){
        int buy=solve(a,i+1,k-1)-a[i];
        int not_buy=solve(a,i+1,k);
        return t[i][k]= max(buy,not_buy);
    }else{
        int sell=a[i]+solve(a,i+1,k-1);
        int not_sell=solve(a,i+1,k);
        return t[i][k]= max(sell,not_sell);
    }
}
    int maxProfit(vector<int>& prices) {
        int k=4;
        memset(t,-1,sizeof(t));
        return solve(prices,0,k);
    }
};