#include<bits/stdc++.h>
using namespace std;

class node{
    public:

    int data;
    node* next;
    node* prev;

    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n=new node(val);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }

    head=n;
}

void insertAtTail(node* &head, int val){

    if(head==NULL){
        insertAtHead(head,val);
        return;
    }

    node* n= new node(val);
    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=n;
    n->prev=temp;
}

void display(node*head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    head->prev=NULL;

    delete todelete;
}

void deletion(node* &head, int pos){
    
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    int count=1;

    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }

    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    

    delete temp;
}

int lenght(node *head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        l++;
        temp = temp->next;
    }
    return l;
}

node* kappend(node* &head, int k){
   node* newhead;
   node* newtail;
   node* tail=head;

   int l=lenght(head);
   k=k%l;
   int count=1;
   while(tail->next!=NULL){
    if(count==l-k){
        newtail=tail;
    }
    if(count==l-k+1){
        newhead=tail;
    }
    tail=tail->next;
    count++;
   }

   newtail->next=NULL;
   tail->next=head;

   return newhead;
}

int main(){
// node* head=NULL;
// insertAtTail(head,1);
// insertAtTail(head,2);
// insertAtTail(head,3);
// insertAtTail(head,4);
// display(head);

// insertAtHead(head,5);
// insertAtHead(head,6);
// display(head);

// insertAtTail(head,7);
// insertAtTail(head,8);
// insertAtTail(head,9);
// insertAtTail(head,10);
// insertAtHead(head,11);
// insertAtHead(head,12);
// display(head);

// deletion(head,6);
// display(head);

// insertAtHead(head,13);
// insertAtHead(head,12);
// display(head);


node* head=NULL;
int arr[]={1,2,3,4,5,6};
for(int i=0;i<6;i++){
    insertAtTail(head,arr[i]);
}
display(head);
node* newhead=kappend(head,3);
display(newhead);

return 0;
}