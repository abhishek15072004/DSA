class Solution {
public:
bool check(string& s,int i,string a){
for(int j=i;j<s.size();j+=i){
    if(s.substr(j,i)!=a){
        return false;
    }
}
return true;
}
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=1;i<=n/2;i++){
           string a=s.substr(0,i);
           if(check(s,i,a)){
            return true;
           }
        }
        return false;
    }
};