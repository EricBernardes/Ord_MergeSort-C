#include <stdio.h>
#include <stdlib.h>
#define max 5

void intercalar(int *V, int inicio, int meio, int fim) {
  int i = inicio;
  int j = meio + 1;
  int k = 0;
  int Tmp[max];
  while (i <= meio || j <= fim) {
    if (i == meio + 1 || (V[j] < V[i] && j != fim + 1)) {
      Tmp[k] = V[j];
      j++;
      k++;
    } else {
      Tmp[k] = V[i];
      i++;
      k++;
    }
  }
  for (i = inicio; i <= fim; i++) {
    V[i] = Tmp[i - inicio];
  }
}

void mergeSort(int *V, int inicio, int fim) {
  int meio;
  if (inicio < fim) {
    meio = (inicio + fim) / 2;
    mergeSort(V, inicio, meio);
    mergeSort(V, meio + 1, fim);
    intercalar(V, inicio, meio, fim);
  }
}

void imprimeVetor(int *v) {
  for (int i = 0; i < max; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

int main() {
  int v[max] = {5, 2, 1, 3, 4};
  mergeSort(v, 0, max - 1);
  imprimeVetor(v);
  return 0;
}