#ifndef BITCOINCHANGE_HPP
#define BITCOINCHANGE_HPP

#include <map>
#include <iomanip>
#include <string>

class BitcoinChange {
    private:
        const std::string databasefile = "database.csv";
    public:
        std::map<std::string, float> database;
        BitcoinChange();
        ~BitcoinChange() = default;
        BitcoinChange(const BitcoinChange& other) = delete;
        BitcoinChange& operator=(const BitcoinChange& other) = delete;
        void lookupDates(std::string file);
};

#endif