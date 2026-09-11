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
        return t[n][m]= a[n-1]+lcs(a,b,n-1,m-1);
    }else{
        return t[n][m]= max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
    }
}
// string printlcs(string& a,string& b,int i,int j,string s){
//     while(i>0 && j>0){
//         if(a[i-1]==b[j-1]){
//             s.push_back(a[i-1]);
//             i--;
//             j--;
//         }else if(t[i][j-1]>t[i-1][j]){
//             j--;
//         }else{
//             i--;
//         }
//     }
//     return s;
// }
    int minimumDeleteSum(string s1, string s2) {
        memset(t,-1,sizeof(t));
        long long sum=0;
        for(char it:s1){
            sum+=it;
        }
        for(char it:s2){
            sum+=it;
        }
       int common= lcs(s1,s2,s1.size(),s2.size());
        // string c=printlcs(s1,s2,s1.size(),s2.size(),"");
       sum-=2*common;
        return sum;
    }
};