class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int no_right_shift = 0;
        while(left!=right){
            left = left >> 1;
            right = right >> 1;
            no_right_shift++;
        }
        return left<<no_right_shift;
    }

};