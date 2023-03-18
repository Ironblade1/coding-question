class BrowserHistory {
public:
    vector<string> hist;
    int ind;
    BrowserHistory(string homepage) {
        hist.push_back(homepage);
        ind =0;
    }
    
    void visit(string url) {
        int l = hist.size()-1;
        while(l>ind){
            hist.pop_back();
            l--;
        }
        hist.push_back(url);
        ind++;
    }
    
    string back(int steps) {
        ind -= steps;
        if(ind<0) ind =0;
        return hist[ind];
    }
    
    string forward(int steps) {
        ind += steps;
        int l = hist.size()-1;
        if(ind>l) ind = l;
        return hist[ind];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */