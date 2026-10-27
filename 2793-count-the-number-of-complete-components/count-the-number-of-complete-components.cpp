class Solution {
public:
    void dfs(vector<vector<int>>& adj, int i,
             vector<bool>& vis, int& nodes, int& edges) {

        vis[i] = true;
        nodes++;
        edges += adj[i].size();

        for(int j = 0; j < adj[i].size(); j++) {
            int neigh = adj[i][j];

            if(!vis[neigh]) {
                dfs(adj, neigh, vis, nodes, edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ct = 0;
        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++) {
            if(vis[i] == false) {
                int nodes = 0;
                int edgeCount = 0;

                dfs(adj, i, vis, nodes, edgeCount);

                edgeCount /= 2;

                if(edgeCount == nodes * (nodes - 1) / 2) {
                    ct++;
                }
            }
        }

        return ct;
    }
};