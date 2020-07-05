#include<bits/stdc++.h>
#include<iostream>
using namespace std;

const int ALPHABET_SIZE=26;

class node{
    public:
    node* children[ALPHABET_SIZE];
    bool end_of_world;
};

node* getNode(){
    node* temp=new node();
    for(int i=0;i<ALPHABET_SIZE;i++){temp->children[i]=NULL;}
    temp->end_of_world=false;
    return temp;
}

void insert(node* pcrawl,string str){
    for(int i=0;i<str.length();i++){
        int index=str[i]-'a';
        if(!pcrawl->children[index]){pcrawl->children[index]=getNode();}
        pcrawl=pcrawl->children[index];
    }
    pcrawl->end_of_world=true;
}

bool search(node* pcrawl,string str){
    for(int i=0;i<str.length();i++){
        int index=str[i]-'a';
        if(!pcrawl->children[index]){return false;}
        pcrawl=pcrawl->children[index];
    }
    return(pcrawl!=NULL && pcrawl->end_of_world);
}

bool isEmpty(node* pcrawl){
    for(int i=0;i<ALPHABET_SIZE;i++){
        if(pcrawl->children[i]!=NULL){return false;}
    }
    return true;
}

node* remove(node* pcrawl,string str,int depth){
    
    if(pcrawl==NULL){return NULL;}

    if(depth==str.size()){
        if(pcrawl->end_of_world){pcrawl->end_of_world=false;}
        if(isEmpty(pcrawl)){
            delete(pcrawl);
            pcrawl=NULL;
        }
        return pcrawl;
    }

    int index=str[depth]-'a';
    pcrawl->children[index]=remove(pcrawl->children[index],str,depth+1);

    if(isEmpty(pcrawl) && pcrawl->end_of_world==false){
        delete(pcrawl);
        pcrawl=NULL;
    }
    return pcrawl;
}

int main(){

    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);

    node* root=getNode();
    for(int i=0;i<n;i++){insert(root,keys[i]);}

    string toFind="answer";
    if(search(root,toFind)){cout<<toFind<<" is present\n";}
    else{cout<<toFind<<" is not present\n";}

    toFind="abcd";
    if(search(root,toFind)){cout<<toFind<<" is present\n";}
    else{cout<<toFind<<" is not present\n";}
    
    toFind="answer";
    remove(root,toFind,0);
    if(search(root,toFind)){cout<<toFind<<" is present\n";}
    else{cout<<toFind<<" is not present\n";}
    
    return 0;
}