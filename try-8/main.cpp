/**
 * Copyright(C) 2021 Supdrewin <https://github.com/supdrewin>
 * main.cpp is part of Recursive Algorithm Example.
 * The Recursive Algorithm Example is free software: you can redistribute
 * it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * The Recursive Algorithm Example is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 * You should have received a copy of the GNU General Public License along
 * with this program.If not, see <https://www.gnu.org/licenses/>.
 */

#include "utility.hpp"

int add(int n) { return n ? n += add(n - 1) : n; }

int find(int data[], int d, int min, int max) {
  if (d > data[(min + max) / 2])
    return find(data, d, (min + max) / 2, max);
  else if (d < data[(min + max) / 2])
    return find(data, d, min, (min + max) / 2);
  return (min + max) / 2;
}

int factor(int n, int *sum) {
  for (int i = 2; i <= n / 2; ++i)
    n % i ?: factor(i, sum);
  return ++*sum;
}

int main() {
  int *data, n = 0;

  assert(argc != 2 ? n : n = atoi(argv[1]));
  data = new int[n];

  for (int i = 0; i < n; ++i)
    data[i] = i * i;

  for (int i = 0; i < n; ++i)
    std::cout << "Add 1 to "                         //
              << i + 1                               //
              << " equals "                          //
              << add(i + 1)                          //
              << '.'                                 //
              << std::endl;                          //
                                                     //
  for (int i = 0; i < n; ++i)                        //
    std::cout << "Data ["                            //
              << find(data, data[i], 0, n)           //
              << "] is "                             //
              << data[i]                             //
              << '.'                                 //
              << std::endl;                          //
                                                     //
  for (int i = 0, sum; i < n; ++i)                   //
    std::cout << "The number of factorizations for " //
              << i + 1                               //
              << " is "                              //
              << factor(i + 1, &(sum = 0))           //
              << '.'                                 //
              << std::endl;

  delete[] data;
  return 0;
}
