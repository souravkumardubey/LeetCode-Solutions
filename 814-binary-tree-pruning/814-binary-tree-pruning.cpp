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
    
    TreeNode* dfs( TreeNode* root ) {
        
        if ( root == NULL ) return NULL;
        
//       we start checking from bottom of the tree, once we reach the end, we check simutaneously if from the base we find that the root value is 0, then obvio theres no chance of having 1 in the subtrees
        TreeNode* left = dfs(root -> left);
        root -> left = left;
        
        TreeNode* right = dfs(root -> right);
        root -> right = right;
        
        if ( !root -> left and !root -> right and root -> val == 0 ) {
            
            return NULL;
            
        }
        
        return root;
        
    }
    
public:
    TreeNode* pruneTree(TreeNode* root) {
        
        if ( !root ) return NULL;
        
        return dfs(root);
        
        // return root;
        
    }
};