//Detect Cycle
//Floyd's Algorithm
//Hare and Tortoise Algorithm


#include<bits/stdc++.h>
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

bool detectCycle(node* &head){

    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow){
            return true;
        }
    }
    return false;

}

void makeCycle(node* &head, int pos){
    node* temp=head;
    node* startNode;

    int count=1;
    while(temp->next!=NULL){

        if(count==pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}

void removeCycle(node* &head){
    node* slow=head;
    node* fast=head;

    do
    {
       slow=slow->next;
       fast=fast->next->next;
    } while (slow!=fast);

    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
       
 slow->next=NULL;
}

int main(){

    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);

    makeCycle(head,3);
    // display1(head);
    cout<<detectCycle(head)<<endl;
    removeCycle(head);

    cout<<detectCycle(head)<<endl;
    display1(head);



return 0;
}
