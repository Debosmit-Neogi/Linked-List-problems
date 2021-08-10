
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

// node* reverse_ll(node* head){
//     // base case
//     if(head==NULL or head->next==NULL) // if 1 or no node is present
//         return head;
//     //recursive cases
//     node* shead= reverse_ll(head->next);  // head->1->5<-4<-3<-2<-shead
//     head->next->next=head;
//     head->next=NULL;
//     return shead;
// }

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
    return c;
}


int main(){
    node* a=NULL;
    node* b=NULL;
    add(&a, 5);
    add(&a,3);
    add(&a,1);
    add(&b,6);
    add(&b,4);
    add(&b,2);
    
    node* c=merge_sorted_ll(a,b);
    print(c);
    
    
}

