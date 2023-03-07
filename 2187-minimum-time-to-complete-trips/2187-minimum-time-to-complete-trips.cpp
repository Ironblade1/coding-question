class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long s = 1;
        long long e = 1e14;
        
        while(s<=e){
            long long mid = s+ (e-s)/2;
            long long covTrip = 0;
            for(int i:time)
                covTrip += mid/i;
            
            if(covTrip>=totalTrips) 
                e = mid-1;
            else
                s = mid+1;
        }
        return s;
    }
};