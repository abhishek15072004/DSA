class Solution {
public:
void dfs(vector<vector<int>>& rooms,int i,vector<bool>&vis){
    vis[i]=true;
    for(int j=0;j<rooms[i].size();j++){
        if(!vis[rooms[i][j]]){
            dfs(rooms,rooms[i][j],vis);
        }
    }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,false);
        dfs(rooms,0,vis);
        for(auto it:vis){
            if(it!=true){
                return false;
            }
        }
        return true;
    }
};