class Solution {
public:
    string reverseWords(string s) {
        string ans ="";
        string temp= "";
        bool started = false; // flag to indicate if we have started adding characters to temp
        for(int i=s.length()-1;i>=0;i--){
            if(s[i] == ' '){
                if(started){
                    reverse(temp.begin(),temp.end());
                    ans += temp + " "; // append a space after each reversed word
                }
                temp ="";
                started = false; // reset the flag
            }
            else{
                temp.push_back(s[i]);
                started = true; // set the flag to true
            }
        }
        if(started){ // check if there are any characters left in temp
            reverse(temp.begin(),temp.end());
            ans += temp;
        }
        else if(ans.length() > 0){ // remove the trailing space if it exists
            ans.pop_back();
        }
        return ans;
    }
};
