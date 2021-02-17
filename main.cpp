#include <iostream>

using namespace std;

class kvepalai {
  private:
    string baze;
    string santykis;
  public:
    void setBaze(string b){baze = b;}
    void setSantykis (string s){santykis= s;}
    string baz() {return baze;}
    string santyk() {return santykis;}
    void pakeisti(string z, string pav){if (baze == z) baze = pav;}
};

class Dior : public kvepalai
 {
  private:
      string pavadinimas;
      double kaina;
  public:
      void setPav(string p){pavadinimas = p;}
      void setKaina (double k){kaina = k;}
      string pav() {return pavadinimas;}
      double kain() {return kaina;}
      friend std::istream& operator>>(std::istream& cin, Dior &a) {
        in >> a.pavadinimas >> a.kaina;
        return cin ;}
      friend std::ostream& operator<<(std::ostream& cout, Dior &a) {
        out << a.pavadinimas << a.kaina;
        return cout ;}
 };
