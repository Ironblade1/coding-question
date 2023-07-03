class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length()) return 0;
        int n = s.length();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]] = i;
        }

        if(s==goal && mp.size() != goal.size()) return 1;

        int i=0, j=0 ;
        bool flag = 0;
        while(i<n && j<n && !flag){
            if(s[i]!=goal[j]){
                char c = goal[j];
                int ind = mp[c];
                swap(s[i],s[ind]);
                flag = 1;
            }
            i++;
            j++;
        }
        cout<<s;
        return (s==goal) && flag;


    }
};