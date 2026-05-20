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
    void insert(TreeNode* root , int val){
        TreeNode* temp = root;
        TreeNode* curr = new TreeNode();
        curr->val = val;
        curr->left = NULL;
        curr->right = NULL;
        while(true){
             if(val < temp->val) {

                if(temp->left == NULL) {
                    temp->left = new TreeNode(val);
                    break;
                }

                temp = temp->left;
            }

            else {

                if(temp->right == NULL) {
                    temp->right = new TreeNode(val);
                    break;
                }

                temp = temp->right;
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      TreeNode* root = new TreeNode();
      root->val = preorder[0];
      root->left = NULL;
      root->right = NULL;
      for(int i = 1 ; i<preorder.size() ; i++){
        insert(root , preorder[i]);
      }
        return root;
    }
};