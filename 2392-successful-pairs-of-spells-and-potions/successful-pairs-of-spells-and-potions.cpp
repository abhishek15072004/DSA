class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans(spells.size(),0);
        for(int i=0;i<spells.size();i++){
            long long target=ceil((double)success/spells[i]);
            int a=lower_bound(potions.begin(),potions.end(),target)-potions.begin();
           
           ans[i]=potions.size()-a;
        }
        return ans;
    }
};