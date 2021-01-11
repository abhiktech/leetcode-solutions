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
        
        vector<int> right_view;
        
        if(!root) {
            return right_view;
        }
        
        queue<TreeNode*> levels;
        levels.push(root);
        
        int cur_level = 1, next_level = 0;
        
        while(cur_level > 0) {
            
            int right_val;
            
            for(int i = 0; i < cur_level; ++i) {
                
                TreeNode* cur = levels.front();
                levels.pop();
                right_val = cur->val;
                
                if(cur->left) {
                    levels.push(cur->left);
                    ++next_level;
                }
                
                if(cur->right) {
                    levels.push(cur->right);
                    ++next_level;
                }
                
            }
            
            right_view.push_back(right_val);
            cur_level = next_level;
            next_level = 0;
        }
        
        return right_view;
    }
};