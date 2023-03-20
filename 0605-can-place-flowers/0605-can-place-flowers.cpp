class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        if(n==0) return true;
        int l = fb.size();
        for(int i=0;i<fb.size();i++){
            if(fb[i]==0 && (i==0 || fb[i-1]==0) && (i==l-1 || fb[i+1]==0)){
                fb[i]=1;
                n--;
            }
            if(n==0) return true;
        }
        return false;
    }
};