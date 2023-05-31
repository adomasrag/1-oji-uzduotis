#include "mylib.h"
#include "functions.h"

void Testinimas(list<Studentas>& studentai, const vector<string>& sugeneruoti_failai, vector<int>& pazymiuKiekis) {
    for (size_t i = 0; i < sugeneruoti_failai.size(); ++i) {
        string pavadinimas = sugeneruoti_failai[i];
        int kiekis = studentu_kiekis[i];
        int kiekispaz = pazymiuKiekis[i];
        cout << "Failo '" << pavadinimas << "' testavimas" << endl;

        ifstream failas(pavadinimas);
        if (failas.is_open()) {
            std::chrono::steady_clock::time_point readBegin = std::chrono::steady_clock::now();

            IvestisIsFailo(studentai, pavadinimas);

            std::chrono::steady_clock::time_point readEnd = std::chrono::steady_clock::now();
            cout << "Duomenu nuskaitymo is failu i atitinkama konteineri laikas: " << fixed << setprecision(6) << std::chrono::duration_cast<std::chrono::duration<double>>(readEnd - readBegin).count() << " sekundes." << endl;

            std::chrono::steady_clock::time_point sortedBegin = std::chrono::steady_clock::now();
            list<Studentas> sortedStudentai = studentai;
            sortedStudentai.sort(PalygintiPavarde);
            std::chrono::steady_clock::time_point sortedEnd = std::chrono::steady_clock::now();
            cout << "Studentu rusiavimas didejimo tvarka konteineryje: " << fixed << setprecision(6) << std::chrono::duration_cast<std::chrono::duration<double>>(sortedEnd - sortedBegin).count() << " sekundes." << endl;

            RikiuotiStudentus(studentai, pavadinimas + "_vargsiukai.txt", pavadinimas + "_kietiakiai.txt", kiekispaz);

            failas.close();
        } else {
            cout << "Klaida: Nepavyko atidaryti failo '" << pavadinimas << "'." << endl;
        }
    }
}
