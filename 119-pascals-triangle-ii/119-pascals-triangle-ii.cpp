class Solution {
public:
    vector<int> getRow(int rowIndex) {        
        
        long long res = 1;

        vector<int> answer;
        rowIndex++;
    
        for(int i = 0; i <= rowIndex; i++) {

            if (i == 0) {
                answer.push_back(1);
                continue;
            }

            res *= (rowIndex-i);
            res /= i;
            
            if(res != 0)
            answer.push_back((int)res);
        }
        
        return answer;

    }
};