#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::~PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe&) {
}

PmergeMe&	PmergeMe::operator=(const PmergeMe&) {
	return *this;
}

void PmergeMe::parseInput(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::stringstream ss(argv[i]);
        long number;

        if (!(ss >> number) || number <= 0 ||
            number > std::numeric_limits<int>::max())
            throw std::runtime_error("Error");

        vec.push_back(static_cast<int>(number));
        deq.push_back(static_cast<int>(number));
    }
}

void PmergeMe::fordJohnsonVector(std::vector<int>& v)
{
    if (v.size() <= 1)
        return ;
    std::vector<int> mainChain;
    std::vector<int> pending;
    
    for (size_t i = 0; i + 1 < v.size(); i += 2)
    {
                if (v[i] < v[i + 1])
        {
            pending.push_back(v[i]);
            mainChain.push_back(v[i + 1]);
        }
        else
        {
            pending.push_back(v[i + 1]);
            mainChain.push_back(v[i]);
        }
    }
    if (v.size() % 2 != 0)
        pending.push_back(v.back());

    fordJohnsonVector(mainChain);

    for (size_t i = 0; i < pending.size(); i++)
    {
        std::vector<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);
        mainChain.insert(pos, pending[i]);
    }
    v = mainChain;
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& d)
{
    if (d.size() <= 1)
        return;

    std::deque<int> mainChain;
    std::deque<int> pending;

    for (size_t i = 0; i + 1 < d.size(); i += 2)
    {
        if (d[i] < d[i + 1])
        {
            pending.push_back(d[i]);
            mainChain.push_back(d[i + 1]);
        }
        else
        {
            pending.push_back(d[i + 1]);
            mainChain.push_back(d[i]);
        }
    }

    if (d.size() % 2 != 0)
        pending.push_back(d.back());

    fordJohnsonDeque(mainChain);

    for (size_t i = 0; i < pending.size(); i++)
    {
        std::deque<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);
        mainChain.insert(pos, pending[i]);
    }

    d = mainChain;
}

void PmergeMe::run(int argc, char** argv)
{
    parseInput(argc, argv);

    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::vector<int> vCopy = vec;
    std::deque<int>  dCopy = deq;

    std::clock_t startV = std::clock();
    fordJohnsonVector(vCopy);
    std::clock_t endV = std::clock();

    std::clock_t startD = std::clock();
    fordJohnsonDeque(dCopy);
    std::clock_t endD = std::clock();

    std::cout << "After:  ";
    for (size_t i = 0; i < vCopy.size(); i++)
        std::cout << vCopy[i] << " ";
    std::cout << std::endl;

    double timeV = (double)(endV - startV) / CLOCKS_PER_SEC * 1000000;
    double timeD = (double)(endD - startD) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of "
              << vCopy.size()
              << " elements with std::vector : "
              << timeV << " us" << std::endl;

    std::cout << "Time to process a range of "
              << dCopy.size()
              << " elements with std::deque  : "
              << timeD << " us" << std::endl;
}






