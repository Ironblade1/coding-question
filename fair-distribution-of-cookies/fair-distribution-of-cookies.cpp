class Solution {
public:
    int ans = INT_MAX;
    void solve(vector<int>& c, int i, vector<int>& st){
        int k = st.size(), n = c.size();

        if(i==n){
            int maxi = 0;
            for(int j=0;j<k;j++)
                maxi = max(maxi, st[j]);
            ans = min(ans, maxi);
            return ;
        }

        for(int j=0;j<k;j++){
            st[j] += c[i];
            solve(c,i+1,st);
            st[j] -= c[i];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
         vector<int> st(k,0); // storing the number cookies each child get
         solve(cookies,0,st);
         return ans;
    }
};