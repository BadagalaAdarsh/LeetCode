class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> answer(stones.begin(), stones.end());
        
        while(answer.size() >= 2){
            
            int y = answer.top();
            answer.pop();
            
            int x = answer.top();
            answer.pop();
            
            if (x!=y){
                answer.push(y-x);
            }
        }
        
        if (answer.size() == 0){
            return 0;
        }
        
        return answer.top();
        
    }
};