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
public:
    TreeNode* invertTree(TreeNode* root) {
        // Strategy is to swap the ptr positions. 

        if(root == nullptr) return root;
        
            
        // while(root->left < root->right){
        if(root !=nullptr && root!=nullptr){
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left, root->right);
        }
        // }
    
        return root;
    }
};
