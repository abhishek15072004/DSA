class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
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
            q.pop();
            res.push_back(node);
            for(int j=0;j<a[node].size();j++){
                indeg[a[node][j]]--;
                if(indeg[a[node][j]]==0){
                    q.push(a[node][j]);
                }
                
            }
        }
        if(res.size()!=n){
            return {};
        }
return res;
    }
};