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
#include <algorithm>
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
/// <returns>a summary of results</returns>
string test_alg(string &alg, int scramble_depth = 200, 
                int trials = 30, string heuristic = "");
/// <summary>
/// allows a user to test each search
/// (with heuristics if applicable) on
/// demand for as long as they want
/// </summary>
void manual_test();
/// <summary>
/// outputs test results used for submission
/// of the assignment
/// </summary>
void auto_test();

int main()
{
    srand(time(0));     // we seed the random number generator only once    
    
    // tests each search and compares automatically
    auto_test();
    // test algs indefinitely
    manual_test();

    // if you want to call the functions yourself 
    // and see the output, here is how you would do it:
    /*
    vector<string> solution_path;
    solution_path = breadth_first_search("1564-7238");
    cout << solution_path << endl;
    solution_path = best_first_search("1564-7238", "tiles");
    cout << solution_path << endl;
    solution_path = best_first_search("1564-7238", "manhattan");
    cout << solution_path << endl;
    solution_path = a_star_search("1564-7238", "tiles");
    cout << solution_path << endl;
    solution_path = a_star_search("1564-7238", "manhattan");
    cout << solution_path << endl;
    */
    return 1;
}

void manual_test() {
    while (true) {
        string alg, heuristic{ "" }; // algorithm and heuristic to use
        int trials, scramble_depth;
        // what algorithm are we using?
        cout << "enter algorithm you want to test.\n" <<
            "breadth, best, or a*.\nother input terminates program\n";
        cin >> alg;
        if ((alg != "breadth") and (alg != "best") and (alg != "a*"))
            return;      // if not an algorithm, break;
        // gathering inputs
        if ((alg != "breadth")) {
            cout << "enter heuristic you wish to use (manhattan or tiles)\n";
            cin >> heuristic;
            if ((heuristic != "manhattan") and (heuristic != "tiles"))
                return;
        }
        cout << "enter desired random scramble moves (positive integer):\n";
        cin >> scramble_depth; cout << endl;
        cout << "enter number of trials (positive integer):\n";
        cin >> trials; cout << endl;
        cout << test_alg(alg, scramble_depth, trials, heuristic) << endl;
    }
}

void auto_test() {
    vector<string> algs{ "breadth", "best", "a*" }, heuristics{"manhattan", "tiles"};
    vector<string> summary;
    for (string alg: algs) {
        if ((alg != "breadth")) {
            for (string heuristic : heuristics) {
                summary.push_back(test_alg(alg, 200, 30, heuristic));
            }
        } else
            summary.push_back(test_alg(alg, 200, 30));
    }
    cout << summary << endl << endl;
}

string test_alg(string& alg, int scramble_depth, int trials, string heuristic) {
    string summary;
    clock_t start, end;         // for timing our algorithms
    float time_sum{ 0 };
    int depth_sum{ 0 };

    std::transform(alg.begin(), alg.end(), alg.begin(), ::toupper);
    cout << "\n____________" << alg << "_____________" << endl;
    cout << "Trial     Depth  Solve Time\n";
    // this is how to make a puzzle object
    Puzzle puzzle("12345678-");
    for (int trial{ 1 }; trial <= trials; trial++) {
        puzzle.scramble(scramble_depth);
        string puz_str = puzzle.as_string();
        vector<string> solution_path;
        // and how to pass the puzzle object to the algorithms
        start = clock();
        if (alg == "BREADTH")
            solution_path = breadth_first_search(puz_str);
        else if (alg == "BEST")
            solution_path = best_first_search(puz_str, heuristic);
        else
            solution_path = a_star_search(puz_str, heuristic);
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
    char buff[30];
    snprintf(buff, 30, 
        "Avg. %*.2f%*.3f\n",
        10, (float)depth_sum / trials, 
        12, time_sum / trials);
    summary = buff;
    summary = "Algorithm: " + alg + " Heuristic: " + heuristic + "\n" + summary;
    return summary;
}