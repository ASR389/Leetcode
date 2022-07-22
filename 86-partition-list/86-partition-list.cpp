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
    ListNode* partition(ListNode* head, int x) {
          if (!head) return nullptr;
        
        ListNode* small= new ListNode (-1);
        ListNode* smaller= small;
        ListNode* great= new ListNode (-1);
        ListNode* greater= great;
        
         while (head != nullptr){
             
              if (head->val < x){
                  
                  smaller->next= head;
                  smaller= smaller->next;
              }
             
             else{
                 
                 greater->next= head;
                 greater= greater->next;
             }
             
             head= head->next;
         }
        
         greater->next= nullptr;
         smaller->next= great->next;
         return  small->next;
    }
};