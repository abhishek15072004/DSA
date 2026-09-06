class Solution {
public:
inline static int t[10001][10001];
int lcs(string& a,string& b,int n,int m){
    if(n==0 || m==0){
        return 0;
    }
    if(t[n][m]!=-1){
        return t[n][m];
    }
    if(a[n-1]==b[m-1]){
        return t[n][m]=1+lcs(a,b,n-1,m-1);
    }else{
        return t[n][m]= max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
    }
    return t[n-1][m-1];
}
    bool isSubsequence(string s, string k) {
        memset(t,-1,sizeof(t));
        int n=k.length();
        int m=s.length();
        return lcs(k,s,n,m)==m;
    }
};