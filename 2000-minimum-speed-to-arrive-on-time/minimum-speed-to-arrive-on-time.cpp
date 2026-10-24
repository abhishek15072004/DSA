class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        long long lo=1,hi=1000000000;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            double sum=0;
            for(int i=0;i<dist.size();i++){
                if(i==dist.size()-1){
                    sum+=(double)dist[i]/mid;
                }else{
                    sum+=ceil((double)dist[i]/mid);
                }
                
            }
            if(sum>hour){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        if(lo>1000000000)return -1;
        return lo;
    }
};