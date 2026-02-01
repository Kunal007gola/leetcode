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
    int carry = 0;
    ListNode *res = NULL;

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *ptr = new ListNode();
        int sum = 0;
        if (l1 == NULL && l2 == NULL){
            if (carry){
                ptr->val = carry;
                return ptr;
            }
            return NULL;
        }

        if (l1 == NULL) {
            sum = l2->val + carry;
            ptr->val = sum%10;
            carry = sum/10;
            
            ptr->next = addTwoNumbers(NULL, l2->next);   
            return ptr;
        }

        if (l2 == NULL){
            sum = l1->val + carry;
            ptr->val = sum%10;
            carry = sum/10;
            ptr->next=addTwoNumbers(l1->next, NULL);
            return ptr;
        }

        sum = l1->val + l2->val + carry;
        ptr->val = sum%10;
        carry = sum/10;

        ptr->next = addTwoNumbers(l1->next, l2->next);
        return ptr;
    }
};