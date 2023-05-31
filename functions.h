#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "mylib.h"

int RandomPazymiai();
bool ArPazymys(int pazymys);
bool PalygintiPavarde(const Studentas& a, const Studentas& b);
float Vidurkis(const vector<int>& pazymiai);
float Mediana(vector<int> pazymiai);
float Galutinis(int egzaminas, float budas, bool ArMediana);
void IvestisRanka(std::vector<Studentas>& studentai, const std::string& stop);
void IvestisAtsitiktinai(vector<Studentas>& studentai);
void IvestisIsFailo(std::vector<Studentas>& studentai, const std::string& failoPavadinimas);
void Isvedimas(const std::vector<Studentas>& studentai, bool ArMediana);
void GeneruotiFailus(const vector<string>& sugeneruoti_failai, const vector<int>& studentu_kiekis, vector<int>& pazymiuKiekis, std::chrono::steady_clock::time_point& programBegin);
void RikiuotiStudentus(std::vector<Studentas>& studentai, const std::string& vargsiukaiFailas, const std::string& kietiakiaiFailas, int kiekispaz);
void Testinimas(vector<Studentas>& studentai, const vector<string>& sugeneruoti_failai, vector<int>& pazymiuKiekis, std::chrono::steady_clock::time_point programBegin);



#endif // FUNCTIONS_H_INCLUDED
