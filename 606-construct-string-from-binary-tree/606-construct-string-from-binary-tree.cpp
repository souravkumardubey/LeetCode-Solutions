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
    
    void getString(TreeNode* root , string& s) {
        
        if ( root -> left == NULL and root -> right == NULL ) {
            
            s += to_string(root->val);
            // s += ')';
            return;
            
        }
        
        s += to_string(root->val);
        s += '(';
        
        if ( root -> left ) {
            
            getString(root -> left, s);
            
        }
        
        s += ')';
        
        if ( root -> right ) {
            
            s += '(';
            // s += to_string(root->val);
            getString(root->right,s);
            s += ')';
            
        }
            
    }
    
public:
    string tree2str(TreeNode* root) {
        
        if ( root == NULL ) {
            
            return "";
            
        }
        
        string s = "";
        
        getString(root , s);
        
        return s;
        
    }
};