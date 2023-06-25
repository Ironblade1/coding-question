class Solution {
public:
    void printParenthesis(int ind,vector<string> &v,int n,int open,int close,string &s){
        if(ind == n){ // base case
            v.push_back(s); // we add final string to vector v
            return; // we return back the control to function
        }

        if(open > 0 && ind != n-1){ // we take "("
            s += "("; // adding "(" to string s
            printParenthesis(ind+1,v,n,open-1,close,s); // recursive function call
            s.pop_back(); // we have to take out "(" before returning the control to prev function. 
        }
        
        if(close > 0 && open < close){
            s += ")";
            printParenthesis(ind+1,v,n,open,close-1,s);
            s.pop_back();
        }

        return ;
       
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        int open = n-1;
        int close = n;
        n *= 2;
        string s = "(";
        
        printParenthesis(1,v,n,open,close,s);

        return v;
    }
};