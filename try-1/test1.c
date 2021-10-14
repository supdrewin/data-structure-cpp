// Standard I/O header
#include <stdio.h>

// Standard library header
#include <stdlib.h>

// foo1 -> O(n)
int foo1(int n) {
  int i, sum = 0;

  for (i = 1; i <= n; i++)
    if (i % 2 == 0)
      sum -= i;
    else
      sum += i;

  return sum;
}

// foo2 -> O(1)
int foo2(int n) {
  if (n % 2 == 0)
    n = -n / 2;
  else
    n = (n + 1) / 2;

  return n;
}

// Start main function
int main(int argc, char **argv) {
  // atoi(): convert string to integer
  printf("O(n): %d\n", //
         foo1(atoi(argv[1])));
  printf("O(1): %d\n", //
         foo2(atoi(argv[1])));

  // Exit with status 0
  return 0;
}

// vim:set nu rnu cuc cul ts=2 sw=2 et si:
