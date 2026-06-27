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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> qu1;
        queue<TreeNode*> qu2;
        vector<int> li;
        if(root==NULL)
        {
            return li;
        }
        qu1.push(root);
        while(!qu1.empty() || !qu2.empty())
        {
            if(qu2.empty())
            {
                vector<int> temp;
                
                while(!qu1.empty())
                {
                    TreeNode*temp1=qu1.front();
                    if(temp1->left!=NULL)
                    {
                        qu2.push(temp1->left);
                    }
                    if(temp1->right!=NULL)
                    {
                        qu2.push(temp1->right);
                    }
                    temp.push_back(temp1->val);
                    qu1.pop();
                    
                }
                li.push_back(temp[temp.size()-1]);
            }
            else
            {
                vector<int> temp;
                
                while(!qu2.empty())
                {
                    TreeNode*temp2=qu2.front();
                    if(temp2->left!=NULL)
                    {
                        qu1.push(temp2->left);
                    }
                    if(temp2->right!=NULL)
                    {
                        qu1.push(temp2->right);
                    }
                    temp.push_back(temp2->val);
                    qu2.pop();
                    cout<<temp2->val<<"\n";
                }
                li.push_back(temp[temp.size()-1]);
            }
        }
        return li;
    }
};
