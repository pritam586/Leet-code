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

        for(int i = left; i <= right; i++) {

            if(inorder[i] == val) {
                return i;
            }
        }

        return -1;
    }

    TreeNode* solve(vector<int>& inorder,
                    vector<int>& postorder,
                    int left,
                    int right,
                    int& postInd) {

        if(left > right) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postInd]);

        int inIndex = search(inorder, left, right, postorder[postInd]);

        postInd--;

        
        root->right = solve(inorder,
                            postorder,
                            inIndex + 1,
                            right,
                            postInd);

        root->left = solve(inorder,
                           postorder,
                           left,
                           inIndex - 1,
                           postInd);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {

        int postInd = postorder.size() - 1;

        return solve(inorder,
                     postorder,
                     0,
                     inorder.size() - 1,
                     postInd);
    }
};