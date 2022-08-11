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

    void getLeafNodes(TreeNode* root , vector < int >& vec) {
        
        if ( !root ) return;
        
        if ( !root->left && !root->right ) {
            
            vec.push_back(root->val);
            return;
            
        }
        
        getLeafNodes(root->left , vec);
        getLeafNodes(root->right , vec);
        
    }
    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            
        vector < int > tree1 , tree2;
    
        getLeafNodes(root1 , tree1);
        getLeafNodes(root2 , tree2);
        
        if ( tree1 == tree2 ) return true;
        
        return false;
        
    }
};