//  Binary Tree Cameras
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
public:
    int ans;
    unordered_set<TreeNode* > s;
    void dfs(TreeNode* r, TreeNode* p){
        if(r){
            dfs(r->left,r);
            dfs(r->right,r);
            if((p == NULL && s.find(r)==s.end()) || s.find(r->left)==s.end() || s.find(r->right)==s.end()){
                ans++;
                s.insert(r);
                s.insert(r->left);
                s.insert(r->right);
                s.insert(p);       
            }
        }
    }
    
    int minCameraCover(TreeNode* root) {
        ans = 0;
        s.insert(NULL);
        dfs(root, NULL);
        
        return ans;
    }
};
