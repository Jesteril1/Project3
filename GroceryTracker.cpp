#include "GroceryTracker.h"

void GroceryTracker::loadData(const std::string& filename) {
    std::ifstream inFile(filename);
    std::string item;
    if (!inFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    while (inFile >> item) {
        itemFrequency[item]++;
    }
    inFile.close();
}

int GroceryTracker::getItemFrequency(const std::string& item) {
    auto it = itemFrequency.find(item);
    if (it != itemFrequency.end()) {
        return it->second;
    }
    else {
        return 0;
    }
}

void GroceryTracker::printFrequencies() {
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}

void GroceryTracker::printHistogram() {
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void GroceryTracker::saveFrequencies(const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }
    for (const auto& pair : itemFrequency) {
        outFile << pair.first << " " << pair.second << std::endl;
    }
    outFile.close();
}
