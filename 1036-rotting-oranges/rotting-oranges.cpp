class Solution {
public:
int x[4]={-1,1,0,0};
int y[4]={0,0,-1,1};
bool valid(int i,int j,int m,int n){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0,time=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        while(!q.empty() && fresh>0){
            time++;
            int s=q.size();
            while(s--){
                pair<int,int>p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;
                for(int k=0;k<4;k++){
                    int row=i+x[k];
                    int col=j+y[k];
                    if(valid(row,col,m,n) && grid[row][col]==1){
                        fresh--;
                        grid[row][col]=2;
                        q.push({row,col});
                    }
                }
               
            }
        }
        if(fresh){
            return -1;
        }else{
            return time;
        }
    }
};