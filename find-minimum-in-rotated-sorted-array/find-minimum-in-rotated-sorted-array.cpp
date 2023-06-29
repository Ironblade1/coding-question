class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int s = 0, e = n-1;
        

        if(nums[s]<=nums[e]) return nums[s];
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]>nums[mid+1]) return nums[mid+1];
            if(nums[mid-1]>nums[mid]) return nums[mid];

             if(nums[mid]>nums[e])  s = mid+1;
            else e = mid-1;
            // mid = e-(e-s)/2;
        }
        return -1;
    }
};