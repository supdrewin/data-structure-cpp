#include "utility.hpp"

void bubble_sort(int *L, int n) {
  for (int i = 0, flag; i < n && flag; i++) {
    flag = 0;

    for (int j = 0; j < n - i - 1; j++)
      if (L[j] > L[j + 1]) {
        flag = 1;

        int temp = L[j];
        L[j] = L[j + 1];
        L[j + 1] = temp;
      }
  }
}

int __main() {
  __assert(argc > 1);

  int i, *L = new int[unsigned(argc - 1)];

  // Get an array from arguments
  for (i = 0; i < argc - 1; i++)
    L[i] = atoi(argv[i + 1]);

  bubble_sort(L, argc - 1);

  for (i = 0; i < argc - 1; i++)
    printf("%d ", L[i]);

  delete[] L;
  return 0;
}
