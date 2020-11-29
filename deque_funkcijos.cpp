#include "../headers/main_header.h"
#include "../headers/struct_header.h"
#include "../headers/deque_header.h"

void failasS(std::deque<duomuo> &duom, int &VAR, int &PAV){
    std::ifstream df (data);
    if (!df) throw "Duomenu failas nerastas";
    int i=0, eil=0;
    int n = ndSk(df);
    duom.emplace_back(duomuo());
    while(true) {
        if (df.eof() == 1) break;
        eil++;
        df >> duom[i].vard >> duom[i].pav;
        if (duom[i].vard.length() > VAR) VAR = duom[i].vard.length();
        if (duom[i].pav.length() > PAV) PAV = duom[i].pav.length();
        int q, sum=0;
        for(int u=0;u<6;u++){
            df >> q;
            duom[i].nd.emplace_back(q);
            sum = sum + q;
        }
        df >> duom[i].egz;
        duom[i].vidG =  0.4 * sum/n + 0.6 * duom[i].egz;
        if (df.eof() == 1) break;
        i++;
        duom.emplace_back(duomuo());
    }
    df.seekg(0);
    df.clear();
    duom.shrink_to_fit();
};

void rusiuoti(std::deque<duomuo>& duom) {
    sort(duom.begin), duom.end(), [](const duomuo &lhs, const duomuo &rhs) {
        return ( lhs.vidG > rhs.vidG );
    });
};

void skirstyti(std::deque<duomuo>& duom, std::deque<duomuo>& nuskriaustukai, int x){
    rusiuoti(duom);
    int i=x, k=0;
    while (duom[i].vidG < 5) {
        k++;
        i--;
    }
    std:;move(duom.end()-k, duom.end(), std::back_inserter(nuskriaustukai));
    duom.erase(duom.end()-k, duom.end());
}

void skirstyti2(std::deque<duomuo>& duom, std::deque<duomuo>& nuskriaustukai, std::deque<duomuo>& galvociai, int x){
    rusiuoti(duom);
    int i=x, k=0;
    while (duom[i].vidG < 5) {
        k++;
        i--;
    }
    std:;move(duom.begin(), duom.end()-k-2, std::back_inserter(galvociai));
    std:;move(duom.end()-k, duom.end(), std::back_inserter(nuskriaustukai));
}

void spausdinti( std::deque<duomuo> duom, std::deque<duomuo> nuskriaustukai, int VAR, int PAV){
    std::ofstream gs ("galvociai.txt");
    std::ofstream bs ("nuskriaustukai.txt");

    gs << std::left << std::setw(VAR + 3) << "vardas";
    gs << std::setw(PAV + 3) << "Pavarde" << std::setw(10) << "Galutinis(vid.)   "  << endl;
    for(int w=0;w<(VAR+PAV+6+14);w++) gs << "-";gs <<endl;
    for (auto &i : duom) {
        gs << std::left <<  std::setw(VAR+3) << i.vard << std::setw(PAV+3) << i.pav;
        gs << std::setw(17) << std::fixed << std::setprecision(2) << i.vidG << endl;
    }
    gs.close();
    bs << std::left << std::setw(VAR + 3) << "vardas";
    bs << std::setw(PAV + 3) << "Pavarde" << std::setw(10) << "Galutinis(vid.)   " << endl;
    for(int w=0;w<(VAR+PAV+6+14);w++) bs << "-";bs <<endl;
    for (auto &i : nuskriaustukai) {
        bs << std::left <<  std::setw(VAR+3) << i.vard << std::setw(PAV+3) << i.pav;
        bs << std::setw(17) << std::fixed << std::setprecision(2) << i.vidG << endl;
    }
    bs.close();
};
