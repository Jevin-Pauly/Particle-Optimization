//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "SearchList.h"
#include "Node.h"
#include "AList.h"

// --------------------------------
// -->    MODIFY This FILE    <----
// --------------------------------

void SearchList::MergeSort()
{
	// add your magic here
	this->pHead = MergeSortMain(this->pHead);
}

void SearchList::InsertionSort()
{
	// add your magic here	
    if (!pHead || !pHead->pNext)
    {
        return;
    }

    Node *curr = pHead;
    Node *newSort = nullptr;

    while (curr)
    {
        Node *next = curr->pNext;

        if (!newSort || curr->key <= newSort->key)
        {
            curr->pNext = newSort;

            if (newSort)
            {
                newSort->pPrev = curr;
            }
            newSort = curr;
            curr->pPrev = nullptr;
        }
        else
        {
            Node *temp = newSort;

            while ((temp->pNext) && curr->key > temp->pNext->key)
            {
                temp = temp->pNext;
            }
            curr->pNext = temp->pNext;

            if (temp->pNext)
            {
                temp->pNext->pPrev = curr;
            }
            temp->pNext = curr;
            curr->pPrev = temp;
        }

        curr = next;
    }
    pHead = newSort;
}

void SearchList::MergeComboSort(int CutoffLength)
{
	// add your magic here
    this->pHead = ComboSort(this->pHead, CutoffLength, this->NumNodes);
}

///////////////////////////////////////////////////////////////////

//Main Insertion sort call
//Node *SearchList::InsertionSortMain(Node *pH)
//{
//    if (!pH || !pH->pNext)
//    {
//        return pH;
//    }
//
//    Node *curr = pH;
//    Node *newSort = nullptr;
//
//    while (curr)
//    {
//        Node *next = curr->pNext;
//
//        if (!newSort || curr->key <= newSort->key)
//        {
//            curr->pNext = newSort;
//
//            if (newSort)
//            {
//                newSort->pPrev = curr;
//            }
//            newSort = curr;
//            curr->pPrev = nullptr;
//        }
//        else
//        {
//            Node *temp = newSort;
//
//            while ((temp->pNext) && curr->key > temp->pNext->key)
//            {
//                temp = temp->pNext;
//            }
//            curr->pNext = temp->pNext;
//
//            if (temp->pNext)
//            {
//                temp->pNext->pPrev = curr;
//            }
//            temp->pNext = curr;
//            curr->pPrev = temp;
//        }
//
//        curr = next;
//    }
//    return newSort;
//}


//Main Merge sort call
Node* SearchList::MergeSortMain(Node *head)
{
    if (!head || !head->pNext)
    {
        return head;
    }
        
    Node *second = Split(head);

    // Recur for left and right halves 
    head = MergeSortMain(head);
    second = MergeSortMain(second);

    // Merge the two sorted halves 
    return Merge(head, second);
}

//Splitting the given double link list in half
Node* SearchList::Split(Node *head)
{
    Node *fast = head, *slow = head;
    while ((fast->pNext) && (fast->pNext->pNext))
    {
        fast = fast->pNext->pNext;
        slow = slow->pNext;
    }
    Node *temp = slow->pNext;
    slow->pNext = NULL;
    return temp;
}

//Helper to merge the lists
Node *SearchList::Merge(Node *first, Node *second)
{
    // If first linked list is empty 
    if (!first)
        return second;

    // If second linked list is empty 
    if (!second)
        return first;

    // Pick the smaller value 
    if (first->key < second->key)
    {
        first->pNext = Merge(first->pNext, second);
        first->pNext->pPrev = first;
        first->pPrev = NULL;
        return first;
    }
    else
    {
        second->pNext = Merge(first, second->pNext);
        second->pNext->pPrev = second;
        second->pPrev = NULL;
        return second;
    }
}

//Helper to run merge and insertion in tandem
Node *SearchList::ComboSort(Node *head, int CutoffLength, int newNumNodes)
{
    if (!head || !head->pNext)
    {
        return head;
    }
    if (newNumNodes <= CutoffLength)
    {
        //head = InsertionSortMain(head); // Perform Insertion Sort on the current list

        Node *curr = head;
        Node *newSort = nullptr;

        while (curr)
        {
            Node *next = curr->pNext;

            if (!newSort || curr->key <= newSort->key)
            {
                curr->pNext = newSort;

                if (newSort)
                {
                    newSort->pPrev = curr;
                }
                newSort = curr;
                curr->pPrev = nullptr;
            }
            else
            {
                Node *temp = newSort;

                while ((temp->pNext) && curr->key > temp->pNext->key)
                {
                    temp = temp->pNext;
                }
                curr->pNext = temp->pNext;

                if (temp->pNext)
                {
                    temp->pNext->pPrev = curr;
                }
                temp->pNext = curr;
                curr->pPrev = temp;
            }

            curr = next;
        }
        head = newSort;
    }
    else
    {
        newNumNodes /= 2;
        //Node *second = Split(head);
        Node *fast = head, *slow = head;
        while ((fast->pNext) && (fast->pNext->pNext))
        {
            fast = fast->pNext->pNext;
            slow = slow->pNext;
        }
        Node *temp = slow->pNext;
        slow->pNext = NULL;
        Node *second = temp;

        // Recur for left and right halves 
        head = ComboSort(head, CutoffLength, newNumNodes);
        second = ComboSort(second, CutoffLength, this->NumNodes - newNumNodes);

        // Merge the two sorted halves 
        head = Merge(head, second);
    }

    return head;
}

// ---  End of File ---
