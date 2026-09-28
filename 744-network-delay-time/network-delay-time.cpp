class Solution {
public:
// dijakstra algo same to same from gfg
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        k--;
        vector<vector<pair<int,int>>>a(n);
        for(int i=0;i<times.size();i++){
            int s=times[i][0]-1;
            int d=times[i][1]-1;
            int t=times[i][2];
            a[s].push_back({d,t});
            // a[d].push_back({s,t});
        }
        vector<int>time(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        time[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            pair<int,int>p=pq.top();
            pq.pop();
            int t=p.first;
            int node=p.second;
            if(t>time[node]){
                continue;
            }else{
                for(int j=0;j<a[node].size();j++){ 
                    int neigh=a[node][j].first;
                    int weight=a[node][j].second;
                    if(t+weight<time[neigh]){
                        time[neigh]=t+weight;
                        pq.push({t+weight,neigh});
                    }
            }
            }
        }
        int maxi=*max_element(time.begin(),time.end());
    if(maxi==INT_MAX){
        return -1;
    }else{
        return maxi;
    }
    }
};