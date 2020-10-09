#include "main_header.h"
#include "struct_header.h"

int main()
{
    vector<duomuo> duom;
    int VAR=0, PAV=0;
    bool err=false;

    try
    {
        failas (duom, VAR, PAV);
    }
    catch (const char* error)
    {
        cerr << error << endl;
        if(error) err=true;
        generuoti (duom, VAR, PAV);
        spausdinti (duom, VAR, PAV);
    }
    if(!err)spausdinti(duom, VAR, PAV);

    return 0;
}
