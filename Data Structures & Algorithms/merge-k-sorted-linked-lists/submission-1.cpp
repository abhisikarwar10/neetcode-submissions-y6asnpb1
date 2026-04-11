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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* out = new ListNode();
        ListNode* res = out;
        ListNode* minn = new ListNode(INT_MAX);
        int mini = -1;
        bool a = false;
        while(!a){
            a = true;
            minn = new ListNode(INT_MAX);
            for (int i = 0; i < lists.size(); i++){
                if(lists[i]!=NULL && lists[i]->val<minn->val){
                    minn = lists[i];
                    mini = i;
                    a = false;
                }
            }
            if(!a){
                out->next = minn;
                out = out->next;
                lists[mini] = lists[mini]->next;
            }
        }
        return res->next;        
    }
};
