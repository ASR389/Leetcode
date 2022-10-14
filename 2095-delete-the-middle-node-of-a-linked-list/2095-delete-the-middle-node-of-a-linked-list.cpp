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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)
        {
            return head->next;
        }
        ListNode* curr=head;
        int count=0;
        while(curr!=NULL)
        {
            
            curr=curr->next;
            count++;
        }
        int k=count/2;
        k=k-1;
        curr=head;
        while(k!=0)
        {
            curr=curr->next;
            k--;
        }
        ListNode* temp=curr->next;
        ListNode* temp1=curr->next->next;
        delete(temp);
        curr->next=temp1;
        return head;
    }
};
