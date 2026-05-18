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

    int search(vector<int>& inorder,
               int left,
               int right,
               int val) {

        for(int i = left; i <= right; i++) {

            if(inorder[i] == val) {
                return i;
            }
        }

        return -1;
    }

    TreeNode* solve(vector<int>& preorder,
                    vector<int>& inorder,
                    int left,
                    int right,
                    int& preInd) {

        if(left > right) {
            return NULL;
        }

        // root from preorder
        TreeNode* root = new TreeNode(preorder[preInd]);

        int inIndex = search(inorder,
                             left,
                             right,
                             preorder[preInd]);

        preInd++;

        // build LEFT first
        root->left = solve(preorder,
                           inorder,
                           left,
                           inIndex - 1,
                           preInd);

        // build RIGHT
        root->right = solve(preorder,
                            inorder,
                            inIndex + 1,
                            right,
                            preInd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        int preInd = 0;

        return solve(preorder,
                     inorder,
                     0,
                     inorder.size() - 1,
                     preInd);
    }
};