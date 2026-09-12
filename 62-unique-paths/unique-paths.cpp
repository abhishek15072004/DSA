class Solution {
public:
inline static int t[101][101];
int solve(int m,int n){
    if(m==1 || n==1){
        return 1;
    }
    if(t[m][n]!=-1)return t[m][n];
    int right=solve(m,n-1);
    int bottom=solve(m-1,n);
    return t[m][n]= right+bottom;
}
    int uniquePaths(int m, int n) {
        memset(t,-1,sizeof(t));
        return solve(m,n);
    }
};