class Solution {
public:
int x[4]={-1,1,0,0};
int y[4]={0,0,-1,1};
bool valid(int i,int j,int n,int m){
    if(i<0 || j<0 || i>=n || j>=m){
        return false;
    }
    return true;
}
void dfs(vector<vector<char>>&a,int i,int j,int n,int m,vector<vector<bool>>&vis){
    vis[i][j]=true;
    for(int k=0;k<4;k++){
        int row=i+x[k];
        int col=j+y[k];
        if(valid(row,col,n,m) && !vis[row][col] && a[row][col]=='X'){
            dfs(a,row,col,n,m,vis);
        }
    }
    return;
}
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>vis(n);
        for(int i=0;i<n;i++){
            vis[i]=vector<bool>(m,false);
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='X'){
                    dfs(board,i,j,n,m,vis);
                    res++;
                }
            }
        }
        return res;
    }
};