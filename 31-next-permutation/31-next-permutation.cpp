class Solution {
public:
    void nextPermutation(vector<int>& nums) {
            int n = nums.size();

    // find the first element that is smaller than its next element
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;
        
    // if no such element exists, then the array is already in descending order
    if (i >= 0) {
        // find the first element that is greater than nums[i]
        int j = n - 1;
        while (j >= 0 && nums[j] <= nums[i])
            j--;
        
        // swap nums[i] and nums[j]
        swap(nums[i], nums[j]);
    }

    // reverse the array from nums[i + 1] to the end
    reverse(nums.begin() + i + 1, nums.end());
    }
};