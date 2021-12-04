#include <iomanip>

#include "utility.hpp"

void bubble_sort(int *list, int n) {
  for (int i{0}, flag{1}; i < n && flag; ++i) {
    flag = 0;
    for (int j{0}; j < n - i - 1; j++)
      if (list[j] > list[j + 1]) {
        int tmp{list[j]};
        list[j] = list[j + 1];
        list[j + 1] = tmp;
        flag = 1;
      }
  }
}

int __main() {
  __assert(argc > 1);
  int *list = new int[unsigned(argc - 1)];

  // Get an array from arguments
  for (int i = 0; i < argc - 1; ++i)
    list[i] = atoi(argv[i + 1]);

  bubble_sort(list, argc - 1);

  for (int i = 0; i < argc - 1; ++i)
    std::cout << std::setw(6) << list[i];
  std::cout << std::endl;

  delete[] list;
  return 0;
}
