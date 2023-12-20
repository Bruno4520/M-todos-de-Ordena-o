#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

//----------------------------------------------------------------- QUICK SORT
int particiona(string *vet, int esq, int dir)
{
    int i, j;
    string aux, pivo;
    i = esq;
    j = dir;
    pivo = vet[esq];

    while(i<j)
    {
        while((vet[i] <= pivo) && (i<dir))
            i++;
        while((vet[j] >= pivo) && (j>esq))
            j--;
        if(i<j)
        {
            aux = vet[j];
            vet[j] = vet[i];
            vet[i] = aux;
        }
    }
    vet[esq] = vet[j];
    vet[j] = pivo;
    return j;
}

void quick(string *vet, int esq, int dir)
{
    if(esq < dir)
    {
        int pivo = particiona(vet,esq,dir);
        quick(vet,esq,pivo-1);
        quick(vet,pivo+1,dir);
    }
}

//----------------------------------------------------------------- SHELL SORT
void shell(string *vet, int n)
{
    int j, h;
    string aux;
    h = n/2;

    while(h>=1)
    {
        for(int i = 1; i < n; i++)
        {
            aux = vet[i];
            for(j = i-h; (j>=0)&&(vet[j]>aux); j=j-h)
                vet[j+h] = vet[j];
            vet[j+h] = aux;
        }
        h = h/2;
    }
}
//----------------------------------------------------------------- MERGE SORT
void mergeIntercala(string *vet, string *aux, int ini, int meio, int fin)
{
    int atual, fimEsq, n;
    atual = ini;
    fimEsq = meio-1;
    n = fin - ini + 1;

    while((ini <= fimEsq)&&(meio<=fin))
    {
        if(vet[ini]<=vet[meio])
            aux[atual++] = vet[ini++];
        else
            aux[atual++] = vet[meio++];
    }
    while(ini <= fimEsq)
        aux[atual++] = vet[ini++];

    while(meio <= fin)
        aux[atual++] = vet[meio++];

    for(int i=0; i<n; i++)
    {
        vet[fin] = aux[fin];
        fin--;
    }
}

void mergeDivide(string *vet, string *aux, int ini, int fin)
{
    int meio;

    if(fin>ini)
    {
        meio = (fin+ini)/2;

        mergeDivide(vet,aux,ini,meio);
        mergeDivide(vet,aux,meio+1,fin);

        mergeIntercala(vet,aux,ini,meio+1,fin);
    }
}

void merge(string *vet, int n)
{
    string aux[n];
    mergeDivide(vet,aux,0,n-1);
}

//----------------------------------------------------------------- BUBBLE SORT
void bubble(string *vet, int n)
{
    string aux;

    for(int i=0; i<n; i++)
        for(int j = 0; j<n-1-i; j++)
            if(vet[j+1] < vet[j])
            {
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
}

//----------------------------------------------------------------- SELECTION SORT
void selection(string *vet, int n)
{
    string aux;
    int menor;

    for(int i=0; i<n-1; i++)
    {
        menor = i;
        for(int j=(i+1); j<n; j++)
        {
            if(vet[j] < vet[menor])
                menor = j;
        }
        aux = vet[i];
        vet[i] = vet[menor];
        vet[menor] = aux;
    }
}
//----------------------------------------------------------------- INSERTION SORT

void insertionSort(int n, string *vet)
{

    int j;
    string aux;
    for(int i=1; i<n; i++)
    {
        aux = vet[i];
        for(j=i-1; (j>=0)&&(vet[j]>aux); j--)
        {
            vet[j+1] = vet[j];

        }
        vet[j+1] = aux;
    }
}
//-----------------------------------------------------------------
int main()
{
    int tIni, tFin, tms;

    int i;
    fstream aurelio40000;

    string ch;
    string palavras[40000];

    tIni = (int) clock();

    aurelio40000.open("aurelio40000.txt", ios::in);
    if(!aurelio40000)
    {
        cout << "Arquivo nao encontrado";
    }
    else
    {
        while (1)
        {
            aurelio40000 >> ch ;
            palavras[i]=ch;
            if (aurelio40000.eof())
                break;
            i++;
        }
    }

    int n = 30000;

    //bubble(palavras,n);
    //selection(palavras,n);
    //insertionSort(n,palavras);
    //shell(palavras,n);
    //merge(palavras,n);
    //quick(palavras,0,n);

    tFin = (int) clock();
    tms = ((tFin-tIni)*1000/CLOCKS_PER_SEC);

/*
    for(int i=0; i<n; i++)
    {
        cout << "\n" << palavras[i];
    }
  */
    cout << "\n\ntempo: "<< tms << " ms";

    int n1,n2,n3;
    int media;

    cin >> n1 >> n2 >> n3;

    media = (n1 + n2 + n3)/3;

    cout << "Media: " << media;

    return 0;
}
//-----------------------------------------------------------------
