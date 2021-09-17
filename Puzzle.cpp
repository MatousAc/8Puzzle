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
            7, 8, 0 },
    hole_ind{8} {}

Puzzle::Puzzle(const char *chars) // char arr to int arr
    : hole_ind {0} {
    if (!chars)           // check for empty string
        throw std::invalid_argument("received nullptr");

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {                       
            // here we get the right part of the string and convert it to an integer
            char tile_val_chr = chars[(row * n) + col];
            if (tile_val_chr == '-') {
                tile_val_chr = '0';
                hole_ind = (row * n) + col;
            }
            grid[row][col] = (int)tile_val_chr % 48;
        }
    }
}

Puzzle::Puzzle(const string& str)   // std:string to int arr
    : hole_ind{ 0 } {
    if (str == "")                  // check for empty string
        throw std::invalid_argument("received empty string");

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            // here we get the right part of the string and convert it to an integer
            char tile_val_chr = str[(row * n) + col];
            if (tile_val_chr == '-') {
                tile_val_chr = '0';
                hole_ind = (row * n) + col;
            }
            grid[row][col] = (int)tile_val_chr % 48;
        }
    }
}


Puzzle::Puzzle(const Puzzle& puz) // copy constructor
    : hole_ind{ puz.hole_ind },
    n{ puz.n } {
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            // here we copy each element
            grid[row][col] = puz.grid[row][col];
        }
    }
}

/// destructor
Puzzle::~Puzzle() {
}


///// operator overloads /////

std::ostream& operator<<(std::ostream& os, const Puzzle& rhs) { // stream insertion operator
    for (int grid_ind{ 0 }; grid_ind < (rhs.n * rhs.n); grid_ind++) {
        cout << (rhs.grid[grid_ind / rhs.n][grid_ind % rhs.n]) << " "; // .get_nth(grid_ind)
        if ((grid_ind + 1) % rhs.n == 0)
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

///// helper methods /////

int Puzzle::get_nth(int& index) const {
    return (grid[index / n][index % n]);
}

void Puzzle::slide(int tile_ind) { // swaps elements @ these indices
    grid[hole_ind / n][hole_ind % n] = (*grid)[tile_ind];
    grid[tile_ind / n][tile_ind % n] = 0;
    hole_ind = tile_ind;
}

char* Puzzle::as_chars() const {
    char* chars = new char[10];  // a place for each tile and one for the end
    chars[9] = '\0';
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            // taking every tile value and putting it back into a character array
            int val = grid[row][col];
            chars[(row * n) + col] = val != 0 ? (char)(val + 48) : '-';
        }
    }
    return chars;
}

string Puzzle::as_string() const { // Puzzle to string convert
    string str{this->as_chars()};
    return str;
//    for (int row = 0; row < n; row++)
//    {
//        for (int col = 0; col < n; col++)
//        {
//            // taking every tile value and putting it back into a character array
//            int val = grid[row][col];
//            chars[(row * n) + col] = val != 0 ? (char)(val + 48) : '-';
//        }
//    }
}

void Puzzle::set_legal_moves(int moves[]) {
    int num_moves{ 0 };
    if (hole_ind > 2)       // if not on top, allow move up
        moves[num_moves++] = hole_ind - 3;
    if (hole_ind < 6)       // if not on bottom, allow move down
        moves[num_moves++] = hole_ind + 3;
    if (hole_ind % n != 0)  // if not on right col, allow move right
        moves[num_moves++] = hole_ind - 1;
    if (hole_ind % n != 2) // if not on left col, allow move left
        moves[num_moves++] = hole_ind + 1;
}

void Puzzle::scramble(const int &moves) { // scrambles a puzzle
    srand(time(0));
    for (int move_num{ 0 }; move_num < moves; move_num++) {
        // get legal options for this puzzle
        int num_options{ 0 };
        int options[]{ 9, 9, 9, 9 };                  // begin with no options
        if (hole_ind > 2)       // if not on top, allow move up
            options[num_options++] = hole_ind - 3;
        if (hole_ind < 6)       // if not on bottom, allow move down
            options[num_options++] = hole_ind + 3;
        if (hole_ind % 3 != 0)  // if not on right col, allow move right
            options[num_options++] = hole_ind - 1;
        if (hole_ind % 3 != 2) // if not on left col, allow move left
            options[num_options++] = hole_ind + 1; 
        
        int move_to = options[rand() % 4];
        if (move_to == 9) move_to = options[rand() % 3];
        if (move_to == 9) move_to = options[rand() % 2];
        this->slide(move_to);
    }
}

///// getter /////

int Puzzle::get_hole() const { // hole_ind getter
    return hole_ind;
}