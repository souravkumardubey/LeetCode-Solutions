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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map < int , map < int , multiset < int > > > mp;
        
        vector < vector < int > > ans;
        
        queue < pair < TreeNode* , pair < int , int > > > q;
        
        q.push( { root , { 0 , 0 } } );
        
        while ( !q.empty() ) {
            
            auto p = q.front();
            
            q.pop();
            
            TreeNode* node = p.first;
            
            int val1 = p.second.first, val2 = p.second.second;
            
            mp[val1][val2].insert(node-> val);
            
            if ( node -> left ) {
                
                q.push( { node -> left , { val1 - 1 , val2 + 1 } } );
                
            }
            
            if ( node -> right ) {
                
                q.push( { node -> right, { val1 + 1 , val2 + 1 } } );
                
            }
            
        }
        
        for ( auto i: mp ) {
            
            vector < int > vec;
            
            for ( auto j: i.second ) {
                
                vec.insert(vec.end(),j.second.begin(),j.second.end());
                
            }
            
            ans.push_back(vec);
            
        }
        
        return ans;
        
    }
    
};