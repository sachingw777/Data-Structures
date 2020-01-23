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

void print(Node *head){
    Node * temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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

int indexOfNIter(Node *head, int n) {
    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        if(temp -> data == n){
            return count;
        }
        temp = temp -> next;
        count++;
    }
    return -1;
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

Node* eliminate_duplicate(Node* head)
{
    Node *temp = head, *t1 = head, *t2 = head->next;
    while(temp != NULL && temp->next != NULL){
        if(t1->data == t2->data){
            Node *deleteNode = t2;
            t2 = t2->next;
            delete deleteNode;
        }else if(t1->next != t2->next){
            t1->next = t2;
            t2 = t2->next;
            t1 = t1->next;
        }
        temp = temp ->next;
    }
    t1->next = NULL;
    return head;
}

void print_linkedlist_spl(Node*head)
{
    if(head == NULL){
        return;
    }
    print_linkedlist_spl(head->next);
    cout << head->data << " ";
}

Node* reverse(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    
    Node* second = reverse(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    head = second;
    return head;
}

bool check_palindrome(Node* head)
{
    Node* fast = head -> next, *slow = head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    Node* secondhead = slow -> next;
    slow -> next = NULL;
    Node* second = reverse(secondhead);
    while(head != NULL && second != NULL){
        if(head -> data == second -> data){
            head = head->next;
            second = second->next;
        }else{
            return false;
        }
    }
    return true;
}

int main(){

    Node *head = takeInput_Better();
    // head = insertNode(head, 3, 99);
    // print(head);
    // deleteNode(head,3);
    // print(head);
    // head = append_LinkedList(head, 2);
    // print(head);
    
    // cout << length(head) <<endl;

    // head = deleteNode(head, 50);
    // print(head);

    // Node n1(10);
    // Node * head = &n1;

    // Node n2(20);
    // n1.next = &n2;

    // Node n3(30);
    // n2.next = &n3;
    // n3.next = NULL;

    // print(head);

    /*
    Node *n10 = new Node(20);
    Node *head = n10;
    Node *n4 = new Node(30);
	n10 -> next = n4;
    print(head);
    */
}