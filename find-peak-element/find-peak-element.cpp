class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[mid + 1]) {
            // The peak must be on the right side
            left = mid + 1;
        } else {
            // The peak must be on the left side (including mid)
            right = mid;
        }
    }

    return left;
}

};