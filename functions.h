#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "mylib.h"

int RandomPazymiai();
bool ArPazymys(int pazymys);
bool PalygintiPavarde(const Studentas& a, const Studentas& b);
bool PalygintiVarda(const Studentas& x, const Studentas& y);
float Vidurkis(const vector<int>& pazymiai);
float Mediana(vector<int> pazymiai);
float Galutinis(int egzaminas, float budas, bool ArMediana);
void IvestisRanka(list<Studentas>& studentai, const string& stop);
void IvestisAtsitiktinai(list<Studentas>& studentai);
void IvestisIsFailo(list<Studentas>& studentai, const string& failoPavadinimas);
void Isvedimas(const list<Studentas>& studentai, bool ArMediana);
void GeneruotiFailus(const vector<string>& sugeneruoti_failai, const vector<int>& studentu_kiekis, vector<int>& pazymiuKiekis);
void RikiuotiStudentus(list<Studentas>& studentai, const string& vargsiukaiFailas, const string& kietiakiaiFailas, int pazymiuKiekis);
void Testinimas(list<Studentas>& studentai, const vector<string>& sugeneruoti_failai, vector<int>& pazymiuKiekis);


#endif // FUNCTIONS_H_INCLUDED
