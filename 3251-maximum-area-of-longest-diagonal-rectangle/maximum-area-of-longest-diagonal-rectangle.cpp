class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
            int n=dimensions.size();
            int maxi=INT_MIN;
           int area=0;
        for(int i=0;i<n;i++){
        int diagonal=(dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1]);
        int currentarea=dimensions[i][0]*dimensions[i][1];
           if(diagonal>maxi){
            maxi=diagonal;
            area=currentarea;
           }else if(diagonal==maxi){
            area=max(area,currentarea);
           }
        }
        return area;
    }
};