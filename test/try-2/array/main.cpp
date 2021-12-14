/** main.cpp -*- C++ -*- Copyright (C) 2021 Supdrewin
 * This file is part of the Data Structure Cpp Project.
 * This Cpp project is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 * This Cpp project is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include <iostream>

#include "array.hpp"

int main() {
  my_cpp::array<int> arr;

  arr.at(0) = 1;
  arr.at(2) = 1;
  arr.resize(5);
  arr[3] = 3;
  arr[4] = 1;

  for (auto _ : arr)
    std::cout << _ << '\t';
  return 0;
}
