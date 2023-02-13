class Solution {
public:

    int merge(vector<int> &nums, int s,int mid, int e){
        int cnt =0;
        int j = mid+1;
        for(int i=s;i<=mid;i++){
            while(j <= e && (nums[i] > 2*(long)nums[j]) ){
                j++;
            }       
            cnt += (j-(mid+1));     
        }

        vector<int> temp;
        int left = s, right = mid+1;

        while(left<= mid && right<=e){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left++]);
            }
            else{
                temp.push_back(nums[right++]);
            }
        }

        while(left<=mid){
            temp.push_back(nums[left++]);
        }

        while(right<=e){
            temp.push_back(nums[right++]);
        }

        for(int i=s; i<=e;i++){
            nums[i] = temp[i-s];
        }
        return cnt;
    }

    int mergeSort(vector<int>& nums, int s, int e){
        if(s>=e) return 0;
        int mid = (s+e)/2;
        int inv = mergeSort(nums,s,mid);
        inv += mergeSort(nums,mid+1,e);
        inv += merge(nums,s,mid,e);
        return inv;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0,nums.size()-1);
    }
};