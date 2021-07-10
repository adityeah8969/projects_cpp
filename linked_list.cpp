#include <bits/stdc++.h>
using namespace std;

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
    
    if(*head == NULL){
        *head = new node(val);
        return;
    }
    
    node* pcrawl = *head;
    while(pcrawl->next!=NULL){
        pcrawl = pcrawl->next;
    }
    
    node* temp_node = new node(val);
    pcrawl->next = temp_node;
    return;
}

void insert_at_beginning(node** head, int val){
    if(*head == NULL){append(head, val); return;}
    node* temp_node = new node(val);
    temp_node->next = *head;
    *head = temp_node;
    return;
}

void insert_after(node** head, node* temp, int val){
    
    if(*head == NULL){
        cout<<"no elements inside\n";
        return;
    }
    
    if(temp == NULL){
        cout<<"enter valid node pointer\n";
        return;
    }
    
    node* pcrawl = *head;
    node* prev = pcrawl;
    while(pcrawl != temp){
        prev = pcrawl;
        pcrawl=pcrawl->next;
    }
    
    if(pcrawl==NULL){
        cout<<"no such node pointer found\n";
        return;
    }
    
    prev = pcrawl;
    pcrawl = pcrawl->next;
    node* temp_node = new node(val);
    temp_node->next = pcrawl->next;
    prev->next = temp_node;
    temp_node->next=pcrawl;
    
    return;
}

void delete_key(node** head, int val){
    
    if(*head == NULL){
        cout<<"no elements inside\n";
        return;
    }
    
    node* pcrawl = *head;
    node* prev = pcrawl;
    while(pcrawl->data != val){
        prev = pcrawl;
        pcrawl=pcrawl->next;
    }
    
    if(pcrawl==NULL){
        cout<<"no such val(node) found\n";
        return;
    }
    
    if(prev == pcrawl){             // if the first element is the node with data 'val'.
        *head = prev->next;
        prev->next = NULL;
        delete(prev);
        return;
    }
    
    prev->next = pcrawl->next;
    pcrawl->next = NULL;
    delete(pcrawl);
    return;
}

void nth_from_end(node** head, int n){
    
    if(n<1){
        cout<<"enter valid n\n";
        return;
    }
    
    if(*head == NULL){
        cout<<"no elements inside\n";
        return;
    }
    
    node* pcrawl = *head;
    node* prev = pcrawl;
    
    int k=1;
    while(k<n && pcrawl!=NULL){
        pcrawl = pcrawl->next;
        k++;
    }
    
    if(k<n){
        cout<<"not enough nodes inside\n";
        return;
    }
    
    while(pcrawl->next!=NULL){
        pcrawl = pcrawl->next;
        prev = prev->next;
    }
    cout<<prev->data<<"\n";
    return;
}


void print_soln(node* head){
    
    node* pcrawl = head;
    
    while(pcrawl != NULL){
        cout<<pcrawl->data<<"->";
        pcrawl = pcrawl->next;
    }
    cout<<"null\n";
    return;
}

int main(){
    
    node* head = NULL;
    print_soln(head);

    append(&head, 6);
    print_soln(head);
    
    insert_at_beginning(&head, 7);
    print_soln(head);
    
    insert_at_beginning(&head, 1);
    print_soln(head);
    
    append(&head, 4);
    print_soln(head);
    
    insert_after(&head,head->next->next, 8);
    print_soln(head);

    delete_key(&head, 1);
    print_soln(head);
    
    nth_from_end(&head, 3);
    
    return 0;
}