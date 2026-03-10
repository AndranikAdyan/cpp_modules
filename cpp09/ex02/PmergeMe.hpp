#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iostream>
# include <sstream>
# include <ctime>
# include <limits>
# include <stdexcept>
# include <algorithm>

class PmergeMe {
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		
		void run(int argc, char** argv);
		
	private:
    std::vector<int> vec;
    std::deque<int>  deq;

    void parseInput(int argc, char** argv);

    void sortVector(std::vector<int>& v);
    void sortDeque(std::deque<int>& d);

    void fordJohnsonVector(std::vector<int>& v);
    void fordJohnsonDeque(std::deque<int>& d);
};

#endif