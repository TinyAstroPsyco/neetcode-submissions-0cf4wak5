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
    int goodCount(TreeNode* node, int current_max){
        int count = 0;
        
        if(node == nullptr) return 0;

        if(node->val >= current_max){
            current_max = max(current_max, node->val);
            count ++;
        }

        count += goodCount(node->left, current_max);
        count += goodCount(node->right, current_max);
        return count;

    }
public:
    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int count = 1;
        int current_max = root->val;

        count += goodCount(root->left, current_max);
        count += goodCount(root->right, current_max);

        return count;

    }
};
