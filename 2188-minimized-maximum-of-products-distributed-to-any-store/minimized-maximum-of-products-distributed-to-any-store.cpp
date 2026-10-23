class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
    int lo=1,hi=*max_element(quantities.begin(),quantities.end());
    while(lo<=hi){
        int k=lo+(hi-lo)/2;
        int totalsum=0;
        for(int it:quantities){
            totalsum+=ceil((double(it))/k);
        }
        if(totalsum<=n){
            hi=k-1;
        }else{
            lo=k+1;
        }
    } 
    return lo; 
    }
};