class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int>st; // helper stack for finding matching parentheses
        
        for(int i=0;i<s.length();++i){
            if(s[i]=='('){ // for open parentheses push into stack
                st.push(i);
            }
            else if(s[i]==')'){ // for closing parentheses
                // if no matching previous open parentheses found, we need to remove the index of that open parentheses from "s" so for now we are marking it with special character '#'
                if(st.empty()){ 
                    s[i]='#';
                }
                else{
                    // if matching open parentheses found remove that from the stack
                    st.pop();
                }
            }
        }

        // if stack is not empty, that means it contains open parentheses indexes which don't have any matching closing parentheses
        while(!st.empty()){
            s[st.top()]='#';
            st.pop();
        }
        
        string ans="";
        for(int i=0;i<s.length();++i){
            if(s[i]!='#'){ // append not marked character to the end of "ans"
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};