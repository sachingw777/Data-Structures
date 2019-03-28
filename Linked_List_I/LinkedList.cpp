#include <iostream>
using namespace std;
#include "Node.cpp"

void print(Node *head){
    Node * temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
      
}

int main(){
/*    Node n1(10);
    Node * head = &n1;

    // print(head);


    Node *n10 = new Node(20);
    Node *head = n10;
    Node *n4 = new Node(30);
	n10 -> next = n4;
    print(head);
}