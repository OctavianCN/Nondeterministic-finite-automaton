#ifndef AFN_H
#define AFN_H

class afn
{
    public:
        afn(char *numefisier);
        bool verificare(char *cuvant);

    private:
        int StariTotale;
        int NrStariFinale;
        int *StarileFinale;
        int NrLitereAlfabet;
        char *Litere;
        int NrTranzitii;
        typedef struct
        {
          int S1,S2;
          char litera;
        } Tranzitii;
        Tranzitii *Tranz;
        bool exista;
};

#endif // AFN_H
