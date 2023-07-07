class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int left = 0, right = 0, ct = 0, cf = 0, len = 0;

        for (right; right < n; right++) {
            if (answerKey[right] == 'T') ct++;
            else cf++;

            while (min(cf, ct) > k) {
                if (answerKey[left] == 'T') ct--;
                else cf--;
                left++;
            }

            len = max(len, right - left + 1);
        }
        return len;
    }
};
