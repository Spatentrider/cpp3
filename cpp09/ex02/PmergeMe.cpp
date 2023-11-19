#include "PmergeMe.hpp"
// Funzione di ordinamento insertion sort per un vettore
void insertionSortVector(std::vector<int>& vec, int start, int end) {
    for (int i = start + 1; i <= end; i++) {
        int key = vec[i];
        int j = i - 1;
        while (j >= start && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

// Implementazione della funzione mergeVector
void mergeVector(std::vector<int>& vec, int start, int mid, int end) {
    std::vector<int> temp(end - start + 1);
    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end) {
        if (vec[i] <= vec[j]) {
            temp[k++] = vec[i++];
        } else {
            temp[k++] = vec[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = vec[i++];
    }

    while (j <= end) {
        temp[k++] = vec[j++];
    }

    for (i = 0; i < k; i++) {
        vec[start + i] = temp[i];
    }
}

// Funzione di merge-insertion sort per vettori
void mergeInsertionSortVectorHelper(std::vector<int>& vec, int start, int end, int threshold) {
    if (start < end) {
        if (end - start + 1 <= threshold) {
            // Passa all'insertion sort per vettori più piccoli
            insertionSortVector(vec, start, end);
        } else {
            int mid = start + (end - start) / 2;
            // Ricorsivamente ordina le due metà del vettore
            mergeInsertionSortVectorHelper(vec, start, mid, threshold);
            mergeInsertionSortVectorHelper(vec, mid + 1, end, threshold);
            // Esegue il merge delle due metà ordinate
            mergeVector(vec, start, mid, end);
        }
    }
}

// Funzione principale di merge-insertion sort per vettori
void mergeInsertionSortVector(std::vector<int>& vec) {
    int threshold = 10; // Soglia per passare all'insertion sort
    mergeInsertionSortVectorHelper(vec, 0, vec.size() - 1, threshold);
}

// Funzione di ordinamento insertion sort per una lista
void insertionSortList(std::list<int>& lis, std::list<int>::iterator start, std::list<int>::iterator end) {
    for (std::list<int>::iterator it = start; it != end; it++) {
        std::list<int>::iterator j = it;
        while (j != lis.begin() && *std::prev(j) > *j) {
            std::iter_swap(j, std::prev(j));
            j--;
        }
    }
}

void mergeList(std::list<int>& lis, int start, int mid, int end) {
    std::list<int> temp;
    std::list<int>::iterator it1 = lis.begin();
    std::advance(it1, start);
    std::list<int>::iterator it2 = lis.begin();
    std::advance(it2, mid + 1);
    std::list<int>::iterator endIt = lis.begin();
    std::advance(endIt, end + 1);

    while (it1 != lis.begin() && it2 != endIt) {
        if (*it1 <= *it2) {
            temp.push_back(*it1++);
        } else {
            temp.push_back(*it2++);
        }
    }

    while (it1 != lis.begin()) {
        temp.push_back(*it1++);
    }

    while (it2 != endIt) {
        temp.push_back(*it2++);
    }

    std::list<int>::iterator tempIt = temp.begin();
    std::advance(tempIt, start);
    for (std::list<int>::iterator it = lis.begin(); it != endIt; ++it) {
        int tempValue = *it;
        *it = *tempIt;
        *tempIt++ = tempValue;
    }
}


// Funzione di merge-insertion sort per liste
void mergeInsertionSortListHelper(std::list<int>& lis, std::list<int>::iterator start, std::list<int>::iterator end, int threshold) {
    if (std::distance(start, end) >= 1) {
        if (std::distance(start, end) + 1 <= threshold) {
            // Passa all'insertion sort per liste più piccole
            insertionSortList(lis, start, std::next(end));
        } else {
            std::list<int>::iterator mid = start;
            std::advance(mid, std::distance(start, end) / 2);
            // Ricorsivamente ordina le due metà della lista
            mergeInsertionSortListHelper(lis, start, mid, threshold);
            mergeInsertionSortListHelper(lis, mid, end, threshold);
            // Esegue il merge delle due metà ordinate
            mergeList(lis, std::distance(lis.begin(), start), std::distance(lis.begin(), mid), std::distance(lis.begin(), end));
        }
    }
}

// Funzione principale di merge-insertion sort per liste
void mergeInsertionSortList(std::list<int>& lis) {
    int threshold = 10; // Soglia per passare all'insertion sort
    mergeInsertionSortListHelper(lis, lis.begin(), std::prev(lis.end()), threshold);
}
