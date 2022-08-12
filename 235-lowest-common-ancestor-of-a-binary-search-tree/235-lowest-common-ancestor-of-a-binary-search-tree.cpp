/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    
    TreeNode* getAncestor(TreeNode* root , TreeNode* p, TreeNode* q) {
        
        if ( !root ) return NULL;
        
        if ( root -> val > p->val && root->val < q->val ) return root;
        else if ( root -> val < p->val && root->val > q->val ) return root;
        else if ( root->val == p->val || root->val == q->val ) return root;
        else {
            
            int mini = min(p->val,q->val);
            
            if ( root->val > mini ) {
                
                return getAncestor(root->left,p,q);
                
            }
            else {
                
                return getAncestor(root->right,p,q);
                
            }
            
        }
        
        return root;
        
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return getAncestor(root , p , q);
        
    }
};