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
    int search(vector<int>& inorder, int left, int right, int val) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == val) return i;
        }
        return -1;
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &preIndex, int left, int right) {
        if (left > right) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex]);

        int inIndex = search(inorder, left, right, preorder[preIndex]);

        preIndex++;

        root->left = solve(preorder, inorder, preIndex, left, inIndex - 1);
        root->right = solve(preorder, inorder, preIndex, inIndex + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;

        TreeNode* root = solve(preorder, inorder, preIndex, 0, inorder.size() - 1);

        return root;
    }
};