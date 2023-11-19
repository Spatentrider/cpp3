#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>  // Per atoi
#include <cctype>   // Per isdigit
#include <ctime>    // Per clock
#include <deque>
#include <vector>
#include <list>

// Dichiarazioni delle funzioni di merge
void mergeVector(std::vector<int>& vec, int start, int mid, int end);
void mergeList(std::list<int>& lis, int start, int mid, int end);

// Dichiarazioni delle funzioni di ordinamento
void insertionSortVector(std::vector<int>& vec, int start, int end);
void mergeInsertionSortVectorHelper(std::vector<int>& vec, int start, int end, int threshold);
void mergeInsertionSortVector(std::vector<int>& vec);

void insertionSortList(std::list<int>& lis, std::list<int>::iterator start, std::list<int>::iterator end);
void mergeInsertionSortListHelper(std::list<int>& lis, std::list<int>::iterator start, std::list<int>::iterator end, int threshold);
void mergeInsertionSortList(std::list<int>& lis);

#endif

