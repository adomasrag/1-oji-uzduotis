#include "mylib.h"
#include "functions.h"

void GeneruotiFailus(const vector<string>& sugeneruoti_failai, const vector<int>& studentu_kiekis) {
    if (sugeneruoti_failai.size() != studentu_kiekis.size()) {
        cout << "Klaida: Nepavyko generuoti failu. Neteisingi failu pavadinimai ar studentu skaiciu kiekis." << endl;
        return;
    }

    for (size_t i = 0; i < sugeneruoti_failai.size(); ++i) {
        string pavadinimas = sugeneruoti_failai[i];
        int kiekis = studentu_kiekis[i];

        ofstream failas(pavadinimas);
        if (failas.is_open()) {
            int tempPazKiekis = RandomPazymiai();
            failas << setw(25) << left << setprecision(2) << "Vardas";
            failas << setw(25) << left << setprecision(2) << "Pavarde";

            for (int j = 1; j <= tempPazKiekis; ++j) {
                failas << "ND" << j << "       ";
            }
            failas << "Egz.\n";

            for (int j = 0; j < kiekis; ++j) {
                string vardas = "Vardas" + to_string(j + 1);
                string pavarde = "Pavarde" + to_string(j + 1);

                failas << setw(25) << left << vardas;
                failas << setw(25) << left << pavarde;
                for (int k = 0; k < tempPazKiekis; ++k) {
                    failas << setw(10) << left << RandomPazymiai();
                }
                failas << RandomPazymiai() << "\n";
            }

            failas.close();
            cout << "Failas '" << pavadinimas << "' sekmingai sugeneruotas." << endl;

        } else {
            cout << "Klaida: Nepavyko atidaryti failo '" << pavadinimas << "'." << endl;
        }
    }
}
