class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        for(int i=0;i<32;i++)
        {
            int remainder=n%2;
            n=n>>1;
            result=result*2+remainder;
        }
        return result;
    }
};
