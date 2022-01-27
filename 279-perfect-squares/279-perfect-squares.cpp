class Solution {
public:
    int numSquares(int n) {
        if (n == 0) return 1;
        
        while (!(n&3))
            n /= 4; /* divide out by square does not change result */
        
        int foo = (int) sqrt(n);
        if (foo*foo == n) return 1; /* test if perfect square */
        
        for (int i = 0; i <= foo; i++) { /* brute force combinations of two squares */
            for (int j = i; j <= n - i*i; j++) { 
                if (i*i + j*j == n) return 2;
            }
        }
        
        if (n%8 == 7) return 4; /* every number is a sum of 4 squares */
        return 3; /* if it is not of the form 4^a (8b+7) then it's a sum of 3 squares */
        
    }
};