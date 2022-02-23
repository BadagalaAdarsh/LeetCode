class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char> st;
        int answer = 0;
        
        for(char ch: s) {
            if (ch == '(')
                st.push(ch);
            else if (ch == ')'){
                if (!st.empty()){
                    st.pop();
                }
               else{
                   answer++;
               }
            }
        }
        
        return answer + (int)st.size();
    }
};