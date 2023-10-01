#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* next;

Node(int d){
    this->data=d;
    this->next=NULL;
}
~Node(){
int value=this->data;
if(this->next!=NULL){
    delete next;
    next=NULL;
}
cout<<"memory is free for node with data"<<value<<endl;

}

};
insertNode(Node* &tail,int element,int d){
 if(tail==NULL){
    Node* newnode=new Node(d);
    tail=newnode;
    newnode->next=newnode;

 }
else{
Node* curr=tail;
while(curr->data!=element){
    curr=curr->next;
}
Node* temp=new Node(d);
temp->next=curr->next;
curr->next=temp;


}

}
void print(Node* tail){
Node* temp=tail;
do{
    cout<<tail->data<<" ";
    tail=tail->next;
}while(tail!=temp);
cout<<endl;

}
void deleteNode(Node* &tail,int value){
//empty list
if(tail==NULL){
    cout<<"list is empty, please check again"<<endl;
    return; 
}
else{
Node* prev=tail;
Node* curr=prev->next;

while(curr->data!=value){
    prev=curr;
    curr=curr->next;
}
prev->next=curr->next;
// 1 node linked list 

if(curr==prev){
    tail=NULL;
}
if(tail==curr){
    tail=prev;
}


if(tail==curr){
    tail=prev;
}
curr->next=NULL;
delete curr;


}

}
bool isCircularList(Node* head){
    if(head==NULL){
        return false;
    }
Node* temp=head->next;
while(temp!=NULL && temp!=head){
    temp=temp->next;
}
if(temp==head){
    return true;
}


return false;

}
int main(){
Node* tail=NULL;
//empty list me insert
insertNode(tail,5,3);
print(tail);

insertNode(tail,3,7);
print(tail);

deleteNode(tail,3);
print(tail);

if(isCircularList(tail)){
    cout<<"Its a circular linkedList !"<<endl;
}
else{
    cout<<"Not circular LL!"<<endl;
}
    return 0;



}