
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

void insert(node** head, int n){
    node* new_node= new node();
    new_node->data=n;
    new_node->next=*head;
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

// Find middle using runners' technique (fast and slow pointer concept)

node* find_middle(node* head){
    
    // runners technique
    node* fast=head->next;
    node* slow= head;
    
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}


int main(){
    node* head=NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);
    
    node* slow= find_middle(head);
    cout<<slow->data;
    
}

