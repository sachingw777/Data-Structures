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
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count ;
}

//Recursive Length
int length1(Node *head) {
    if(head == NULL){
        return 0;
    }
    
    return 1 + length(head->next);
}


//Recursive Length
int length1(Node *head) {
    if(head == NULL){
        return 0;
    }
    
    return 1 + length(head->next);
}


void print(Node *head){
    Node * temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
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
}

Node* insertNode(Node *head, int i, int data){
    Node *newNode = new Node(data);
    Node *temp = head;
    int count = 0;

    if(i == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }

    while(temp != NULL && count < i - 1){
        temp = temp -> next;
        count++;
    }
    if(temp != NULL){
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
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

void append_LinkedList1(Node* head,int n){
    Node * temp = head;
    Node * h2 = NULL, *secondIndex = NULL;
    int count = 0, length_LL = length(head);
    
    while(temp->next != NULL){
        // if(count == length_LL - n - 1){
        //     cout << temp->data << endl;
        // }
        temp = temp->next;
        count++;
    }
    cout << temp->data;
    // return head;
}

Node* append_LinkedList(Node* head,int n){
    Node * temp = head;
    Node * h2 = NULL, *secondIndex = NULL;
    int count = 0, length_LL = length(head);
    
    while(temp->next != NULL){
        if(count == length_LL - n - 1){
            secondIndex = temp;
            h2 = temp->next;
        }
        temp = temp->next;
        count++;
    }
    secondIndex->next = NULL;
    temp->next = head;
    head = h2;  

    return head;
}


int main(){

    Node *head = takeInput_Better();
    head = append_LinkedList(head, 2);
    print(head);
    
    // cout << length(head) <<endl;

    // head = deleteNode(head, 50);
    // print(head);

    /*    Node n1(10);
    Node * head = &n1;

    Node n2(20);
    n1.next = &n2;

    Node n3(30);
    n2.next = &n3;
    n3.next = NULL;

    print(head);
*/
    /*
    Node *n10 = new Node(20);
    Node *head = n10;
    Node *n4 = new Node(30);
	n10 -> next = n4;
    print(head);
    */
}