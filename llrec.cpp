#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    // Make sure head is not empty
    if (head == nullptr) {return;}
    // Make smaller and larger intially nullptr to avoid errors
    smaller = larger = nullptr;
    // Recurse until base case where list is single item
    if (head->next != nullptr) {llpivot(head->next, smaller, larger, pivot);}
    if (head->val <= pivot) {
        head->next = smaller;
        smaller = head;
    }
    else {
        head->next = larger;
        larger = head;
    }
    head = nullptr;
}
