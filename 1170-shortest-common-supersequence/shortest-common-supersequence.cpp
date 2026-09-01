class Solution {
public:
inline static int t[1001][1001];
// finding longest common subsequence
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
    return t[n][m]=max(lcs(a,b,n,m-1),lcs(a,b,n-1,m));
   }
}
// backtracing dp table and constructing longest common supersequence
string printlcs(string& a,string& b,string ans,int n,int m){
    int i=n,j=m;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
           ans.push_back(a[i-1]);
           i--;
           j--;
        }else{
            if(t[i-1][j]>t[i][j-1]){
                ans.push_back(a[i-1]);
                i--;
            }else{
                ans.push_back(b[j-1]);
                j--;
            }
        }
    }
    while(i>0){
        ans.push_back(a[i-1]);
        i--;
    }
    while(j>0){
        ans.push_back(b[j-1]);
        j--;
    }
    return ans;
}
    string shortestCommonSupersequence(string str1, string str2) {
        memset(t,-1,sizeof(t));
        int n=str1.size();
        int m=str2.size();
        lcs(str1,str2,n,m);
        string res=printlcs(str1,str2,"",n,m);
        reverse(res.begin(),res.end());
      return res;
          
        
    }
};