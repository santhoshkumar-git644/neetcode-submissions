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
    int count=0;
    void hi(TreeNode* root,int maxi)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->val>=maxi)
        {
            count++;
            
        }
        hi(root->right,max(maxi,root->val));
            hi(root->left,max(maxi,root->val));
        return;
    }
    int goodNodes(TreeNode* root) {
        hi(root,INT_MIN);
        return count;
    }
};
