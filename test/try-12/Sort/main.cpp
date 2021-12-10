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

#include <chrono>
#include <iostream>
#include <random>

#include "sort.hh"

#define max_test_count 10000

static std::uniform_int_distribution<unsigned> dist(0, max_test_count);

int main() {
  std::random_device rd;

  sort::array<unsigned, max_test_count> arr;

  for (auto &_ : arr)
    _ = dist(rd);

  auto begin{std::chrono::steady_clock::now()};

  // arr.insert_sort();

  auto end{std::chrono::steady_clock::now()};

  std::chrono::duration<double> used_time = end - begin;

  for (auto _ : arr)
    std::cout << _.key << '\t';

  std::cout << "Used time: " << used_time.count() << "s\n";

  begin = std::chrono::steady_clock::now();

  arr.select_sort();

  end = std::chrono::steady_clock::now();

  used_time = end - begin;

  for (auto _ : arr)
    std::cout << _.key << '\t';

  std::cout << "Used time: " << used_time.count() << "s\n";

  return 0;
}