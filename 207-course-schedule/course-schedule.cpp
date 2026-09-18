class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
     vector<vector<int>>a(n);
     vector<int>indeg(n,0);
     for(int i=0;i<prerequisites.size();i++){
        int u=prerequisites[i][1];
        int v=prerequisites[i][0];
        a[u].push_back(v);
        indeg[v]++;
     }
     queue<int>q;
     for(int i=0;i<n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
     }
     vector<int>res;
     while(!q.empty()){
        int node=q.front();
        res.push_back(node);
        q.pop();
        for(int i=0;i<a[node].size();i++){
            indeg[a[node][i]]--;
            if(indeg[a[node][i]]==0){
                q.push(a[node][i]);
            }
        }
     }
     if(res.size()!=n){
        return false;
     }
     return true;
    }
};