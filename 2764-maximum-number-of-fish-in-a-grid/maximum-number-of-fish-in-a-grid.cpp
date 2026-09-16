class Solution {
public:
int x[4]={-1,1,0,0};
int y[4]={0,0,-1,1};
bool valid(int i,int j,int m,int n){
    if(i<0 || i>=n || j<0 ||j>=m){
        return false;
    }
    return true;
}
int dfs(vector<vector<int>>&a,int i,int j,int n,int m,vector<vector<bool>>&vis){
     vis[i][j]=true;
     int sum=a[i][j];
     for(int k=0;k<4;k++){
        int row=i+x[k];
        int col=j+y[k];
        if(valid(row,col,m,n) && !vis[row][col] && a[row][col]!=0){
              sum+=dfs(a,row,col,n,m,vis);
           
        }
     }
     return sum;
}
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        vector<vector<bool>>vis(n);
        for(int i=0;i<n;i++){
           vis[i]= vector<bool>(m,false);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]!=0){ 
                maxi=max(maxi,dfs(grid,i,j,n,m,vis));
                }
            }
        }
        return maxi;
    }
};