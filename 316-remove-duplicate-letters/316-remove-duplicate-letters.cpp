class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> dict(256, 0);
        vector<bool> visited(256, false);
        
        for(char ch: s) dict[ch]++;
        
        string answer = "";
        
        for(char ch: s) {
            dict[ch]--;
            
            if (visited[ch]) continue;
            
            if(answer.size() == 0){
                answer += ch;
                visited[ch] = true;
                continue;
            }
            
            while(ch < answer.back() && dict[answer.back()]){
                visited[answer.back()] = false;
                cout << answer.back() << " " ;
                answer.pop_back();
            }
            
            answer += ch;
            visited[ch] = true;
        }
        
        return answer;
    }
};