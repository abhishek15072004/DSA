class Solution {
public:
long long mod=1000000007;
// Recursion method
// calculating power from recursion without pow() function due to overflow
long long power(long long a,long long n){
    if(n==0){
        return 1;
     }
     long long ans=power(a,n/2);
     if(n%2==0){
        return (ans*ans)%mod;
     }
     return (((a*ans)%mod)*ans)%mod;
}
    int countGoodNumbers(long long n) {
        long long evenposition=(n+1)/2;
        long long oddposition=(n)/2;
        long long ans=power(5,evenposition)*power(4,oddposition)%mod;
        return ans;
    }
};