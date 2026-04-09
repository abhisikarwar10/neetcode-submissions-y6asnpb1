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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head;
        int c = 0;
        while(tmp!=NULL){
            c++;
            tmp=tmp->next;
        }
        int d = c-n-1;
        if(d==-1){
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }
        tmp = head;
        while(d>0){
            tmp=tmp->next;d--;
        }
        if(tmp!=NULL && tmp->next!=NULL){
            ListNode* del = tmp->next;
            tmp->next = del->next;
            delete del;
        }
        return head;       
    }
};
