class Solution {
public:
    int minMaxDifference(int num) {
        int max_num = num;
        int min_num = num;
        for (int d1 = 0; d1 < 10; d1++) {
            for (int d2 = 0; d2 < 10; d2++) {
                string new_num = to_string(num);
                replace(new_num.begin(), new_num.end(), '0' + d1, '0' + d2);
                if (new_num != to_string(num)) {
                    max_num = max(max_num, stoi(new_num));
                    min_num = min(min_num, stoi(new_num));
                }
            }
        }
        return max_num - min_num;
    }
};