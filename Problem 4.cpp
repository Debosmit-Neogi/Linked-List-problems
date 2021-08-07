
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

// utility function to insert node at head of linked list
void insert(node** head, int n){
    node* new_node= new node();
    new_node->data=n;
    new_node->next=*head;
    *head=new_node;
}

// utility function to print linked list
void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

// function to reverse linked list in sets of k elements

node* reverse(node* head, int k){
    if(!head)
    return NULL;
    
    node* current=head;
    node* Next=NULL;
    node* prev=NULL;
    int count=0;
    while(current!=NULL && count<k){
        Next=current->next;
        current->next=prev;
        prev=current;
        current=Next;
        count++;
    }
    if(Next!=NULL)
      head->next=reverse(Next,k);
    return prev;
}

int main(){
    node* head=NULL;
    insert(&head,8);
    insert(&head,7);
    insert(&head,6);
    insert(&head,5);
    insert(&head,4);
    insert(&head,3);
    insert(&head,2);
    insert(&head,1);
    print(head);
    
    node* head_new=reverse(head,3);
    print(head_new);
    
    
}
