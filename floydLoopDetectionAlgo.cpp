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
};
void insertAtPos(Node* &head,int position,int d){
Node* temp=head;
int cnt=1;
while(cnt<position-1){
    temp=temp->next;
    cnt++;
}
//creating a node for d
Node* nodeToInsert= new Node(d);

nodeToInsert->next=temp->next;
temp->next=nodeToInsert;




}
void insertAtHead(Node* &head,int d){
    //new node create
Node* temp=new Node(d);
temp->next=head;
head=temp; 
}
void insertAtTail(Node* &tail,int d){
Node* temp=new Node(d);
tail->next=temp;
tail=tail->next;
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<endl;
}

Node* floydDetectLoop(Node* head){
if(head==NULL){
    return NULL;
}
Node* slow= head;
Node* fast=head;
while(slow!=NULL && fast!=NULL){
    fast=fast->next;
    if(fast !=NULL){
        fast=fast->next;
    }
    slow=slow->next;
    if(slow==fast){
        return slow;
    }
}
return NULL;
}




int main(){
    //create a new node
Node* node1=new Node(10);

cout<<node1-> data <<endl;
cout<<node1-> next<<endl;
//head pointed to node1
Node* head=node1;
Node* tail=node1;
print(head);
insertAtTail(tail,12);
print(head);
insertAtPos(head,4,22);
print(head);
tail->next=head->next;
cout<<"head"<<head->data<<endl;
cout<<"tail"<<tail->data<<endl;

if(floydDetectLoop(head)!=NULL){
cout<<"Cycle is Present"<<endl;
}
else{
    cout<<"No cycle "<<endl;
}
    return 0;
}