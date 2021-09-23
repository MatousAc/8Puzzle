#pragma once
#include "Puzzle.h"
struct node { // node declaration
    Puzzle* puz;
    int priority;
    struct node* next;
};

/// <summary>
/// this class implements a priority queue. 
/// pop returns the node with lowest priority
/// </summary>
class priority_queue {
private:
    //Declare a front pointer head.
    node* head;
public:
    priority_queue();   //constructor
    void insert(Puzzle* puz, int priority);
    Puzzle* get_top();
    int size();
    void show();
};
