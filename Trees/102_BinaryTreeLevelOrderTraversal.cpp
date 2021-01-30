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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(!root) {
            return {};
        }
        
        vector<vector<int>> res;
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        int curLevel = 1, nextLevel = 0;
        
        while(curLevel != 0) {
            
            vector<int> cur;
            
            for(int i = 0; i < curLevel; ++i) {
                
                cur.push_back(nodes.front()->val);
                
                if(nodes.front()->left) {
                    nodes.push(nodes.front()->left);
                    ++nextLevel;
                }
                
                if(nodes.front()->right) {
                    nodes.push(nodes.front()->right);
                    ++nextLevel;
                }
                
                nodes.pop();
                
            }
            
            res.push_back(cur);
            curLevel = nextLevel;
            nextLevel = 0;
            
        }
        
        return res;
    }
};