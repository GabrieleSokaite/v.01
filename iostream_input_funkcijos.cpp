#include "../headers/main_header.h"
#include "../headers/struct_header.h"

void vardT(vector<duomuo>&duom, int y)
{
    cout << "Iveskite varda: \n";
    cin >> duom[y].vard;
    while (!netinka(duom[y].vard))
        {
            cout << "Vardas netinka. Ivesti kita: \n";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> duom[y].vard;
        }
}

void pavT(vector<duomuo>&duom, int y)
{
    cout << "Iveskite pavarde: \n";
    cin >> duom[y].pav;
    while (!netinka(duom[y].pav))
        {
            cout << "Pavarde netinka. Ivesti kita: \n";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> duom[y].pav;
        }
}

void tikrinimas (int &f)
{
    while (f!=0 && f!=1)
    {
        cout << "Ivestas netinkamas simbolis. \n";
        cin >> f;
    }
}

void egzI(vector<duomuo>& duom, int y, int f){
    if (f==1)
        {
            while(true)
            {
                int eg = 0;
                cout << "Iveskite egzamino rezultata: \n";
                cin >> eg;
                if( !cin.fail() && eg>= 0 && eg <= 10)
                {
                    if(eg!=0)
                    {
                        duom[y].egz = eg;
                        break;
                    }
                }
                else
                    {
                        cout << "Netinkamas pazymys. \n";
                        cin.clear();
                        cin.ignore(256, '\n');
                        continue;
                    }
            }
        }
        else if(f==0)
            {
                genEG(duom,y);
            }
}

void ndI(vector<duomuo>& duom, int y, int f){
    int k=0, q=1;
    if (f==1)
        {
            cout << "Ivedus nd rezultatus spausti 0. \n";
            while(q!=0)
            {
                cout << "Iveskite nd pazymius: \n";
                cin >> q;
                if( !cin.fail() && q>= 0 && q <= 10)
                {
                    if(q!=0)
                    {
                        duom[y].nd.push_back(q);
                        k++;
                    }
                }
                else
                    {
                        cout << "Netinkamas nd pazymys. \n";
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        q=1;
                        continue;
                    }
            }
            GP(duom,k,y);
        }
        else if(f==0)
        {
            cout << "Iveskite kiek nd pazymiu norite generuoti: \n";
            int n=0;
            while(true)
            {
                cin >> n;
                if (!cin.fail() && n!=0)
                    {
                        break;
                    }
                else
                    {
                        cout << "Ivestis bloga. Ivesti skaiciu: \n";
                        cin.clear();
                        cin.ignore(256, '\n');
                        continue;
                    }
           }
           genND(duom,n,y);
           GP(duom,n,y);
        }
}

void generuoti(vector<duomuo>&duom, int &VAR, int &PAV)
{
    int i=0, pr=0;
    duom.reserve(100);
    while(true)
    {
        cout << "Norint prideti varda ir pavarde spausti 1, o uzbaigimui 0: \n";
        cin >> pr;
        if (pr == 1)
        {
            duom.emplace_back(duomuo());
            int f;
            vardT(duom,i);
            pavT(duom,i);
            if(duom[i].vard.length()>VAR) VAR=duom[i].vard.length();
            if(duom[i].pav.length()>PAV) PAV=duom[i].pav.length();
            cout<< "Ivesti egzamino pazymi ranka spausti 1, generavimui 0: \n";
            cin >> f;
            vardT(f);
            egzI(duom,i,f);
            cout << "Ivesti nd pazymius ranka spausti 1, generavimui 0: \n";
            cin >> f;
            tikrinimas(f);
            ndI(duom,i,f);
            i++;
        }
        else break;
    }
    duom.shrink_to_fit();
};
