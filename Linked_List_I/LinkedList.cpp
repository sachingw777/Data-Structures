#include <iostream>
using namespace std;
#include "Node.cpp"

Node *takeInput_Better(){
    int data;
    cin >> data;

    Node *head = NULL; 
    Node *tail = NULL; 

    while(data != -1){
        Node * newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

Node *takeInput(){
    int data;
    cin >> data;

    Node *head = NULL; 
    while(data != -1){
        Node * newNode = new Node(data);
        if(head == NULL){
            head = newNode;
        }else{
            Node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cin >> data;
    }
    return head;
}

int length(Node *head) {
    Node * temp = head;
    int count = 0;
    while(temp->next != NULL){
        temp = temp->next;
        count++;
    }
    return count ;
}

void print(Node *head){
    Node * temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
      
void printIthNode(Node *head, int i) {
    if(i > length(head)){
        return;
    }
    Node * temp = head;
    int count = 0;
    while(temp != NULL){
        if(count == i){
            cout << temp->data;
        }
        temp = temp->next;
        count++;
}

void insertNode(Node *head, int i, int data){
    Node *newNode = new Node(data);
    Node *temp = head;
    int count = 0;

    if(i == 0){
        newNode->next = head;
        head = newNode;
    }

    while(temp != NULL && count < i - 1){
        temp = temp -> next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

Node* insertNodeRec(Node *head, int i, int data) {
    if(head == NULL){
        if(i == 0){
            Node *newNode = new Node(data);
            return newNode;
        }
        else{
            return head;
        }
    }
    
    Node *newNode = new Node(data);
    
    if(i == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }
    
    head->next = insertNodeRec(head->next, i - 1, data);
    return head;
}

Node* deleteNode(Node *head, int i) {
    Node *temp = head;
    if(i == 0){
        temp = temp->next;
        return temp;
        delete head;
    }
    
    int count = 0; 
    Node *previousNode = NULL;
    while(temp != NULL && count <= i - 1){
        if(count == i - 1){
            previousNode = temp;
        }

        // if (temp == NULL || temp->next == NULL){
        //  return head; 
        // }
        
        temp = temp->next;
        count++;
    }
  if(temp != NULL){
previousNode->next = temp->next;
    delete temp;
  }  
    return head;
}

Node* deleteNodeRec(Node *head, int i) {
    if(head == NULL){
        return head;
    }
    
    Node *temp = head;
    if(i == 0){
        head = head->next;
        delete temp;
        return head;
    }
    head->next = deleteNodeRec(head->next, i - 1);
    return head;
}

Node* append_LinkedList(Node* head,int n){
    Node * temp = head;
    Node * h2 = NULL, *secondIndex = NULL;
    int count = 0, length_LL = length(head);
    
    while(temp->next != NULL){
        if(count == length_LL - n - 1){
            cout << temp->data;
        }
    }
    return head;
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