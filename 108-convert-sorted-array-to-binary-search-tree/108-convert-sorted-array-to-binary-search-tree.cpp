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
    
    TreeNode* getBST(vector < int >& nums , int l , int r ) {
        
        if ( l > r ) return NULL;
        
        int mid = ( l + ( r - l ) / 2 );
        TreeNode* root = new TreeNode(nums[mid]);
        
        root -> left = getBST(nums , l , mid - 1);
        root -> right = getBST(nums , mid + 1 , r);
        
        return root;
        
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int n = nums.size() - 1;
        
        return getBST(nums , 0 , n);
        
    }
};