#include "mylib.h"
#include "functions.h"

int RandomPazymiai() {
    static std::random_device rd;
    static std::mt19937 mt(rd());
    static std::uniform_int_distribution<int> pazymiaiRng(1, 10);
    return pazymiaiRng(mt);
}

bool ArPazymys(int pazymys) {
    return pazymys >= 1 && pazymys <= 10;
}

float Vidurkis(const vector<int>& pazymiai) {
    int suma = 0;
    for (int pazymys : pazymiai) {
        suma += pazymys;
    }
    return static_cast<float>(suma) / pazymiai.size();
}

float Mediana(vector<int> pazymiai) {
    sort(pazymiai.begin(), pazymiai.end());
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

void IvestisRanka(vector<Studentas>& studentai, const string& stop) {
    string vardas, pavarde;
    int pazymys;

    while (true) {
        cout << "Iveskite studento varda (arba 'STOP' jei norite baigti ivedima): ";
        getline(cin, vardas);

        if (vardas == stop)
            break;

        cout << "Iveskite studento pavarde: ";
        getline(cin, pavarde);

        Studentas studentas;
        studentas.vardas = vardas;
        studentas.pavarde = pavarde;

        while (true) {
            cout << "Iveskite pazymi (arba 'STOP' jei norite baigti pazymiu ivedima siam studentui): ";
            string ivestis;
            getline(cin, ivestis);

            if (ivestis == stop)
                break;

            try {
                pazymys = stoi(ivestis);
                if (ArPazymys(pazymys))
                    studentas.pazymiai.push_back(pazymys);
                else
                    throw runtime_error("Klaida: Klaidingas pazymys. Prasome ivesti pazymi nuo 1 iki 10.");
            } catch (const exception& e) {
                cout << "Klaida: " << e.what() << ". Iveskite pazymi." << endl;
                continue;
            }
        }

        cout << "Iveskite egzamino rezultata siam studentui: ";
        while (true) {
            string ivestis;
            getline(cin, ivestis);

            try {
                pazymys = stoi(ivestis);
                if (ArPazymys(pazymys)) {
                    studentas.egzaminas = pazymys;
                    break;
                } else {
                    throw runtime_error("Klaida: Klaidingas pazymys. Prasome ivesti pazymi nuo 1 iki 10.");
                }
            } catch (const exception& e) {
                cout << "Klaida: " << e.what() << ". Iveskite pazymi." << endl;
            }
        }

        studentai.push_back(studentas);
        cout << endl;
    }
}

void IvestisAtsitiktinai(vector<Studentas>& studentai) {
    string vardas, pavarde;
    int pazymys;

    cout << "Iveskite studentu skaiciu: ";
    int studentuSkaicius;

    while (true) {
        string ivestis;
        getline(cin, ivestis);

        try {
            studentuSkaicius = stoi(ivestis);
            break;
        } catch (const exception& e) {
            cout << "Klaida: " << e.what() << ". Iveskite studentu skaiciu." << endl;
        }
    }

    for (int i = 0; i < studentuSkaicius; ++i) {
        Studentas studentas;

        cout << "Iveskite studento varda: ";
        getline(cin, vardas);
        studentas.vardas = vardas;

        cout << "Iveskite studento pavarde: ";
        getline(cin, pavarde);
        studentas.pavarde = pavarde;

        cout << "Iveskite namu darbu skaiciu siam studentui: ";
        int pazymiuSkaicius;

        while (true) {
            string ivestis;
            getline(cin, ivestis);

            try {
                pazymiuSkaicius = stoi(ivestis);
                break;
            } catch (const exception& e) {
                cout << "Klaida: " << e.what() << ". Iveskite namu darbu skaiciu." << endl;
            }
        }


        cout << "Atsitiktinai sugeneruoti pazymiai: ";
        for (int j = 0; j < pazymiuSkaicius; ++j) {
            pazymys = RandomPazymiai();
            studentas.pazymiai.push_back(pazymys);
            cout << pazymys << " ";
        }
        cout << endl;

        studentas.egzaminas = RandomPazymiai();
        cout << "Atsitiktinai sugeneruotas egzamino rezultatas: " << studentas.egzaminas << endl;

        studentai.push_back(studentas);
        cout << endl;
    }
}

void IvestisIsFailo(std::vector<Studentas>& studentai) {
    std::string failoPavadinimas;

    while (true) {
        std::cout << "Iveskite failo pavadinima: ";
        std::getline(std::cin, failoPavadinimas);

        std::ifstream failas(failoPavadinimas);
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

            studentas.egzaminas = studentas.pazymiai.back(); // Last number in the row is the exam score
            studentas.pazymiai.pop_back();
            studentai.push_back(studentas);
        }

        failas.close();
            break;
        } else {
            std::cout << "Klaida: Nepavyko atidaryti failo. Patikrinkite, ar failas egzistuoja." << std::endl;
        }
    }
}

bool PalygintiPavarde(const Studentas& x, const Studentas& y) {
    return x.pavarde < y.pavarde;
}

void Isvedimas(const vector<Studentas>& studentai, bool ArMediana) {
    if (studentai.empty()) {
        cout << "Nera studentu duomenu." << endl;
        return;
    }

    cout << "Pavarde\t\tVardas\t\tGalutinis balas" << (ArMediana ? "(mediana)" : "(vidurkis)") << endl;
    cout << "--------------------------------------------------" << endl;

    vector<Studentas> sortedStudentai = studentai;
    sort(sortedStudentai.begin(), sortedStudentai.end(), PalygintiPavarde);
    for (const auto& studentas : sortedStudentai) {
        float vidurkis;
        if (ArMediana) {
            vidurkis = Mediana(studentas.pazymiai);
        } else {
            vidurkis = Vidurkis(studentas.pazymiai);
        }
        float galutinis = Galutinis(studentas.egzaminas, vidurkis, ArMediana);

        cout << left << setw(15) << studentas.pavarde << "\t" << setw(15) << studentas.vardas;
        cout << fixed << setprecision(2) << galutinis << endl;
    }
}
