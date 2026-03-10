#include <iostream>
#include <iomanip>


#include "BitcoinExchange.hpp"

template <typename K, typename V>
void printMap(const std::map<K, V>& data)
{
    typename std::map<K,V>::const_iterator it;
    for (it = data.begin(); it != data.end(); ++it)
    {
        std::cout << it->first << " -> "
                  << std::fixed << std::setprecision(2)
                  << it->second << std::endl;
    }
}
// ?????????????????????????????????????????????
int main(int argc, char **argv)
{
    if (argc != 2)
        throw std::invalid_argument("could not open file");
    
    std::ifstream db("data.txt");
    if (!db.is_open())
        throw std::runtime_error("could not open database");
    
    BitcoinExchange be;
    be.fill_db(db);
    
    std::ifstream input(argv[1]);
    if (!input.is_open())
        throw std::runtime_error("could not open database");

    be.print_result(input);
    return 0;
}

