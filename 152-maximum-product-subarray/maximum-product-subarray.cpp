class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int prdt=1;
        int maxi=INT_MIN;

        // traversing left to right
        for(int i=0;i<n;i++){
            prdt*=nums[i];
            maxi=max(maxi,prdt);
            if(prdt==0){
                prdt=1;
            }
        }

        prdt=1;
// traversing right to left 
          for(int i=n-1;i>=0;i--){
            prdt*=nums[i];
            maxi=max(maxi,prdt);
            if(prdt==0){
                prdt=1;
            }
        }
        return maxi;
    }
};