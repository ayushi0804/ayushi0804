/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void markParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent_track, TreeNode* target){
        queue<TreeNode*>queue;
        queue.push(root);
        while(!queue.empty()){
            TreeNode* current = queue.front();
            queue.pop();
            if(current->left){
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right){
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent_track;
        markParent(root,parent_track,target);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()){
            int size = queue.size();
            if(curr_level++ == k)break;
            for(int i = 0; i < size; i++){
                TreeNode* curr = queue.front();
                queue.pop();
                if(curr->left && !visited[curr->left]){
                    queue.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right && !visited[curr->right]){
                    queue.push(curr->right);
                    visited[curr->right] = true;
                }
                if(parent_track[curr] && !visited[parent_track[curr]]){
                    queue.push(parent_track[curr]);
                    visited[parent_track[curr]] = true;
                }
            }
        }
        vector<int>result;
        while(!queue.empty()){
            TreeNode* curr = queue.front();
            queue.pop();
            result.push_back(curr->val);
        }
        return result;
    }
};