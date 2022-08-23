class Solution {
public:
    ListNode* rev(ListNode* a){
        ListNode* prev=NULL;
        ListNode* n=NULL;
        while(a){
            n=a->next;
            a->next=prev;
            prev=a;
            a=n;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* first=head;
        ListNode* second=head;
        if(head->next==NULL)
            return true;
        if(head->next->next==NULL)
            return (head->val==head->next->val);
        
        ListNode* f=head;
        ListNode* s=head;
        while(f->next && f->next->next){
            s=s->next;
            f=f->next->next;
        }
        s->next=rev(s->next);
        s=s->next;
        f=head;
        while(f && s){
            if(f->val!=s->val)
                return false;
            f=f->next;
            s=s->next;
                
        }
        return true;
    }
};