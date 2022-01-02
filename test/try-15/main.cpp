/**
 * Copyright(C) 2021 Supdrewin <https://github.com/supdrewin>
 * main.cpp is part of Sort Algorithm Example.
 * The Sort Algorithm Example is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 * The Sort Algorithm Example is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABI-
 * LITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <https://www.gnu.org/licenses/>.
 */

#if __cplusplus >= 201402L

#include <cstddef>
#include <cstdio>
#include <random>

template <class tp, class func> //
void BiMerge(tp *arr, size_t size, func cmp) {
  auto s1{size / 2}, s2{size - s1};
  auto *arr1{new tp[s1]}, *arr2{new tp[s2]};

  for (size_t i{}; i < s1; ++i)
    arr1[i] = arr[i];
  for (size_t i{}; i < s2; ++i)
    arr2[i] = arr[i + s1];

  if (s1 > 1)
    BiMerge(arr1, s1, cmp);
  if (s2 > 1)
    BiMerge(arr2, s2, cmp);

  size_t i{}, j{}, k{};

  while (i < s1 and j < s2)
    arr[k++] = cmp(arr1[i], arr2[j]) //
                   ? arr1[i++]
                   : arr2[j++];

  while (i < s1)
    arr[k++] = arr1[i++];
  while (j < s2)
    arr[k++] = arr2[j++];

  delete[] arr1;
  delete[] arr2;
}

template <class tp, class func> //
void RadixSort(tp *arr, size_t size, func cmp) {
  size_t mbit{};

  for (size_t i{}; i < size; ++i) {
    size_t j{};
    auto k{arr[i]};

    while (k)
      ++j, k /= 10;

    if (j > mbit)
      mbit = j;
  }

  for (size_t i{}, k{1}; i < mbit; ++i, k *= 10)
    for (size_t j{}; j < size; ++j)
      BiMerge(arr, size, [k, cmp](tp l, tp r) {
        return cmp(l / static_cast<tp>(k) % 10, //
                   r / static_cast<tp>(k) % 10);
      });
}

template <class tp> auto up = [](tp l, tp r) { return l <= r; };
template <class tp> auto down = [](tp l, tp r) { return l >= r; };

static const size_t size{100};

std::uniform_int_distribution<int> dist(0, 100);
std::random_device rd;

int main() {
  int arr[size];

  for (auto &_ : arr)
    _ = dist(rd);

  auto arr1{arr}, arr2{arr};
  auto print = [](int *arr, size_t size) -> void {
    for (size_t i{}; i < size; ++i)
      printf("%d%c", arr[i],
             ((i + 1) % 5 and //
              i + 1 < size)   //
                 ? '\t'
                 : '\n');
  };

  BiMerge(arr1, size, down<int>);

  printf("BiMerge:\n");
  print(arr1, size);

  RadixSort(arr2, size, up<int>);

  printf("RadixSort:\n");
  print(arr2, size);

  return 0;
}

#endif
