#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <fstream>
# include <string>
# include <utility>
# include <sstream>
# include <iomanip>
# include <iostream>

class BitcoinExchange {
    public:
        std::map<std::string, double> data;

        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
    
        void fill_db(std::ifstream& file);
        void print_result(std::ifstream& file);
};

#endif