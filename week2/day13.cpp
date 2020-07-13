/*
Same Tree

Solution
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
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

//Solution 1 : Using Inorder traversal and a vector.
//Compare both vectors
//Before pushing to vector increment that value by 1 everytime before pushing.this will handle your last testcase
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();
class Solution {
    void inorder (TreeNode* root,vector<int>& v,int i)
    {
            if(root==NULL)
                    return;
            inorder(root->left,v,i+1);
            v.push_back((root->val)+i);
            inorder(root->right,v,i+1);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
            int i=0;
            vector<int> v1;
            inorder(p,v1,i);
            vector<int> v2;
            int j=0;
            inorder(q,v2,j);
            if(v1==v2)
                    return true;
            
            return false;
    }
};


//Solution 2: Using Recursion

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
                return true;
        if((!p && q) || (p && !q))
                return false;
        if(p->val == q->val)
                return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
        else
                return false;
    }
};