#include "mylib.h"
#include "functions.h"


void RikiuotiStudentus1STRAT(vector<Studentas>& studentai, const string& vargsiukaiFailas, const string& kietiakiaiFailas, int pazymiuKiekis) {
    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakiai;

    std::chrono::steady_clock::time_point sortBegin = std::chrono::steady_clock::now();

    for (const auto& studentas : studentai) {
        double galutinis = Galutinis(studentas.egzaminas, Vidurkis(studentas.pazymiai), false);
        if (galutinis < 5.0) {
            vargsiukai.push_back(studentas);
        } else {
            kietiakiai.push_back(studentas);
        }
    }

    std::chrono::steady_clock::time_point sortEnd = std::chrono::steady_clock::now();
    cout << "Failo rikiavimo i dvi grupes 1 STRATEGIJA laikas: " << fixed << setprecision(6) << std::chrono::duration_cast<std::chrono::duration<double>>(sortEnd - sortBegin).count() << " sekundes." << endl;

    IsvedimasIFaila(vargsiukaiFailas, kietiakiaiFailas, vargsiukai, kietiakiai, pazymiuKiekis);
}

void RikiuotiStudentus2STRAT(vector<Studentas>& studentai, const string& vargsiukaiFailas, const string& kietiakiaiFailas, int pazymiuKiekis) {

    std::chrono::steady_clock::time_point sortBegin = std::chrono::steady_clock::now();

    vector<Studentas> vargsiukai;
    auto is_vargsiukas = [](const auto& studentas) {
    double galutinis = Galutinis(studentas.egzaminas, Vidurkis(studentas.pazymiai), false);
    return galutinis < 5.0;
    };

    auto it = std::stable_partition(studentai.begin(), studentai.end(), is_vargsiukas);
    std::copy(studentai.begin(), it, std::back_inserter(vargsiukai));
    studentai.erase(studentai.begin(), it);




    std::chrono::steady_clock::time_point sortEnd = std::chrono::steady_clock::now();
    cout << "Failo rikiavimo i dvi grupes 2 STRATEGIJA laikas: " << fixed << setprecision(6) << std::chrono::duration_cast<std::chrono::duration<double>>(sortEnd - sortBegin).count() << " sekundes." << endl << endl;

    IsvedimasIFaila(vargsiukaiFailas, kietiakiaiFailas, vargsiukai, studentai, pazymiuKiekis);
}
