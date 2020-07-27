/*
 Construct Binary Tree from Inorder and Postorder Traversal

Solution
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
class Solution {
    TreeNode* buildUtil(vector<int>& in,vector<int>& post,unordered_map<int,int>& um1,int start,int end,int& index)
    {
            if(start>end)
                    return NULL;
            int curr = post[index];
            TreeNode *node = new TreeNode(curr);
            (index)--;
            
            if(start==end)
                    return node;
            int iIndex = um1[curr];
            
            node->right = buildUtil(in,post,um1,iIndex+1,end,index);
            node->left  = buildUtil(in,post,um1,start,iIndex-1,index);
            
            return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            int n = inorder.size();
           unordered_map<int,int> um1;
            for(int i=0;i<n;i++)
                    um1[inorder[i]] = i;
            int index = n-1;
            return buildUtil(inorder,postorder,um1,0,n-1,index);
        
    }
};