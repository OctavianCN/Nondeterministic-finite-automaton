#include <iostream>
#include "afn.h"
using namespace std;

int main()
{
    afn Limbaj("citire.in");
    if(Limbaj.verificare("cabbbbbbbc")==true)
        cout<<"Cuvant acceptat";
    else
        cout<<"Cuvant neacceptat";
    return 0;
}
