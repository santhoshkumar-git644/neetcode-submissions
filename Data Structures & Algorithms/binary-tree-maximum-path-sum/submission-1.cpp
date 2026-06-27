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
int max1=INT_MIN;
int maxPath(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int right=maxPath(root->right);
        int left=maxPath(root->left);
        max1=max(max1,root->val+right+left);
        if(root->right==NULL && root->left==NULL)
        {
            max1=max(max1,max(root->val,0));
            return max(root->val,0);
        }
        else
        {
            max1=max(max1,max(root->val,max(root->val+right,root->val+left)));
            return max(0,max(root->val,max(root->val+right,root->val+left)));
        }
        return 0;
    }
    int inorder(TreeNode*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        inorder(root->left);
        inorder(root->right);
        max1=max(max1,root->val);
        return max1;
    }
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        if(max1==0)
        {
            max1=INT_MIN;
            inorder(root);
        }
        return max1;
    }
};
