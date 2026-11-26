/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
#define ed endl
#define Node ListNode
#define null NULL
   bool hasCycle(ListNode *head) {
       if(head==null)
       return false;
       if(head->next==null)
       return false;
       Node* slow=head;
       Node* fast=head;
       while(fast != null and fast->next!=null)
       {
           slow=slow->next;
           fast=fast->next->next;
           if(slow==fast)
           return true;
       }
       return false;
   }

    
};