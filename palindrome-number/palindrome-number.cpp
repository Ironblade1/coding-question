class Solution {
private:
    bool checkPalindrome(string s ,int i ,int j){
        if(i>j){
            return true;
        }
        if(s[i]!=s[j]){
            return false;
        }
        else{
            return (checkPalindrome(s,++i,--j));
        }  
    }
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        bool ans = checkPalindrome(s,0,s.length()-1);
        return ans;
    }
};