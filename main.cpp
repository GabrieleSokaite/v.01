#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;
using std:: cout;
using std:: cin;
using std:: endl;
using std:: vector;
using std:: string;
using std::ifstream;

struct duomuo {
    string vard, pav;
    int paz, egz, pas, gen, skc;
    float gp = 0;
};

bool ar(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
    return true;
}

int main()
{
    duomuo Eil; duomuo Eil_mas[5];

    cout << "Pasirinkite kaip norite ivesti duomenis (1 - irasyti, 2 - skaityti is failo): \n";
    cin >> Eil.pas;

    if (Eil.pas == 1) /*duomenys irasomi ranka*/
    {
        cout << "Ar norite generuoti skaicius? (Pasirinkimai: 1 atitinka taip, 2 atitinka ne): \n";
        cin >> Eil.gen;
        if (Eil.gen == 1) /*generuoja skaicius*/
            {
                cout << "Iveskite kiek skaiciu generuoti norite: \n";
                srand((unsigned) time(0));
                int random, n;
                cin >> n;
                for (int index = 0; index < n; index++)
                {
                    random = (rand() % 10) + 1;
                    cout << random << endl;
                }
        cout << "Iveskite varda, pavarde: \n";
        cin >> Eil.vard >> Eil.pav;
        if ((ar(Eil.vard)) || (ar(Eil.pav)))
            cout << "Netinkamai ivestas vardas ar pavarde.\n";
        else
            cout << "Ivestas tinkamas vardas ir pavarde.\n";
           }
        else if (Eil.gen == 2) /*skaiciai ivedami ranka*/
            {
                cout << "Iveskite egzamino pazymi. Iveskite namu darbu pazymius (kai ivedete visus parasykite 000): \n";
                cin >> Eil.egz;
                if (Eil.paz != 000) cin >> Eil.paz;
            }
        else
            cout << "Negalimas toks ivedimas.\n" <<endl;
    }
    else if (Eil.pas == 2) /*duomenys nuskaitomi is failo*/
    {
        ifstream indata; /*indata = cin*/
        int num; /*variable for input value*/
        indata.open("kursiokai.txt");
        if(!indata)
        {
            cerr << "Error: failo nepavyko atidaryti" << endl;
            exit(1);
        }
        indata >> num;
        while ( !indata.eof() )
        {
            cout << "Skaitomas failas toliau " << num << endl;
            indata >> num;
            char VAR[10];
            char PAV[15];
            indata >> VAR;
            indata >> PAV;
            cout << VAR << endl;
            cout << PAV << endl;
        }
        indata.close();
        cout << "Perskaitytas failas" << endl;


    }
    else
        cout << "Nepasirinkote kaip norite nuskaityti duomenis.\n";
    return 0;
}
