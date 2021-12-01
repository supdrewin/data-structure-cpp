#include "utility.hpp"

// Sample 1.7 from textbook
void BubbleSort(int *L, int n) {
  int temp, flag = 1;

  for (int i = 0; i < n && flag; i++) {
    flag = 0;

    for (int j = 0; j < n - i - 1; j++)
      if (L[j] > L[j + 1]) {
        flag = 1;

        temp = L[j];
        L[j] = L[j + 1];
        L[j + 1] = temp;
      }
  }
}

int main(int argc, char **argv) {
  int i, L[argc - 1];

  // Get an array from arguments
  for (i = 0; i < argc - 1; i++)
    L[i] = atoi(argv[i + 1]);

  BubbleSort(L, argc - 1);

  for (i = 0; i < argc - 1; i++)
    printf("%d ", L[i]);

  return 0;
}
