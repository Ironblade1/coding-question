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
        unordered_map<int,int> count; // hash map to store the frequency of the elements in the subarray
        int i,j;  // variables i and j are used to keep track of the subarray boundaries
        for(i=0,j=0;j<fruits.size();j++){
            count[fruits[j]]++;  // increase the count of the current fruit
            if(count.size()>2){
                count[fruits[i]]--;
                if(count[fruits[i]] ==0){   // reduce the count of the first fruit and remove it from the map if its count becomes 0
                    count.erase(fruits[i]);  // move the start of the subarray to the right
                }
                i++;
            }
        }
        return j-i;    // return the length of the longest subarray with at most two unique elements





    }













};