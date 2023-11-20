#include "PMergeMe.hpp"

int main(int argc, char** argv) 
{
    if (argc < 2) 
	{
        std::cerr << "Error: No input sequence provided" << std::endl;
        return 1;
    }

    std::deque<int> inputSequence;
    for (int i = 1; i < argc; i++) 
	{
        for (size_t j = 0; argv[i][j]; j++) 
		{
            if (!isdigit(argv[i][j])) 
			{
                std::cerr << "Error: Only positive numbers allowed => " << argv[i] << std::endl;
                return 1;
            }
        }
        int num = atoi(argv[i]);
        if (num > 0) 
		{
            inputSequence.push_back(num);
        }
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < inputSequence.size(); i++) 
	{
        std::cout << inputSequence[i] << " ";
    }
    std::cout << std::endl;

    PMergeMe merger;

    std::vector<int> vec(inputSequence.begin(), inputSequence.end());
    clock_t startTime1 = clock();
    merger.mergeInsertionSortVector(vec);
    clock_t endTime1 = clock();

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++) 
	{
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    double time1 = double(endTime1 - startTime1) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << inputSequence.size() << " elements with std::vector: " << time1 << " seconds" << std::endl;

    std::list<int> lis(inputSequence.begin(), inputSequence.end());
    clock_t startTime2 = clock();
    merger.mergeInsertionSortList(lis);
    clock_t endTime2 = clock();

    double time2 = double(endTime2 - startTime2) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << inputSequence.size() << " elements with std::list: " << time2 << " seconds" << std::endl;

    return 0;
}
