#include <iostream>

// Implementation inspired by this article 
// https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/ 

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
    
void update_result(int*& result, int value){
    if(result == nullptr){
        result = new int{value};
    }
    else{
        *result = std::max(value, *result);
    }        
}

int maxPathSumHelper(TreeNode* root, int*& result){
    if(root == nullptr) {
        return 0;
    }
            
    int val_left = maxPathSumHelper(root->left, result);
    int val_right = maxPathSumHelper(root->right, result);
    
    int local_result = std::max(val_left, val_right) + root->val;
    local_result = std::max(local_result, root->val);
        
    int max_val = std::max(local_result, val_left + val_right + root->val);
    update_result(result, max_val);
    
    return local_result;
}

int maxPathSum(TreeNode*& root) {
    int* result_ptr = nullptr;
    maxPathSumHelper(root, result_ptr);
    int result = *result_ptr;
    delete result_ptr;
    return result;
}

void testMaximumPathSum(){
    TreeNode *root = new TreeNode(10); 
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20); 
    root->left->right = new TreeNode(1); 
    root->right->right = new TreeNode(-25); 
    root->right->right->left = new TreeNode(3); 
    root->right->right->right = new TreeNode(4); 
    std::cout << "Max path sum is " << maxPathSum(root) << std::endl;
    std::cout << "Expecting : " << 42 << std::endl << std::endl; 
}