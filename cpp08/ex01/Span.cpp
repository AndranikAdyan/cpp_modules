#include "Span.hpp"

Span::Span(): max_size(0) {
}

Span::Span(unsigned int size): max_size(size) {
}

Span::~Span() {
}

Span::Span(const Span& other)
	: max_size(other.max_size), numbers(other.numbers) {
}

Span&	Span::operator=(const Span& other) {
	if (this != &other) {
		numbers = other.numbers;
		max_size = other.max_size;
	}
	return *this;
}

void Span::addNumber(int n) {
    if (numbers.size() >= max_size)
        throw std::runtime_error("Span is full");
    numbers.push_back(n);
}

int Span::shortestSpan() {
    if (numbers.size() <= 1)
        throw std::runtime_error("Not enough numbers");
    std::vector<int> temp(numbers);
    std::sort(temp.begin(), temp.end());
    
    int diff;
    int minSpan = temp[1] - temp[0];
    for (unsigned long int i = 0; i < temp.size() - 1; ++i) {
        diff = temp[i + 1] - temp[i];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan() {
    if (numbers.size() <= 1)
        throw std::runtime_error("Not enough numbers");
    
    int minValue = *std::min_element(numbers.begin(), numbers.end());
    int maxValue = *std::max_element(numbers.begin(), numbers.end());
    
    return maxValue - minValue;
}









