class Solution {
public:
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder)
    {
        if(inorder.empty()) return NULL;

        int val = preorder[preIndex++];
        TreeNode* root = new TreeNode(val);

        int idx = find(inorder.begin(), inorder.end(), val) - inorder.begin();

        vector<int> left(inorder.begin(), inorder.begin() + idx);
        vector<int> right(inorder.begin() + idx + 1, inorder.end());

        root->left = build(preorder, left);
        root->right = build(preorder, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return build(preorder, inorder);
    }
};