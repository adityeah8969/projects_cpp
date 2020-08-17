#include<bits/stdc++.h>
using namespace std;

#define ll long long int

class node{
    public:
        int data;
        node* next;
        node(int val){
            this->data = val;
            this->next = NULL;
        }
};

void append(node** head, int val){

    node* prev = *head;
    node* pcrawl = *head;

    while(pcrawl!=NULL){
        prev = pcrawl;
        pcrawl = pcrawl->next;
    }

    node* to_insert = new node(val);
    if(prev == NULL){
        *head = to_insert;
        return;
    }
    prev->next = to_insert;
    return;
}

void print_soln(node* head){
    cout<<"linked list: ";
    while(head!=NULL){
        cout<<" -> "<<head->data;
        head = head->next;
    }
    cout<<"\n";
    return;
}



node* merge(node* a, node* b){

    node* head1 = NULL;                         // initialize head1 with NULL

    node* pcrawl_a = a;
    node* pcrawl_b = b;

    while(pcrawl_a!=NULL && pcrawl_b!=NULL){
        if(pcrawl_a->data <= pcrawl_b->data){
            append(&head1, pcrawl_a->data);
            pcrawl_a=pcrawl_a->next;
        }
        else{
            append(&head1, pcrawl_b->data);
            pcrawl_b=pcrawl_b->next;
        }
    }

    if(pcrawl_a==NULL){
        while(pcrawl_b!=NULL){
            append(&head1, pcrawl_b->data);
            pcrawl_b=pcrawl_b->next;
        }
    }

    if(pcrawl_b==NULL){
        while(pcrawl_a!=NULL){
            append(&head1, pcrawl_a->data);
            pcrawl_a=pcrawl_a->next;
        }
    }

    return head1;
}

void split_list(node* head, node** a, node** b){

    if(head == NULL){return;}

    node* slow = head;
    node* fast = head->next;                    //* make fast point to head->next

    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    *a = head;
    *b = slow->next;
    slow->next=NULL;
    return;
}

void merge_sort(node** head){

    if(*head == NULL || (*head)->next==NULL){return;}

    node* a=NULL;
    node* b=NULL;

    split_list(*head, &a, &b);
    merge_sort(&a);
    merge_sort(&b);

    *head = merge(a,b);

    return;
}


int main(){

    node* head = NULL;

    append(&head, 15);
    append(&head, 10);
    append(&head, 5);
    append(&head, 20);
    append(&head, 3);
    append(&head, 2);

    print_soln(head);
    merge_sort(&head);

    cout<<"\nlist after sorting: ";
    print_soln(head);

    return 0;
}