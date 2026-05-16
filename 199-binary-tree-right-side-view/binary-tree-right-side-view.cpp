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
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        if(root==NULL) return ans;
        while(!q.empty()){
            int n = q.size();
            int i = 0;
            while(i<n-1){
                 TreeNode* node= q.front();
                 q.pop();
                   if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
                i++;

            }
             TreeNode* node= q.front();
                 q.pop();
                 ans.push_back(node->val);
                  if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }

        }
        return ans;
    }
};