#include "main_header.h"
#include "struct_header.h"

int main()
{
    vector<duomuo> duom;
    vector<duomuo> nuskriaustukai;

    int VAR=0, PAV=0;
    bool err=false;
    static const int n=1000;

    auto start1=std::chrono::high_resolution_clock::now();
    generuotiF(n);
    auto end1=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time1=end1-start1;
    cout << "Generavimas uztruko " << time1.count() << " s." << endl;
    auto start2=std::chrono::high_resolution_clock::now();

    try
    {
        failas (duom, VAR, PAV, n);
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
    return 0;
}
