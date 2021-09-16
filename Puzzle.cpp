//  Name: Ac Hybl
//  Assignment number: 1
//  Assignment: 8-Puzzle-Search
//  File name: Puzzle.cpp
//  Date last modified: September 16, 2021
//  Honor statement: I have neither given nor received any unauthorized help on this assignment.

#include "Puzzle.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

///// constructors /////

Puzzle::Puzzle()
    : grid{ 1, 2, 3,    // default initializations
            4, 5, 6,
            7, 8, 0 } {}

Puzzle::Puzzle(const char *chars) // char arr to int arr
    {
    if (!chars) {         // check for empty string
        throw std::invalid_argument("received nullptr");
    }

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {                       
            // here we get the right part of the string and convert it to an integer
            char tile_val_chr = chars[(row * n) + col];
            if (tile_val_chr == '-')
                tile_val_chr = '0';
            grid[row][col] = (int)tile_val_chr % 48;
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
Puzzle::~Puzzle() {
}


///// helper methods /////

int Puzzle::get_nth(int& index) const {
    // cout << puz.grid[index / puz.n][index % puz.n] << endl;
    return (grid[index / n][index % n]);
}

char* Puzzle::as_chars() const {
    char* chars = new char[n * n];
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            // taking every tile value and putting it back into a character array
            int val = grid[row][col];
            chars[(row * n) + col] = val != 0 ? (char)(val + 48) : '-';
        }
    }
    chars[n * n] = '\0';
    return chars;
}

///// operator overloads /////

std::ostream& operator<<(std::ostream& os, const Puzzle& rhs) { // stream insertion operator
    for (int grid_indx{ 0 }; grid_indx < (rhs.n * rhs.n); grid_indx++) {
        cout << rhs.get_nth(grid_indx) << " ";
        if ((grid_indx + 1) % rhs.n == 0)
            cout << endl;
    }
    os << "";
    return os;
}

bool Puzzle::operator==(const Puzzle &rhs) const { // equality overload
    // return false if they are of different sizes
    if (n != rhs.n) return false;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {   // returns false if an element doesn't match
            if (grid[row][col] != rhs.grid[row][col]) 
                return false;
        }
    }
    return true;
}

