class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1;
           int hi=*max_element(piles.begin(),piles.end());
           while(lo<=hi){
            int k=(lo+hi)/2;
            long long totalhour=0;
            for(int it:piles){
               totalhour+=ceil(double(it)/k);
            }
            if(totalhour<=h){
                hi=k-1;
            }else{
                lo=k+1;
            }
           }
           return lo;
    }
};