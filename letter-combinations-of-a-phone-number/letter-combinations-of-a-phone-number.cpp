class Solution {
public:
    void solve(string digits, int i, string s, vector<string>& ans, string map[]){
        if(i>= digits.length()){ 
            ans.push_back(s);
            return ;
        }
        int num = digits[i] - '0';
        string val = map[num];
        for(auto c:val){
            s.push_back(c);
            solve(digits,i+1,s,ans,map);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string s = "";
    vector<string> ans;
    if(digits.length()==0) return ans;
    solve(digits, 0, s,ans,mapping);
    return ans;
    }
};