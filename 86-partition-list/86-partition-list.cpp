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
    ListNode* partition(ListNode* head, int x) {
        ListNode *a1=new ListNode(0);
        ListNode *a2=new ListNode(0);
        ListNode *p1=a1,*p2=a2;
        while(head!=NULL){
            if(head->val>=x){
                p2->next=head;
                p2=p2->next;
            }
            else if(head->val<x){
                p1->next=head;
                p1=p1->next;
            }
            head=head->next;
        }
        p2->next=NULL;
        p1->next=a2->next;
        return a1->next;
    }
};