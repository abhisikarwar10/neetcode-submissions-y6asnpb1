/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

    unordered_map<Node*, Node*> um;
    Node* temp = head;

    Node* curr = new Node(temp->val);
    Node* headNew = curr;

    um[head] = curr;   // ✅ fix

    while(temp != NULL){            

        // ---- RANDOM ----
        if(temp->random == NULL){
            curr->random = NULL;
        } else {
            if(um.find(temp->random) == um.end()){  
                um[temp->random] = new Node(temp->random->val);
            }
            curr->random = um[temp->random];
        }

        // ---- NEXT ----
        if(temp->next == NULL){
            curr->next = NULL;
        } else {
            if(um.find(temp->next) == um.end()){                   
                um[temp->next] = new Node(temp->next->val);
            }
            curr->next = um[temp->next];
        }

        um[temp] = curr;   // ✅ moved here

        temp = temp->next;
        curr = curr->next;
    }

    return headNew;    
    }
};
