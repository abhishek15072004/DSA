class Solution {
public:
int countnegative(vector<int>&a){
    int n=a.size();
    int lo=0,hi=n-1;
    int ans=n;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(a[mid]<0){
            hi=mid-1;
            ans=mid;
        }else{
            lo=mid+1;
        }
    }
    return n-ans;
}
// since sorted each row of matrix we can apply binary search on matrix
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ct=0;
        for(int i=0;i<n;i++){
            if(grid[i][m-1]<0){
             ct+=countnegative(grid[i]);
            }
        }
        return ct;
    }
};