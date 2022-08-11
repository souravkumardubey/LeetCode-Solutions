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

    bool checkBST(TreeNode* root , long long mini , long long maxi) {
        
        if ( !root ) return true;
        
        if ( root -> val > mini && root -> val < maxi ) {
            
            return checkBST(root->left , mini , root->val) && checkBST(root->right, root->val , maxi);
            
        }
        
        return false;
        
    }
    
public:
    bool isValidBST(TreeNode* root) {
        
        if ( !root ) return true;
        
        return checkBST(root , LONG_MIN , LONG_MAX);
        
    }
};