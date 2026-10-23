class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
          int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
    while(lo<=hi){
        int k=lo+(hi-lo)/2;
         int totaldays = 1;
            int sum = 0;

            for (int it : weights) {
                if (sum + it > k) {
                    totaldays++;
                    sum = it;
                } else {
                    sum += it;
                }
            }
        if(totaldays<=days){
            hi=k-1;
        }else{
            lo=k+1;
        }
    } 
    return lo;   
    }
};