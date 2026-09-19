class Solution {
public:
inline static int t[10001];
int solve(int n){
    if(n<=0){
        return 0;
    }
    if(t[n]!=-1){
        return t[n];
    }
    int ans=INT_MAX;
    for(int i=1;i*i<=n;i++){
int take=1+solve(n-i*i);
ans=min(ans,take);
    }
    return t[n]= ans;
}
    int numSquares(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};