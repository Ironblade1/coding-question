class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = arr[n-1];
        int ans;
        int cnt =0;
        for(int i=1;i<=1000+k+1;i++){
            if(find(arr.begin(),arr.end(), i) == arr.end()){
                cnt++;
                ans =i;
                if(cnt == k) break;
            }
        }
        // for(int i:ans) cout<<i<<",";
        return ans;
    }
};