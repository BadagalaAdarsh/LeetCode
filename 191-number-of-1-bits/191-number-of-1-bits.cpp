class Solution {
public:
    int hammingWeight(uint32_t n) {
     
        int answer= 0;
        
        while(n){
            answer += (n&1);
            n >>= 1;
        }
        
        return answer;
    }
};