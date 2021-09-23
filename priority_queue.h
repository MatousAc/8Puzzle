//  Name: Ac Hybl
//  Assignment number: 1
//  Assignment: 8-Puzzle-Search
//  File name: priority_queue.h
//  Date last modified: September 22, 2021
//  Honor statement: I have neither given nor received any unauthorized help on this assignment.

// This code is heavily adapted from technical-recipes.com
// It barely resembles the original, but I still should give
// some credit for the idea of structuring a pq like this.
// https://www.tutorialspoint.com/cplusplus-program-to-implement-priority-queue
#pragma once
#include "Puzzle.h"
struct node { // node declaration
    Puzzle* puz;
    int priority;
    int depth;
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
    void insert(Puzzle* puz, string heuristic, int depth = 0);
    node* get_top();
    int size();
    void show();
};
