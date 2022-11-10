class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char> st;
        
        for(char ch: s) {
            if (st.size() != 0 ){
                if (st.top() == ch) {
                    st.pop();
                }
                else {
                    st.push(ch);
                }
            }
            else{
                st.push(ch);
            }
        }
        
        string answer = "";
        
        while(st.size() != 0) {
            char ch = st.top();
            st.pop();
            answer += ch;
        }
        
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};