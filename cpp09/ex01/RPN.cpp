#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) : data(other.data) {}

RPN&	RPN::operator=(const RPN& other) {
	if (this != &other)
		data = other.data;
	return *this;
}

int RPN::solve(const std::string& expr) {
    for (size_t i = 0; i < expr.length(); ++i)
    {
        
        if (expr[i] == ' ')
            continue ;
        else if (isdigit(expr[i]))
            data.push(expr[i] - '0');
        else if (expr[i] == '+') {
            if (data.size() < 2)
                throw std::runtime_error("Error");
            int first = data.top();
            data.pop();
            int second = data.top();
            data.pop();
            data.push(second + first);
        }
        else if (expr[i] == '-') {
            if (data.size() < 2)
                throw std::runtime_error("Error");
            int first = data.top();
            data.pop();
            int second = data.top();
            data.pop();
            data.push(second - first);
        }
        else if (expr[i] == '*') {
            if (data.size() < 2)
                throw std::runtime_error("Error");
            int first = data.top();
            data.pop();
            int second = data.top();
            data.pop();
            data.push(second * first);
        }
        else if (expr[i] == '/') {
            if (data.size() < 2)
                throw std::runtime_error("Error");
            int first = data.top();
            data.pop();
            int second = data.top();
            data.pop();
            if (first == 0)
                throw std::runtime_error("Divizion by Zero");
            data.push(second / first);
        }
        else
            throw std::runtime_error("Invalid Argument");
    }
    if (data.size() != 1)
		throw std::runtime_error("Invalid expression");
	return data.top();
}