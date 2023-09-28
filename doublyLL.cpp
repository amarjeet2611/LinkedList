#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* prev;
Node* next;
//constructor
Node(int d){
this->data=d;
this->prev=NULL;
this->next=NULL;
}
};

//traversal of Doubly Linked list
void print(Node* head){
Node* temp=head;
while(temp!=NULL){
    cout<<temp->data<<" " ;
    temp=temp->next;
}

cout<<endl;
}
//function for giving length of ll
int getLength(Node* head){
int len=0;

Node* temp=head;
while(temp!=NULL){
  len++;
    temp=temp->next;
}
return len;

}
insertAtHead(Node* &head, int d){
Node* newnode=new Node(d);
newnode->next=head;
head->prev=newnode;
head=newnode;

}
insertAtTail(Node* &tail,int d){
Node* newnode=new Node(d);
tail->next=newnode;
newnode->prev=tail;
tail=newnode;

}
insertAtPos(Node* &tail, Node* &head,int pos,int d){
if(pos==1){
    insertAtHead(head,d);

}
Node* temp=head;
int cnt=1;
while(cnt<pos-1){
    temp=temp->next;
    cnt++;
}
if(temp->next==NULL){
    insertAtTail(tail,d);
   
}
Node* newnode=new Node(d);
newnode->prev=temp;
newnode->next=temp->next;
temp->next=newnode;
newnode->next->prev=newnode;


}

int main(){
Node* node1=new Node(10);
Node* head=node1;
Node* tail=node1;
print(head);
cout<<getLength(head)<<endl;
insertAtHead(head,11);
print(head);

insertAtHead(head,8);
print(head);

insertAtHead(head,15);
print(head);

insertAtHead(head,12);
print(head);

insertAtTail(tail,40);
print(head);

insertAtPos(tail,head,2,100);
print(head);
return 0;
}