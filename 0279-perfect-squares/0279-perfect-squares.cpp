class Solution {
public:
    int numSquares(int n) {
        if (n == 0) return 0;
        
        while (!(n&3))
            n /= 4;
        
        int foo = (int) sqrt(n);
        if (foo*foo == n) return 1; 
        
        for (int i = 0; i <= foo; i++) {
            for (int j = i; j <= n - i*i; j++) { 
                if (i*i + j*j == n) return 2;
            }
        }
        
        if (n%8 == 7) return 4; 
        return 3; 
        
    }
};