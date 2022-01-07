class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t answer = 0;
        
        int start = 31;
        
        while(start >= 0) {
            
            int bit = n&1;
            
            if (bit)
                answer = answer | (1 << start);
            
            start--;
            n = n >> 1;
        }
        
        return answer;
        
    }
};