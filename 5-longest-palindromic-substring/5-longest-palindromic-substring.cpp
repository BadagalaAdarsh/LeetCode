class Solution {
public:
    pair<int,int> getstring(string& s, int center1, int center2){
        
       
        
        int left = center1, right = center2;
        
        while(left >= 0 && right <= (int)s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        
        
        return {++left, --right};
        
    }
    
    string longestPalindrome(string s) {
        
        
        pair<int, int> answer (0,0);
        
        for(int i = 0; i < (int)s.length(); i++){
            pair<int,int> even = getstring(s, i, i+1);
            pair<int,int> odd = getstring(s, i , i);
            cout << "even" << even.first << even.second << " " << "odd" << odd.first << odd.second << " " << s[i] << endl;
            answer = (even.second - even.first > odd.second - odd.first) ? (answer.second- answer.first > even.second - even.first ? answer : even) : (answer.second - answer.first > odd.second - odd.first ? answer : odd);
        }
        
        cout << "final answer is " << answer.first << " " << answer.second;
        
        return s.substr(answer.first, answer.second - answer.first + 1);
        
    }
};