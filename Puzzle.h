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
private:
	/// <summary>
	/// Represents an n-puzzle as a multidimensional array. 
	/// n rows of pointers each pointing to an array 
	/// of n integers. 
	/// </summary>
	int** grid;
	/// <summary>
	/// size of grid
	/// </summary>
	int n;
	
public:
	/// all constructors are defined below
	Puzzle();					// empty
	Puzzle(const char* chars);	// char arr to int arr
	// Puzzle(const Puzzle& g);	// copy
	// Puzzle(Puzzle&& g);			// move
	~Puzzle();					// destructor

	/// helper methods
	void print() const;
};

