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
#include <chrono>

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
using std::ofstream;
using std::srand;
using std::time;
using std::runtime_error;
using std::exception;
using std::to_string;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzaminas;
};

const vector<string> sugeneruoti_failai = {
    "stud1000.txt",
    "stud10000.txt",
    "stud100000.txt",
    "stud1000000.txt",
    "stud10000000.txt",
};

const vector<int> studentu_kiekis = {
    1000,
    10000,
    100000,
    1000000,
    10000000,
};


#endif // MYLIB_H_INCLUDED
