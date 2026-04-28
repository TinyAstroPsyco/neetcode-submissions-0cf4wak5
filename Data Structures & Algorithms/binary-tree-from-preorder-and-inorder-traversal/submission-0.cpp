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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // I need a has map to add all the indexes to it
        unordered_map<int, int> inorder_map;
        for(int i =0; i<inorder.size(); i++){
            inorder_map[inorder[i]] = i;
        }
        int preIndex = 0;

        return build(preorder, inorder_map, preIndex, 0, inorder.size() - 1);

    }

    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inorder_map, int& preIndex, int left_limit, int right_limit){
        // I need to get the index of the root
        
        if (left_limit > right_limit) return nullptr;
        
        int root_val = preorder[preIndex++];
        
        int root_idx = inorder_map[root_val];

        TreeNode* root = new TreeNode(root_val);

        root->left = build(preorder, inorder_map, preIndex, left_limit, root_idx -1);
        root->right = build(preorder, inorder_map, preIndex, root_idx + 1, right_limit);

        return root;
    }

};
