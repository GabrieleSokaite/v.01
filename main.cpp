#include "headers/main_header.h"
#include "headers/struct_header.h"
#include "headers/list_header.h"
#include "headers/deque_header.h"

int main()
{
    std::vector<duomuo> duom;
    std::vector<duomuo> nuskriaustukai;
    std::vector<duomuo> galvociai;
    std::list<duomuo> duoml;
    std::list<duomuo> nuskriaustukail;
    std::list<duomuo> galvociail;
    std::deque<duomuo> duomd;
    std::deque<duomuo> nuskriaustukaid;
    std::deque<duomuo> galvociaid;

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::durution<float> duration;

    int VAR=0, PAV=0;
    bool err=false;
    static const int n=100;

    start_c(start);
    failasG(n);
    end_c(end);
    std::chrono::duration<double> time1=end-start;
    cout << "Generavimas uztruko " << time1.count() << " s." << endl;
    failasS(duom, VAR, PAV, n);
    start_c(start);
    skirstyti(duom, nuskriaustukai, n);
    end_c(end);
C:\Users\Gabriele\Desktop\Objektinis Programavimas\v1.0\funkcijos.cpp    std::chrono::duration<double> time2 = end-start;
    cout << "Vector rusiavimas uztruko(2strategija) " << time2.count() << " s." << endl;
    start_c(start);
    spausdinti(duom,nuskriaustukai,VAR,PAV);
    end_c(end);
    std::chrono::duration<double> time3 = end-start;
    cout << "Vector spausdinimas uztruko(2strategija) " << time3.count() << " s." << endl;
    duom.resize(1);
    nuskriaustukai.resize(1);

    failasS(duoml, VAR, PAV);
    start_c(start);
    skirstyti(duoml, nuskriaustukail);
    end_c(end);
    std::chrono::duration<double> timel2 = end-start;
    cout << "List rusiavimas uztruko(2strategija) " << timel2.count() << " s." << endl;
    start_c(start);
    spausdinti(duoml,nuskriaustukail,VAR,PAV);
    end_c(end);
    std::chrono::duration<double> timel3 = end-start;
    cout << "List spausdinimas uztruko(2strategija) " << timel3.count() << " s." << endl;
    duoml.resize(1);
    nuskriaustukail.resize(1);

    failasS(duomd, VAR, PAV);
    start_c(start);
    skirstyti(duomd, nuskriaustukaid, n);
    end_c(end);
    std::chrono::duration<double> timed2 = end-start;
    cout << "Deque rusiavimas uztruko (2strategija) " << timed2.count() << " s." << endl;
    start_c(start);
    spausdinti(duomd,nuskriaustukaid,VAR,PAV);
    end_c(end);
    std::chrono::duration<double> timed3 = end-start;
    cout << "Deque spausdinimas uztruko (2strategija) " << timed3.count() << " s." << endl;
    duom.resize(1);
    nuskriaustukaid.resize(1);


    failasS(duom,VAR,PAV,n);
    start_c(start);
    skirstyti2(duom,nuskriaustukai,galvociai,n);
    end_c(end);
    std::chrono::duration<double> time22 = end-start;
    cout << "Vector rusiavimas uztruko(1 strategija) " << time22.count() << "s." << endl;
    start_c(start);
    spausdinti(galvociai,nuskriaustukai,VAR,PAV);
    end_c(end);
    std::chrono::duration<double> time33 = end-start;
    cout << "Vector isvedimas uztruko(1 strategija) " << time33.count() << "s." << endl << endl;
    duom.resize(1);

    failasS(duoml,VAR,PAV);
    start_c(start);
    skirstyti2(duoml,nuskriaustukail,galvociail);
    end_c(end);
    std::chrono::duration<double> timel22 = end-start;
    cout << "List rusiavimas uztruko(1 strategija) " << timel22.count() << "s." << endl;
    start_c(start);
    spausdinti(galvociail,nuskriaustukail,VAR,PAV);
    end_c(end);
    std::chrono::duration<double> timel33 = end-start;
    cout << "List isvedimas uztruko(1 strategija) " << timel33.count() << "s." << endl << endl;
    duoml.resize(1);

    failasS(duomd,VAR,PAV);
    start_c(start);
    skirstyti2(duomd,nuskriaustukaid,galvociaid,n);
    end_c(end);
    std::chrono::duration<double> timed22 = end-start;
    cout << "Deque rusiavimas uztruko(1 strategija) " << timed22.count() << "s." << endl;
    start_c(start);
    spausdinti(galvociaid,nuskriaustukaid,VAR,PAV);
    end_c(end);
    std::chrono::duration<double> timed33 = end-start;
    cout << "Deque isvedimas uztruko(1 strategija) " << timed33.count() << "s." << endl << endl;
    duomd.resize(1);

    failasS(duom,VAR,PAV, n);
    start_c(start);
    nuskriaustukai = nuskriaustukai(duom);
    end_c(end);
    std::chrono::duration<double> timev = end-start;
    cout << "Vector rusiavimas uztruko(stable_partition) " << timev.count() << "s." << endl;
    spausdinti(galvociai,nuskriaustukai,VAR,PAV);
    duom.resize(1);

    return 0;
}
