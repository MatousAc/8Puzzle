//  Name: Ac Hybl
//  Assignment number: 1
//  Assignment: 8-Puzzle-Search
//  File name: Puzzle.cpp
//  Date last modified: September 16, 2021
//  Honor statement: I have neither given nor received any unauthorized help on this assignment.

#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/// <summary>
/// An object representing an 8-Puzzle.
/// </summary>
class Puzzle
{
	///// friends /////

	/// <summary>
	/// stream insertion operator overload
	/// </summary>
	/// <param name="os"></param>
	/// <param name="rhs"></param>
	/// <returns></returns>
	friend std::ostream& operator<<(std::ostream& os, const Puzzle& rhs);
	/// <summary>
	/// stream extraction operator overload.
	/// takes a C-style string and puts it 
	/// into a Puzzle's grid
	/// </summary>
	/// <param name="is"></param>
	/// <param name="rhs"></param>
	/// <returns></returns>
	friend std::istream& operator>>(std::istream& is, Puzzle& rhs);
private:
	/// <summary>
	/// Represents an 8-puzzle as a multidimensional array. 
	/// 3 rows of arrays each pointing to an array 
	/// of n integers. 
	/// </summary>
	int grid[3][3];
	/// <summary>
	/// size of grid
	/// </summary>
	int n{ 3 };
	/// <summary>
	/// the current index of 
	/// the missing tile
	/// </summary>
	int hole_ind{};

	
public:
	///// constructors /////

	/// <summary>
	/// default constructor
	/// creates a solved 3x3 Puzzle. 
	/// note: 0 is being used for "-"
	/// </summary>
	Puzzle();
	/// <summary>
	/// creates an nxn Puzzle from an 
	/// arr of chars of length n*n
	/// </summary>
	/// <param name="s">(a c-style string)</param>
	Puzzle(const char *chars);
	/// <summary>
	/// creates an nxn Puzzle from an 
	/// arr of chars of length n*n
	/// </summary>
	/// <param name="str">(std:string)</param>
	Puzzle(const string& str);

	/// <summary>
	/// duplicates a puzzle
	/// </summary>
	/// <param name="puz"></param>
	Puzzle(const Puzzle& puz);
	~Puzzle();					// destructor

	///// member f(x)s /////

	/// <summary>
	/// sets puzzle to solution state
	/// </summary>
	/// <param name="rhs"></param>
	/// <returns></returns>
	void reset();

	///// operator overloads (as member f(x)s /////
	
	/// <summary>
	/// equality operator overload.
	/// returns true if all elements
	/// in two Puzzle's grid-arrays 
	/// are equal
	/// </summary>
	bool operator==(const Puzzle& rhs) const;

	///// helper methods ////

	/// <summary>
	/// returns a c-style string 
	/// representation of a Puzzle
	/// </summary>
	/// <returns></returns>
	// char* as_chars() const;

	/// <summary>
	/// returns a pointer to a std::string 
	/// representation of a Puzzle
	/// </summary>
	/// <returns></returns>
	string as_string() const;

	/// <summary>
	/// slides tile in specified index
	/// into the hole_ind
	/// </summary>
	/// <param name="ind1"></param>
	/// <param name="ind2"></param>
	void slide(int tile_ind);

	/// <summary>
	/// returns indices of all the tiles
	/// that can currently slide into
	/// the empty space (0). it encodes
	/// them into a 4-digit integer
	/// </summary>
	/// <returns></returns>
	void set_legal_moves(int moves[]);

	/// <summary>
	/// scrambles the puzzle by the
	/// specified number of moves
	/// </summary>
	/// <param name="moves"></param>
	void scramble(const int &moves);

	///// getter /////

	/// <summary>
	/// fetches hole_ind
	/// </summary>
	/// <returns></returns>
	int get_hole() const;
};

