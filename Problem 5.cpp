
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
    int flag; // flag==1 if node is visited, otherwise flag=0
};

void insert(node** head, int n){
    node* new_node= new node();
    new_node->data=n;
    new_node->next=*head;
    new_node->flag=0;
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

bool isLoop(node* head){
    while(head!=NULL){
        if(head->flag==1) // node already visited, loop is present
            return true;
        
        head->flag=1; // if node is visited for 1st time, flag=1
        head=head->next;
    }
    return false;
}

int main(){
    node* head=NULL;
    insert(&head,20);
    insert(&head,7);
    insert(&head,4);
    insert(&head,19);
    
    // creating a loop
    
    head->next->next->next->next=head;
    print(head);
    
    bool result= isLoop(head);
    if(result==true)
        cout<<"Loop is present\n";
    else
        cout<<"Loop not present\n";
    
}

