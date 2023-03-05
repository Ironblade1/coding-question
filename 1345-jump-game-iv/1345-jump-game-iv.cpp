#include <unordered_map>
#include<queue>

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>> indexofValues;
        for(int i=0;i<n;i++){
            indexofValues[arr[i]].push_back(i);
        }
        
        vector<bool> visi(n,0); visi[0]=1;
        queue<int> q; q.push(0);
        
        int steps =0;
        
        while(!q.empty()){
            for(int size=q.size();size>0;size--){
                
                int front = q.front(); q.pop();
                
                if(front==n-1) return steps;
                
                vector<int> next = indexofValues[arr[front]];
                next.push_back(front-1); next.push_back(front+1);
                
                for(int ind:next){
                    if(ind>=0 && ind<n && !visi[ind]){
                        visi[ind] = 1;
                        q.push(ind);
                    }
                }
                indexofValues[arr[front]].clear();
            }
            steps++;
        }
        return steps;
    }
};