class Solution {
public:

// brute force 

    int solve(vector<int>& fruits){
        int bas[2];
        int n = fruits.size();
        int maxi = 0;
        vector<vector<int>> f;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                vector<int> ft;
               for(int k=i;k<=j;k++){
                   ft.push_back(fruits[k]);
               }
               f.push_back(ft);
            }
        }
        for(auto ft:f){
            for(auto i:ft){
                cout<<i<<" ";
            }cout<<endl;
        }

        for(auto ft:f){
            int ans = ft.size();
            if(set(ft.begin(),ft.end()).size() == 2 || set(ft.begin(),ft.end()).size() == 1){
                maxi = max(maxi,ans);
            }
            
        }
        return maxi;
    }

    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> count;
        int i,j;
        for(i=0,j=0;j<fruits.size();j++){
            count[fruits[j]]++;
            if(count.size()>2){
                count[fruits[i]]--;
                if(count[fruits[i]] ==0){
                    count.erase(fruits[i]);
                }
                i++;
            }
        }
        return j-i;





    }













};