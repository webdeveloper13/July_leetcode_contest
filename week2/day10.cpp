/*
Flatten a Multilevel Doubly Linked List

Solution
You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.

Example 1:

Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation:

The multilevel linked list in the input is as follows:



After flattening the multilevel linked list it becomes:


Example 2:

Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation:

The input multilevel linked list is as follows:

  1---2---NULL
  |
  3---NULL
Example 3:

Input: head = []
Output: []
 

How multilevel linked list is represented in test case:

We use the multilevel linked list from Example 1 above:

 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
The serialization of each level is as follows:

[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
To serialize all levels together we will add nulls in each level to signify no node connects to the upper node of the previous level. The serialization becomes:

[1,2,3,4,5,6,null]
[null,null,7,8,9,10,null]
[null,11,12,null]
Merging the serialization of each level and removing trailing nulls we obtain:

[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
 

Constraints:

Number of Nodes will not exceed 1000.
1 <= Node.val <= 10^5
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

//Solution 1 : Take a vector of type Node and fill it in DFS order giving preference
// to child node. Then once arrays are filled with Nodes in required order
//make connections between them.
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
} ();

class Solution {
    void fillArray(Node* head,vector<Node *>& ans)
    {
            ans.push_back(head);
            if(head->child)
                    fillArray(head->child,ans);
            if(!head->next)
                    return;
            if(head->next)
                    fillArray(head->next,ans);
                    
    }
public:
    Node* flatten(Node* head) {
            if(head==NULL)
                    return head;
            vector<Node *> ans;
            ans.push_back(NULL);
            fillArray(head,ans);
            for(int i=1;i<ans.size()-1;i++)
            {
                    ans[i]->prev = ans[i-1];
                    ans[i]->next = ans[i+1];
                    ans[i]->child = NULL;
            }
            
            ans[ans.size()-1]->prev = ans[ans.size()-2];
            ans[ans.size()-1]->next = NULL;
            ans[ans.size()-1]->child = NULL;
            
            return ans[1];
        
    }
};


//Solution 2: Using recursion without array
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
} ();
class Solution {
public:
    Node* flatten(Node* head) {
            if(head==NULL)
                    return NULL;
            Node* temp = head;
            while(temp)
            {
                    if(temp->child)
                    {
                            Node *nextNode = temp->next;
                            Node *child = flatten(temp->child);
                            temp->child = NULL;
                            temp->next = child;
                            child->prev = temp;
                            Node *lastNode = child;
                            while(lastNode->next)
                                    lastNode = lastNode->next;
                            lastNode->next = nextNode;
                            if(nextNode)
                                    nextNode->prev = lastNode;
                            
                    }
                    
                    temp = temp->next;
            }
            
            return head;
        
    }
};