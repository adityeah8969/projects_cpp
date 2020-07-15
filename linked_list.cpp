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


void insert_at_beginning(node** head, int val){
    
    if(*head == NULL){append(head, val); return;}

    node* next_node = (*head)->next;
    node* to_insert = new node(val);
    (*head)->next = to_insert;
    to_insert->next = next_node;
    
    return;
}

void insert_after(node** head, node* temp, int val){

    node* pcrawl = *head;
    node* prev = *head;
    
    while(pcrawl!=temp){
        prev = pcrawl;
        pcrawl = pcrawl->next;
    }

    node* to_insert = new node(val);
    prev->next = to_insert;
    to_insert->next = pcrawl;
    return;
}

void delete_key(node** head, int val){

    if(*head == NULL){
        cout<<"no elements in the list \n";
        return;
    }

    if((*head)->data == val){
        node* to_delete = (*head);
        node* next_to_head = (*head)->next;
        (*head) = next_to_head;
        if((*head) == NULL){
            cout<<"No node left\n";
        }
        delete(to_delete);
        return;
    }

    node* pcrawl = *head;
    node* prev = *head;

    while(pcrawl!=NULL){
        if(pcrawl->data == val){break;}
        prev = pcrawl;
        pcrawl = pcrawl->next;
    } 

    node* to_delete = pcrawl;
    prev->next = pcrawl->next;
    delete(to_delete);
    return;
}

int nth_from_end(node** head, int n){

    node* temp1 = *head;
    node* temp2 = *head;

    int k=1;
    while(k<n && temp2!=NULL){temp2=temp2->next;k++;}
    if(k<n){cout<<"not enough number of nodes\n";return INT_MAX;}
    
    if(temp2!=NULL){temp2=temp2->next;}

    while(temp2!=NULL){
        temp2=temp2->next;
        temp1=temp1->next;
    }
    return temp1->data;
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

int main(){

    node* head = NULL;
    append(&head, 6);
    insert_at_beginning(&head, 7);
    insert_at_beginning(&head, 1);
    append(&head, 4);
    insert_after(&head,head->next, 8);
    
    print_soln(head);

    // delete_key(&head, 1);
    // print_soln(head);
    
    cout<<nth_from_end(&head, 3)<<"\n";
    

    return 0;
}