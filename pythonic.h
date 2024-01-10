// python_functions.h

#ifndef PYTHON_FUNCTIONS_H
#define PYTHON_FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

// Function to replicate Python's input function
template <typename T>
T input(const string& prompt) {
    cout << prompt;
    string user_input;
    getline(cin, user_input);

    T result;
    stringstream ss(user_input);
    ss >> result;

    return result;
}

// Function to replicate Python's print function
template <typename T>
void print(const T& value) {
    cout << value;
}

template <typename... Args>
void print(const Args&... args) {
    (cout << ... << args);
    cout << endl;
}

// Function to replicate Python's len function
template <typename Container>
size_t len(const Container& container) {
    if constexpr (std::is_same_v<Container, const char*> || std::is_same_v<Container, char*>) {
        return std::strlen(container);
    } else {
        return std::size(container);
    }
}

// Specialized version of len for arrays
template <typename T, size_t N>
size_t len(const T (&array)[N]) {
    return N;
}

// Function to replicate Python's range function
vector<int> range(int start, int end, int step = 1) {
    vector<int> result;
    for (int i = start; i < end; i += step) {
        result.push_back(i);
    }
    return result;
}

// Function to replicate Python's sum function
template <typename T>
T sum(const vector<T>& values) {
    T result = 0;
    for (const T& value : values) {
        result += value;
    }
    return result;
}

// Function to replicate Python's join function
template <typename Container>
string join(const Container& elements, const string& delimiter) {
    ostringstream result;
    auto it = begin(elements);
    if (it != end(elements)) {
        result << *it++;
        while (it != end(elements)) {
            result << delimiter << *it++;
        }
    }
    return result.str();
}

// Function to replicate Python's split function
vector<string> split(const string& str, const string& delimiter) {
    vector<string> result;
    size_t start = 0;
    size_t end = str.find(delimiter);
    while (end != string::npos) {
        result.push_back(str.substr(start, end - start));
        start = end + delimiter.size();
        end = str.find(delimiter, start);
    }
    result.push_back(str.substr(start));
    return result;
}

// Function to replicate Python's max function
template <typename T>
const T& max(const T& a, const T& b) {
    return (a > b) ? a : b;
}

// Function to replicate Python's min function
template <typename T>
const T& min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

// Function to replicate Python's abs function
template <typename T>
T abs(const T& value) {
    return (value < 0) ? -value : value;
}

#endif // PYTHON_FUNCTIONS_H
