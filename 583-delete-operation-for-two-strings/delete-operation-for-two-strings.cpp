class Solution {
public:
inline static int t[501][501];
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
    int minDistance(string word1, string word2) {
        memset(t,-1,sizeof(t));
        int n=word1.size();
        int m=word2.size();
        int k=lcs(word1,word2,n,m);
       int ans= abs(n-k)+abs(m-k);
       return ans;
    }
};