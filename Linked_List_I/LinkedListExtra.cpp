#include <iostream>
using namespace std;
#include "Node.cpp"

Node* midpoint_linkedlist(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    Node *slow = head, *fast = head->next;
    
    while(fast!=NULL && fast->next!= NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeTwoLLs(Node *head1, Node *head2) {
    Node *finalHead = NULL, *finalTail = NULL;
    if(head1 -> data <= head2 -> data){
        finalHead = head1;
        finalTail = head1;
        head1 = head1 -> next;
    }else
    {
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

Node* mergeTwoLLs_rec(Node *head1, Node *head2) {
    Node *newNode = NULL;
    
    if(head1 == NULL){
        return head2;
    }else if(head2 == NULL){
        return head1;
    }
    
    if(head1->data <= head2-> data){
        newNode = head1;
        newNode->next = mergeTwoLLs(head1->next, head2);
    }else{
        newNode = head2;
        newNode->next = mergeTwoLLs(head1, head2->next);
    }
    return newNode;

}

Node* mergeSort(Node *head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *mid = midpoint_linkedlist(head);
    Node *h2 = mid->next;
    mid->next = NULL;
    
    Node *first = mergeSort(head);
    Node *second = mergeSort(h2);
    
    return mergeTwoLLs(first, second);
    
}