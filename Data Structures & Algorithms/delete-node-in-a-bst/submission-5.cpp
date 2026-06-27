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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        {
            return root;
        }
        if(root->val==key)
        {
            if(root->left==NULL)
            {
                root=root->right;
                return root;
            }
            else if(root->right==NULL)
            {
                root=root->left;
                return root;
            }
            else
            {
                TreeNode*temp=root->right;
                if(temp->left==NULL)
                {
                    root->val=root->right->val;
                    root->right=root->right->right;

                    return root;
                }
                while(temp->left->left!=NULL)
                {
                    temp=temp->left;
                }
                root->val=temp->left->val;
                temp->left = temp->left->right;
                return root;
            }
        }
        else
        {
            if(root->val>key)
            {
                root->left=deleteNode(root->left,key);
            }
            else
            {
                root->right=deleteNode(root->right,key);
            }
        }
        return root;
    }
};