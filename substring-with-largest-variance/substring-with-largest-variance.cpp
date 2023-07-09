class Solution {
public:
    int largestVariance(string s) {
        unordered_set<char> set;
        for(auto c:s){
            set.insert(c);
        }
        
        for(auto i:set){
            cout<<i<<" ";
        }

        int ans = 0;
        for(auto i:set){
            for(auto j:set){
                if(i==j) continue;

                for(int k=0;k<2;k++){
                    int c1 = 0; // counter for i;
                    int c2 = 0; // counter for j;
                    for(auto c:s){
                        if(c==i) c1++;
                        if(c==j) c2++;
                        
                        if(c2>c1){
                            c2=0;
                            c1 = 0;
                        }
                        if(c1>0 && c2>0)
                            ans = max(ans, c1-c2);
                    }
                    reverse(s.begin(),s.end());
                }
            }
        }
        return ans;
    }
};