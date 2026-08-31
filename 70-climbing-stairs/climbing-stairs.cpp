class Solution {
public:
inline static int t[46][46];
 int solve(int n){
     if(n==1  ){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(t[n][n]!=-1){
            return t[n][n];
        }
        return t[n][n]=solve(n-1)+solve(n-2);
 }
    int climbStairs(int n) {
       memset(t,-1,sizeof(t));
       return solve(n);
       
    }
};