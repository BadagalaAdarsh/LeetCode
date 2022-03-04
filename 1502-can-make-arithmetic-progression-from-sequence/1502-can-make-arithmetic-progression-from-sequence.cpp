class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        unordered_set<int> uset(arr.begin(),arr.end());
        int max = *max_element(arr.begin(),arr.end());
        int min = *min_element(arr.begin(),arr.end());
        int diff = (max-min)/(arr.size()-1);
        for(int i=1;i<arr.size();i++){
            if(!uset.count(min + i * diff)){
                return false;
            }
        }
        return true;
    }
};