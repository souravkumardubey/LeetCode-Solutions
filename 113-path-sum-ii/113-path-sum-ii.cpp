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
    
    void getPaths( TreeNode* root , vector < vector < int > > &allPaths , vector < int > &possiblePath , int targetSum ) {
                
        if ( root == NULL ) return;
        
        if ( !root->left && !root->right ) {
            
            possiblePath.push_back(root->val);
            if ( root->val == targetSum ) {
                
                allPaths.push_back(possiblePath);
                
            }
            possiblePath.pop_back();
            return;
            
        }
        
        possiblePath.push_back(root->val);
        getPaths(root->left , allPaths , possiblePath , targetSum - root->val);
        getPaths(root->right , allPaths, possiblePath , targetSum - root->val);
        possiblePath.pop_back();
        
        return; 
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector < vector < int > > allPaths;
        vector < int > possiblePath;
        
        getPaths( root , allPaths , possiblePath , targetSum );
        
        return allPaths;
        
    }
};