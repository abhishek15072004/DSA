class Solution {
public:
int x[8]={-1,1,0,0,-1,-1,1,1};
int y[8]={0,0,-1,1,-1,1,-1,1};
bool valid(int n,int m,int i,int j){
if(i<0 || i>=n || j<0 || j>=m){
    return false;
}
return true;
}

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]!=0 || grid[n-1][m-1]!=0){
            return -1;
        }
        vector<vector<bool>>visited(n);
        for(int i=0;i<n;i++){
            visited[i]=vector<bool>(m,false);
        }
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        visited[0][0]=true;
        
        while(!q.empty()){
         int i=q.front().first.first;
         int j=q.front().first.second;
         int dist=q.front().second;
         q.pop();
         if(i==n-1 && j==m-1){
            return dist;
         }
         for(int k=0;k<8;k++){
            int row=i+x[k];
            int col=j+y[k];
            if(valid(n,m,row,col) && !visited[row][col] && grid[row][col]==0){
                visited[row][col]=true;
                q.push({{row,col},dist+1});
            }
         }
        }
  return -1;
            
    }
};