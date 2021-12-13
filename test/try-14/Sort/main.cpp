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
#include <random>

#include "sort.hpp"
#include "utility.hpp"

#define __array_size 20000

int main() {
  std::random_device _dev_random;

  std::uniform_int_distribution<unsigned> dist(0, __array_size);

  my_cpp::array<unsigned, __array_size> random_array;

  for (auto &_ : random_array)
    _ = dist(_dev_random);

  auto test_array{random_array};

  //------------------------- std ------------------------------//
  auto begin = std::chrono::steady_clock::now();

  my_cpp::sort(test_array);

  auto end = std::chrono::steady_clock::now();

  std::chrono::duration<double> used_time = end - begin;

  std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
      "Random Standard Sort: " SGR_RESET_ALL SGR_BROWN_FOREGROUND
            << used_time.count() << "s\n";
  //-//

  begin = std::chrono::steady_clock::now();

  my_cpp::sort(test_array);

  end = std::chrono::steady_clock::now();

  used_time = end - begin;

  std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
      "Sequence Standard Sort: " SGR_RESET_ALL SGR_BROWN_FOREGROUND
            << used_time.count() << "s\n";
  //-//

  auto reverse_array{test_array};

  begin = std::chrono::steady_clock::now();

  my_cpp::sort(reverse_array, true);

  end = std::chrono::steady_clock::now();

  used_time = end - begin;

  std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
      "Reverse Standard Sort: " SGR_RESET_ALL SGR_BROWN_FOREGROUND
            << used_time.count() << "s\n"
            << std::endl;
  //------------------------------------------------------------//

  //------------------------ bubble ----------------------------//
  test_array = random_array;

  begin = std::chrono::steady_clock::now();

  test_array.bubble_sort();

  end = std::chrono::steady_clock::now();

  used_time = end - begin;

  std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
      "Random Bubble Sort: " SGR_RESET_ALL SGR_BROWN_FOREGROUND
            << used_time.count() << "s\n";
  //-//

  begin = std::chrono::steady_clock::now();

  test_array.bubble_sort();

  end = std::chrono::steady_clock::now();

  used_time = end - begin;

  std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
      "Sequence Bubble Sort: " SGR_RESET_ALL SGR_BROWN_FOREGROUND
            << used_time.count() << "s\n";
  //-//

  test_array = reverse_array;

  begin = std::chrono::steady_clock::now();

  test_array.bubble_sort();

  end = std::chrono::steady_clock::now();

  used_time = end - begin;

  std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
      "Reverse Bubble Sort: " SGR_RESET_ALL SGR_BROWN_FOREGROUND
            << used_time.count() << "s\n"
            << std::endl;
  //------------------------------------------------------------//

  //------------------------ insert ----------------------------//
  test_array = random_array;

  begin = std::chrono::steady_clock::now();

  test_array.insert_sort();

  end = std::chrono::steady_clock::now();

  used_time = end - begin;

  std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
      "Random Insert Sort: " SGR_RESET_ALL SGR_BROWN_FOREGROUND
            << used_time.count() << "s\n";
  //-//

  begin = std::chrono::steady_clock::now();

  test_array.insert_sort();

  end = std::chrono::steady_clock::now();

  used_time = end - begin;

  std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
      "Sequence Insert Sort: " SGR_RESET_ALL SGR_BROWN_FOREGROUND
            << used_time.count() << "s\n";
  //-//

  test_array = reverse_array;

  begin = std::chrono::steady_clock::now();

  test_array.insert_sort();

  end = std::chrono::steady_clock::now();

  used_time = end - begin;

  std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
      "Reverse Insert Sort: " SGR_RESET_ALL SGR_BROWN_FOREGROUND
            << used_time.count() << "s\n"
            << std::endl;
  //------------------------------------------------------------//

  //------------------------- quick ----------------------------//
  test_array = random_array;

  begin = std::chrono::steady_clock::now();

  test_array.quick_sort();

  end = std::chrono::steady_clock::now();

  used_time = end - begin;

  std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
      "Random Quick Sort: " SGR_RESET_ALL SGR_BROWN_FOREGROUND
            << used_time.count() << "s\n";
  //-//

  begin = std::chrono::steady_clock::now();

  test_array.quick_sort();

  end = std::chrono::steady_clock::now();

  used_time = end - begin;

  std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
      "Sequence Quick Sort: " SGR_RESET_ALL SGR_BROWN_FOREGROUND
            << used_time.count() << "s\n";
  //-//

  test_array = reverse_array;

  begin = std::chrono::steady_clock::now();

  test_array.quick_sort();

  end = std::chrono::steady_clock::now();

  used_time = end - begin;

  std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
      "Reverse Quick Sort: " SGR_RESET_ALL SGR_BROWN_FOREGROUND
            << used_time.count() << "s\n"
            << std::endl;
  //------------------------------------------------------------//

  //------------------------ select ----------------------------//
  test_array = random_array;

  begin = std::chrono::steady_clock::now();

  test_array.select_sort();

  end = std::chrono::steady_clock::now();

  used_time = end - begin;

  std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
      "Random Select Sort: " SGR_RESET_ALL SGR_BROWN_FOREGROUND
            << used_time.count() << "s\n";
  //-//

  begin = std::chrono::steady_clock::now();

  test_array.select_sort();

  end = std::chrono::steady_clock::now();

  used_time = end - begin;

  std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
      "Sequence Select Sort: " SGR_RESET_ALL SGR_BROWN_FOREGROUND
            << used_time.count() << "s\n";
  //-//

  test_array = reverse_array;

  begin = std::chrono::steady_clock::now();

  test_array.select_sort();

  end = std::chrono::steady_clock::now();

  used_time = end - begin;

  std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
      "Reverse Select Sort: " SGR_RESET_ALL SGR_BROWN_FOREGROUND
            << used_time.count() << "s\n"
            << std::endl;
  //------------------------------------------------------------//

  //------------------------ shell -----------------------------//
  test_array = random_array;

  begin = std::chrono::steady_clock::now();

  test_array.shell_sort();

  end = std::chrono::steady_clock::now();

  used_time = end - begin;

  std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
      "Random Shell Sort: " SGR_RESET_ALL SGR_BROWN_FOREGROUND
            << used_time.count() << "s\n";
  //-//

  begin = std::chrono::steady_clock::now();

  test_array.shell_sort();

  end = std::chrono::steady_clock::now();

  used_time = end - begin;

  std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
      "Sequence Shell Sort: " SGR_RESET_ALL SGR_BROWN_FOREGROUND
            << used_time.count() << "s\n";
  //-//

  test_array = reverse_array;

  begin = std::chrono::steady_clock::now();

  test_array.shell_sort();

  end = std::chrono::steady_clock::now();

  used_time = end - begin;

  std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
      "Reverse Shell Sort: " SGR_RESET_ALL SGR_BROWN_FOREGROUND
            << used_time.count() << "s\n"
            << std::endl;
  //------------------------------------------------------------//

  return 0;
}
