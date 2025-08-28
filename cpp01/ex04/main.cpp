#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int main(int argc, char const *argv[])
{
	if (argc != 4)
	{
		std::cout << "Usage: ./replace <filename> <arg1> <arg2>" << std::endl;
		return 1;
	}
	
	std::string buff(4096, '\0');
	std::ifstream file(argv[1], std::ios::binary);
	if (!file.is_open())
	{
		std::cout << "Error: could not open file: " << argv[1] << std::endl;
		return (1);
	}

	std::string result;
	std::string filename = argv[1];
	std::string arg1 = argv[2];
	std::string arg2 = argv[3];
	while (true) {
		file.read(&buff[0], buff.size());
		ssize_t count = file.gcount();
		if (count == 0)
			break;
		buff.resize(count);
		for (int i = 0; i < count; i++) {
			if (buff.substr(i, arg1.size()) == arg1) {
				result += arg2;
				i += arg1.size() - 1;
			}
			else {
				result += buff[i];
			}
		}
	}
	std::ofstream outfile(filename + ".replace", std::ios::out | std::ios::trunc);
	outfile << result;
	return 0;
}
