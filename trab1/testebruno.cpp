#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

int main() {
   int tIni, tFin, tms;

   int i;
   fstream aurelio40000;

   string ch;
   string palavras[40000];

   tIni = (int) clock();
   aurelio40000.open("aurelio40000.txt", ios::in);

   if(!aurelio40000) {
      cout << "Arquivo nao encontrado";
   } else {
      while (1) {
         aurelio40000 >> ch ;
         palavras[i]=ch;
         if (aurelio40000.eof())
            break;
         i++;
      }
   }

   int n = 30000;

   //ALGORITMOS:
   //bubble(palavras,n);
   //selection(palavras,n);
   //insertionSort(n,palavras);
   //shell(palavras,n);
   //merge(palavras,n);
   //quick(palavras,0,n);

   tFin = (int) clock(); // Tempo final medido
   tms = ((tFin-tIni)*1000/CLOCKS_PER_SEC); // Calcula o intervalo entre os tempos

   // Imprime as palavras organizadas

   for(int i=0; i<n; i++) {
      cout << "\n" << palavras[i];
   }

   // Calcula a media dos valores obtidos:

   cout << "\n\ntempo: "<< tms << " ms\n\n";

   /*
   int n1[42],n2[42],n3[42];
   int media[42];

   for(int i = 0; i<42; i++)
   {
      cin >> n1[i] >> n2[i] >> n3[i];

      media[i] = (n1[i] + n2[i] + n3[i])/3;
   }
      for(int i = 0; i<42; i++)
   {
      cout<< media[i]<< " \n";

   }
   */

   return 0;
}