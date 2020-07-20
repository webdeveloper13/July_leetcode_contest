/*
Remove Linked List Elements

Solution
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    ListNode* removeElements(ListNode* head, int val) {
            if(head==NULL)
                    return head;
            ListNode *curr = head;
            if(curr->val==val)
            {
                    while(curr->next!=NULL && curr->next->val==val)
                            curr = curr->next;
                    curr = curr->next;
                    head = curr;
            }
            
            if(head==NULL)
                    return head;
            
            while(curr->next!=NULL)
            {
                    if(curr->next->val==val)
                    {
                            ListNode *temp = curr;
                            while(temp->next!=NULL && temp->next->val==val)
                            {
                                    temp = temp->next;
                            }
                            
                            curr->next = temp->next;
                            //curr = curr->next;
                    }
                    if(curr->next==NULL)
                            break;
                    //cout<<curr->val<<" ";
                    curr = curr->next;
            }
            
            return head;
        
    }
};