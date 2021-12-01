// Standard I/O header
#include <stdio.h>

// Standard library header
#include <stdlib.h>

// Sample 1.7 from textbook
void BubbleSort(int *L, int n) {
  int i, j, temp, flag = 1;

  for (i = 0; i < n && flag; i++) {
    flag = 0;

    for (j = 0; j < n - i - 1; j++)
      if (L[j] > L[j + 1]) {
        flag = 1;

        temp = L[j];
        L[j] = L[j + 1];
        L[j + 1] = temp;
      }
  }
}

// Start main function
int main(int argc, char **argv) {
  int i, L[argc - 1];

  // Get an array from arguments
  for (i = 0; i < argc - 1; i++)
    L[i] = atoi(argv[i + 1]);

  BubbleSort(L, argc - 1);

  for (i = 0; i < argc - 1; i++)
    printf("%d ", L[i]);

  // Exit with status 0
  return 0;
}

// vim:set nu rnu cuc cul ts=2 sw=2 et si:
