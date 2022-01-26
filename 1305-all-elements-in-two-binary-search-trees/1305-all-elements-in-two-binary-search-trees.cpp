/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void helper(TreeNode* root1, TreeNode* root2, priority_queue<int, vector<int> , greater<int> >& pq){
        
        if(root1 != NULL && root2 != NULL){
            pq.push(root1->val);
            pq.push(root2->val);
            helper(root1->left, root2->left, pq);
            helper(root1->right, root2->right, pq);
            
            return;
        }
        
        if(root1 != NULL){
            pq.push(root1->val);
            helper(root1->left, NULL, pq);
            helper(root1->right, NULL, pq);
            
            return;
        }
        
        else if(root2 != NULL) {
            pq.push(root2->val);
            helper(NULL, root2->left, pq);
            helper(NULL, root2->right, pq);
            
            return;
        }
        
        return;
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        helper(root1, root2, pq);
        
        vector<int> answer;
        
        while(!pq.empty()) {
            int number = pq.top();
            pq.pop();
            
            answer.push_back(number);
            
        }
        
        return answer;
    }
};