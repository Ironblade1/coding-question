class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long sum = 0;
        int ind;
        long long cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                ind =i;
                cnt++;
            }
            else{
                sum+= (cnt*(cnt+1))/2;
            cnt =0;
            }
            
            
        }
        if(cnt !=0) sum += cnt*(cnt+1)/2;
        
        return sum;
    }
};