#include "PmergeMe.hpp"

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(const PMergeMe& other) 
{
	return;
}


PMergeMe& PMergeMe::operator=(const PMergeMe& other) 
{
	return *this;
}

PMergeMe::~PMergeMe() {}

void PMergeMe::insertionSortVector(std::vector<int>& vec, int start, int end) 
{
    for (int i = start + 1; i <= end; i++) 
	{
        int key = vec[i];
        int j = i - 1;
        while (j >= start && vec[j] > key) 
		{
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

void PMergeMe::mergeVector(std::vector<int>& vec, int start, int mid, int end) 
{
    std::vector<int> temp(end - start + 1);
    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end) 
	{
        if (vec[i] <= vec[j]) 
		{
            temp[k++] = vec[i++];
        } 
		else 
		{
            temp[k++] = vec[j++];
        }
    }

    while (i <= mid) 
	{
        temp[k++] = vec[i++];
    }

    while (j <= end) 
	{
        temp[k++] = vec[j++];
    }

    for (i = 0; i < k; i++) 
	{
        vec[start + i] = temp[i];
    }
}

void PMergeMe::mergeInsertionSortVectorHelper(std::vector<int>& vec, int start, int end, int threshold) 
{
    if (start < end) 
	{
        if (end - start + 1 <= threshold) 
		{
            insertionSortVector(vec, start, end);
        } 
		else 
		{
            int mid = start + (end - start) / 2;
            mergeInsertionSortVectorHelper(vec, start, mid, threshold);
            mergeInsertionSortVectorHelper(vec, mid + 1, end, threshold);
            mergeVector(vec, start, mid, end);
        }
    }
}

void PMergeMe::mergeInsertionSortVector(std::vector<int>& vec) 
{
    int threshold = 10;
    mergeInsertionSortVectorHelper(vec, 0, vec.size() - 1, threshold);
}

void PMergeMe::insertionSortList(std::list<int>& lis, std::list<int>::iterator start, std::list<int>::iterator end) 
{
    for (std::list<int>::iterator it = start; it != end; it++) 
	{
        std::list<int>::iterator j = it;
        while (j != lis.begin() && *std::prev(j) > *j) 
		{
            std::iter_swap(j, std::prev(j));
            j--;
        }
    }
}

void PMergeMe::mergeList(std::list<int>& lis, int start, int mid, int end) 
{
    std::list<int> temp;
    std::list<int>::iterator it1 = lis.begin();
    std::advance(it1, start);
    std::list<int>::iterator it2 = lis.begin();
    std::advance(it2, mid + 1);
    std::list<int>::iterator endIt = lis.begin();
    std::advance(endIt, end + 1);

    while (it1 != lis.begin() && it2 != endIt) 
	{
        if (*it1 <= *it2) 
		{
            temp.push_back(*it1++);
        } 
		else 
		{
            temp.push_back(*it2++);
        }
    }

    while (it1 != lis.begin()) 
	{
        temp.push_back(*it1++);
    }

    while (it2 != endIt) 
	{
        temp.push_back(*it2++);
    }

    std::list<int>::iterator tempIt = temp.begin();
    std::advance(tempIt, start);
    for (std::list<int>::iterator it = lis.begin(); it != endIt; ++it) 
	{
        int tempValue = *it;
        *it = *tempIt;
        *tempIt++ = tempValue;
    }
}

void PMergeMe::mergeInsertionSortListHelper(std::list<int>& lis, std::list<int>::iterator start, std::list<int>::iterator end, int threshold) 
{
    if (std::distance(start, end) >= 1) 
	{
        if (std::distance(start, end) + 1 <= threshold) 
		{
            insertionSortList(lis, start, std::next(end));
        } 
		else
		{
            std::list<int>::iterator mid = start;
            std::advance(mid, std::distance(start, end) / 2);
            mergeInsertionSortListHelper(lis, start, mid, threshold);
            mergeInsertionSortListHelper(lis, mid, end, threshold);
            mergeList(lis, std::distance(lis.begin(), start), std::distance(lis.begin(), mid), std::distance(lis.begin(), end));
        }
    }
}

void PMergeMe::mergeInsertionSortList(std::list<int>& lis) 
{
    int threshold = 10;
    mergeInsertionSortListHelper(lis, lis.begin(), std::prev(lis.end()), threshold);
}
