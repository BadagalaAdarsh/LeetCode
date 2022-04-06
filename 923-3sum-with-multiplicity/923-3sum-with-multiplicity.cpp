class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        unordered_map<int,int> hashmap;
        int answer = 0, mod = 1e9 + 7;
        
        for(int i = 0; i < arr.size(); i++) {
            
            answer = (answer + hashmap[target - arr[i]]) % mod;
            
            for(int j = 0; j < i; j++){
                hashmap[arr[i] + arr[j]]++;
            }
         }
        
        return answer;
    }
};