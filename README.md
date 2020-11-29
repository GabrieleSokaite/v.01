# v.01
Papildymas:
1. Galutinė programos versija.
2. Studentų skaidymas į du skirtingus konteinerius.
3. Papildyta funkcijomis, kurios leidžia skaičiuoti pagal 1 strategiją.
main.cpp išimtas try catch.

100 studentų:

Failo generavimas uztruko 0.0166667s.

Vector rusiavimas uztruko(2 strategija) 0.00241723s.
Vector isvedimas uztruko(2 strategija) 0.0145358s.
List rusiavimas uztruko(2 strategija) 0.00143631s.
List isvedimas uztruko(2 strategija) 0.0140246s.
Deque rusiavimas uztruko(2 strategija) 0.00395528s.
Deque isvedimas uztruko(2 strategija) 0.00902195s.

Vector rusiavimas uztruko(1 strategija) 0.00382974s.
Vector isvedimas uztruko(1 strategija) 0.0186023s.
List rusiavimas uztruko(1 strategija) 0.00213456s.
List isvedimas uztruko(1 strategija) 0.00867815s.
Deque rusiavimas uztruko(1 strategija) 0.00159631s.
Deque isvedimas uztruko(1 strategija) 0.0100094s.

Vector rusiavimas uztruko(stable_partition) 0.000461538s.

1000 studentų:

Failo generavimas uztruko 0.177447s.

Vector rusiavimas uztruko(2 strategija) 0.0249243s.
Vector isvedimas uztruko(2 strategija) 0.0423742s.
List rusiavimas uztruko(2 strategija) 0.0164697s.
List isvedimas uztruko(2 strategija) 0.0392779s.
Deque rusiavimas uztruko(2 strategija) 0.0321145s.
Deque isvedimas uztruko(2 strategija) 0.0616213s.

Vector rusiavimas uztruko(1 strategija) 0.0471253s.
Vector isvedimas uztruko(1 strategija) 0.0628135s.
List rusiavimas uztruko(1 strategija) 0.0715524s.
List isvedimas uztruko(1 strategija) 0.0503696s.
Deque rusiavimas uztruko(1 strategija) 0.0344591s.
Deque isvedimas uztruko(1 strategija) 0.0418158s.

Vector rusiavimas uztruko(stable_partition) 0.00460964s.

10000 studentų:

Failo generavimas uztruko 0.706272s.

Vector rusiavimas uztruko(2 strategija) 0.26133s.
Vector isvedimas uztruko(2 strategija) 0.276337s.
List rusiavimas uztruko(2 strategija) 0.173108s.
List isvedimas uztruko(2 strategija) 0.271526s.
Deque rusiavimas uztruko(2 strategija) 0.195009s.
Deque isvedimas uztruko(2 strategija) 0.336301s.

Vector rusiavimas uztruko(1 strategija) 0.310294s.
Vector isvedimas uztruko(1 strategija) 0.290751s.
List rusiavimas uztruko(1 strategija) 0.167759s.
List isvedimas uztruko(1 strategija) 0.360693s.
Deque rusiavimas uztruko(1 strategija) 0.200047s.
Deque isvedimas uztruko(1 strategija) 0.383927s.

Vector rusiavimas uztruko(stable_partition) 0.0388193s.

100000 studentų:

Failo generavimas uztruko 6.06982s.

Vector rusiavimas uztruko(2 strategija) 2.48271s.
Vector isvedimas uztruko(2 strategija) 2.43356s.
List rusiavimas uztruko(2 strategija) 2.20417s.
List isvedimas uztruko(2 strategija) 2.634s.
Deque rusiavimas uztruko(2 strategija) 2.29506s.
Deque isvedimas uztruko(2 strategija) 2.90855s.

Vector rusiavimas uztruko(1 strategija) 2.41303s.
Vector isvedimas uztruko(1 strategija) 2.80808s.
List rusiavimas uztruko(1 strategija) 2.50176s.
List isvedimas uztruko(1 strategija) 2.4293s.
Deque rusiavimas uztruko(1 strategija) 1.87861s.
Deque isvedimas uztruko(1 strategija) 3.00293s.

Vector rusiavimas uztruko(stable_partition) 0.437255s.

Antra strategija yra greitesnė už pirmąją. Greičiausias yra list tipo konteineris. Naudojant stable_partition algoritmą vektoriaus greitis žymiai išauga ir tuomet lenkia kito tipo konteinerius.
