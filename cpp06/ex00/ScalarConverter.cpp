#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <iomanip>

ScalarConverter::ScalarConverter() {
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter&) {
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter&) {
	return *this;
}

static bool	isSpecialLiteral(const std::string& str) {
	size_t	length = str.size();
	if (length >= 3 && length <= 5) {
	char	firstChar = str[0] , lastChar = str[length - 1];
	if (firstChar == 'n' && lastChar == 'f') return str == "nanf";
	if (firstChar == 'n' && lastChar == 'n') return str == "nan";
	if (firstChar == '+' && lastChar == 'f') return ((length == 5) ? str == "+inff" : str == "+inf");
	if (firstChar == '-' && lastChar == 'f') return ((length == 5) ? str == "-inff" : str == "-inf");
	}
	return false;	
}

static bool isSpecialChar(const std::string& str) {
	return (str.size() == 3 && str[0] == '\'' && str[2] == '\'');
}

static bool	isValidNumber(const std::string& str) {
	size_t		index = 0, length = str.size();
	bool	hasDecimalPoint = false, hasSign = false;
	if (length && (str[index] == '-' || str[index] == '+'))
		hasSign = static_cast<bool>(++index);
	if (!(length - index))
		return false;
	while (index < length) {
		if (str[index] == 'f') {
			if (index != length - 1)
				return false;
		}
		else if (str[index] == '.') {
			if (!index || index == length - 1 || !std::isdigit(str[index + 1]))
				return false;
			if (hasDecimalPoint || !(index - static_cast<size_t>(hasSign) || index == length - 1))
				return false;
			hasDecimalPoint = true;
		}
		else if (!std::isdigit(str[index]))
			return false;
		++index;
	}
	return true;
}
static void	printSpecialLiteral(const std::string& str) {
	std::cout << "char: impossible\n""int: impossible\n";
	switch(str[0]) {
		case 'n': std::cout << "float: nanf\n""double: nan\n"; break;
		case '+': std::cout << "float: +inff\n""double: +inf\n"; break;
		case '-': std::cout << "float: -inff\n""double: -inf\n"; break;
	}
}

static void	printAllTypes(double value, int precision) {
	bool	isInIntRange = static_cast<double>(std::numeric_limits<int>::max()) >= value
						&& static_cast<double>(std::numeric_limits<int>::min()) <= value;
	bool	isInFloatRange = static_cast<double>(std::numeric_limits<float>::max()) >= value
						&& -static_cast<double>(std::numeric_limits<float>::max()) <= value;
	std::cout << "char: ";
	if (!isInIntRange || value < 0.0 || value > 127.0)
		std::cout << "impossible\n";
	else if (value < 32.0 || value > 126.0)
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(value) << "'\n";
	std::cout << "int: ";
	if (isInIntRange)
		std::cout << static_cast<int>(value) << "\n";
	else
		std::cout << "impossible\n";
	std::cout << "float: ";
	if (isInFloatRange)
		std::cout << std::fixed << std::setprecision(precision) << static_cast<float>(value) << "f\n";
	else
		std::cout << "impossible\n";
	std::cout << "double: " << value << "\n";
}

static int	getPrecisionNumber(const std::string& input) {
	size_t decimalPos = input.find('.');
	if (decimalPos == std::string::npos)
		return 1;
	else
		return (input.size() - decimalPos - 1 - (input[input.size() - 1] == 'f'));
}

void	ScalarConverter::convert(const std::string& text) {
	bool	isSpecialLit = isSpecialLiteral(text);
	bool	isCharLiteral = (isSpecialLit) ? false : isSpecialChar(text);
	bool	isNumber = (isSpecialLit) ? false : ((isCharLiteral) ? true : isValidNumber(text));
	if (isSpecialLit) printSpecialLiteral(text);
	else if (isNumber) {
		double	convertedValue = (isCharLiteral) ? static_cast<double>(text[1]) : std::atof(text.c_str());
		printAllTypes(convertedValue, getPrecisionNumber(text));
	}
	else
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}	
