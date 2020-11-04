#include "../headers/main_header.h"
#include "../headers/struct_header.h"
#include "../headers/list_header.h"

void failasS(std::list<duomuo> &duom, int &VAR, int &PAV){
    std::list<duomuo>::iterator it;
    std::ifstream df (data);
    if (!df) throw "Duomenu failas nerastas";
    int i=0, eil=0;
    int n = ndSk(df);
    duom.emplace_back(duomuo());
    it = duom.begin();
    int a=0;
    while(true) {
        if (df.eof() == 1) break;
        eil++;
        df >> it->vard >> it->pav;
        if (it->vard.length() > VAR) VAR = it->vard.length();
        if (it->pav.length() > PAV) PAV = it->pav.length();
        int q, sum=0;
        for(int u=0;u<6;u++){
            df >> q;
            it->nd.emplace_back(q);
            sum = sum + q;
        }
        df >> it->egz;
        it->vidG =  0.4 * sum/n + 0.6 * it->egz;
        if(it->vidG>=5)a++;
        if (df.eof() == 1) break;
        i++;
        duom.emplace_back(duomuo());
        it++;
    }
};

void rusiuoti(std::list<duomuo>& duom) {
    duom.sort([](const duomuo &lhs, const duomuo &rhs) {
        return ( lhs.vidG > rhs.vidG );
    });
};

void skirstyti(std::list<duomuo>& duom, std::list<duomuo>& nuskriaustukai){
    rusiuoti(duom);
    std::list<duomuo>::iterator it;
    it = duom.begin();
    for(auto l : duom){
        if(l.vidG >= 5) it++;
    }
    nuskriaustukai.splice(nuskriaustukai.begin(), duom, it, duom.end() );
}

void spausdinti( std::list<duomuo> duom, std::list<duomuo> nuskriaustukai, int VAR, int PAV){
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
