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
    vector<int> arr;
    TreeNode*inorder(TreeNode*root)
    {
        if(root==NULL)
        {
            return root;
        }
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
        return root;
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]<=arr[i-1])
            {
                return false;
            }
        }
        return true;
    }
};
