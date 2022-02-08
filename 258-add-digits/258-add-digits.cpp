class Solution {
public:
    int addDigits(int num) {
        
        if (num < 10) return num;
        
        int answer = 0;
        
        while(num) {
            answer += num%10;
            num /= 10;
  
        }
        
        return addDigits(answer);
    }
};