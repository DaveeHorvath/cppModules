#include "BitcoinChange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

static bool is_valid_date(std::string &date)
{
	std::tm tm = {};
	std::istringstream ss(date);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	return (ss.eof() && !ss.fail());
}

BitcoinChange::BitcoinChange()
{
    std::ifstream data{databasefile};
    database = std::map<std::string, float>();
    if (!data.is_open())
        throw std::runtime_error("Cant open Database");
    for (std::string line; std::getline(data, line);)
    {
        float val;
        std::string key;
        std::stringstream cur(line);
        if (!std::getline(cur, key, ',') || ! (cur >> val) || !(is_valid_date(key)))
            throw std::runtime_error("invalid data in db");
        database.insert_or_assign(key, val);
    }
    data.close();
}

void BitcoinChange::lookupDates(std::string file)
{
    std::ifstream data{file};
    if (!data.is_open())
        throw std::runtime_error("Cant open Database");
    for (std::string line; std::getline(data, line);)
    {
        float val;
        std::string key;
        std::stringstream cur(line);
        if (!std::getline(cur, key, '|') || ! (cur >> val) || !(is_valid_date(key)))
        {
            std::cerr << "Error: invalid line in infile\n";
            continue ;
        }
        if (val > 1000 || val < 0)
            std::cerr << "Error: invalid amount in infile\n";
        auto it = database.lower_bound(key);
        std::cout << key << " => " << val << " = " << val * it->second << "\n";
    }
    data.close();
}

