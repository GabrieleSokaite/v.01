#include "../headers/main_header.h"
#include "../headers/struct_header.h"

double mediana(std::vector<duomuo> duom, int x, int y)
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

void genND(std::vector<duomuo>&duom, int x, int y)
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

void genEG(std::vector<duomuo>&duom, int y)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> random(1,10);
    int a;
    duom[y].egz=random(gen);
}

double ndSum(std:;vector<duomuo> duom, int x, int y)
{
    double sum=0;
    for (int z=0; z<x; z++)
    {
        sum += duom[y].nd[z];
    }
    return sum;
}

void GP(std::vector<duomuo>& duom, int x, int y)
{
    duom[y].vidG=0.4*ndSum(duom,x,y)/x+0.6*duom[y].egz;
    duom[y].medG=0.4*mediana(duom,x,y) + 0.6 * duom[y].egz;
}

void stringT (std::ifstream &df, string a, bool &fail, int eil)
{
    if(!netinka(std::move(a)))
       {
            df.clear();
            df.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            fail=true;
            cout << "Netinkamas vardas arba pavarde " << eil << "eiluteje. Duomenys nenuskaityti. \n";
       }
}

void nd(std::ifstream &df,std::vector<duomuo> &duom, int x, int y, bool &fail, int eil){
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

void failasG(int x) {
    std::ofstream gf(data);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> random(1, 10);
    int a, b;
    gf << std::left << std::setw(14) << "Vardas" << std::setw(15) << "Pavarde" << "ND1 ND2 ND3 ND4 ND5 ND6 Egzaminas" << endl;
    for (int i=1; i <= x; i++) {
        gf << "Vardas" << std::setw(8) << i << "Pavarde" << std:setw(8) << i;
        for (int j=0; j<6; j++) {
            a = random(gen);
            gf << std::setw(4) << a;
        }
        b = random(gen);
        gf << b << endl;
    }
    gf.close();
}

void failasS(std::vector<duomuo> &duom, int &VAR, int &PAV, int n){
    std::ifstream df (data);
    if (!df) throw "Duomenu failas nerastas";
    duom.reserve(n);
    int i=0, eil=0, n = ndSk(df);
    duom.emplace_back(duomuo());
    while(true){
        if(df.eof()==1) break;
        eil++;
        df >> duom[i].vard >> duom[i].pav;
        if(duom[i].vard.length()>VAR) VAR = duom[i].vard.length();
        if(duom[i].pav.length()>PAV) PAV = duom[i].pav.length();
        int q, sum=0;
        for (int u=0; u<6; u++) {
            df >> q;
            duom[i].nd.emplace_back(q);
            sum = sum + q;
        }
        df >> duom[i].egz;
        duom[i].vidG = 0.4 * sum/n + 0.6 * duom[i].egz;
        if (df.eof() == 1) break;
        i++;
        duom.emplace_back(duomuo());
    }
    df.seekg(0);
    df.clear();
    duom.shrink_to_fit();
};

void rusiuoti(std::vector<duomuo>& duom)
{
    sort(duom.begin(), duom.end(), [](const duomuo &lhs, const duomuo &rhs)
         {
             return (lhs.vidG > rhs.vidG);
         });
};

void skirstyti(std::vector<duomuo>& duom, std::vector<duomuo> & nuskriaustukai, int x)
{
    rusiuoti(duom);
    int i = x, k = 0;
    while (duom[i].vidG < 5)
    {
        k++;
        i--;
    }
    std::move(duom.end()-k, duom.end(), std::back_inserter(nuskriaustukai));
    duom.erase (duom.end()-k, duom.end());
}

void skirstyti2(std::vector<duomuo>& duom, std::vector<duomuo> & nuskriaustukai, std::vector<duomuo>& galvociai, int x)
{
    rusiuoti(duom);
    int i = x, k = 0;
    while (duom[i].vidG < 5)
    {
        k++;
        i--;
    }
    std::move(duom.end()-k, duom.end(), std::back_inserter(nuskriaustukai));
    std::move(duom.begin(), duom.end()-k-1, std::back_inserter(galvociai));
}

bool negavoSkolos(const duomuo& s)
{
    return s.vidG > 5;
}

std::vector<duomuo> nuskriaustukai(std::vector<duomuo>& duom)
{
    std::vector<duomuo>::iterator it = stable_partition(duom.begin(), duom.end(), negavoSkolos);
    std::vector<duomuo> minksti(it, duom.end());
    duom.erase(it, duom.end());
    return minksti;
}

void spausdinti(std::vector<duomuo> duom, std::vector<duomuo> nuskriaustukai, int VAR, int PAV){
    std::ofstream gs ("kietiakai.txt");
    std::ofstream bs ("nuskriaustukai.txt");

    gs << std::left << std::setw(VAR + 3) << "vardas";
    gs << std::setw(PAV + 3) << "Pavarde" << std::setw(10) << "Galutinis(VID)   " << endl;
    for(int w=0;w<(VAR+PAV+6+14);w++) gs << "-";
    gs <<endl;
    for (auto &i : duom) {
        gs << std::left <<  std::setw(VAR+3) << i.vard << std::setw(PAV+3) << i.pav;
        gs << std::setw(17) << std::fixed << std::setprecision(2) << i.vidG << endl;
    }
    gs.close();
    bs << std::left << std::setw(VAR + 3) << "vardas";
    bs << std::setw(PAV + 3) << "Pavarde" << std::setw(10) << "Galutinis(VID)   " << endl;
    for(int w=0;w<(VAR+PAV+6+14);w++) bs << "-";
    bs <<endl;
    for (auto &i : nuskriaustukai) {
        bs << std::left <<  std::setw(VAR+3) << i.vard << std::setw(PAV+3) << i.pav;
        bs << std::setw(17) << std::fixed << std::setprecision(2) << i.vidG << endl;
    }
    bs.close();
};

void start_c(std::chrono::time_point<std::chrono::high_resolution_clock> &start) {
    start = std:chrono::high_resolution_clock::now();
}

void end_c(std::chrono::time_point<std::chrono::high_resolution_clock> &end) {
    end = std:chrono::high_resolution_clock::now();
}
