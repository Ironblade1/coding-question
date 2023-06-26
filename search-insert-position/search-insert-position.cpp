class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        
        int mid = e-(e-s)/2;
        while(s<=e){
            if(nums[mid]== target) return mid;
            
            if(nums[mid]>target) e = mid-1;
            else{
                s = mid+1;
            }
            mid = e-(e-s)/2;
        }
        return s;
    }
};