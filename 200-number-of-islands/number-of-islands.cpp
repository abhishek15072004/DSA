class Solution {
public:
int x[4]={-1,1,0,0};
int y[4]={0,0,-1,1};
bool valid(int i,int j,int m,int n){
    if(i>=n || j>=m || i<0 ||j<0 ){
        return false;
    }
    return true;
}

void dfs(vector<vector<char>>&a,int i,int j,int m,int n,vector<vector<bool>>&vis){
    vis[i][j]=true;
  
    for(int k=0;k<4;k++){
          int row=i+x[k];
          int column=j+y[k];
          if(valid(row,column,m,n) && a[row][column]=='1'  && !vis[row][column] ){
            dfs(a,row,column,m,n,vis);
          }
    }
    return;
}
    int numIslands(vector<vector<char>>& a) {
        int n=a.size();
        int m=a[0].size();
        vector<vector<bool>>vis(n);
        for(int i=0;i<n;i++){
            vector<bool>t(m,false);
            vis[i]=t;
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='1'&& !vis[i][j]){
                    dfs(a,i,j,m,n,vis);
                    res++;
                }
            }
        }
        return res;
    }
};