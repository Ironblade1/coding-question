class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length()) return 0;   // s and goal have different length 
        int n = s.length();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]] = i;
        }

        if(s==goal && mp.size() != goal.size()) return 1;  // in this edge case s and goal are indentical and they have duplicate element eg (s = "aa" and goal = "aa" if swap between 0 and 1 index then s and goal are identical)

        int i=0, j=0 ;
        bool flag = 0;   // using flag for doing only 1 swap
        while(i<n && j<n && !flag){
            if(s[i]!=goal[j]){
                char c = goal[j];
                int ind = mp[c];
                swap(s[i],s[ind]);
                flag = 1;
            }
            if(flag) break;
            i++;
            j++;
        }
        cout<<s;
        return (s==goal) && flag; // after 1 swap between 2 element checking s and goal are eqaul and also check their is swap process occured or not


    }
};