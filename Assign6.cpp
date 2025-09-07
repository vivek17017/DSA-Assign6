#include<iostream>
using namespace std;
struct node
{
    int item;
    node* next;
};
class CLL{
    private:
        node* last;
    public:
        CLL(){
            last=nullptr;
        }
        void insertDataAtBeggining(int);
        void insertDataAtEnd(int);
        node* searchNode(int);
        void insertDataAfter(int,node*);
        void deleteFirstNode();
        void deleteLastNode();
        void deleteSpecificNode(node*);
        ~CLL();
};
void CLL::insertDataAtBeggining(int data){
    node* temp=new node;
    temp->item=data;
    if(last==nullptr){
        temp->next=temp;
        last=temp;
    }
    else{
        
        temp->next=last->next;
        last->next=temp;
    }
}
void CLL::insertDataAtEnd(int data){
    node* temp=new node;
    temp->item=data;
    if(last==nullptr){
        temp->next=temp;
        last=temp;
    }
    else{
        
        temp->next=last->next;
        last->next=temp;
        last=temp;
    }
}
node* CLL::searchNode(int data){
    if(last==nullptr)
    return nullptr;
    else{
    node* t=last;
    while (last->next!=t)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    return nullptr;
}
    
}
void CLL::insertDataAfter(int data,node* t){
    if(last!=nullptr){
    if(searchNode(t->item)==t){
        node* temp=new node;
        temp->item=data;
        temp->next=t->next;
        t->next=temp;
        if(t==last)
        last=temp;
    }
    else
    cout<<"node is not correct";
}
}
void CLL::deleteFirstNode(){
    if(last!=nullptr){
        node* temp=last->next;
        last->next=last->next->next;
        if(last->next==last)
        last=nullptr;
        delete temp;
        
    }
}
void CLL::deleteLastNode(){
    if(last!=nullptr){
    node* t=last;
    if(last->next==last){
        delete last;
        last=nullptr;
    }
    else{
    while (last!=t->next)
    {
        t=t->next;
    }
    t->next=last->next;
    delete last;
    last=t;
        
    }
}
}
void CLL::deleteSpecificNode(node* temp){
    if(last!=nullptr){
        if(temp==searchNode(temp->item)){
            node* t=temp;
    while (temp!=t->next)
    {
        t=t->next;
    }
    t->next=temp->next;
    delete temp;
        }
    }
}
CLL::~CLL(){
    while (last!=nullptr)
    {
        deleteFirstNode();
    }
    
}