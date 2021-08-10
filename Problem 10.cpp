
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

void add(node** head, int n){
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


node* merge_sorted_ll(node* a, node* b){
    // base cases
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    
    //recursive function
    node* c;
    if(a->data<b->data){
        c=a;
        c->next=merge_sorted_ll(a->next,b);
    }
    
    else if(b->data<a->data){
        c=b;
        c->next=merge_sorted_ll(a,b->next);
    }
    return c; //returns head of the merged sorted linked list
}

node* midpoint(node* head){
    node* fast=head->next;
    node* slow=head;
    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

node* merge_sort(node* head){
    /*
    Steps to follow:
    1. find mid point of linkedlist
    2. break ll from mid
    3. apply merge_sort function recursively on the 2 smaller linkedlist untill both 
    get sorted
    4.merge the 2 sorted linked list
    */
    if(head==NULL or head->next==NULL)
        return head;
    node* mid=midpoint(head); //find midpoint of main linkedlist
    node*a =head;
    node* b=mid->next;
    mid->next=NULL; //break ll from midpoint
    
    //recursively call merge sort function on 2 seperate linkedlist
    a=merge_sort(a);
    b=merge_sort(b);
    return merge_sorted_ll(a,b);
    
}


int main(){
    node* head=NULL;
    add(&head, 5);
    add(&head,3);
    add(&head,1);
    add(&head,6);
    add(&head,4);
    add(&head,2);
    print(head);
    node* c= merge_sort(head);
    print(c);
    
    
}

