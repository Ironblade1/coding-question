class Solution {
public:

    int hcf(int n1 , int n2){
        int maxi =1;
        for(int i=1;i<=n1;i++){
            if(n1%i==0 && n2%i==0){
                maxi = max(maxi,i);
            }
        }
        return maxi;
    }

    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 == str2+str1){
            return str1.substr(0,__gcd(str1.size(),str2.size()));
        }
        return "";
    }
};