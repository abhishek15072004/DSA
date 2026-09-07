class Solution {
public:

    int numMatchingSubseq(string s, vector<string>& words) {
     unordered_map<char,vector<int>>m;
     for(int i=0;i<s.size();i++){
        m[s[i]].push_back(i);
     }
     int ans=0;
     for(auto word:words){
        int prev=-1;
        bool check=true;
        for(char ch:word){
            auto it=upper_bound(m[ch].begin(),m[ch].end(),prev);
            if(it==m[ch].end()){
                check=false;
                break;
            }
            prev=*it;
        }
        if(check)ans++;
     }
     return ans;
    }
};