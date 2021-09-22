//  Name: Ac Hybl
//  Assignment number: 1
//  Assignment: 8-Puzzle-Search
//  File name: 8-Puzzle-Search.cpp
//  Date last modified: September 22, 2021
//  Honor statement: I have neither given nor received any unauthorized help on this assignment.

#include "Puzzle.h"
#include <iostream>
#include "Search.h"
#include <chrono>
#include <stdlib.h>
using std::cout;
using std::cin;
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
/// for the 8-Puzzle problem. Tests are timed using the 
/// chrono library. iomanip is used for some formatted output.
/// </summary>
/// <returns>default 1 if no errors</returns>
void test_alg(string &alg);

int main()
{
    srand(time(0));     // we seed the random number generator only once    
    // Puzzle puzzle("12345678-");
    // puzzle.scramble(100);
    // cout << puzzle << endl;
    // cout << puzzle.misplaced_tiles() << endl;
    // cout << puzzle.manhattan_distance() << endl;


    /// testing our searches for as long as we want
    while (true)
    {
        string alg;     // algorithm to use
        // what algorithm are we using?
        cout << "enter algorithm you want to test.\n" <<
            "breadth, best, or a*.\nother input terminates program\n";
        cin >> alg;
        if ((alg != "breadth") and (alg != "best") and (alg != "a*"))
            break;      // if not an algorithm, break;
        test_alg(alg);
    }
}

    void test_alg(string &alg) {
        clock_t start, end;         // for timing our algorithms
        int trials, scramble_depth, depth_sum{ 0 };
        float time_sum{ 0 };

        // gathering inputs
        string heuristic{""};       // what heuristic?
        if ((alg != "breadth")) {
            cout << "enter heuristic you wish to use (manhattan or tiles)\n";
            cin >> heuristic;
        }
        cout << "enter desired random scramble moves (positive integer):\n";
        cin >> scramble_depth; cout << endl;
        cout << "enter number of trials (positive integer):\n";
        cin >> trials; cout << endl;

        cout << "Trial     Depth  Solve Time\n";
        Puzzle puzzle("12345678-");
        for (int trial{ 1 }; trial <= trials; trial++) {
            puzzle.scramble(scramble_depth);
            start = clock();
            vector<string> solution_path = breadth_first_search(puzzle.as_string());
            end = clock();
            float time = ((float)end - start) / CLOCKS_PER_SEC;
            // depth = size - 1 because initial node is of depth 0
            int depth = solution_path.size() - 1;
            depth_sum += depth;     // keep track of totals
            time_sum += time;

            puzzle.reset();
            printf("%*d", 5, trial);
            printf("%*d", 10, depth);
            printf("%*.3f\n", 12, time);
        }
        cout << "~~~~~~~~~ Average ~~~~~~~~~\n";
        printf("%*d%*.2f%*.3f\n", 
            5, trials, 
            10, (float)depth_sum / trials, 
            12, time_sum / trials);
    }