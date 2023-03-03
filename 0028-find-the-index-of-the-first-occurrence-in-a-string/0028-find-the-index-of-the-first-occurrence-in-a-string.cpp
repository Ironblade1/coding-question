class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = -1;
        int needleSize = needle.size();
        int i=0;
        
        while(i<haystack.size()){
            int n = find(haystack.begin()+i,haystack.end(),needle[0])-haystack.begin();
            string st = haystack.substr(n,needleSize);
            
            if(st == needle){
                ans = n;
                break;
            }
            else{
                i++;
                // continue;
            }
        }
        // if(ans != -1) return ans;
        // else return -1;
        return ans;
    }
};