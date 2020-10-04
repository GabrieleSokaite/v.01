#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct duomuo
{
    string vard, pav;
    int egz=0, dyd=1, pask=0;
    double vidG=0, medG=0;
    double *nd=new double[dyd];

    void sort()
    {
        int a=pask;
        double b;
        bool swap;
        while(a>1)
        {
            swap=false;
            for (int i=0; i<a-1; i++)
            {
                if (nd[i]>nd[i+1])
                {
                    swap=true;
                    b=nd[i];
                    nd[i]=nd[i+1];
                    nd[i+1]=b;
                }
            }
            if (!swap)
                break;
            a--;
        }
    }

    void didinti()
    {
        dyd *= 2;
        auto *newArr = new double [dyd];
        for (int i=0; i<pask; i++)
            newArr[i]=nd[i];
        delete [] nd;
        nd = newArr;
    }
};

const int n=2;

double mediana(vector<duomuo>& duom, int x, int y)
{
    double med;
    duom[x].sort();
    if (y%2==0)
        med=(duom[x].nd[y/2-1]+duom[x].nd[y/2])/2.0;
    else
        med=duom[x].nd[y/2];
    return med;
};

bool netinka(const string a)
{
    char c;
    for (int i=0; i<a.length(); i++)
    {
        c=a.at(i);
        if(!((c>= 'a' && c <= 'z') || (c>='A' && c<='Z')))
            return false;
    }
};

void generuoti(vector<duomuo>&duom)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> random(1,10);
    double vid;
    int i=0, pr=0;
    while(true)
    {
        cout << "Norint prideti varda ir pavarde spausti 1: \n";
        cin >> pr;
        if (pr == 1)
        {
            duom.push_back(duomuo());
            double sum=0;
            int k=0, q=1, f;
            cout << "Iveskite varda: \n";
            cin >> duom[i].vard;
            while (!netinka(duom[i].vard))
            {
                cout << "Vardas netinka. Ivesti kita: \n";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> duom[i].vard;
            }

            cout << "Iveskite pavarde: \n";
            cin >> duom[i].pav;
            while (!netinka(duom[i].pav))
            {
                cout << "Pavarde netinka. Ivesti kita: \n";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> duom[i].pav;
            }
            cout << "Ivesti egzamino pazymi ranka spausti 1. Generuoti atsitiktinai spausti 0. \n";
            cin >> f;
            while (f!=0 && f!=1)
            {
                cout << "Neteisingai ivesta, bandyti dar karta. \n";
                cin >> f;
            }
            if (f==1)
            {
                while(true)
                {
                    int eg=0;
                    cout << "Ivesti egzamino pazymi: \n";
                    cin >> eg;
                    if (eg>=0 && eg <=10)
                    {
                        if(q!=0)
                        {
                            duom[i].egz=eg;
                            break;
                        }
                    }
                    else
                    {
                        cout << "Netinka pazymus, ivesti dar karta. \n";
                        continue;
                    }
                }
            }
            else if (f==0)
            {
                duom[i].egz=random(gen);
            }
            cout << "Ivesti nd ranka spausti 1. Generuoti nd spausti 0. \n";
            cin >> f;
            while (f!=0 && f!=1)
            {
                cout << "Ivesta neteisingai. Dar karta bandyti. \n";
                cin >> f;
            }
            if (f==1)
            {
                cout << "Iveskite nd. Baigus ivedineti spausti 0 \n";
                while (q!=0)
                {
                    cput << "Ivesti namu darbu pazymi: \n";
                    cin >> q;
                    if (q>=0 && q<=10)
                    {
                        if (q!=0)
                        {
                            k++;
                            if (duom[i].pask + 1 == duom[i].dyd) duom[i].didinti();
                            duom[i].nd[duom[i].pask]=q;
                            duom[i].pask++;
                        }
                    }
                    else
                    {
                        cout << "Netinkamas pazymys, ivesti kita. \n";
                        continue;
                    }
                }
                for (int z=0; z<k; z++)
                {
                    sum+= duom[i].nd[z];
                }
                vid = sum/k;
                duom[i].vidG=0.4*vid+0.6*duom[i].egz;
                duom[i].medG=0.4*mediana(duom, i, k) + 0.6 * duom[i].egz;
            }
            else if (f==0)
            {
                cout << "Ivesti kiek nd pazymiu generuosite: \n";
                cin >> duom[i].dyd;
                for (int j=0; j<duom[i].dyd; j++)
                {
                    duom[i].nd[j]=random(gen);
                }
                for (int z=0; z<duom[i].dyd; z++)
                {
                    sum += duom[i].nd[z];
                }
                vid = sum/ duom[i].dyd;
                duom[i].vidG = 0.4 * vid + 0.6 * duom[i].egz;
                duom[i].medG=0.4*mediana(duom, i, duom[i].dyd) + 0.6 * duom[i].egz;
            }
            i++;
        }
        else break;
    }
};

void spausdinti (vector<duomuo>duom)
{
    cout <<"Vardas     Pavarde             Galutinis(VID)    Galutinis(MED)" <<endl;
    for (int i=0; i<duom.size(); i++)
    {
        cout << std::left <<  std::setw(11) << duom[i].vard << std::setw(19) << duom[i].pav << "  ";
        cout << std::setw(6) << std::fixed << std::setprecision(2) << duom[i].vidG << "             ";
        cout << std::setw(12) << std::fixed << std::setprecision(2) << duom[i].medG << endl;
    }
};

int main()
{
    vector<duomuo> duom;
    generuoti(duom);
    spausdinti(duom);
    return 0;
};
