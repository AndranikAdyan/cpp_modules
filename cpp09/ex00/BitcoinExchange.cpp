#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : data(other.data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		data = other.data;
	return *this;
}

static std::string trim(const std::string& s)
{
    size_t start = s.find_first_not_of(" \t");
    if (start == std::string::npos) return "";

    size_t end = s.find_last_not_of(" \t");
    return s.substr(start, end - start + 1);
}


bool check_date(const std::string& d)
{
	if (d.size() != 10)
		return false;

	if (d[4] != '-' || d[7] != '-')
		return false;

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (d[i] < '0' || d[i] > '9')
			return false;
	}

	int year, month, day;
	std::stringstream ss;
	ss << d.substr(0,4) << ' ' << d.substr(5,2) << ' ' << d.substr(8,2);
	ss >> year >> month >> day;

	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	if (year < 0)
		return false;
	return true;
}

static void check_data_line(const std::string& line)
{
	size_t pos = line.find(',');
	if (pos == std::string::npos)
		throw std::invalid_argument("Invalid argument in db");

	std::string date = line.substr(0,pos);
	std::string val = line.substr(pos+1);
	double rate;

	if (!check_date(date))
		return throw std::invalid_argument("Invalid argument in db");

	std::stringstream ss(val);
	ss >> rate;

	if (ss.fail())
		return throw std::invalid_argument("Invalid argument in db");
}

static void add_to_map(std::map<std::string, double>& data, std::string& line) {
	check_data_line(line);
	size_t pos = line.find(',');
	std::string key = line.substr(0,pos);
	std::string val = line.substr(pos + 1);

	double rate;
	std::stringstream ss(val);
	ss >> rate;

	data.insert(std::make_pair(key, rate));
}

void BitcoinExchange::fill_db(std::ifstream& file) {
	std::string line;

	std::getline(file, line);

	while(std::getline(file, line))
		add_to_map(this->data, line);
}


void BitcoinExchange::print_result(std::ifstream& file)
{
    std::string line;

    while (std::getline(file, line))
    {
        std::string date_str;
        double value = 0.0;

        size_t pos = line.find('|');
        if (pos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        date_str = trim(line.substr(0,pos));
        std::string val_str = trim(line.substr(pos+1));

        if (date_str == "date" && val_str == "value")
            continue;

        std::stringstream ss(val_str);
        ss >> value;
        if (ss.fail()) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (value < 0) {
            std::cout << "Error: not a positive number.\n";
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number.\n";
            continue;
        }

        std::map<std::string,double>::const_iterator it = data.begin();
        std::map<std::string,double>::const_iterator found = data.end();

        for (; it != data.end(); ++it) {
            if (it->first == date_str) {
                found = it;
                break;
            }
            if (it->first > date_str) {
                break;
            }
            found = it;
        }

        if (found == data.end()) {
            std::cout << "Error: date not found in database => " << date_str << std::endl;
            continue;
        }

        double rate = found->second;
        double result = rate * value;

        std::cout << date_str << " => " << value << " = "
                  << std::fixed << std::setprecision(2)
                  << result << std::endl;
    }
}


