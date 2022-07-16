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
        Node* ans = new Node(0);
        Node* temp = head;
        while(temp!=NULL){
            //cout<<temp->val<<" ";
            Node* t = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = t;
            temp = temp->next->next;
        }
        temp = head;
        while(temp!=NULL){
            if(temp->random)
                temp->next->random = temp->random->next;
            temp=temp->next->next;
        }
        Node* h = ans;
        temp = head;
        while(temp!=NULL){
            h->next = temp->next;
            h=h->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return ans->next;
    }
};