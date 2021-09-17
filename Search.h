#ifndef SEARCH_H_INCLUDED_
#define SEARCH_H_INCLUDED_
#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::string;

/// <summary>
/// takes a search tree and follows the
/// solution up the tree to the original
/// problem. returns a vector of this 
/// traversal in reversed order
/// </summary>
/// <param name="tree"></param>
/// <returns></returns>
std::vector<string> past(unordered_map<string, string>& tree);

/// <summary>
/// implements breadth first search
/// </summary>
/// <param name="problem"></param>
/// <returns></returns>
std::vector<string> breadth_first_search(const string& problem);
#endif