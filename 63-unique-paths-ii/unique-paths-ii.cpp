class Solution {
public:
inline static int t[101][101];
int solve(vector<vector<int>>& a,int n,int m,int i,int j){
    if(i<0 || j<0)return 0;
    if(a[i][j]==1){
        return 0;
    }
    if(i==0 && j==0){
        return 1;
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    int right=solve(a,n,m,i,j-1);
    int down=solve(a,n,m,i-1,j);
    return t[i][j]= right+down;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        memset(t,-1,sizeof(t));
        return solve(obstacleGrid,n,m,m-1,n-1);
    }
};