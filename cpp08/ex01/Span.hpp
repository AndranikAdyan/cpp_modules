#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <iostream>
# include <list>

class Span {
    private:
        unsigned int max_size;
        std::vector<int> numbers;
        Span();


    public:

        Span(unsigned int size);
        ~Span();
		
		Span(const Span&);
		Span&	operator=(const Span&);

        void addNumber(int n);

        int shortestSpan();
        int longestSpan();
        
        template <typename Iter>
        void addRange(Iter begin, Iter end) {
            for (; begin != end; ++begin)
                addNumber(*begin);
        }
};

#endif