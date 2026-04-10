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

        unordered_map<Node*,Node*> um;
        Node* temp = head;
        Node* curr = new Node(temp->val);
        Node* headNew = curr;
        bool f = false;
        um[head] = curr;
        while(temp!=NULL){            
            if(temp->random==NULL){
                curr->random = NULL;
            }else{
                if(um.find(temp->random)==um.end()){  
                    curr->random = new Node(temp->random->val);                 
                    um[temp->random] = curr->random;
                }else{
                    curr->random = um[temp->random];
                }
            }
            if(temp->next==NULL){
                curr->next = NULL;
            }else{
                if(um.find(temp->next)==um.end()){                   
                    curr->next = new Node(temp->next->val);  
                    um[temp->next] = curr->next;
                }else{
                    curr->next = um[temp->next];
                }
            }       
            um[temp] = curr;                      
            curr = curr->next;              
            temp=temp->next;
        }
        curr = NULL;  
        return headNew;   
    }
};
