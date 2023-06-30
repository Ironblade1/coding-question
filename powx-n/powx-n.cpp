class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n==1) return x;
        if(n==-1) return 1/x;

        if(n%2==0){
            double ans = myPow(x,n/2);
            return ans*ans;
        }
        else{
            if(n<0){
                double ans = myPow(x,n/2);
                return ans*ans*1/x;
            }
            else{
                double ans = myPow(x,n/2);
                return ans*ans*x;
            }
        }
        return 0;
    }
};