class Solution {
public:
bool res=true;
void dfs(vector<vector<int>>&a,int node,int c,vector<int>&visited){
    visited[node]=c;
    for(int j=0;j<a[node].size();j++){
        if(visited[a[node][j]]!=-1 && visited[a[node][j]]==c){
           
            res=false;
            return;
        }
        if(visited[a[node][j]]==-1){
            dfs(a,a[node][j],1-c,visited);
        }
    }
}
  
// graph coloring method here visited array name you can replace with colors vetor for better understanding and 1-c for fliping color from 0 to 1 and 1 to 0 you and also do and of color whole not gate
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,-1);
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                dfs(graph,i,0,visited);
            }
        }
        return res;
    }
};