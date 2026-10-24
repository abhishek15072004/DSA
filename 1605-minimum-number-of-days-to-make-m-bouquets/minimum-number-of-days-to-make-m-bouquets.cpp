class Solution {
public:
bool possible(vector<int>& bloomDay,int day,int m,int k){
    int flower=0,bouquet=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=day){
            flower++;
            if(flower==k){
                bouquet++;
                flower=0;
            }
        }else{
            flower=0;
        }
    }
    return m<=bouquet;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size())return -1;
        int lo=*min_element(bloomDay.begin(),bloomDay.end());
        int hi=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(possible(bloomDay,mid,m,k)){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
};