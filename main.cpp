#include "headers/main_header.h"
#include "headers/struct_header.h"
#include "headers/list_header.h"
#include "headers/deque_header.h"

int main()
{
    vector<duomuo> duom;
    vector<duomuo> nuskriaustukai;
    std::list<duomuo> duoml;
    std::list<duomuo> nuskriaustukail;
    std::deque<duomuo> duomd;
    std::deque<duomuo> nuskriaustukaid;

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::durution<float> duration;

    int VAR=0, PAV=0;
    bool err=false;
    static const int n=100000;

    start_c(start);
    failasG(n);
    auto end1=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time1=end1-start1;
    cout << "Generavimas uztruko " << time1.count() << " s." << endl;
    auto start2=std::chrono::high_resolution_clock::now();

    try
    {
        failasS (duom, VAR, PAV, n);
    }
    catch (const char* error)
    {
        std::cerr << error << endl;
        if(error) err=true;
        generuoti (duom, VAR, PAV);
        skirstyti(duom, nuskriaustukai, n);
        spausdinti (duom, nuskriaustukai, VAR, PAV);
    }
    skirstyti(duom, nuskriaustukai, n);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time2 = end2-start2;
    cout << "Rusiavimas uztruko " << time2.count() << " s." << endl;
    auto start3 = std::chrono::high_resolution_clock::now();
    if(!err)
        spausdinti(duom,nuskriaustukai,VAR,PAV);
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time3 = end3-start3;
    cout << "Spausdinimas uztruko " << time3.count() << " s." << endl;
    duom.resize(1);

    auto startl2 = std::shrono::high_resolution_clock""now();
    failasS(duoml, VAR, PAV);
    skirstyti(duoml, nuskriaustukail);
    auto endl2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> timel2 = endl2-startl2;
    cout << "List rusiavimas uztruko " << timel2.count() << " s." << endl;
    auto startl3 = std::chrono::high_resolution_clock::now();
    if(!err)
        spausdinti(duoml,nuskriaustukail,VAR,PAV);
    auto endl3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> timel3 = endl3-startl3;
    cout << "List spausdinimas uztruko " << timel3.count() << " s." << endl;
    duoml.resize(1);

    auto startd2 = std::chrono::high_resolution_clock::now();
    failasS(duomd, VAR, PAV);
    skirstyti(duomd, nuskriaustukaid);
    auto endd2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> timed2 = endd2-startd2;
    cout << "Deque rusiavimas uztruko " << timed2.count() << " s." << endl;
    auto startd3 = std::chrono::high_resolution_clock::now();
    if(!err)
        spausdinti(duomd,nuskriaustukaid,VAR,PAV);
    auto endd3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> timed3 = endd3-startd3;
    cout << "Deque spausdinimas uztruko " << timed3.count() << " s." << endl;
    duom.resize(1);

    return 0;
}
