class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int count = 0;
        
        sort(people.begin(), people.end());
        
        int left = 0, right = people.size() - 1;
        
        while(left <= right){
            
            if(people[left] + people[right] <= limit){
                count++;
                left++;
                right--;
            }
            
            else if(people[left] + people[right] > limit ){
                count++;
                right--;
            }
        }
        
        return count;
        
    }
};