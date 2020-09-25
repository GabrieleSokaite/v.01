#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
using std:: cout;
using std:: cin;
using std:: endl;

struct duomuo {
    string vard, pav;
    int paz, egz, gen, skc;
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
    }
    else if (Eil.gen == 2) /*skaiciai ivedami ranka*/
    {
        cout << "Iveskite egzamino pazymi. Iveskite namu darbu pazymius (kai ivedete visus parasykite 000): \n";
        cin >> Eil.egz;
        if (Eil.paz != 000) cin >> Eil.paz;
    }
    else
        cout << "Negalimas toks ivedimas.\n" <<endl;
    cout << "Iveskite ka norite skaiciuoti. Variantai: 1 atitinka vidurki, 2 atitinka mediana): \n";
    cin >> Eil.skc;
    if (Eil.skc == 1) /*skaiciuosim vidurki*/
    {

    }
    else if (Eil.skc == 2) /*skaiciuosim mediana*/
    {

    }
    else
        cout << "Nepasirinkote ka norite skaiciuoti.\n";
    /*vector konteineris*/
    cout << "Iveskite varda, pavarde: \n";
    cin >> Eil.vard >> Eil.pav;
    if (ar(Eil.vard))
        cout << "Netinkamas vardas\n";
    else
        cout << Eil.vard << "   " << Eil.pav << endl;
    if (ar(Eil.pav))
        cout << "Netinkama pavarde \n";
    else
        cout << Eil.vard << "   " << Eil.pav;

    char a;
    cin >> a;

    return 0;
}
