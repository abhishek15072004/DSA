class Solution {
public:
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 1;
        }
        vector<int>tribonaci(n+1);
        tribonaci[0]=0;
        tribonaci[1]=1;
        tribonaci[2]=1;
        for(int i=3;i<n+1;i++){
            tribonaci[i]=tribonaci[i-1]+tribonaci[i-2]+tribonaci[i-3];
        }
        return tribonaci[n];
    }
};