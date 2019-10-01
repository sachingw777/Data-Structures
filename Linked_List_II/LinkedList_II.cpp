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
    if(head2 -> data <= head2 -> data){
        finalHead = head1;
        finalTail = head1;
        head1 = head1 -> next;
    }else{
        finalHead = head2;
        finalTail = head2;
        head2 = head2 -> next;
    }

    while(head1 != NULL || head2 != NULL){
        if(head1 < head2){
            finalTail -> next = head1;
            head1 = head1 -> next;
        }else
        {
            finalTail -> next = head2;
            head2 = head2 -> next;
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

    if(head1 != NULL){
        finalTail -> next= head1;
    }
    if(head2 != NULL){
        finalTail -> next= head2;
    }

    return finalHead;
}