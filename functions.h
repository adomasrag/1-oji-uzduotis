#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "mylib.h"

int RandomPazymiai();
bool ArPazymys(int pazymys);
float Vidurkis(const vector<int>& pazymiai);
float Mediana(vector<int> pazymiai);
float Galutinis(int egzaminas, float vidurkis, bool ArMediana);
void IvestisRanka(vector<Studentas>& studentai, const string& stop);
void IvestisAtsitiktinai(vector<Studentas>& studentai);
void IvestisIsFailo(vector<Studentas>& studentai);
bool PalygintiPavarde(const Studentas& a, const Studentas& b);
void Isvedimas(const vector<Studentas>& studentai, bool ArMediana);


#endif // FUNCTIONS_H_INCLUDED
