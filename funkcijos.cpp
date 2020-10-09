#include "main_header.h"
#include "struct_header.h"

double mediana(vector<duomuo> duom, int x, int y)
{
    double med;
    sort(duom[y].nd.begin(), duom[y].nd.end());
    if (y%2==0)
        med=(duom[y].nd[x/2-1]+duom[y].nd[x/2])/2.0;
    else
        med=duom[y].nd[x/2];
    return med;
};

bool netinka(const string a)
{
    for (char i : a)
    {
        if(!((i>= 'a' && i <= 'z') || (i>='A' && i<='Z')))
            return false;
    }
    return true;
}

void genND(vector<duomuo>&duom, int x, int y)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> random(1,10);
    int a;
    for (int j=0; j<x; j++)
    {
        a=random(gen);
        duom[y].nd.push_back(a);
    }
}

void genEG(vector<duomuo>&duom, int y)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> random(1,10);
    int a;
    duom[y].egz=random(gen);
}

double ndSum(vector<duomuo> duom, int x, int y)
{
    double sum=0;
    for (int z=0; z<x; z++)
    {
        sum += duom[y].nd[z];
    }
    return sum;
}

void GP(vector<duomuo>& duom, int x, int y)
{
    duom[y].vidG=0.4*ndSum(duom,x,y)/x+0.6*duom[y].egz;
    duom[y].medG=0.4*mediana(duom,x,y) + 0.6 * duom[y].egz;
}

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

void stringT (std::ifstream &df, string a, bool &fail, int eil)
{
    if(!netinka(std::move(a)))
       {
            df.clear();
            df.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            fail=true;
            cout << "Netinkamas vardas ir pavarde " << eil << "eiluteje. Duomenys nenuskaityti. \n";
       }
}

void nd(std::ifstream &df,vector<duomuo> &duom, int x, int y, bool &fail, int eil){
    int q=0;
    for(int j=0; j<x; j++){
        df >> q;
        if(!df.fail() && q > 0 && q <= 10){
            duom[y].nd.push_back(q);
        }
        else {
            df.clear();
            df.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            fail = true;
            cout << "Ivestas netinkamas nd pazymys " << eil << " eiluteje. Duomenys nenuskaityti." << endl;
            break;
        }
    }
}

void egz(std::ifstream &df,std::vector<duomuo> &duom, int y, bool &fail, int eil){
    int q=0;
    df >> q;
    if(!df.fail() && q > 0 && q <= 10){
        duom[y].egz = q;
    }
    else {
        df.clear();
        df.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        fail = true;
        cout << "Ivestas netinkamas egzamino pazymys " << eil << " eiluteje. Duomenys nenuskaityti." << endl;
    }
}

int ndSk(std::ifstream &df){
    size_t n=0;
    string str = "ND";
    string p_eil;
    getline(df,p_eil);
    string::size_type pos = 0;
    while((pos=p_eil.find(str,pos)) != string::npos){
        n++;
        pos+=str.size();
    }
    return n;
}

void failas(vector<duomuo> &duom, int &VAR, int &PAV){
    std::ifstream df (data);
    duom.reserve(100);
    int i=0, eil=0, n = ndSk(df);
    duom.emplace_back(duomuo());
    while(true){
        bool fail = false;
        if(df.eof()==1) break;
        eil++;
        df >> duom[i].vard;
        stringT(df, duom[i].vard,fail,eil);
        if(fail)continue;
        df >> duom[i].pav;
        stringT(df, duom[i].pav,fail,eil);
        if(fail)continue;
        if(duom[i].vard.length()>VAR) VAR = duom[i].vard.length();
        if(duoom[i].pav.length()>PAV) PAV = duom[i].pav.length();
        nd(df,duom,n,i,fail,eil);
        if(fail)continue;
        egz(df,duom,i,fail,eil);
        if(fail)continue;
        GP(duom,n,i);
        if(df.eof()==1) break;
        i++;
        duom.emplace_back(duomuo());
    }
    duom.shrink_to_fit();
};

void rikiuoti(vector<duomuo>& duom) {
    sort(duom.begin(), duom.end(), [](const duomuo &lhs, const duomuo &rhs) {
        if (lhs.vard != rhs.vard) {
            return lhs.vard < rhs.vard;
        } else {
            return lhs.pav < rhs.pav;
        }
    });
};

void spausdinti(vector<duomuo> duom, int VAR, int PAV){
    rikiuoti(duom);
    cout << endl;
    cout << std::left << std::setw(VAR + 3) << "vardas";
    cout << std::setw(PAV + 3) << "Pavarde" << std::setw(10) << "Galutinis(VID)   " << std::setw(10) << "Galutinis(MED)" << endl;
    for(int w=0;w<(VAR+PAV+6+31);w++) cout << "-";cout <<endl;
    for (auto &i : duom) {
        cout << std::left <<  std::setw(VAR+3) << i.vard << std::setw(PAV+3) << i.pav;
        cout << std::setw(17) << std::fixed << std::setprecision(2) << i.vidG;
        cout << std::setw(10) << std::fixed << std::setprecision(2) << i.medG << endl;
    }
};
