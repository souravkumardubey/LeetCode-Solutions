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
    
private:
    
    vector < TreeNode* > forests;
    
    TreeNode* getRoots( TreeNode* root , map < int , int >& mp ) {
        
        if ( root == NULL ) return NULL;
        
        if ( root -> left ) {
            
            root -> left = getRoots(root -> left, mp);
            
        }
        
        if ( root -> right ) {
            
            root -> right = getRoots(root -> right , mp);
            
        }
        
        if ( mp[root->val] ) {
            
            if ( root -> left ) forests.push_back( root -> left );
            if ( root -> right ) forests.push_back( root -> right );
            
            return NULL;
            
        }
        
        return root;
        
    }
    
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
                
        if ( root == NULL ) return forests;
        
        map < int , int > mp;
        
        for ( auto i : to_delete ) mp[i] += 1;
        
        if ( !mp[root->val] ) forests.push_back(root);
        
        getRoots(root , mp );
        
        return forests;
        
    }
};