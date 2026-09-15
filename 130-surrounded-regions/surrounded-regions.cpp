class Solution {
public:
int x[4]={-1,1,0,0};
int y[4]={0,0,-1,1};
bool valid(int i,int j,int n,int m){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}
void dfs(vector<vector<char>>&a,int i,int j,int n,int m){
    a[i][j]='#';
    for(int k=0;k<4;k++){
        int row=i+x[k];
        int col=j+y[k];
        if(valid(row,col,n,m) && a[row][col]=='O'){
            dfs(a,row,col,n,m);
        }
    }
    return;
}
    void solve(vector<vector<char>>& a) {
        int n=a.size();
        int m=a[0].size();
        for(int i=0;i<n;i++){
            if(a[i][0]=='O' ){
                dfs(a,i,0,n,m);
            }
            if(a[i][m-1]=='O'){
                dfs(a,i,m-1,n,m);
            }
        }
        for(int j=0;j<m;j++){
            if(a[0][j]=='O'){
                dfs(a,0,j,n,m);
            }
            if(a[n-1][j]=='O'){
                dfs(a,n-1,j,n,m);
            }
        }
     for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(a[i][j]=='O'){
            a[i][j]='X';
        }else if(a[i][j]=='#'){
            a[i][j]='O';
        }
      }
     }
    }
};