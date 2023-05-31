#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::fixed;
using std::setw;
using std::setprecision;
using std::string;
using std::vector;
using std::istringstream;
using std::sort;
using std::getline;
using std::stoi;
using std::ifstream;
using std::srand;
using std::time;
using std::runtime_error;
using std::exception;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzaminas;
};


#endif // MYLIB_H_INCLUDED
