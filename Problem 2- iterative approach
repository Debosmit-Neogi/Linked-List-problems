
/* reverse a linked list- iterative */

#include <bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node* next;
};

void reverse(node** head){
    node* current=* head;
    node* prev=NULL;
    node* Next=NULL;
    
    while(current!=NULL){
        Next=current->next;
        current->next=prev;
        prev=current;
        current=Next;
    }
    *head=prev;
}

// Function to add node before head

void add(node** head, int n){
    node* new_node = new node();
    new_node->next=*head;
    new_node->data=n;
    *head=new_node;
}


void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

int main(){
    node* head=NULL;
    add(&head,6);
    add(&head,5);
    add(&head,4);
    add(&head,3);
    add(&head,2);
    add(&head,1);
    
    reverse(&head);
    
    print(head);
    
}



