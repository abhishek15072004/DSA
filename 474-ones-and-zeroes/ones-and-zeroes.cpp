class Solution {
public:
// knapsack problem
inline static int t[101][101][601];
int solve(vector<string>& s,int m,int n,int i){
    if(i==s.size() || (m==0 && n==0)){
        return 0;
    }
    if(t[m][n][i]!=-1){
        return t[m][n][i];
    }
    int zero=0,one=0;
    for(char c:s[i]){
        if(c=='0'){
            zero++;
        }else{
            one++;
        }
    }
    // take step
    // and check for cureent string have less number of zeros and ones than m and n because we cannot take more than m and n zero having strings
    int take=0;
    if(zero<=m && one<=n){ 
     take=1+solve(s,m-zero,n-one,i+1);
    }
    // dont take
    int not_take=solve(s,m,n,i+1);
    return t[m][n][i]= max(take,not_take);

}
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(t,-1,sizeof(t));
        return solve(strs,m,n,0);
    }
};