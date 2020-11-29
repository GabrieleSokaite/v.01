#ifndef STRUCT_HEADER_H_INCLUDED
#define STRUCT_HEADER_H_INCLUDED

struct duomuo
{
    string vard, pav;
    int egz=0;
    double vidG=0, medG=0;
    vector<int> nd;
};

double mediana(std::vector<duomuo> duom, int x, int y);
bool netinka(const string a);
void genND(std::vector<duomuo>&duom, int x, int y);
void genEG(std::vector<duomuo>&duom, int y);
double ndSum(std::vector<duomuo> duom, int x, int y);
void GP(std::vector<duomuo>& duom, int x, int y);
void vardT(std::vector<duomuo>&duom, int y);
void pavT(std::vector<duomuo>&duom, int y);
void tikrinimas (int &f);
void egzI(std::vector<duomuo>& duom, int y, int f);
void ndI(std::vector<duomuo>& duom, int y, int f);
void generuoti(std::vector<duomuo>&duom, int &VAR, int &PAV);
void stringT (std::ifstream &df, string a, bool &fail, int eil);
void nd(std::ifstream &df,std::vector<duomuo> &duom, int x, int y, bool &fail, int eil);
void egz(std::ifstream &df,std::vector<duomuo> &duom, int y, bool &fail, int eil);
int ndSk(std::ifstream &df);
void failasG(int x);
void failasS(std::vector<duomuo> &duom, int &VAR, int &PAV, int n);
void rikiuoti(std::vector<duomuo>& duom);
void rusiuoti(std::vector<duomuo>& duom);
void skirstyti(std::vector<duomuo>& duom, std::vector<duomuo> &nuskriaustukai, int x);
void skirstyti2(std::vector<duomuo>& duom, std::vector<duomuo> &nuskriaustukai, std::vector<duomuo>& galvociai, int x);
bool negavoSkolos(const duomuo& s);
std::vector<duomuo> nuskriaustukai(std::vector<duomuo>& duom);
void spausdinti(std::vector<duomuo> duom, std::vector<duomuo> nuskriaustukai, int VAR, int PAV);
void start_c(std::chrono::time_point<std::chrono::high_resolution_clock> &start);
void end_c(std::chrono::time_point<std::chrono::high_resolution_clock> &end);

#endif // STRUCT_HEADER_H_INCLUDED

