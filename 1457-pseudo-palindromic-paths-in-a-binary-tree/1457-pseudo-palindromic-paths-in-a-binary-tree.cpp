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
    
    int ans = 0;
    unordered_map < int, int > mp;
    
public:
    void helper(TreeNode* root) {
        
        if ( !root ) return;
        
        mp[root->val]++;
        
        if ( !root -> left && !root -> right ) {

            int odd = 0;
            
            for ( auto i : mp ) {
                
                if ( i.second & 1 ) {
                    
                    odd += 1;
                    
                }
                
            }

            if ( odd <= 1 ) ans += 1;
            
        }
        
        helper( root -> left );
        
        helper( root -> right );
        
        mp[root -> val] -= 1;
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        helper(root);
        return ans;
        
    }

};