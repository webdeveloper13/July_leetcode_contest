/*
 Binary Tree Level Order Traversal II

Solution
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/
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
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>> ans;
            if(!root)
                    return ans;
            queue<TreeNode *> q1;
            q1.push(root);
            vector<int> v1;
            while(!q1.empty())
            {
                    int n = q1.size();
                    while(n>0)
                    {
                            auto node = q1.front();
                            v1.push_back(node->val);
                            if(node->left)
                                    q1.push(node->left);
                            if(node->right)
                                    q1.push(node->right);
                            q1.pop();
                            n--;
                                    
                    }
                    
                    ans.push_back(v1);
                    v1.clear();
            }
            
            vector<vector<int>> res;
            for(int i=ans.size()-1;i>=0;i--)
            {
                    for(int j=0;j<ans[i].size();j++)
                    {
                            v1.push_back(ans[i][j]);
                    }
                    
                    res.push_back(v1);
                    v1.clear();
            }
            
            return res;
        
    }
};