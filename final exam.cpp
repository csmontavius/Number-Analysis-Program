/*
Program: Number Analysis Program
Programmer: Montavius Spratley Burford
Date: 5/9/2025
Requirments:Write a modular program that asks the user for a file name. 
Assume the file contains a series of numbers, each written on a separate line. 
The program should read the contents of the file into an array then display the following data:
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

// Function declarations
vector<int> ReadNumbersFromFile(const string& filename);
int FindLowest(const vector<int>& numbers);
int FindHighest(const vector<int>& numbers);
int CalculateTotal(const vector<int>& numbers);
double CalculateAverage(const vector<int>& numbers);

int main() {
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;

    vector<int> numbers = {1, 3, 8, 21, 42, 45; // Simulating file data

    if (numbers.empty()) {
        cout << "Error: No valid numbers found in file or file could not be opened." << endl;
        return 1;
    }

    // Display results
    cout << "Lowest number: " << FindLowest(numbers) << endl;
    cout << "Highest number: " << FindHighest(numbers) << endl;
    cout << "Total: " << CalculateTotal(numbers) << endl;
    cout << "Average: " << CalculateAverage(numbers) << endl;

    return 0;
}

// Function implementations
vector<int> ReadNumbersFromFile(const string& filename) {
    ifstream file(filename);
    vector<int> numbers;
    int num;

    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return numbers;
    }

    while (file >> num) {
        numbers.push_back(num);
    }

    return numbers;
}

int FindLowest(const vector<int>& numbers) {
    int lowest = numeric_limits<int>::max();
    for (int num : numbers) {
        if (num < lowest) {
            lowest = num;
        }
    }
    return lowest;
}

int FindHighest(const vector<int>& numbers) {
    int highest = numeric_limits<int>::min();
    for (int num : numbers) {
        if (num > highest) {
            highest = num;
        }
    }
    return highest;
}

int CalculateTotal(const vector<int>& numbers) {
    int total = 0;
    for (int num : numbers) {
        total += num;
    }
    return total;
}

double CalculateAverage(const vector<int>& numbers) {
    if (numbers.empty()) return 0.0;
    return static_cast<double>(CalculateTotal(numbers)) / numbers.size();
}
