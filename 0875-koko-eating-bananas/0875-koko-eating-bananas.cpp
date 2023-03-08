class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        
        sort(piles.begin(),piles.end());
        // int s = piles[0];
        int e = piles[piles.size()-1];
        
        int s = 1;
        // int e = piles[];
        
        while(s<=e){
            long long t =0;
            int mid = s+(e-s)/2;
            for(int pile:piles){
                if(pile%mid==0) t += pile/mid;
                else{
                    t += pile/mid + 1;
                }
            }
            
            if(t<=h) e = mid-1;
            else s = mid+1;
        }
        return s;
    }
};