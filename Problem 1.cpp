

#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

void reverse(node** head){
    node* current=*head;
    node* prev=NULL;
    node* Next=NULL;
    
    while(current!=0){
        Next=current->next;
        current->next=prev;
        prev=current;
        current=Next;
    }
    *head= prev;
}

void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

void add_front(node** head, int n){
    node* new_node= new node();
    new_node->data=n;
    new_node->next=*head;
    *head=new_node;
}

void add_one(node** head){
    reverse(head);
    node* temp=*head;
    temp->data+=1;
    // loop upto 2nd last element
    while(temp->next!=NULL){
        if(temp->data>9){
            temp->data-=10;
            temp->next->data+=1;
        }
        temp=temp->next;
    }
    node* new_node=new node();
    new_node->data=1;
    if(temp->data>9){
        temp->data-=10;
        temp->next=new_node;
    }
    reverse(head);

}

int main(){
    int t; cin>>t;
    while(t--){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    node* head=NULL;
    for(int i=n-1;i>=0;i--){
        add_front(&head, arr[i]);
    }
    
    
    // print(head);
    
    // reverse(&head);
    // print(head);
    
    add_one(&head);
    print(head);
    }
    
}


