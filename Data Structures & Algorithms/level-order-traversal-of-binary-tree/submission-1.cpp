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
 
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //We will first push the node to the queue.
        vector<vector<int>> output;
        queue<TreeNode* > q;
        if(root == nullptr) return output;
        q.push(root);
        while(!q.empty()){
            
            int size = q.size();
            vector<int> temp;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
            }
            output.push_back(temp);

        }
        return output;
    }
};
