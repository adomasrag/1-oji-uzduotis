#include "mylib.h"
#include "functions.h"

void Testinimas(deque<Studentas>& studentai, const vector<string>& sugeneruoti_failai) {
    for (size_t i = 0; i < sugeneruoti_failai.size(); ++i) {
        string pavadinimas = sugeneruoti_failai[i];
        int kiekis = studentu_kiekis[i];
        cout << "Failo '" << pavadinimas << "' testavimas" << endl;

        ifstream failas(pavadinimas);
        if (failas.is_open()) {
            std::chrono::steady_clock::time_point readBegin = std::chrono::steady_clock::now();

            IvestisIsFailo(studentai, pavadinimas);

            std::chrono::steady_clock::time_point readEnd = std::chrono::steady_clock::now();
            cout << "Duomenu nuskaitymo is failu i atitinkama konteineri laikas: " << fixed << setprecision(6) << std::chrono::duration_cast<std::chrono::duration<double>>(readEnd - readBegin).count() << " sekundes." << endl;

            std::chrono::steady_clock::time_point sortedBegin = std::chrono::steady_clock::now();
            sort(studentai.begin(), studentai.end(), PalygintiVarda);
            std::chrono::steady_clock::time_point sortedEnd = std::chrono::steady_clock::now();
            cout << "Studentu rusiavimas didejimo tvarka konteineryje: " << fixed << setprecision(6) << std::chrono::duration_cast<std::chrono::duration<double>>(sortedEnd - sortedBegin).count() << " sekundes." << endl;

            Studentas pirmaeile = studentai.front();
            int kiekispaz = pirmaeile.pazymiai.size();

            RikiuotiStudentus1STRAT(studentai, pavadinimas + "_1stratVARG.txt", pavadinimas + "_1stratKIET.txt", kiekispaz);
            RikiuotiStudentus2STRAT(studentai, pavadinimas + "_2stratVARG.txt", pavadinimas + "_2stratKIET.txt", kiekispaz);

            studentai.clear();
            failas.close();
        } else {
            cout << "Klaida: Nepavyko atidaryti failo '" << pavadinimas << "'." << endl;
        }
    }
}
