class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        // alone sorting by price is not efficient when testcase like this come
        // items = {{1, 2}, {2, 10}, {3, 4}};
        // queries = {3};
        // my output=4
        // expected=10 which is highest beauty we can get by paying price less than equal to queries[i] 


        // it stores the maximum beauty seen so far after sorting by price.
        int maxi=0;
        for(int i=0;i<items.size();i++){
          maxi=max(maxi,items[i][1]);
          items[i][1]=maxi;
        }

        vector<int>ans(queries.size(),0);
        for(int i=0;i<queries.size();i++){
            auto it=upper_bound(items.begin(),items.end(),vector<int>{queries[i],INT_MAX});
           if(it!=items.begin()){
            it--;
            // *it[1]  because of vector in pair we use it.second
            ans[i]=(*it)[1];
           }
        }
        return ans;
    }
};