#include <iostream>
using namespace std;
#include "Node.cpp"

int indexOfNRecursive(Node *head, int n) {
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node *smallAns = indexOfNRecursive(head->next, n);
   
    if(smallAns != -1){
        return smallAns +
    }

    if(head -> data == n){
        return 0;
    }else{
        return -1;
    }                                                                                                                                                                                                                                                                        
}

//need revamp. code not correct.
Node* arrange_LinkedList(Node* head)
{
    Node *EvenHead = NULL, *EvenTail = NULL, *OddHead = NULL, *OddTail = NULL;

    while(head != NULL){
        if(temp -> data % 2 == 0){
            if(EvenHead == NULL){
                EvenHead = temp;
                EvenTail = temp;
            }else{
                EvenTail -> next = temp;
            }
        }else{
            if(OddHead == NULL && OddTail == NULL){
                OddTail = temp;
                OddHead = temp;
            }else{
                OddTail -> next = temp;
            }
        }
        temp = temp -> next;
    }
    EvenTail -> next = NULL;
    OddTail -> next = NULL;

    if(OddHead == NULL){
        return EvenHead;
    }else if(EvenHead == NULL){
        return OddHead;
    }else{
        OddTail -> next = EvenHead;
        return OddHead;
    }
}

// 1 test case need fixing - get back later
Node* skipMdeleteN(Node  *head, int M, int N) {
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

//need fixing
Node* swap_Nodes(Node *head,int i,int j) {
    Node *iNode = NULL, *jNode = NULL, *previous = NULL;
    int count = 1;

    while(count < i){
        if(count == i - 1){
            previous = temp;
        }
        temp = temp -> next;
    }
    iNode = previous -> next;
    jNode = iNode -> next;

    previous -> next = jNode;
    iNode = jNode -> next;
    jNode -> next = iNode;  
}

//complete code
Node *kReverse(Node *head, int n){

}