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

        ListNode* out = new ListNode();
        ListNode* res = out;
        int sum = 0;
        int carry = 0;

        while(l1!=NULL || l2!=NULL){
            sum = 0;
            if(l1!=NULL){
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = 0;
            carry = sum/10;
            sum = sum%10;
            out->val = sum;
            if(l1==NULL && l2==NULL){
                out->next = NULL;
            }else{
                out->next = new ListNode();
                out = out->next;
            }            
        }
        if(carry>0){
            out->next = new ListNode(carry);
            out = out->next;
            out->next = NULL;
        }
        return res;
    }
};
