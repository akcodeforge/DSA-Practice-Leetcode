class Solution {
public:
    Node* copyRandomList(Node* head) {
        //1. creating the deep copy 
        Node* deep=new Node(-1);
        Node* deepC=deep;
        Node* temp=head;
        while(temp){
        Node* a=new Node(temp->val);
            deepC->next=a;
            temp=temp->next;
            deepC=deepC->next;
        }
        Node* duplicate=deep->next;
        Node* a=head;
        Node* b=duplicate;
        deep=new Node(-1);
        Node* deepD=deep;
        while(b){
            deepD->next=a;
            deepD=deepD->next;
            a=a->next;
            deepD->next=b;
            deepD=deepD->next;
            b=b->next;
        }
        deep=deep->next;
        Node* t1=deep;// t1 traverse in original list
        while(t1){
            Node* t2=t1->next;
            if(t1->random) t2->random=t1->random->next;
            t1=t1->next->next; 
        }
        // step4 remove the connection
        Node* d1=new Node(-1);
        Node* d2=new Node(-1);
        t1=d1;
        Node* t2=d2;
        Node* t=deep;
        while(t){
            t1->next=t;
            t=t->next;
            t1=t1->next;
            t2->next=t;
            t=t->next;
            t2=t2->next;
        }
        t1->next=NULL;
        t2->next=NULL;
        d1=d1->next; /// original with random
        d2=d2->next;/// duplicate with random
        return d2;
    }
};