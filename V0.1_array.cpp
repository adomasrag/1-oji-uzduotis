#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>
#include <iomanip>

struct Studentas {
    std::string vardas;
    std::string pavarde;
    int* pazymiai;
    int pazymiuKiekis;
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

float Vidurkis(const int* pazymiai, int pazymiuKiekis) {
    int suma = 0;
    for (int i = 0; i < pazymiuKiekis; ++i) {
        suma += pazymiai[i];
    }
    return static_cast<float>(suma) / pazymiuKiekis;
}

float Mediana(int* pazymiai, int pazymiuKiekis) {
    std::sort(pazymiai, pazymiai + pazymiuKiekis);
    if (pazymiuKiekis % 2 == 0) {
        return (pazymiai[pazymiuKiekis / 2 - 1] + pazymiai[pazymiuKiekis / 2]) / 2.0;
    } else {
        return pazymiai[pazymiuKiekis / 2];
    }
}

float Galutinis(int egzaminas, float vidurkis, bool ArMediana) {
    if (ArMediana) {
        return 0.6 * egzaminas + 0.4 * vidurkis;
    } else {
        return 0.6 * egzaminas + 0.4 * vidurkis;
    }
}

void IvestisRanka(Studentas studentai[], int& studentuKiekis, const std::string& stop) {
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

        std::cout << "Iveskite pazymi (arba 'STOP' jei norite baigti pazymiu ivedima siam studentui): ";
        std::string ivestis;
        std::getline(std::cin, ivestis);

        int pazymiuKiekis = 0;
        while (ivestis != stop) {
            pazymys = std::stoi(ivestis);
            if (ArPazymys(pazymys)) {
                ++pazymiuKiekis;
                int* naujiPazymiai = new int[pazymiuKiekis];
                std::copy(studentas.pazymiai, studentas.pazymiai + pazymiuKiekis - 1, naujiPazymiai);
                naujiPazymiai[pazymiuKiekis - 1] = pazymys;
                delete[] studentas.pazymiai;
                studentas.pazymiai = naujiPazymiai;
            } else {
                std::cout << "Klaidingas pazymys. Prasome ivesti pazymi nuo 1 iki 10." << std::endl;
            }
            std::cout << "Iveskite pazymi (arba 'STOP' jei norite baigti pazymiu ivedima siam studentui): ";
            std::getline(std::cin, ivestis);
        }

        std::cout << "Iveskite egzamino rezultata siam studentui: ";
        std::cin >> studentas.egzaminas;
        std::cin.ignore();

        studentai[studentuKiekis++] = studentas;
        std::cout << std::endl;
    }
}

void IvestisAtsitiktinai(Studentas studentai[], int& studentuKiekis) {
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

        studentas.pazymiai = new int[pazymiuSkaicius];
        studentas.pazymiuKiekis = pazymiuSkaicius;

        std::cout << "Atsitiktinai sugeneruoti pazymiai: ";
        for (int j = 0; j < pazymiuSkaicius; ++j) {
            int pazymys = RandomPazymiai();
            studentas.pazymiai[j] = pazymys;
            std::cout << pazymys << " ";
        }

        std::cout << std::endl;
        studentas.egzaminas = RandomPazymiai();
        std::cout << "Atsitiktinai sugeneruotas egzamino rezultatas: " << studentas.egzaminas;

        studentai[studentuKiekis++] = studentas;
        std::cout << std::endl;
    }
}

void Isvedimas(Studentas studentai[], int studentuKiekis, bool ArMediana) {
    std::cout << std::left << std::setw(15) << "Vardas"
              << std::setw(15) << "Pavarde"
              << std::setw(15) << (ArMediana ? "Galutinis (Med.)" : "Galutinis (Vid.)") << std::endl;
    std::cout << std::string(45, '-') << std::endl;

    for (int i = 0; i < studentuKiekis; ++i) {
        std::cout << std::left << std::setw(15) << studentai[i].vardas
                  << std::setw(15) << studentai[i].pavarde;

        float vidurkis = Vidurkis(studentai[i].pazymiai, studentai[i].pazymiuKiekis);
        float galutinis = Galutinis(studentai[i].egzaminas, vidurkis, ArMediana);
        std::cout << std::setw(15) << std::fixed << std::setprecision(2) << galutinis << std::endl;
    }
}

void Naikinimas(Studentas studentai[], int studentuKiekis) {
    for (int i = 0; i < studentuKiekis; ++i) {
        delete[] studentai[i].pazymiai;
    }
}

int main() {
    const std::string stop = "STOP";
    const int maxStudentuKiekis = 100;

    Studentas studentai[maxStudentuKiekis];
    int studentuKiekis = 0;

    std::cout << "Pasirinkite ivedimo buda:\n"
              << "1. Rankinis ivedimas\n"
              << "2. Atsitiktinis ivedimas\n"
              << "Pasirinkimas: ";
    int pasirinkimas;
    std::cin >> pasirinkimas;
    std::cin.ignore();

    if (pasirinkimas == 1) {
        IvestisRanka(studentai, studentuKiekis, stop);
    } else if (pasirinkimas == 2) {
        IvestisAtsitiktinai(studentai, studentuKiekis);
    } else {
        std::cout << "Netinkamas pasirinkimas. Paleiskite programa is naujo." << std::endl;
        return 0;
    }

    std::cout << std::endl;

    std::cout << "Pasirinkite skaiciavimo buda:\n"
              << "1. Galutinis pazymys naudojant vidurki\n"
              << "2. Galutinis pazymys naudojant mediana\n"
              << "Jusu pasirinkimas: ";
    std::cin >> pasirinkimas;

    if (pasirinkimas == 1) {
        Isvedimas(studentai, studentuKiekis, false);
    } else if (pasirinkimas == 2) {
        Isvedimas(studentai, studentuKiekis, true);
    } else {
        std::cout << "Netinkamas pasirinkimas. Paleiskite programa is naujo." << std::endl;
        return 0;
    }
    Naikinimas(studentai, studentuKiekis);

    return 0;
}
