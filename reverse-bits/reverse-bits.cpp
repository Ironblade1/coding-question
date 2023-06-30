class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
       uint32_t res = 0;
       for(int i=0;i<32;i++){
           uint32_t lsb = n & 1;
           uint32_t revlsb = lsb<<(32-i-1); 
           res = res | revlsb;
           n= n>>1;
       } 
       return res;
    }
};