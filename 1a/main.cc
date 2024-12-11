#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

int main() {
    std::unique_ptr<std::vector<int>> left(new std::vector<int>);
    std::unique_ptr<std::vector<int>> right(new std::vector<int>);

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

    int distance = 0;

    // Vectors are same length, compare values.
    for (int i = 0; i < left->size(); i++) {
        distance += std::abs(left->at(i) - right->at(i));
    }

    std::cout << "Total Distance: " << distance << std::endl;

    return 0;
}