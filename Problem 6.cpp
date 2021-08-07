#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

void delete_duplicate(node* head){
    node* temp=head;
    node* aux=NULL;
    while(temp->next!=NULL){ //traverse upto last node
        if(temp==NULL)
            return;
        if(temp->data==temp->next->data){
            aux=temp->next; // "aux" pointer points towards the node to be deleted 
            temp->next=aux->next;
            delete aux;
        }
        else
            temp=temp->next;
    }
}

// utility function to insert node at head
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
int main(){
    node* head=NULL;
    
    insert(&head,19);
    insert(&head,19);
    insert(&head, 19);
    insert(&head,14);
    insert(&head,7);
    insert(&head,7);
    insert(&head,2);
    
    
    print(head);
    delete_duplicate(head);
    print(head);
}
