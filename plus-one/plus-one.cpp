class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int val = digits[n-1]+1;
        int carry = val/10;
        digits[n-1] = val%10;
        int i= n-2;
        while(carry!=0 && i>=0){
            int v = carry + digits[i];
            carry = v/10;
            digits[i] = v%10;
            i--;
        }
        if(carry!=0){
            int v = carry;
            digits.insert(digits.begin(), v);
        }
        return digits;
    }
};