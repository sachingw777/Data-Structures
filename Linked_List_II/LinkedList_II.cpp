#include <iostream>
using namespace std;
#include "Node.cpp"

Node* midpoint_linkedlist(Node *head){
    if(head == NULL && head->next == NULL){
        return head;
    }
    
    Node *slow = head, *fast = head->next;
    
    while(fast!=NULL && fast->next!= NULL){   
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *reverse_linked_list_rec(Node *head)
{
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node *smallOutput = reverse_linked_list_rec(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return smallOutput;
}

Node* mergeTwoLLs(Node *head1, Node *head2) {
    Node *finalHead = NULL, *finalTail = NULL;
    if(head1 -> data <= head2 -> data){
        finalHead = head1;
        finalTail = head1;
        head1 = head1 -> next;
    }else{
        finalHead = head2;
        finalTail = head2;
        head2 = head2 -> next;
    }

    while(head1 != NULL && head2 != NULL){
        if(head1 -> data <= head2 -> data){
            finalTail -> next = head1;
            head1 = head1 -> next;
            finalTail = finalTail -> next;
        }else if(head1 -> data > head2 -> data)
        {
            finalTail -> next = head2;
            head2 = head2 -> next;
            finalTail = finalTail -> next;
        }
    }

    if(head1 != NULL){
        finalTail -> next= head1;
    }
    if(head2 != NULL){
        finalTail -> next= head2;
    }

    return finalHead;
}

Node* mergeSort(Node *head) {
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node *midpoint = midpoint_linkedlist(head);   //midpoints h1, h2
    Node *h2 = midpoint -> next;
    midpoint -> next = NULL;
    
    Node *first = mergeSort(head);        //RC
    Node *second = mergeSort(h2);
    
    return mergeTwoLLs(first, second);
}

Node *rev_linkedlist_itr(Node* head)
{
    Node *previous = NULL, *current = head, *nextIndex = NULL;

    while(current != NULL){
        nextIndex = current -> next;    //save next
        current -> next = previous;     //join previous
        previous = current;             //move pointers
        current = nextIndex;
        nextIndex = nextIndex -> next;
    }
    
    return previous;
}

//1test case fail. other 5passed. check later.
Node skipMdeleteN(Node *head, int M, int N) {
    if(M == 0){
        return NULL;
    }
    Node *previous = NULL, *temp = head;
    int count = 1;


    while(temp != NULL){
        if(count == M){
            previous = temp;
        }

        if(count == M + N){
            previous -> next = temp -> next;
            count = 0;
        }

        count++;
        temp = temp -> next;
    }
    previous -> next = NULL;
    return head;
}

Node* arrange_LinkedList(Node* head)
{
    Node *evenHead = NULL, *evenTail = NULL, *oddHead = NULL, *oddTail = NULL;
    if(head -> data % 2 == 0){
        evenHead = head;
        evenTail = head;
        head = head -> next; 
    }else{
        oddHead = head;
        oddTail = head;
        head = head -> next;
    }

    while(head != NULL){
        if(head -> data % 2 == 0){
            if(evenHead == NULL){
                evenHead = head;
                evenTail = head;
            }else{
                evenTail -> next = head;
                evenTail = evenTail -> next;
            }
        }else{
            if(oddHead == NULL){
                oddHead = head;
                oddTail = head;
            }else{
                oddTail -> next = head;
                oddTail = oddTail -> next;
            }
        }
        head = head -> next;
    }

    if(oddHead != NULL){
        oddTail -> next = evenHead;
        return oddHead;
    }else{
        return evenHead;
    }
}

int indexOfNRecursive(Node *head, int n) {    
    if(head == NULL){
        return -1;
    }

    if(head -> data == n){
        return 0;
    }

    int smallAns = indexOfNRecursive(head->next, n);
   
    if(smallAns != -1){
        return smallAns +1;
    }else{
        return -1;
    }
    
}