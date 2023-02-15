class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size()-1;
        int carry =0;
        int sum =0;
        vector<int> ans;
        while(n>=0 || carry>0 || k>0){
            sum = carry;
            if(k>0){
                int t = k%10;
                sum += t;
                k= k/10;
            }
            if(n>=0){
                sum += num[n];
                n--;
            }
            carry = sum/10;
            ans.push_back(sum%10);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};