#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    
    node(int val){
        data =  val;
        next =  NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}

void insertAtTail(node* &head, int val){

    node* n = new node(val);

    if(head==NULL){
        head=n;
        return;
    }

    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
 
}

void display1(node* &head){
    node* temp = head;
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    while(temp!=NULL){
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

bool Search(node* head, int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;

}

/*
void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;

    delete todelete;
}
*/

void deletion(node* &head, int val){

node* temp=head;
    if(head==NULL){
        return;
    }

    if(head->next==NULL){
        head=NULL;
        delete head;
        return;
    }

    
    if(temp->data==val){
        head=temp->next;
        delete temp;
        return;
    }
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;
}

// node* reverse(node* &head){
//     node* prevptr=NULL;
//     node* currptr=head;
//     node* nextptr;

//     while(currptr!=NULL){
//         nextptr=currptr->next;
//         currptr->next=prevptr;

//         prevptr=currptr;
//         currptr=nextptr;
//     }
//     return prevptr;
// }

//Recursive method

node* reverse1(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* newhead=reverse1(head->next);
    head->next->next=head;
    head->next=NULL;

    return newhead;
}

// node* reverse2(node* &head){
//     // node* &head;
//     while(head->next!=NULL){
//         node* &head=swap(&head,&head->next);
//     }
// }


node* reversek(node* &head, int k){

    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    
    if(nextptr!=NULL){
    head->next = reversek(nextptr,k);
    }

    return prevptr;
}


int main(){

node* head=NULL;
insertAtTail(head,1);
insertAtTail(head,2);
insertAtTail(head,3);
display1(head);

insertAtHead(head,4);
insertAtHead(head,5);
insertAtHead(head,6);

cout<<Search(head,5)<<endl;
display1(head);

int k=2;
node* newhead1 = reversek(head,k);
display1(newhead1);

node* newhead = reverse1(head);
display1(newhead);
//in singly linked list after reversing we can't acess it


cout<<Search(head,5)<<endl;

deletion(head,1);
deletion(head,2);
deletion(head,3);
deletion(head,4);
deletion(head,5);
display1(head);

deletion(head,6);
display1(head);


return 0;
}