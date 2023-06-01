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

bool PalygintiPavarde(const Studentas& x, const Studentas& y) {
    return x.pavarde < y.pavarde;
}

bool PalygintiVarda(const Studentas& x, const Studentas& y) {
    return x.vardas < y.vardas;
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

float Galutinis(int egzaminas, float budas, bool ArMediana) {
    if (ArMediana) {
        return 0.6 * egzaminas + 0.4 * budas;
    } else {
        return 0.6 * egzaminas + 0.4 * budas;
    }
}

void Isvedimas(const deque<Studentas>& studentai, bool ArMediana) {
    if (studentai.empty()) {
        cout << "Nera studentu duomenu." << endl;
        return;
    }

    cout << "Pavarde\t\tVardas\t\tGalutinis balas" << (ArMediana ? "(mediana)" : "(vidurkis)") << endl;
    cout << "--------------------------------------------------" << endl;

    deque<Studentas> sortedStudentai = studentai;
    sort(sortedStudentai.begin(), sortedStudentai.end(), PalygintiPavarde);
    for (const auto& studentas : sortedStudentai) {
        float budas;
        if (ArMediana) {
            budas = Mediana(studentas.pazymiai);
        } else {
            budas = Vidurkis(studentas.pazymiai);
        }
        float galutinis = Galutinis(studentas.egzaminas, budas, ArMediana);

        cout << left << setw(15) << studentas.pavarde << "\t" << setw(15) << studentas.vardas;
        cout << fixed << setprecision(2) << galutinis << endl;
    }
}

void IsvedimasIFaila(const string& vargsiukaiFailas, const string& kietiakiaiFailas, const deque<Studentas>& vargsiukai, const deque<Studentas>& kietiakiai, int pazymiuKiekis) {
    ofstream vargsiukaiStream(vargsiukaiFailas);
    ofstream kietiakiaiStream(kietiakiaiFailas);

    if (vargsiukaiStream.is_open() && kietiakiaiStream.is_open()) {
        vargsiukaiStream << setw(25) << left << setprecision(2) << "Vardas";
        vargsiukaiStream << setw(25) << left << setprecision(2) << "Pavarde";

        for (int j = 1; j <= pazymiuKiekis; ++j) {
            vargsiukaiStream << "ND" << j << "       ";
        }
        vargsiukaiStream << "Egz.\n";
        for (const auto& studentas : vargsiukai) {
            vargsiukaiStream << setw(25) << left << studentas.vardas;
            vargsiukaiStream << setw(25) << left << studentas.pavarde;

            for (const auto& pazymys : studentas.pazymiai) {
                vargsiukaiStream << setw(10) << left << pazymys;
            }
            vargsiukaiStream << setw(10) << left << studentas.egzaminas << endl;
        }

        kietiakiaiStream << setw(25) << left << setprecision(2) << "Vardas";
        kietiakiaiStream << setw(25) << left << setprecision(2) << "Pavarde";

        for (int k = 1; k <= pazymiuKiekis; ++k) {
            kietiakiaiStream << "ND" << k << "       ";
        }
        kietiakiaiStream << "Egz.\n";
        for (const auto& studentas : kietiakiai) {
            kietiakiaiStream << setw(25) << left << studentas.vardas;
            kietiakiaiStream << setw(25) << left << studentas.pavarde;

            for (const auto& pazymys : studentas.pazymiai) {
                kietiakiaiStream << setw(10) << left << pazymys;
            }
            kietiakiaiStream << setw(10) << left << studentas.egzaminas << endl;
        }

        vargsiukaiStream.close();
        kietiakiaiStream.close();
    } else {
        cout << "Klaida: Nepavyko atidaryti failu " << vargsiukaiFailas << " ir " << kietiakiaiFailas << endl;
    }
}

