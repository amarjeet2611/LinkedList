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
void reverse1(Node* &head,Node* curr,Node* prev){
//base case
  if(head==NULL || head->next==NULL){
    return head;
  }
  Node* chotahead=reverse(head->next);
  head->next->next=head;
  head->next=NULL;
  return chotahead;

}
Node* reverseLinkedList(Node* head){

    return reverse1(head->next);
    
}

int main(){
return 0;
}