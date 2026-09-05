class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> mp;
        unordered_set<int> bad;

        for(int i = 0; i < nums.size(); i++) {

            // New block starts
            if(i == 0 || nums[i] != nums[i-1]) {

                if(mp.count(nums[i])) {
                    bad.insert(nums[i]);
                }

                mp[nums[i]] = 1;
            }
        }

        int ans = 0;

        for(auto x : mp) {
            if(!bad.count(x.first)) {
                ans++;
            }
        }

        return ans;
    }
};