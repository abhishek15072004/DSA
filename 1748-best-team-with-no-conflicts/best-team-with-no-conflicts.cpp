class Solution {
public:
inline static int t[1001][1001];
int solve(vector<pair<int,int>>& a,int i,int prev){
if(i>=a.size()){
    return 0;
}
if(t[i][prev+1]!=-1){
    return t[i][prev+1];
}
int take=0;
if(prev==-1 || a[i].second>=a[prev].second){
    take=a[i].second+solve(a,i+1,i);
}
int not_take=solve(a,i+1,prev);
return t[i][prev+1]= max(take,not_take);
}
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> a;
        int n=scores.size();
        for(int i=0;i<n;i++){
            a.push_back({ages[i],scores[i]});
        }
        memset(t,-1,sizeof(t));
        sort(a.begin(),a.end());
        return solve(a,0,-1);
    }
};