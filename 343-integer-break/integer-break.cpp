class Solution {
public:
inline static int t[59];
int solve(int n){
    if(n<=1){
        return 1;
    }
    if(t[n]!=-1){
        return t[n];
    }
    int mul=1;
    for(int i=1;i<n;i++){
        // helping in choosing the best integer that sums to get n
        int take=max(n-i,solve(n-i));
        
        mul=max(mul,i*take);
    }
    return t[n]=mul;
}
    int integerBreak(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};