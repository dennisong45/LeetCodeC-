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
Backtracking Method and DFS

1) Go Left Go Right
2) If targetSum == 0 and its leafNode push temp vector
3) if over Target Sum popback vector



*/
class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        dfs(root,targetSum);
    
        return ans;
    }

    void dfs(TreeNode* root, int targetSum){

        if(root == NULL ){
            return;
        }
         temp.push_back(root->val);
         targetSum-=root->val;

        if(root->left == NULL && root->right == NULL){
            if(targetSum == 0){
                ans.push_back(temp);

            }
        }else{
            dfs(root->left,targetSum);
            dfs(root->right,targetSum);
        }

        temp.pop_back();
        return;
        
        
    }
};