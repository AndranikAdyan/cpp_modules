#include <iostream>

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	int j;
	for (int i = 1; argv[i]; i++)
	{
		for (j = 0; argv[i][j]; j++)
			std::cout << static_cast<unsigned char>(toupper(argv[i][j]));
		if (argv[i][j - 1])
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
