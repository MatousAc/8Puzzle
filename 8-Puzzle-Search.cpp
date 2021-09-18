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
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::setw;
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
    
    /// testing our searches
    int trials, scramble_depth, depth_sum{ 0 };
    float time_sum{ 0 };
    cout << "Enter desired random scramble moves: ";
    cin >> scramble_depth; cout << endl;
    cout << "Enter number of trials: ";
    cin >> trials; cout << endl;

    cout << "Trial" << setw(10);
    cout << "Depth:" << setw(20);  // formatting
    cout << "Time to solve" << setw(20) << endl; 
    for (int trial{ 0 }; trial < trials; trial++) {
        cout << setw(0);
        Puzzle puzzle("12345678-");
        puzzle.scramble(scramble_depth);
        start = clock();
        vector<string> solution_path = breadth_first_search(puzzle.as_string());
        end = clock();
        float time = ((float)end - start) / CLOCKS_PER_SEC;
        int depth = solution_path.size();
        depth_sum += depth;         // keep track of totals
        time_sum += time;

        cout << trial << setw(10) <<// output stats
                depth << setw(20) <<
                time << setw(20) << endl;
    }
    cout << setw(0) <<
            "Avg." << setw(10) <<   // avg stats
            depth_sum / trials << setw(20) <<
            time_sum / trials << setw(20) << endl;
}
