#include <bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node* next;
};

node* reverse_recursive(node* head){
    if(head==NULL) // corner case
        return head;
    if(head->next==NULL)  // base case
        return head;
    
    node* shead= reverse_recursive(head->next); // shead= new head for the reversed linked list
    head->next->next=head;
    head->next=NULL;
    return shead;
}

void add(node** head, int n){
    node* new_node= new node();
    new_node->next= *head;
    *head= new_node;
    new_node->data=n;
}

void print(node* head){
    node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

int main(){
    node* head=NULL;
    add(&head, 5);
    add(&head, 4);
    add(&head, 3);
    add(&head, 2);
    add(&head, 1);
    
    print(head);
    
    node* shead=reverse_recursive(head);
    
    print(shead);
}



