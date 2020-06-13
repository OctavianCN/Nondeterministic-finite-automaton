#include <fstream>
#include "afn.h"
#include <cstring>
#include <iostream>
using namespace std;
afn::afn(char *numefisier)
{
    ifstream f (numefisier);
    f>>StariTotale>>NrStariFinale;
    StarileFinale=new int[NrStariFinale];
    for(int i=0;i<NrStariFinale;i++)
        f>>StarileFinale[i];
    f>>NrLitereAlfabet;
    Litere=new char[NrLitereAlfabet];
    for(int i=0;i<NrLitereAlfabet;i++)
        f>>Litere[i];
    f>>NrTranzitii;
    Tranz=new Tranzitii[NrTranzitii];
    for(int i=0;i<NrTranzitii;i++)
        f>>Tranz[i].S1>>Tranz[i].S2>>Tranz[i].litera;
}
bool afn::verificare(char *cuvant)
{
    int *StarileCurente,*NoileStariCurente;
    int i=0,j=0,nrSC=1,nrNSC=0,PozLitera=0;
    int ok=0;
     StarileCurente=new int[nrSC];
     NoileStariCurente=new int[StariTotale];
     StarileCurente[nrSC-1]=0;
     if(cuvant=="CuvantulNul")
     {
         for(i=0;i<NrStariFinale;i++)
         {
             if(StarileFinale[i]==0)
                return true;
             else
                return false;
         }
     }
     for(i=0;i<strlen(cuvant);i++)
     {
         for(j=0;j<NrLitereAlfabet;j++)
         {
             if(Litere[j]==cuvant[i])
                ok=1;
         }
         if(ok==0)
            return false;
         ok=0;
     }
     while(PozLitera<strlen(cuvant))
     {

         for(i=0;i<nrSC;i++)
         {
             for(j=0;j<NrTranzitii;j++)
             {


                 if((Tranz[j].S1==StarileCurente[i])&&(cuvant[PozLitera]==Tranz[j].litera))
                 {


                     nrNSC++;
                     NoileStariCurente[nrNSC-1]=Tranz[j].S2;

                 }
             }
         }
        PozLitera++;
         if((PozLitera==strlen(cuvant))&&(nrNSC!=0))
         {
             for(i=0;i<nrNSC;i++)
             {
                 for(j=0;j<NrStariFinale;j++)
                  {

                      if(NoileStariCurente[i]==StarileFinale[j])
                        {

                            return true;
                        }
                  }
             }
             return false;
         }
         if((PozLitera==strlen(cuvant))||(nrNSC==0))
            return false;
        nrSC=nrNSC;
        StarileCurente=new int[nrSC];
        for(i=0;i<nrSC;i++)
            {
                StarileCurente[i]=NoileStariCurente[i];
            }
        nrNSC=0;
     }

    return false;
}
