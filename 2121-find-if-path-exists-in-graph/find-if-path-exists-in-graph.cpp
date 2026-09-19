class Solution {
public:
bool res=false;;
void dfs(vector<vector<int>>&a,int i,vector<bool>&visited,int dest){
    if(i==dest){
        res=true;
        return;
    }
    visited[i]=true;
    for(int j=0;j<a[i].size();j++){
        if(!visited[a[i][j]]){
            dfs(a,a[i][j],visited,dest);
        }
    }
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>a(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            a[u].push_back(v);
            a[v].push_back(u);
        }
        vector<bool>visited(n,false);
       
        
                dfs(a,source,visited,destination);
            
        
        return res;
    }
};