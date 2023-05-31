#include "mylib.h"
#include "functions.h"

void IvestisRanka(deque<Studentas>& studentai, const string& stop) {
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
    }
}


void IvestisAtsitiktinai(deque<Studentas>& studentai) {
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

void IvestisIsFailo(deque<Studentas>& studentai, const string& failoPavadinimas) {
    ifstream failas(failoPavadinimas);
    if (failas.is_open()) {
        string eilute;
        getline(failas, eilute);

        while (getline(failas, eilute)) {
            istringstream iss(eilute);

            Studentas studentas;
            iss >> studentas.vardas >> studentas.pavarde;

            int pazymys;
            while (iss >> pazymys) {
                if (ArPazymys(pazymys))
                    studentas.pazymiai.push_back(pazymys);
                else
                    cout << "Klaidingas pazymys. Prasome ivesti pazymi nuo 1 iki 10." << endl;
            }

            if (studentas.pazymiai.empty()) {
                cout << "Nera pazymiu studentui: " << studentas.pavarde << " " << studentas.vardas << endl;
                continue;
            }

            studentas.egzaminas = studentas.pazymiai.back();
            studentas.pazymiai.pop_back();
            studentai.push_back(studentas);
        }
        failas.close();
    } else {
        cout << "Klaida: Nepavyko atidaryti failo. Patikrinkite, ar failas egzistuoja." << endl;
    }
}
