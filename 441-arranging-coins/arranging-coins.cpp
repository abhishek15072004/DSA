class Solution {
public:
    int arrangeCoins(int n) {
        int ct=0,i=1;
        while(n>0){
            n=n-i;
           i++;
           ct++;
        }
     if(n<0){
        return ct-1;
     }else{
        return ct;
     }
    }
};