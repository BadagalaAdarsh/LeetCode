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
    ListNode* headNode;
    Solution(ListNode* head) {
        headNode = head;
    }
    
    int getRandom() {
        // normal method is to push every thing into vector in constructor
        // then get rand() % length of vector as current index return that element
        // it needs order of n space to store all the elements in the list
        
        
        // reservoir sampling algorithm
        
        int result;
        int length = 1; // assuming only one element in the list;
        
        ListNode* currentNode = headNode;
        
        while(currentNode) {
            
            if(rand() % length == 0) 
                result = currentNode->val;
            
            length++;
            currentNode = currentNode->next;
        }
        
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */