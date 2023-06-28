class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        int n = nums.size();
        int s = 0, e = n-1; 
        int mid = 0;
        while(s<=e){
             mid = e-(e-s)/2;
            if(target == nums[mid]){
                int i = mid,j = mid;
                while(i<n && nums[i] == target) i++;
                while(j>=0 && nums[j] == target) j--;
                ans = {j+1,i-1};
                break;
            }
            else if(target> nums[mid]) s= mid+1;
            else e = mid-1;
        }
        return ans;
    }
};