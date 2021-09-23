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
#include "priority_queue.h"
using std::unordered_map;
using std::string;
using std::vector;

///// helpers /////

vector<string> past(unordered_map<string, string>& tree) {
     string puzzle_state{ "12345678-" };        // this is the end of our tree. now we traverse up the tree
     vector<string> solution_path;              // this is the path from the solution to the original state
     solution_path.push_back(puzzle_state);     // start with solution
     while (tree[puzzle_state] != "init") {     // while puzzle state is not back where we started
         solution_path.push_back(tree[puzzle_state]);
         puzzle_state = tree[puzzle_state];
         Puzzle puzzle(puzzle_state);
         // cout << puzzle << endl;
     }                                          // now we reverse to get path from puzzle to solution
     std::reverse(solution_path.begin(), solution_path.end());
     return solution_path;
 }

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
        int moves[5] = { 9, 9, 9, 9, 9 };           // begin with no moves (9 is like null in this case)
        puzzle->set_legal_moves(moves);             // set the legal moves for this puzzle
        int move_num{ 0 };
        for (int move : moves) {                    // for each move:
            if (move == 9) break;                   // if no more moves, move to next in queue
            /// add new puzzle to list. modify puzzle with last move
            Puzzle* child_puz;
            if (moves[++move_num] != 9)             // if this is the last move
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

std::vector<string> best_first_search(const string& seq, const string& heuristic) {
    return a_best(seq, heuristic, false);   // false = do best first search (no depth)
}

std::vector<string> a_star_search(const string& seq, const string& heuristic) {
    return a_best(seq, heuristic, true);
}

std::vector<string> a_best(const string& seq, const string& heuristic, bool depth_flag) {
    Puzzle solution("12345678-");
    priority_queue puzzles;

    Puzzle* problem = new Puzzle(seq);
    puzzles.insert(problem, heuristic);
    unordered_map<string, string> tree;
    tree[problem->as_string()] = "init";

    Puzzle* puzzle;
    if (*problem == solution) goto finish;
    while (true) {
        node* temp = puzzles.get_top();     // get next node in priority queue
        puzzle = temp->puz;                 // extract puzzle
        int depth{ 0 };
        if (depth_flag)                     // if a*
            depth = temp->depth + 1;        // get depth and increment
        delete temp;                        // deallocate memory
        string parent_str = puzzle->as_string();

        // get legal moves for this puzzle
        int moves[]{ 9, 9, 9, 9, 9 };
        puzzle->set_legal_moves(moves);
        int move_num{ 0 };
        for (int move : moves) {
            if (move == 9) break;
            Puzzle* child_puz;
            if (moves[++move_num] != 9)
                child_puz = new Puzzle(*puzzle);
            else
                child_puz = puzzle;
            child_puz->slide(move);
            string child_str = child_puz->as_string();

            // check for solution, update history
            if (tree.find(child_str) == tree.end()) {
                tree[child_str] = parent_str;
                if (*child_puz == solution) goto finish;
                puzzles.insert(child_puz, heuristic, depth);
            }
        }
    }
finish:
    delete problem;
    return past(tree);
}

