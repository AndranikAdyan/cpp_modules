#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <stdexcept>

class	RPN {
	public:
		RPN();
		~RPN();
		RPN(const RPN&);
		RPN&	operator=(const RPN&);
		
		int solve(const std::string& expr);
		
	private:
		std::stack<int>	data;
};

#endif