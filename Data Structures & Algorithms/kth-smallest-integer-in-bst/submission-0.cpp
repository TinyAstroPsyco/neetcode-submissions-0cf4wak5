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
    int kthSmallest(TreeNode* root, int k) {
        //lets do dfs
        stack<TreeNode*> st;
        int counter = 1;
        TreeNode* node = root;

        while(node != nullptr || !st.empty()){
            
            while(node != nullptr){
                st.push(node);
                node = node->left;
            }
            
            node = st.top();
            st.pop();

            k--;

            if(k == 0) return (node->val);
            node = node->right;
        }
        return 0;
    }
   
};
