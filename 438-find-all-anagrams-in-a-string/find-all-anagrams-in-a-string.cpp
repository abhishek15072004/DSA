class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(p.length()>s.length()){
            return ans;
        }
        vector<int>freqp(26,0);
        vector<int>freqwin(26,0);
        for(auto it:p){
            freqp[it-'a']++;
        }
        int left=0;
        for(int right=0;right<s.size();right++){
            freqwin[s[right]-'a']++;
            if(right-left+1>p.size()){
                freqwin[s[left]-'a']--;
                left++;
            }
            if(right-left+1==p.size()){
                if(freqp==freqwin){
                    ans.push_back(left);
                }
            }
        }
        return ans;
    }
};