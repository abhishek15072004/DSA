class Solution {
public:
inline static int t[1001][1001];
int lcs(string& a,string& b,int n,int m){
    if(n==0 || m==0){
        return 0;
    }
    if(t[n][m]!=-1){
        return t[n][m];
    }
    if(a[n-1]==b[m-1]){ 
        return t[n][m]= 1+lcs(a,b,n-1,m-1);
}else{
    return t[n][m]=max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
}
return t[n-1][m-1];
}
    int longestPalindromeSubseq(string s) {
        memset(t,-1,sizeof(t));
        int n=s.size();
        string b="";
       for(int i=n-1;i>=0;i--){
        b+=s[i];
       }
        
        int m=b.size();
        int ans=lcs(s,b,n,m);
        return ans;
    }
};