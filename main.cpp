#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;
using std:: cout;
using std:: cin;
using std:: string;
using std:: vector;
using std:: endl;


struct duomuo {
    string vard, pav;
    int paz[10], egz;
    float gp = 0;
};

int main()
{
    duomuo Eil; duomuo Eil_mas[5];

    cout << "Iveskite varda, pavarde ir 5 namu darbu pazymius duomenis: \n";
    cin >> Eil.vard >> Eil.pav;

    for (int i=0; i<5; i++) {
        cin >> Eil.paz[i];
        Eil.gp = Eil.gp + (float) Eil.paz[i];
    }

    int max;
    cout << "Iveskite max galima egzamino bala: \n";
    cin >> max;
    if (max > 0 && max <= 10)
    {
        srand(time(0));
        Eil.egz = (rand () % max) + 1;
    cout << Eil.egz << endl;
    }
    else
        cout << "Nera tokio pazymio \n";
        system ("pause");

    if (Eil.egz > 0 && Eil.egz <= 10)
    {
        Eil.gp = Eil.gp / 5.0;
        Eil.gp = Eil.gp * 0.4 + 0.6 * Eil.egz;
    }
    else
        Eil.gp = Eil.gp / 5.0 * 0.4;

    cout << "Vardas" << "   " << "Pavarde" << "     " << "Galutinis pazymys" << endl;
    cout << Eil.vard << "   " << Eil.pav;
    cout << " " << Eil.gp << endl;

    char a;
    cin >> a;

    return 0;
}
