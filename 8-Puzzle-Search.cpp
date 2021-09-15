//  Name: Ac Hybl
//  Assignment number: 1
//  Assignment: 8-Puzzle-Search
//  File name: 8-Puzzle-Search.cpp
//  Date last modified: September 16, 2021
//  Honor statement: I have neither given nor received any unauthorized help on this assignment.

#include "Puzzle.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/// <summary>
/// This functions mainly tests different search methods
/// for the 8-Puzzle problem. Tests are timed using ??????
/// </summary>
/// <returns>default 1 if no errors</returns>
int main()
{
    cout << "Starting Main" << endl;
    Puzzle puz1();
    puz1.print();
    Puzzle puz2("1564-7238");
}
