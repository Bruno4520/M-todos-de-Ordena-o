#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

// Definição das constantes de entrada:
#define N1 1000
#define N2 5000
#define N3 10000
#define N4 15000
#define N5 20000
#define N6 30000
#define N7 40000

using namespace std;

// Imprime vetor:
void printVetor(vector<string> &vet) {
   for (int i = 0; i < vet.size(); i++) {
      cout << vet[i];
      
      if (i < vet.size() - 1)
         cout << " ";
   }
}

// Ordenação Simples
// Insertion Sort:
void insertionSort(vector<string> &vet) {
   int n = vet.size();

   for (int i = 1; i < n; i++) {
      string chave = vet[i];
      int j = i - 1;

      while (j >= 0 && vet[j] > chave) {
         vet[j + 1] = vet[j];
         j = j - 1;
      }

      vet[j + 1] = chave;
   }
}

// Selection Sort:
void selectionSort(vector<string> &vet) {
   int n = vet.size();

   for (int i = 0; i < n - 1; i++) {
      int minIndex = i;

      for (int j = i + 1; j < n; j++) {
         if (vet[j] < vet[minIndex])
            minIndex = j;
      }

      if (minIndex != i)
         swap(vet[i], vet[minIndex]);
   }
}

// Bubble Sort:
void bubbleSort(vector<string> &vet) {
   int n = vet.size();
   bool troca;
   
   do {
      troca = false;
      for (int i = 0; i < n - 1; i++) {
         if (vet[i] > vet[i + 1]) {
            swap(vet[i], vet[i + 1]);
            troca = true;
         }
      }
   } while (troca);
}

// Ordenação Eficiente:
// Shell Sort:
void shellSort(vector<string>& vet) {
   int n = vet.size();
   
   for (int h = n / 2; h > 0; h /= 2) {
      for (int i = h; i < n; i++) {
         string temp = vet[i];
         int j;

         for (j = i; j >= h && vet[j - h] > temp; j -= h)
            vet[j] = vet[j - h];
         
         vet[j] = temp;
      }
   }
}

// Merge Sort:
void merge(vector<string> &vet, int esq, int meio, int dir) {
   int n1 = meio - esq + 1;
   int n2 = dir - meio;

   vector<string> esqVet(n1);
   vector<string> dirVet(n2);

   for (int i = 0; i < n1; i++)
      esqVet[i] = vet[esq + i];
   for (int j = 0; j < n2; j++)
      dirVet[j] = vet[meio + 1 + j];

   int i = 0, j = 0, k = esq;

   while (i < n1 && j < n2) {
      if (esqVet[i] <= dirVet[j]) {
         vet[k] = esqVet[i];
         i++;
      } else {
         vet[k] = dirVet[j];
         j++;
      }
      k++;
   }

   while (i < n1) {
      vet[k] = esqVet[i];
      i++;
      k++;
   }

   while (j < n2) {
      vet[k] = dirVet[j];
      j++;
      k++;
   }
}

void mergeAux(vector<string> &vet, int esq, int dir) {
   if (esq < dir) {
      int middle = esq + (dir - esq) / 2;

      mergeAux(vet, esq, middle);
      mergeAux(vet, middle + 1, dir);

      merge(vet, esq, middle, dir);
   }
}

void mergeSort(vector<string> &vet) {
   int n = vet.size();

   mergeAux(vet, 0, n - 1);
}

// Quick Sort:
int particiona(vector<string> &vet, int menor, int maior) {
   string pivo = vet[maior];
   int i = menor - 1;

   for (int j = menor; j < maior; j++) {
      if (vet[j] <= pivo) {
         i++;
         swap(vet[i], vet[j]);
      }
   }

   swap(vet[i + 1], vet[maior]);
   return i + 1;
}

void quickSortHelper(vector<string> &vet, int menor, int maior) {
   if (menor < maior) {
      int pi = particiona(vet, menor, maior);

      quickSortHelper(vet, menor, pi - 1);
      quickSortHelper(vet, pi + 1, maior);
   }
}

void quickSort(vector<string> &vet) {
   int n = vet.size();
   quickSortHelper(vet, 0, n - 1);
}

int main() {
   // Iniciar contadores de tempo:
   int tempoIni, tempoFim, tempoMs;

   // Ler o arquivo .txt
   ifstream arquivo("aurelio40000.txt");

   if (!arquivo) {
      cerr << "Não foi possível abrir o arquivo." << endl;

      return 1;
   }

   vector<string> palavras;
   string linha;

   // Lendo e colocando as palavras do arquivo no vetor:
   int contador = 0;

   while (getline(arquivo, linha) && contador < N7) {
      palavras.push_back(linha);
      contador++;
   }

   // Imprima o vetor desordenado
   cout << "Vetor desordenado:" << endl;
   printVetor(palavras);
   cout << endl;

   // Ordena usando um dos algoritmos de ordenação e obtém o tempo gasto:

   // Ordenação:
   // selectioSort(palavras);
   // bubbleSort(palavras);
   // shellSort(palavras);
   // mergeSort(palavras);
   // quickSort(palavras);

   tempoIni = (int) clock(); // Tempo inicial
   insertionSort(palavras);
   tempoFim = (int) clock(); // Tempo final

   // Imprima o vetor ordenado
   cout << "\nVetor ordenado:" << endl;
   printVetor(palavras);
   cout << endl;

   // Calculando a diferença do tempo:
   tempoMs = ((tempoFim-tempoIni) * 1000/CLOCKS_PER_SEC);

   // Exibindo o tempo resultado:
   cout << endl << "Tempo necessario: " << tempoMs << "ms" << endl;

   return 0;
}