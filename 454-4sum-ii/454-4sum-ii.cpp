class Solution {
private:
    void addToMap(map<int,int>& hashmap, vector<int>& array) {
        
        for(int num: array){
            hashmap[num]++;
        }
    }
    
    void findSum(map<int,int>& hashmap1, map<int,int>& hashmap2, map<int,int>& sum) {
        
        for(auto [key1, value1]: hashmap1){
            for(auto [key2, value2]: hashmap2) {
                int currentSum = key1 + key2;
                sum[currentSum] += value1 * value2;
            }
        }
    }
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
      
        map<int,int> hashmap1;
        map<int,int> hashmap2;
        map<int,int> hashmap3;
        map<int,int> hashmap4;
        
        // adding to map
        addToMap(hashmap1, nums1);
        addToMap(hashmap2, nums2);
        addToMap(hashmap3, nums3);
        addToMap(hashmap4, nums4);
        
            
        int count = 0;
        
        map<int,int> sum1;
        map<int,int> sum2;
        
        // find sum
        findSum(hashmap1, hashmap2, sum1);
        findSum(hashmap3, hashmap4, sum2);
        
        for(auto [sum, occur]: sum1) {
            
            int required = 0-sum;
            
            if(sum2.find(required) != sum2.end()){
                count += occur * sum2[required];
            }
        }
        
        return count;      
        
        
    }
};