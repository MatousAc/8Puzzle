//  Name: Ac Hybl
//  Assignment number: 1
//  Assignment: 8-Puzzle-Search
//  File name: priority_queue.cpp
//  Date last modified: September 22, 2021
//  Honor statement: I have neither given nor received any unauthorized help on this assignment.

// This code is heavily adapted from technical-recipes.com
// It barely resembles the original, but I still should give
// some credit for the idea of structuring a pq like this.
// https://www.tutorialspoint.com/cplusplus-program-to-implement-priority-queue

#include "priority_queue.h"
priority_queue::priority_queue() {//constructor
    head = NULL;            // head starts as nothing
}
void priority_queue::insert(Puzzle* puz, string heuristic, int depth = 0) {
    int priority{ 0 };
    if (heuristic == "tiles")// since depth is always 0 in best first, we can always add it
        priority = puz->misplaced_tiles() + depth;
    else if (heuristic == "manhattan")
        priority = puz->manhattan_distance() + depth;
    node* t, * q;           // temp node ptrs           // by default depth = 0
    t = new node;
    t->priority = priority; // give it a priority
    t->puz = puz;           // associate it with puzzleptr
    t->depth = depth;       // give it it's depth
    if (head == NULL || priority < head->priority) {
        t->next = head;     // put t out front if it has lowest priority
        head = t;
    }
    else {
        q = head;           // start @ front
        while (q->next != NULL && q->next->priority <= priority)
            q = q->next;    // move to last node with equal priority
        t->next = q->next;  // put t after q
        q->next = t;
    }
}

node* priority_queue::get_top() {
    Puzzle* puz;
    node* temp;
    if (head == NULL) {
        cout << "Queue Underflow\n";
        cout << this->size();
    }
    else {
        puz = head->puz;    // get first puzzle
        temp = head;        // we have to deallocate this memory elsewhere
        head = head->next;  // move head next node
        return temp;
    }
}

int priority_queue::size() {
    node* ptr;
    ptr = head;
    int size{ 0 };
    while (ptr != NULL) {
        size++;
        ptr = ptr->next;
    }
    return size;
}

void priority_queue::show() { //print queue
    node *ptr;
    ptr = head;
    if (head == NULL)
    cout<<"Queue is empty\n";
    else {
    cout<<"Queue is :\n";
    cout<<"Priority Item\n";
    while(ptr != NULL) {
        cout<<*(ptr->puz)<<" "<<ptr->priority<<endl<<endl;
        ptr = ptr->next;
    }
    }
}