#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <deque>
#include <vector>
#include <list>

class PMergeMe 
{
	public:
    PMergeMe();
    PMergeMe(const PMergeMe& newPMergeMe);
    PMergeMe& operator=(const PMergeMe& newPMergeMe);
    ~PMergeMe();

    void mergeVector(std::vector<int>& vec, int start, int mid, int end);
    void mergeList(std::list<int>& lis, int start, int mid, int end);
    void insertionSortVector(std::vector<int>& vec, int start, int end);
    void mergeInsertionSortVectorHelper(std::vector<int>& vec, int start, int end, int threshold);
    void mergeInsertionSortVector(std::vector<int>& vec);
    void insertionSortList(std::list<int>& lis, std::list<int>::iterator start, std::list<int>::iterator end);
    void mergeInsertionSortListHelper(std::list<int>& lis, std::list<int>::iterator start, std::list<int>::iterator end, int threshold);
    void mergeInsertionSortList(std::list<int>& lis);
};

#endif

