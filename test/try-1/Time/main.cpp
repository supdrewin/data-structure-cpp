#include "utility.hpp"

// foo1 -> O(n)
int foo1(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++)
    i % 2 ? sum += i : sum -= i;
  return sum;
}

// foo2 -> O(1)
inline int foo2(int n) { return n = (n % 2 ? n + 1 : -n) / 2; }

int __main() {
  __assert(argc == 2);
  printf("O(n): %d\n", foo1(atoi(argv[1])));
  printf("O(1): %d\n", foo2(atoi(argv[1])));
  return 0;
}
