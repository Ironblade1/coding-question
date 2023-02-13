class Solution {
public:
    int countOdds(int low, int high) {
        int cnt =0;
        for(low;low<=high;low++){
            if(low%2) cnt++;
        }   
        return cnt;
    }
};