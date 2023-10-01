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
Node* kreverse(Node* head,int k){
    //base case
    if(head==NULL){
        return NULL;
    }
    //step1: reverse 1st k nodes
Node* next=NULL;
Node* curr=head;
Node* prev=NULL;
int count=0;

while(curr!=NULL && count<k){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
    count++;
}

return prev;

}
int main(){
    return 0;
}