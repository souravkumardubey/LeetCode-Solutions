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
    int cnt = 0;
    void goodNodes(TreeNode* root , int maxi) {
        
        if ( root == NULL ) return;
                
        if ( root -> val >= maxi ) {
            
            cnt += 1;
            maxi = root -> val;
            
        } 
        
        goodNodes( root -> left , maxi );
        goodNodes( root -> right, maxi );
        
        return;
        
    }
    
public:
    int goodNodes(TreeNode* root) {
        
        if ( root == NULL ) return 0;
        
        goodNodes(root, INT_MIN);
        return cnt;
        
    }
};