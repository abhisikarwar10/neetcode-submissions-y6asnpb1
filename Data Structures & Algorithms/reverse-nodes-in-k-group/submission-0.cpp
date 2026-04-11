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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || head->next == nullptr || k==1){
            return head;
        }
        ListNode* out = head;
        ListNode* temp = head;
        int c = 0;
        while(temp!=nullptr && c!=k){
            temp = temp->next;
            c++;
        }
        if(c==k){
            temp = head;
        }else{
            return head;
        }
        ListNode* next = nullptr;
        int m = k;
        while(m-- && temp!=nullptr){
            ListNode* tn = temp->next;
            temp->next = next;
            next = temp;
            temp = tn;
        }
        ListNode* final = next;
        ListNode* nextListR  = reverseKGroup(temp,k);
        out->next = nextListR;
        return final;
        
    }
};
