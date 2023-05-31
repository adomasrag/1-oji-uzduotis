#include "mylib.h"
#include "functions.h"

int main() {
    deque<Studentas> studentai;
    string stop = "STOP";

    srand(static_cast<unsigned>(time(nullptr)));

    cout << "Pasirinkite ivedimo buda:\n"
              << "1. Rankinis ivedimas\n"
              << "2. Atsitiktinis ivedimas\n"
              << "3. Nuskaitymas is failo\n"
              << "4. Generuoti failus\n"
              << "Pasirinkimas: ";
    int pasirinkimas;
    cin >> pasirinkimas;
    cin.ignore();

    try {
        if (pasirinkimas == 1) {
            IvestisRanka(studentai, stop);
        } else if (pasirinkimas == 2) {
            IvestisAtsitiktinai(studentai);
        } else if (pasirinkimas == 3) {
            string failoPavadinimas;
            while (true) {
                cout << "Iveskite failo pavadinima: ";
                getline(cin, failoPavadinimas);

                if (failoPavadinimas.size() >= 4 && failoPavadinimas.substr(failoPavadinimas.size() - 4) == ".txt") {
                    break;
                }
                cout << "Klaida: Failo pavadinimas turi baigtis \".txt\".\n";
            }
            IvestisIsFailo(studentai, failoPavadinimas);
        } else if (pasirinkimas == 4) {
            vector<int> pazymiuKiekis;
            GeneruotiFailus(sugeneruoti_failai, studentu_kiekis, pazymiuKiekis);
            Testinimas(studentai, sugeneruoti_failai, pazymiuKiekis);
        } else {
            throw runtime_error("Netinkamas pasirinkimas. Paleiskite programa is naujo.");
        }
    } catch (const exception& e) {
        cout << "Klaida: " << e.what() << endl;
        return 1;
    }
    if(pasirinkimas != 4) {
        cout << "Pasirinkite skaiciavimo buda:\n"
                  << "1. Naudojant vidurki\n"
                  << "2. Naudojant mediana\n"
                  << "Pasirinkimas: ";
        pasirinkimas = 0;
        cin >> pasirinkimas;

        try {
            if (pasirinkimas == 1) {
                Isvedimas(studentai, false);
            } else if (pasirinkimas == 2) {
                Isvedimas(studentai, true);
            } else {
                throw runtime_error("Netinkamas pasirinkimas. Paleiskite programa is naujo.");
            }
        } catch (const exception& e) {
            cout << "Klaida: " << e.what() << endl;
            return 1;
        }
    }
    return 0;
}
