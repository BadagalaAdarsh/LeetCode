class Solution {
public:
    int countVowelStrings(int n) {
        // (n  + 1) * (n  + 2) * (n + 3) * (n+4) / 4!
        
        return (n + 1) * (n + 2) * (n + 3) * (n +4) / 24;
    }
};