class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string rs = s;
        reverse(rs.begin(),rs.end());
        return (s == rs);
    }
};