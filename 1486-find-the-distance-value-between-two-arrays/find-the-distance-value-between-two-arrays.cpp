class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ct=0;
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<arr1.size();i++){
            int a=lower_bound(arr2.begin(),arr2.end(),arr1[i])-arr2.begin();

            bool valid=true;
            if(a<arr2.size() && abs(arr2[a]-arr1[i])<=d){
                valid=false;
            }
            if(a>0 && abs(arr2[a-1]-arr1[i])<=d){
                valid=false;
            }
            if(valid)ct++;
        }
        return ct;
    }
};