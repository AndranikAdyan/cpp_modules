#ifndef MUTANT_STACK
# define MUTANT_STACK

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() : std::stack<T>() { }
    ~MutantStack() { }

    MutantStack(const MutantStack<T>& oth) : std::stack<T>(oth) { }

    MutantStack<T>& operator=(const MutantStack<T>& oth) {
        if (this != &oth)
            std::stack<T>::operator=(oth);
        return *this;
    }

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};

#endif
