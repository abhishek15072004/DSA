class Solution {
public:
// long long binarttonumber(string s){
//     long long ans=0;
//     for(int i=0;i<s.size();i++){
//         ans=ans*2+(s[i]-'0');
//     }
//     return ans;
// }
// string converttobinary(long long n){
//     long long sum=0;
//     while(n>0){
//         long long rem=n%2;
//         sum=sum*10+rem;
//         n=n/2;

//     }
//     string ans=to_string(sum);
//     reverse(ans.begin(),ans.end());
//     return ans;
// }
    string addBinary(string a, string b) {
        // long long k=binarttonumber(a);
        // long long l=binarttonumber(b);
        // long long m=k+l;
        // return converttobinary(m);
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        string ans="";
        while(i>=0 || j>=0 || carry){
            int sum=carry;
            if(i>=0){
                sum+=a[i]-'0';
                i--;
            }
            if(j>=0){
                sum+=b[j]-'0';
                j--;
            }
            ans+=(sum%2)+'0';
            carry=sum/2;
        }
reverse(ans.begin(),ans.end());
        return ans;
    }
};