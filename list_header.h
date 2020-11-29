#ifndef LIST_HEADER_H_INCLUDED
#define LIST_HEADER_H_INCLUDED

void failasS(std::list<duomuo> &duom, int &VAR, int &PAV);
void rusiuoti(std::list<duomuo>& duom);
void skirstyti(std::list<duomuo>& duom, std::list<duomuo> &nuskriaustukai);
void skirstyti2(std::list<duomuo>& duom, std::list<duomuo> &nuskriaustukai, std::list<duomuo>& galvociai);
void spausdinti(std::list<duomuo> duom, std::list<duomuo> nuskriaustukai, int VAR, int PAV);

#endif // LIST_HEADER_H_INCLUDED
