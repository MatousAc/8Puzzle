//  Name: Ac Hybl
//  Assignment number: 1
//  Assignment: 8-Puzzle-Search
//  File name: 8-Puzzle-Search.cpp
//  Date last modified: September 16, 2021
//  Honor statement: I have neither given nor received any unauthorized help on this assignment.

#include "Puzzle.h"
#include <iostream>
#include "Search.h"
#include <chrono>
using std::cout;
using std::endl;
using std::vector;

/// the below code is directly taken from the 
/// "vectorutils" homework template
/// written by Dr. Halterman for CPTR-318
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << '{'; os << '\n';
    if (!vec.empty()) {
        auto iter = vec.begin();
        auto end = vec.end();
        os << *iter++;
        while (iter != end)
            os << "\n" << *iter++;
    }
    os << '\n'; os << '}';
    return os;
}

/// <summary>
/// This functions mainly tests different search methods
/// for the 8-Puzzle problem. Tests are timed using ??????
/// </summary>
/// <returns>default 1 if no errors</returns>
int main()
{
    clock_t start, end;             // for timing our algorithms
    // scramble
    Puzzle puzzle("12345678-");
    puzzle.scramble(20);
    cout << puzzle << endl;
    start = clock();
    vector<string> solution_path = breadth_first_search(puzzle.as_string());
    end = clock();
    cout << solution_path << endl;
    cout << "Time to solve: " << ((float)end - start) / CLOCKS_PER_SEC;
    // breadth_first_search("1564-7238");

     //greedy(solution.as_chars());
}
