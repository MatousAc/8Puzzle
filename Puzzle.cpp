//  Name: Ac Hybl
//  Assignment number: 1
//  Assignment: 8-Puzzle-Search
//  File name: Puzzle.cpp
//  Date last modified: September 16, 2021
//  Honor statement: I have neither given nor received any unauthorized help on this assignment.

#include "Puzzle.h"
#include <iostream>
#include <math.h>
using std::cout;
using std::cin;
using std::endl;
using std::atoi;
using std::string;

///// constructors /////

/// <summary>
/// default constructor
/// creates a solved 3x3 Puzzle 
/// note: 0 is being used for "-"
/// </summary>
/// thanks to Deepak Ingole for explaining how to do this on
/// https://stackoverflow.com/questions/18273370/the-correct-way-to-initialize-a-dynamic-pointer-to-a-multidimensional-array/18273553
Puzzle::Puzzle()
    : grid{ nullptr }, n{ 0 } { // default initializations
    cout << "default 3x3 Puzzle constructor called" << endl;
    grid = new int* [3];        // point to 3 pointers
    grid[0] = new int[1, 2, 3]; // asgn ptr0 to this spec. int arr
    grid[1] = new int[4, 4, 6];
    grid[2] = new int[7, 8, 0];
    n = 3;                      // record size for simplicity
}

/// <summary>
/// creates an nxn Puzzle from a 
/// string of length n*n
/// </summary>
/// <param name="s">(a string pointer)</param>
Puzzle::Puzzle(const char* chars)
    {
    cout << "nxn Puzzle constructor called" << endl;

    if (chars == nullptr) {         // check for empty string
        throw std::invalid_argument("received nullptr");
    }

    // truncates on purpose, sets size of puzzle. leaves off any extra characters
    n = sqrt(strlen((chars)));
    cout << "puzzle is of size " << n << endl;
    cout << "Char[] Testing:\n" << endl <<
            "chars:   " << chars << endl <<
            "*chars:   " << *chars << endl <<
            "&chars:   " << &chars << endl;
    grid = new int* [n];
    for (int row = 0; row < n; row++)
    {
        grid[row] = new int[n];
        for (int col = 0; col < n; col++)
        {                       
            // here we get the right part of the string and convert it to an integer
            // string* tile_val_chr = s + (row * n) + col;
            // if (tile_val_chr == "-")
            //     tile_val_chr = "0";
            // grid[row][col] = std::atoi(tile_val_chr);
        }
    }
}


/// copy consructor
// Puzzle::Puzzle(const Puzzle& g)
//     : grid{ nullptr } {
//     grid = new int[std::strlen(g.grid) + 1];
//     std::strcpy(grid, g.grid);
// }

/// move constructor
// Puzzle::Puzzle(Puzzle&& g)
//     : grid{ g.grid } {
//     g.grid = nullptr;
//     std::cout << "Move constructor used" << std::endl;
// }

/// destructor
/// deallocates all memory used for the puzzle representation
Puzzle::~Puzzle() {
    for (int row = 0; row < n; row++)   // for all rows
    {
        delete[] grid[row];             // deallocate their memory
    }
    delete[] grid;                      // deallocate grid's memory
}
