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
	
public:
	///// constructors /////

	/// <summary>
	/// default constructor
	/// creates a solved 3x3 Puzzle. 
	/// note: 0 is being used for "-"
	/// </summary>
	Puzzle();					// empty
	/// <summary>
	/// creates an nxn Puzzle from an 
	/// arr of chars of length n*n
	/// </summary>
	/// <param name="s">(a c-style string)</param>
	Puzzle(const char *chars);	// char arr to int arr

	// Puzzle(const Puzzle& g);	// copy
	// Puzzle(Puzzle&& g);			// move
	~Puzzle();					// destructor

	///// helper methods ////
	/// <summary>
	/// returns the value of the nth 
	/// tile of the Puzzle
	/// </summary>
	/// <returns>int</returns>
	int get_nth(int &index) const;

	/// <summary>
	/// returns a string representation of
	/// a Puzzle
	/// </summary>
	/// <returns></returns>
	char* as_chars() const;

	///// operator overloads (as member f(x)s /////
	
	/// <summary>
	/// equality operator overload.
	/// returns true if all elements
	/// in two Puzzle's grid-arrays 
	/// are equal
	/// </summary>
	bool operator==(const Puzzle& rhs) const;
};

