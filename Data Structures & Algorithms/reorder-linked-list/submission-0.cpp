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
    void reorderList(ListNode* head) {

        ListNode* se = head;
        ListNode* fs = head->next;

        while(fs!=NULL && fs->next!=NULL){
            fs=fs->next->next;
            se=se->next;
        }

        ListNode* fe = se->next;
        ListNode* ss = head;
        se->next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = fe;

        while(curr!=NULL){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        ss = head;
        fs = prev;
        while(fs!=NULL ){
            ListNode* s = ss->next;
            ListNode* f = fs->next;

            ss->next = fs;
            fs->next = s;

            ss = s;
            fs = f;
        }


    }
};
