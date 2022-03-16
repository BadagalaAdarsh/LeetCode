class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        
        int index = 0;
        for(int num: pushed){
            st.push(num);
            
            while(!st.empty() && st.top() == popped[index]){
                st.pop();
                index++;
            }
        }
        
        return st.size() == 0;
    }
};