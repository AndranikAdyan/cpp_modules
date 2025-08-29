#include "Harl.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
		std::cout << "Usage: ./harlFilter <level>" << std::endl;
	
	Harl harl;
	std::string level = argv[1];
	harl.complain(level);
	return 0;
}
