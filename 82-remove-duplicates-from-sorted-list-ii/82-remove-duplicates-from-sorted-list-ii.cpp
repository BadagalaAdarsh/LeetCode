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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* auxiliary_head = new ListNode(-1);
        ListNode* iter = auxiliary_head;
        
        while(head != NULL) {
            
            if(head->next && head->val == head->next->val) {
                
                // if current node value is equal to its next value
                int current = head->val;
                while(head && head->val == current) 
                    head = head->next;
            }
            
            else{
                // assing node to next iterator
                iter->next = head;
                iter = iter->next;
                head = head->next;
            }
        }
        
        iter->next = NULL;
        
        // because our dummy node is before the actual head
        return auxiliary_head->next;
    }
};