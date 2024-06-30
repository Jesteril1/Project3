#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class GroceryTracker {
public:
    void loadData(const std::string& filename);
    int getItemFrequency(const std::string& item);
    void printFrequencies();
    void printHistogram();
    void saveFrequencies(const std::string& filename);

private:
    std::map<std::string, int> itemFrequency;
};

#endif
