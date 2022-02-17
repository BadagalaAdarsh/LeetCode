class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        int count = 0;
        
        for (char ch: stones){
            for (char jew: jewels){
                if (ch == jew){
                    count++;
                }
            }
        }
        
        return count;
    }

};