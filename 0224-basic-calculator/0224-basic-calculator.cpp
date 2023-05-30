class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int res = 0;
        int sum =0;
        int sign = 1;
        int n = s.length();
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                sum = s[i] - '0';
                while(i+1<n && isdigit(s[i+1])){
                    sum = sum*10 + (s[i+1]-'0');
                    i++;
                }
                res += sum*sign;
            }
            else if(s[i] == '+') sign = 1;
            else if(s[i] == '-') sign = -1;
            else if(s[i] == '('){
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }
            else if(s[i]==')'){
                int xsign = st.top();
                st.pop();
                int xres = st.top();
                st.pop();
                res = xsign*res + xres;
            }
        }
        return res;
    }
};