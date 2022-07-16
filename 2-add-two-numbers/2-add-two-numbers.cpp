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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        bool overflow = false;
        int val1, val2;
        
        while(l1 != nullptr || l2 != nullptr){
            ListNode* newNode;
            if(l1 == nullptr){
                val1 = 0;
                val2 = l2->val;
            }else if(l2 == nullptr){
                val1 = l1->val;
                val2 = 0;
            }else{
                val1 = l1->val;
                val2 = l2->val;
            }
            if(val1 + val2 + 1 >= 10 && overflow){
                newNode = new ListNode((val1 + val2 + 1) % 10);
                overflow = true;
            }else if(val1 + val2 >= 10){
                newNode = new ListNode((val1 + val2) % 10);
                overflow = true;
            }else if(overflow){
                newNode = new ListNode(val1 + val2 + 1);
                overflow = false;
            }else{
                newNode = new ListNode(val1 + val2);
                overflow = false;
            }
            curr->next = newNode;
            curr = curr->next;
            if(l1 != nullptr){
                l1 = l1->next;  
            }
            if(l2 != nullptr){
                l2 = l2->next;
            }
        }
        if(overflow){
            ListNode* newNode = new ListNode(1);
            curr->next = newNode;
            curr = curr->next;
        }
        return head->next;
    }
};