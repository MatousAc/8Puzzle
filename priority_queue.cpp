// This code is heavily adapted from technical-recipes.com
// It barely resembles the original, but I still should give
// credit for the idea.
// https://www.tutorialspoint.com/cplusplus-program-to-implement-priority-queue

#include "priority_queue.h"
priority_queue::priority_queue() {//constructor
    head = NULL;            // head starts as nothing
}
void priority_queue::insert(Puzzle* puz, int priority) {
    node* t, * q;           // temp node ptrs
    t = new node;
    t->priority = priority; // give it a priority
    t->puz = puz;           // associate it with puzzleptr
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

Puzzle* priority_queue::get_top() {
    Puzzle* puz;
    node* del;
    if (head == NULL) {
        cout << "Queue Underflow\n";
        cout << this->size();
    }
    else {
        puz = head->puz;    // get first puzzle
        del = head;
        head = head->next;  // move head next node
        delete del;         // deallocate memory
        return puz;
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