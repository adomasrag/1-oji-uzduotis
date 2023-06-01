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
void IvestisRanka(deque<Studentas>& studentai, const string& stop);
void IvestisAtsitiktinai(deque<Studentas>& studentai);
void IvestisIsFailo(deque<Studentas>& studentai, const string& failoPavadinimas);
void Isvedimas(const deque<Studentas>& studentai, bool ArMediana);
void GeneruotiFailus(const vector<string>& sugeneruoti_failai, const vector<int>& studentu_kiekis);
void RikiuotiStudentus1STRAT(deque<Studentas>& studentai, const string& vargsiukaiFailas, const string& kietiakiaiFailas, int pazymiuKiekis);
void RikiuotiStudentus2STRAT(deque<Studentas>& studentai, const string& vargsiukaiFailas, const string& kietiakiaiFailas, int pazymiuKiekis);
void Testinimas(deque<Studentas>& studentai, const vector<string>& sugeneruoti_failai);
void IsvedimasIFaila(const string& vargsiukaiFailas, const string& kietiakiaiFailas, const deque<Studentas>& vargsiukai, const deque<Studentas>& kietiakiai, int pazymiuKiekis);

#endif // FUNCTIONS_H_INCLUDED
