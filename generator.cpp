#include "mylib.h"
#include "functions.h"

void GeneruotiFailus(const vector<string>& sugeneruoti_failai, const vector<int>& studentu_kiekis, vector<int>& pazymiuKiekis, std::chrono::steady_clock::time_point& programBegin) {
    if (sugeneruoti_failai.size() != studentu_kiekis.size()) {
        cout << "Klaida: Nepavyko generuoti failu. Neteisingi failu pavadinimai ar studentu skaiciu kiekis." << endl;
        return;
    }

    for (size_t i = 0; i < sugeneruoti_failai.size(); ++i) {
        string pavadinimas = sugeneruoti_failai[i];
        int kiekis = studentu_kiekis[i];
        pazymiuKiekis.push_back(RandomPazymiai());
        int kiekispaz = pazymiuKiekis[i];

        programBegin = std::chrono::steady_clock::now();
        std::chrono::steady_clock::time_point generateBegin = std::chrono::steady_clock::now();
        ofstream failas(pavadinimas);
        if (failas.is_open()) {

            failas << setw(25) << left << setprecision(2) << "Vardas";
            failas << setw(25) << left << setprecision(2) << "Pavarde";

            for (int j = 1; j <= kiekispaz; ++j) {
                failas << "ND" << j << "       ";
            }
            failas << "Egz.\n";

            for (int j = 0; j < kiekis; ++j) {
                string vardas = "Vardas" + to_string(j + 1);
                string pavarde = "Pavarde" + to_string(j + 1);

                failas << setw(25) << left << vardas;
                failas << setw(25) << left << pavarde;
                for (int k = 0; k < kiekispaz; ++k) {
                    failas << setw(10) << left << RandomPazymiai();
                }
                failas << RandomPazymiai() << "\n";
            }
            failas.close();
            cout << "Failas '" << pavadinimas << "' sekmingai sugeneruotas." << endl;

            std::chrono::steady_clock::time_point generateEnd = std::chrono::steady_clock::now();
            cout << "Failo generavimo laikas: " << fixed << setprecision(6) << std::chrono::duration_cast<std::chrono::duration<double>>(generateEnd - generateBegin).count() << " sekundes." << endl << endl;
        } else {
            cout << "Klaida: Nepavyko atidaryti failo '" << pavadinimas << "'." << endl;
        }
    }
}
