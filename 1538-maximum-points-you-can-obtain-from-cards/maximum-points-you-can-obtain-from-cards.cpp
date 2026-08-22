class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int sum=0;
        int maxi=0;
    for(int i=0;i<k && i<a.size();i++){
sum+=a[i];
maxi=max(sum,maxi);
    }
    int r=a.size()-1;
    while(k && r>=0 ){
        sum=sum-a[k-1]+a[r];
        maxi=max(maxi,sum);
        k--,r--;
    }
    return maxi;
    }
};