
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

void remove_duplicate(node* head){
    node * temp1= head;
    node* temp2;
    node* aux;
    while(temp1!=NULL && temp1->next!=NULL){
        temp2=temp1;
        while(temp2->next!=NULL){
            if(temp2->next->data==temp1->data){
                aux=temp2->next;
                temp2->next=aux->next;
                delete aux;
            }
            else
                temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}

int main(){
    node* head=NULL;
    insert(&head, 5);
    insert(&head, 13);
    insert(&head, 5);
    insert(&head, 56);
    insert(&head, 1);
    insert(&head, 5);
    
    print(head);
    
    remove_duplicate(head);
    
    print(head);
}

