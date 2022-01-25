class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        if(arr.size() < 3) return false;
        
        int i =1;
        
        int increase = 0;
        
        for( ; i < arr.size(); i++){
            
            if(arr[i] <= arr[i-1])
                break;
            increase++;
        }
        
        int decrease = 0;
        for( ; i < arr.size(); i++) {
            if (arr[i] >= arr[i-1])
                break;
            
            decrease--;
        }
        
        return i == (int)arr.size() && decrease != 0 && increase != 0;
        
    }
};