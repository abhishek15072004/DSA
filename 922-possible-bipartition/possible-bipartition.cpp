class Solution {
public:
bool res=true;
void dfs(vector<vector<int>>&a,int node,int c,vector<int>&visited){
    visited[node]=c;
  for(int i=0;i<a[node].size();i++){
    if(visited[a[node][i]]!=-1 && visited[a[node][i]]==c){
        res=false;
        return;
    }
    if(visited[a[node][i]]==-1){
        dfs(a,a[node][i],1-c,visited);
    }
  }
  return;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // graph coloring 
        // n+1 becausing the value can go from 0 to n not n-1 thats why
        vector<vector<int>>a(n+1);
        for(int i=0;i<dislikes.size();i++){
            int src=dislikes[i][0];
            int dest=dislikes[i][1];
            a[src].push_back(dest);
            a[dest].push_back(src);
        }
        vector<int>visited(n+1,-1);
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                dfs(a,i,0,visited);
            }
        }
        return res;
    }
};