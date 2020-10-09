#ifndef STRUCT_HEADER_H_INCLUDED
#define STRUCT_HEADER_H_INCLUDED

struct duomuo
{
    string vard, pav;
    int egz=0;
    double vidG=0, medG=0;
    vector<int> nd;
};

double mediana(vector<duomuo> duom, int x, int y);
bool netinka(const string a);
void genND(vector<duomuo>&duom, int x, int y);
void genEG(vector<duomuo>&duom, int y);
double ndSum(vector<duomuo> duom, int x, int y);
void GP(vector<duomuo>& duom, int x, int y);
void vardT(vector<duomuo>&duom, int y);
void pavT(vector<duomuo>&duom, int y);
void tikrinimas (int &f);
void egzI(vector<duomuo>& duom, int y, int f);
void ndI(vector<duomuo>& duom, int y, int f);
void generuoti(vector<duomuo>&duom, int &VAR, int &PAV);
void stringT (std::ifstream &df, string a, bool &fail, int eil);
void nd(std::ifstream &df,vector<duomuo> &duom, int x, int y, bool &fail, int eil);
void egz(std::ifstream &df,std::vector<duomuo> &duom, int y, bool &fail, int eil);
int ndSk(std::ifstream &df);
void failas(vector<duomuo> &duom, int &VAR, int &PAV);
void rikiuoti(vector<duomuo>& duom);
void spausdinti(vector<duomuo> duom, int VAR, int PAV);

#endif // STRUCT_HEADER_H_INCLUDED
