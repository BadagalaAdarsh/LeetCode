class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        stack<pair<int,int>> leftSmall, rightSmall;
        
        vector<int> left(arr.size()), right(arr.size());
        
        for(int i = 0; i < arr.size(); i++) {
            left[i] = i + 1;
            right[i] = arr.size() - i;
        }
        
        for(int i = 0; i < arr.size(); i++) {
            
            while(!leftSmall.empty() && leftSmall.top().first > arr[i]) leftSmall.pop();
            left[i] = leftSmall.empty() ? i + 1: i - leftSmall.top().second;
            leftSmall.push({arr[i], i});
            
            
            while(!rightSmall.empty() && rightSmall.top().first > arr[i]) {
                auto x = rightSmall.top();
                rightSmall.pop();
                right[x.second] = i - x.second;
            }
            
            rightSmall.push({arr[i], i});
        }
        
        long answer = 0;
        const int MOD = 1e9 + 7;
        
        for(int i = 0; i < arr.size(); i++) {
            answer = (long)(answer + (long)arr[i] * (long)left[i] * (long)right[i]) % MOD;
        }
        
        return (int)answer;
    }
};