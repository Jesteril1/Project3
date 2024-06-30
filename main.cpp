#include <iostream>
#include <string>
#include "GroceryTracker.h"

void displayMenu() {
    std::cout << "1. Look up the frequency of a specific item\n";
    std::cout << "2. Print the frequency of all items\n";
    std::cout << "3. Print a histogram of item frequencies\n";
    std::cout << "4. Exit the program\n";
    std::cout << "Enter your choice: ";
}

int main() {
    GroceryTracker tracker;
    std::string inputFilename = "CS210_Project_Three_Input_File.txt";
    std::string outputFilename = "frequency.dat";

    // Load data from file
    std::cout << "Loading data from file: " << inputFilename << std::endl;
    tracker.loadData(inputFilename);

    // Save frequencies to backup file
    std::cout << "Saving frequencies to backup file: " << outputFilename << std::endl;
    tracker.saveFrequencies(outputFilename);

    int choice;
    std::string item;

    while (true) {
        displayMenu();
        std::cin >> choice;

        // Handle invalid input
        if (std::cin.fail()) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(INT_MAX, '\n'); // discard invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue;
        }

        switch (choice) {
        case 1:
            std::cout << "Enter the item name: ";
            std::cin >> item;
            std::cout << item << " was purchased " << tracker.getItemFrequency(item) << " times.\n";
            break;
        case 2:
            std::cout << "Printing the frequency of all items:\n";
            tracker.printFrequencies();
            break;
        case 3:
            std::cout << "Printing the histogram of item frequencies:\n";
            tracker.printHistogram();
            break;
        case 4:
            std::cout << "Exiting program...\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

    return 0;
}
