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
        Node* b=deep->next;
        Node* a=head;
        /// map a map with<original,duplicate>node;
        unordered_map<Node*,Node*>mp;
        Node* tempa=a;
        Node* tempb=b;
        while(tempa!=NULL){
            mp[tempa]=tempb;
            tempa=tempa->next;
            tempb=tempb->next;
        }
        for(auto x:mp){
            Node* o=x.first;
            Node* d=x.second;
            if(o->random!=NULL){/// kam karo
                Node* oran=o->random;
                Node* dran=mp[oran];
                d->random=dran;
            }
        }
        return b;
    }
};