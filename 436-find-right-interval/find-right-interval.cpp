class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({intervals[i][0],i});
        }
        sort(v.begin(),v.end());
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){ 
            int end=intervals[i][1];
            // binary search
        int a=lower_bound(v.begin(),v.end(),make_pair(end,0))-v.begin();
        if(a<n){
            ans[i]=v[a].second;
        }
        }
        return ans;
    }
};