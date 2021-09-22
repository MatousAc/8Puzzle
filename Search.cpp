//  Name: Ac Hybl
//  Assignment number: 1
//  Assignment: 8-Puzzle-Search
//  File name: Search.cpp
//  Date last modified: September 22, 2021
//  Honor statement: I have neither given nor received any unauthorized help on this assignment.

/// this file has search functions in it
#include "Search.h"
#include "Puzzle.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using std::unordered_map;
using std::string;
using std::vector;

///// All My Search Algorithms /////

std::vector<string> breadth_first_search(const string& seq) {
    Puzzle solution("12345678-");                   // define the solved (default) state
    vector<Puzzle*> puzzles{};                      // using a vector as a FIFO queue
    Puzzle* problem = new Puzzle(seq);              // generate a puzzle from string
    puzzles.push_back(problem);                     // add problem to the queue
    unordered_map<string, string> tree;             // keep track puzzle sequence w/ hashmap
    tree[problem->as_string()] = "init";            // mark initial state

    Puzzle* puzzle;                                 // initialize current puzzle ptr
    int queue_index{ 0 };                           // to keep track of where we are in the queue
    if (*problem == solution) goto finish;          // check once for init. state being solved
    while (true) {                                  // do till we have a solution
        puzzle = puzzles[queue_index++];            // get next puzzle
        string parent_str = puzzle->as_string();    // to insert into the tree

        // get legal moves for this puzzle
        // int num_moves{ 0 };
        int moves[5]{ 9 };                          // begin with no moves (9 is like null in this case)
        puzzle->set_legal_moves(moves);             // set the legal moves for this puzzle
        for (int move : moves) {                    // for each move:
            if (move == 9) break;                   // if no more moves, move to next in queue
            /// add new puzzle to list. modify puzzle with last move
            Puzzle* child_puz;
            if (moves[move + 1] != 9)
                child_puz = new Puzzle(*puzzle);    // make copy
            else
                child_puz = puzzle;                 // grab pointer
            child_puz->slide(move);                 // make the move, get char repr
            string child_str = child_puz->as_string();

            // if the child isn't in the table yet, check for solution,
            // return if found, and otherwise add child to the tree and queue
            if (tree.find(child_str) == tree.end()) {
                tree[child_str] = parent_str;
                if (*child_puz == solution) goto finish;
                puzzles.push_back(child_puz);       // add to queue
            }
        }
    }
finish:
    delete problem;                                 // dereference the puzzle
    return past(tree);                              // return path to current state (solution)
}


///// helpers /////

vector<string> past(unordered_map<string, string>& tree) {
     string puzzle_state{ "12345678-" };        // this is the end of our tree. now we traverse up the tree
     vector<string> solution_path;              // this is the path from the solution to the original state
     solution_path.push_back(puzzle_state);     // start with solution
     while (tree[puzzle_state] != "init") {     // while puzzle state is not back where we started
         solution_path.push_back(tree[puzzle_state]);
         puzzle_state = tree[puzzle_state];
     }                                          // now we reverse to get path from puzzle to solution
     std::reverse(solution_path.begin(), solution_path.end());
     return solution_path;
 }
