#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

int main() {
    std::unique_ptr<std::vector<int>> left(new std::vector<int>);
    std::unique_ptr<std::vector<int>> right(new std::vector<int>);
    std::unique_ptr<std::vector<int>> count(new std::vector<int>);

    std::ifstream input ("input.txt");

    if (input.is_open()) {
        std::string s;

        while (!input.eof()) {
            // Grab first number
            std::getline(input, s, ' ');
            left->push_back(std::stoi(s));

            // Grab second number
            std::getline(input, s);
            s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
            right->push_back(std::stoi(s));
        }
    }

    // Sort vectors
    std::sort(left->begin(), left->end());
    std::sort(right->begin(), right->end());

    for (int i = 0; i <= right->back(); i++) {
        count->push_back(0);
    }

    int similarity = 0;

    // Get count of numbers in right list
    for (int i : *right) {
        count->at(i) += 1;
    }

    for (int i = 0; i < left->size(); i++) {
        similarity += left->at(i) * count->at(left->at(i));
    }

    std::cout << "Total Similarity: " << similarity << std::endl;

    return 0;
}