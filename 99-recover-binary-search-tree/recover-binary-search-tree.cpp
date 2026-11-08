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
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* sec = NULL;
        TreeNode* prev = NULL;
        while(root != NULL){
            if(root->left == NULL){
                if(prev != NULL && prev->val > root->val){
                    if(first == NULL)first = prev;
                    sec = root;
                }
                prev = root;
                root = root->right;
            }else{
                TreeNode* IP = root->left;
                while(IP->right != NULL && IP->right != root)IP = IP->right;
                if(IP->right == NULL){
                    IP->right = root;
                    root = root->left;
                }else{
                    if(prev != NULL && prev->val > root->val){
                        if(first == NULL)first = prev;
                        sec = root;
                    }
                    prev = root;
                    IP->right = NULL;
                    root = root->right;
                } 
            }
        }
        if(first != NULL && sec != NULL){
            int temp = first->val;
            first->val = sec->val;
            sec->val = temp;
        }
    }
};