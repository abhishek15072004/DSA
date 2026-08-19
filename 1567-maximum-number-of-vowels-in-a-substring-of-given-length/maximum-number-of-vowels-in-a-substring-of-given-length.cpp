class Solution {
public:
bool isvowel(char c){
    return c=='a'|| c=='e' || c=='i' || c=='o' || c=='u';
}
    int maxVowels(string s, int k) {
        int l=0,vowel=0,ans=0;
        for(int i=0;i<s.size();i++){
        if(isvowel(s[i])){
            vowel++;
        }
           if(i-l+1==k){
            ans=max(ans,vowel);
            if(isvowel(s[l])){
                vowel--;
            }
            l++;
           }
        }
        return ans;
    }
};