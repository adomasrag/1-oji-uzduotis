#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>


struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> pazymiai;
    int egzaminas;
};

int RandomPazymiai() {
    static std::random_device rd;
    static std::mt19937 mt(rd());
    static std::uniform_int_distribution<int> pazymiaiRng(1, 10);
    return pazymiaiRng(mt);
}

bool ArPazymys(int pazymys) {
    return pazymys >= 1 && pazymys <= 10;
}

float Vidurkis(const std::vector<int>& pazymiai) {
    int suma = 0;
    for (int pazymys : pazymiai) {
        suma += pazymys;
    }
    return static_cast<float>(suma) / pazymiai.size();
}

float Mediana(std::vector<int> pazymiai) {
    std::sort(pazymiai.begin(), pazymiai.end());
    int dydis = pazymiai.size();
    if (dydis % 2 == 0) {
        return (pazymiai[dydis / 2 - 1] + pazymiai[dydis / 2]) / 2.0;
    } else {
        return pazymiai[dydis / 2];
    }
}

float Galutinis(int egzaminas, float vidurkis, bool ArMediana) {
    if (ArMediana) {
        return 0.6 * egzaminas + 0.4 * vidurkis;
    } else {
        return 0.6 * egzaminas + 0.4 * vidurkis;
    }
}

void IvestisRanka(std::vector<Studentas>& studentai, const std::string& stop) {
    std::string vardas, pavarde;
    int pazymys;

    while (true) {
        std::cout << "Iveskite studento varda (arba 'STOP' jei norite baigti ivedima): ";
        std::getline(std::cin, vardas);

        if (vardas == stop)
            break;

        std::cout << "Iveskite studento pavarde: ";
        std::getline(std::cin, pavarde);

        Studentas studentas;
        studentas.vardas = vardas;
        studentas.pavarde = pavarde;

        while (true) {
            std::cout << "Iveskite pazymi (arba 'STOP' jei norite baigti pazymiu ivedima siam studentui): ";
            std::string ivestis;
            std::getline(std::cin, ivestis);

            if (ivestis == stop)
                break;

            pazymys = std::stoi(ivestis);
            if (ArPazymys(pazymys))
                studentas.pazymiai.push_back(pazymys);
            else
                std::cout << "Klaidingas paþymys. Prasome ivesti pazymi nuo 1 iki 10." << std::endl;
        }

        std::cout << "Iveskite egzamino rezultata siam studentui: ";
        std::cin >> studentas.egzaminas;
        std::cin.ignore();

        studentai.push_back(studentas);
        std::cout << std::endl;
    }
}


void IvestisAtsitiktinai(std::vector<Studentas>& studentai) {
    std::string vardas, pavarde;
    int pazymys;

    std::cout << "Iveskite studentu skaiciu: ";
    int studentuSkaicius;
    std::cin >> studentuSkaicius;
    std::cin.ignore();

    for (int i = 0; i < studentuSkaicius; ++i) {
        Studentas studentas;

        std::cout << "Iveskite studento varda: ";
        std::getline(std::cin, vardas);
        studentas.vardas = vardas;

        std::cout << "Iveskite studento pavarde: ";
        std::getline(std::cin, pavarde);
        studentas.pavarde = pavarde;

        std::cout << "Iveskite namu darbu skaiciu siam studentui: ";
        int pazymiuSkaicius;
        std::cin >> pazymiuSkaicius;
        std::cin.ignore();

        std::cout << "Atsitiktinai sugeneruoti pazymiai: ";
        for (int j = 0; j < pazymiuSkaicius; ++j) {
            pazymys = RandomPazymiai();
            studentas.pazymiai.push_back(pazymys);
            std::cout << pazymys << " ";
        }
        std::cout << std::endl;

        studentas.egzaminas = RandomPazymiai();
        std::cout << "Atsitiktinai sugeneruotas egzamino rezultatas: " << studentas.egzaminas << std::endl;

        studentai.push_back(studentas);
        std::cout << std::endl;
    }
}

void IvestisIsFailo(std::vector<Studentas>& studentai) {
    std::ifstream failas("kursiokai.txt");
    if (failas.is_open()) {
        std::string eilute;
        std::getline(failas, eilute);

        while (std::getline(failas, eilute)) {
            std::istringstream iss(eilute);

            Studentas studentas;
            iss >> studentas.vardas >> studentas.pavarde;

            int pazymys;
            while (iss >> pazymys) {
                if (ArPazymys(pazymys))
                    studentas.pazymiai.push_back(pazymys);
                else
                    std::cout << "Klaidingas pazymys. Prasome ivesti pazymi nuo 1 iki 10." << std::endl;
            }

            if (studentas.pazymiai.empty()) {
                std::cout << "Nera pazymiu studentui: " << studentas.pavarde << " " << studentas.vardas << std::endl;
                continue;
            }

            studentas.egzaminas = studentas.pazymiai.back();
            studentas.pazymiai.pop_back();
            studentai.push_back(studentas);
        }

        failas.close();
    } else {
        std::cout << "Nepavyko atidaryti failo. Paleiskite programa is naujo." << std::endl;
        return;
    }
}

bool PalygintiPavarde(Studentas& x, Studentas& y) {
    return x.pavarde < y.pavarde;
}

void Isvedimas(const std::vector<Studentas>& studentai, bool ArMediana) {
    std::cout << "Pavarde\t\tVardas\t\tGalutinis balas" << (ArMediana ? "(mediana)" : "(vidurkis)") << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    std::vector<Studentas> sortedStudentai = studentai;
    std::sort(sortedStudentai.begin(), sortedStudentai.end(), PalygintiPavarde);
    for (const auto& studentas : sortedStudentai) {
        float vidurkis;
        if (ArMediana) {
            vidurkis = Mediana(studentas.pazymiai);
        } else {
            vidurkis = Vidurkis(studentas.pazymiai);
        }
        float galutinis = Galutinis(studentas.egzaminas, vidurkis, ArMediana);

        std::cout << std::left << std::setw(15) << studentas.pavarde << "\t" << std::setw(15) << studentas.vardas;
        std::cout << std::fixed << std::setprecision(2) << galutinis << std::endl;
    }
}

int main() {
    std::vector<Studentas> studentai;
    std::string stop = "STOP";

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::cout << "Pasirinkite ivedimo buda:\n"
              << "1. Rankinis ivedimas\n"
              << "2. Atsitiktinis ivedimas\n"
              << "3. Nuskaitymas is failo\n"
              << "Pasirinkimas: ";
    int pasirinkimas;
    std::cin >> pasirinkimas;
    std::cin.ignore();

    if (pasirinkimas == 1) {
        IvestisRanka(studentai, stop);
    } else if (pasirinkimas == 2) {
        IvestisAtsitiktinai(studentai);
    } else if (pasirinkimas == 3) {
        IvestisIsFailo(studentai);
    } else {
        std::cout << "Netinkamas pasirinkimas. Paleiskite programa is naujo." << std::endl;
        return 0;
    }

    std::cout << "Pasirinkite skaiciavimo buda:\n"
              << "1. Galutinis pazymys naudojant vidurki\n"
              << "2. Galutinis pazymys naudojant mediana\n"
              << "Jusu pasirinkimas: ";
    pasirinkimas = 0;
    std::cin >> pasirinkimas;

    if (pasirinkimas == 1) {
        Isvedimas(studentai, false);
    } else if (pasirinkimas == 2) {
        Isvedimas(studentai, true);
    } else {
        std::cout << "Netinkamas pasirinkimas. Paleiskite programa is naujo." << std::endl;
        return 0;
    }

    return 0;
}
