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

/*
1. DFS go left
2. DFS go right
3. TargetSum - nodeValue each step
4. once it reach leaf, if leaf not equal to targetSum, means its not going to be zero return false.
5. Return true if lastNode equal to value that going to be zero.

*/
class Solution {
public:

    bool hasPathSum(TreeNode* root, int targetSum) {
 
        if(root == NULL ) {
            return false;
        }
        
        if(root->left == NULL && root->right == NULL && root->val == targetSum){
            return true;
        }
        // 22 - 4 - 11 - 7 = 0
        return hasPathSum(root->left,targetSum-root->val) ||   hasPathSum(root->right,targetSum-root->val);

        //18 - 4 -11 - 7
        
        
    }
    

    

};