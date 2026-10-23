class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo=1,hi=*max_element(nums.begin(),nums.end());
        while(lo<=hi){
            int k=lo+(hi-lo)/2;
            int totalsum=0;
            for(int it:nums){
                totalsum+=ceil(double(it)/k);
            }
            if(totalsum<=threshold){
              
                 hi=k-1;
            }else{
                 lo=k+1;
            }
        }
        return lo;
    }
};