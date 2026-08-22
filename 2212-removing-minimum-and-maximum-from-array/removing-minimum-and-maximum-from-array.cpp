class Solution {
public:
    int minimumDeletions(vector<int>& v) {
        int maxi=*max_element(v.begin(),v.end());
        int mini=*min_element(v.begin(),v.end());
        int maxi_index=0,mini_index=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==maxi){
                maxi_index=i;
            }
            if(v[i]==mini){
                mini_index=i;
            }
        }
      int left=min(maxi_index,mini_index);
      int right=max(maxi_index,mini_index);
      int n=v.size();
     int a=n-left;
     int b=right+1;
     int c=left+1+n-right;
     return min({a,b,c});
      
    }
};