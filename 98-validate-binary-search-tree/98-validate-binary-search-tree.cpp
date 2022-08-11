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
    
    vector < int > inOrder;
    
    void getInOrder(TreeNode* root) {
        
        if ( root == NULL ) return;
        
        getInOrder(root->left);
        inOrder.push_back(root->val);
        getInOrder(root->right);
        
    }
    
public:
    bool isValidBST(TreeNode* root) {
        
        if ( !root ) return true;
        
        getInOrder(root);
        
        for ( int i = 0 ; i < inOrder.size() - 1 ; i++ ) {
            
            if ( inOrder[i] >= inOrder[i+1] ) return false;
        
        }
        
        return true;
        
    }
};