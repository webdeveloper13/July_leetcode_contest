/*
Maximum Width of Binary Tree

Solution
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.
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
public:
    int widthOfBinaryTree(TreeNode* root) {
            if(!root)
                    return 0;
            queue<pair<TreeNode *,int>> q;
            q.push({root,1});
            int ans = 1;
            while(!q.empty())
            {
                    int n = q.size();
                    int minval = INT_MAX;
                    int maxval = 0;
                    while(n>0)
                    {
                            auto node = q.front();
                            q.pop();
                            int x = node.second*2;
                            if(node.first->left)
                            {
                                    q.push({node.first->left,x});
                                    minval = min(minval,x);
                                    maxval = max(maxval,x);
                            }
                            
                            if(node.first->right)
                            {
                                    q.push({node.first->right,x-1});
                                    minval = min(minval,x-1);
                                    maxval = max(maxval,x-1);
                            }
                            
                            n--;
                    }
                    
                     minval = (minval==INT_MAX)?0:minval;
                     ans = max((maxval-minval+1),ans);
            }
            
            
           
            
            return ans;
        
    }
};




/* Explanation
           1
         /   \
        2     3
       / \    /\ 
      4   5  6  7 
Basic structure
We will use a pair {node,val} where value is the position of the element in that level from right if the tree was full
So the values of pair for node 1 to 7 will be:
{1,1}
{2,2} {3,1}
{4,4} {5,3} {6,2} {7,1}
As you can see the position of 7 from right is 1 and 4 is (4 is the 4th node from right in that level)
So the width will be position of 4 - position of 7 +1 = 4.
Even if any number between 4 and 7 were absent the ans will be 4.
What if seven is absent then we have 6 which is the rightmost node of that level, so width should be 3:
position of 4 - position of 6 +1 =3
i.e.
Leftmost node postion - rightmost node position + 1 so when we run algo we can calculate this by :
max - min +1

Calculation of position
Now how to fill in these position:
The value of pair will be filled this way:
for the root node it will be {node,val} : {1,1}
then for left node: {node->left, val*2}
for right node: {node->right, val*2 - 1}

        1 - {1,1}
         /   \
        2     3     for 2: {2,2*1} = {2,2} | 3: {3,2*1-1} = {3,1}
       / \    /\ 
      4   5  6  7 

for  4: {4,2*2} = {4,4}
5: {5,2*2-1} = {5,3}
6: {6,2*1} = {6,2}  - parent of 6 and 7 is 3: {3,1}
7: {7,2*1-1} = {7,1}
Calculating width and finding max width
So you can see this will give the correct position to all existing nodes even if the nodes in between or before or after were absent.

Then we just need to do current max = maxpos - minpos + 1 (plus 1 bcoz we while subtracting we are removing one position)
the ans = max(currentmax, ans) which will be the final ans.

Datastructures and other factors in code
The First is a queue to perform level order traversal
Queue will contain pair of type {TreeNode*,int} where first is node and second is position of the node
minval and maxval contain the minimum and maximum position of the current level
maxval - minval +1 will give the width of current level
ans will contain the max width of the entire tree
*/