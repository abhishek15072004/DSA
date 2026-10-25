class Solution {
public:
void dfs(vector<vector<int>>& a,int i,vector<bool>& vis){
    vis[i]=true;
    for(int j=0;j<a[i].size();j++){
        if(a[i][j]==1 && vis[j]==false){
            dfs(a,j,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& a) {
        int n=a.size();
        int ct=0;
        vector<bool>vis(n,false);
        for(int i=0;i<a.size();i++){
            if(vis[i]==false){
                ct++;
                dfs(a,i,vis);
            }
        }
        return ct;
    }
};