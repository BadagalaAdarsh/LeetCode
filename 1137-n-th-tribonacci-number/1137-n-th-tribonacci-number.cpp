class Solution {
public:
    int tribonacci(int n) {
        
        if(n == 0) return 0;
        if( n ==1 || n == 2) return 1;
        
        vector<int> answer(n + 1);
        
        answer[0] = 0;
        answer[1] = 1;
        answer[2] = 1;
        
        for(int i = 3; i <= n; i++) {
            answer[i] = answer[i-3] + answer[i-2] + answer[i-1];
        }
        
        return answer[n];
        
    }
};