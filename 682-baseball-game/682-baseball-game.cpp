class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        stack<int> st;
        
        for(auto op: ops){
            if(op != "C" && op != "D" && op != "+") {
                st.push(stoi(op));
            }
            
            else if(op == "C"){
                st.pop();
            }
            
            else if(op == "D"){
                int topElement = st.top();
                topElement = 2 * topElement;
                st.push(topElement);
            }
            
            else if(op == "+"){
                int one = st.top();
                st.pop();
                
                int two = st.top();
                st.push(one);
                st.push(one + two);
            }
        }
        
        int answer = 0;
        
        while(!st.empty()){
            int num = st.top();
            st.pop();
            cout << num << endl;
            
            answer += num;
        }
        
        return answer;
    }
};