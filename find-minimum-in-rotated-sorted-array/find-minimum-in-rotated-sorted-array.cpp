class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;

        // Check if the array is sorted (not rotated)
        if (nums[s] <= nums[e])
            return nums[s];

        while (s <= e) {
            int mid = s + (e - s) / 2;

            // Check if mid is the minimum element
            if (nums[mid] > nums[mid + 1])
                return nums[mid + 1];

            // Check if mid-1 is the minimum element
            if (nums[mid - 1] > nums[mid])
                return nums[mid];

            // If the above conditions are not satisfied, adjust search range
            if (nums[mid] > nums[e])
                s = mid + 1;
            else
                e = mid - 1;
        }

        // This line will never be reached, as the minimum element will always be found before the loop ends
        return -1;
    }
};
