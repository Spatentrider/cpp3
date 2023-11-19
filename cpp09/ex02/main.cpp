#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	// Check if an input sequence is provided
	if (argc < 2) {
		std::cerr << "Error: No input sequence provided" << std::endl;
		return 1;
	}

	std::deque<int> inputSequenze;
	// Iterate through command-line arguments
	for (int i = 1; i < argc; i++) {
		// Check if the argument contains only positive numbers
		for (size_t j = 0; argv[i][j]; j++) {
			if (!isdigit(argv[i][j])) {
				std::cerr << "Error: Only positive number allowed => " << argv[i] << std::endl;
				return 1;
			}
		}
		// Convert the argument to an integer
		int num = atoi(argv[i]);

		// Add the positive number to the input sequence
		if (num > 0) {
			inputSequenze.push_back(num);
		}
	}

	// Print the input sequence before sorting
	std::cout << "Before: ";
	for (size_t i = 0; i < inputSequenze.size(); i++) {
		std::cout << inputSequenze[i] << " ";
	}
	std::cout << std::endl;

	// Sort using the first container (vector)
	std::vector<int> vec(inputSequenze.begin(), inputSequenze.end());
	clock_t startTime1 = clock();
	mergeInsertionSortVector(vec);
	// quickSortVector(vec, 0, vec.size() - 1);
	clock_t endTime1 = clock();

	std::cout << "After: ";
	// Print the sorted sequence using the first container (vector)
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	// Print the time taken to process the range using std::vector
	double time1 = double(endTime1 - startTime1) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << inputSequenze.size() << " element with std::vector : " << time1 << " us" << std::endl;

	// Sort using the second container (list)
	std::list<int> lis(inputSequenze.begin(), inputSequenze.end());
	clock_t startTime2 = clock();
	mergeInsertionSortList(lis);
	// quickSortList(lis, 0, lis.size() - 1);
	clock_t endTime2 = clock();

	// Print the time taken to process the range using std::list
	double time2 = double(endTime2 - startTime2) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << inputSequenze.size() << " element with std::list   : " << time2 << " us" << std::endl;

	return 0;
}