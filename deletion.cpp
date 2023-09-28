#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
~Node(){
    int value=this->data;
    //memory free
    if(this->next!=NULL){
        delete next;
        this->next=NULL;
    }
   cout<<"Memory is free for node with data"<<value<<endl; 
}

};
void deleteNode(int pos,Node* &head){

    if(pos==1){
Node* temp=head;
head=head->next;
temp->next=NULL;
delete temp;

    }
    else{
//deleting any middle node or last node 
Node* curr=head;
Node* prev=NULL;
int cnt=1;
while(cnt<=pos){
prev=curr;
curr=curr->next;
cnt++;
}
prev->next=curr->next;
curr->next=NULL;
delete curr;
    }

}


void insertAtHead(Node* &head,int d){
    //new node create
Node* temp=new Node(d);
temp->next=head;
head=temp; 
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    //create a new node
Node* node1=new Node(10);



//head pointed to node1
Node* head=node1;
print(head);
insertAtHead(head,12);
print(head);




deleteNode(1,head);
print(head);
    return 0;
}