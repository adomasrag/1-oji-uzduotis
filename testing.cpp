#include "mylib.h"
#include "functions.h"

void Testinimas(vector<Studentas>& studentai, const vector<string>& sugeneruoti_failai) {
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
            vector<Studentas> sortedStudentai = studentai;
            sort(sortedStudentai.begin(), sortedStudentai.end(), PalygintiVarda);

            std::chrono::steady_clock::time_point sortedEnd = std::chrono::steady_clock::now();
            cout << "Studentu rusiavimas didejimo tvarka konteineryje: " << fixed << setprecision(6) << std::chrono::duration_cast<std::chrono::duration<double>>(sortedEnd - sortedBegin).count() << " sekundes." << endl;

            Studentas studentastemp = sortedStudentai[1];
            int kiekispaz = studentastemp.pazymiai.size();

            RikiuotiStudentus1STRAT(sortedStudentai, pavadinimas + "_1stratVARG.txt", pavadinimas + "_1stratKIET.txt", kiekispaz);
            RikiuotiStudentus2STRAT(sortedStudentai, pavadinimas + "_2stratVARG.txt", pavadinimas + "_2stratKIET.txt", kiekispaz);

            studentai.clear();
            failas.close();
        } else {
            cout << "Klaida: Nepavyko atidaryti failo '" << pavadinimas << "'." << endl;
        }
    }
}
