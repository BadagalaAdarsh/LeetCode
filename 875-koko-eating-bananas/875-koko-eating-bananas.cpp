class Solution {
    
private:
    bool canEat(vector<int>&piles, int k , int h) {
        
        int currentTime = 0;
        for(int pile: piles) {
            int div = pile/k;
            currentTime += div;
            
            if(pile % k != 0) currentTime++; // if it is not exactly divisible then taking one more as alternative to ceil
        }
        
        return currentTime <= h;
    
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while(left <= right) {
            
            int mid = left + ((right - left) >> 1);
            
            if (canEat(piles, mid, h) ) right = mid - 1;
            else left = mid + 1;
        }
        
        return left;
    }
};