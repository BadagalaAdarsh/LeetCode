/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    vector<int> nums;
    Solution(ListNode* head) {
        
        while(head) {
            nums.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        
    int max = nums.size() -1;
    int min = 0;
    int range = max - min + 1;
    int num = rand() % range + min;

        
       ;
        
        return nums[num];
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */