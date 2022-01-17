class Solution {
private:
    void helper(vector<string>&result, int open, int close, string& current, int n) {
        
        if(open == n && close == n) {
            result.push_back(current);
            return ;
        }
        
        if(open < n) {
            current.push_back('(');
            helper(result, open+1, close, current, n);
            current.pop_back();
        }
        
        if(close < open) {
            current.push_back(')');
            helper(result, open, close+1, current, n);
            current.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        string current;
        helper(result, 0, 0, current, n);
        
        return result;
    }
};