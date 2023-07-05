class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2)
            return s;
        
        int n = s.length();
        int start = 0;
        int maxLength = 1;
        
        // Expand around center
        for (int i = 0; i < n; i++) {
            // For odd length palindrome
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLength) {
                    maxLength = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
            
            // For even length palindrome
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLength) {
                    maxLength = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
        }
        
        return s.substr(start, maxLength);
    }
};
