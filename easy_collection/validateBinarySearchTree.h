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
    bool helper(TreeNode* root, int& min_val, int& max_val){            
        bool valid_bst = true;            
        min_val = root->val;
        max_val = root->val;

        if(root->left != nullptr){
            int min_left, max_left;
            bool valid_left = helper(root->left, min_left, max_left);
            valid_bst = valid_bst && valid_left && (max_left < root->val);
            min_val = min(root->val, min_left);
        }

        if(root->right != nullptr){
            int min_right, max_right;
            bool valid_right = helper(root->right, min_right, max_right);
            valid_bst = valid_bst && valid_right && (root->val < min_right);
            max_val = max(root->val, max_right);
        }           
        return valid_bst;        
    }

    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        int min_val, max_val;
        return helper(root, min_val, max_val);
    }
};