/**
 * Copyright(C) 2021 Supdrewin <https://github.com/supdrewin>
 * main.cpp is part of Compressed Matrix Example.
 * The Compressed Matrix Example is free software: you can redistribute
 * it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * The Compressed Matrix Example is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.If not, see <https://www.gnu.org/licenses/>.
 */

#include <random>

#include "CompressedMatrix.hpp"

#define N 4

int main() {
  static std::uniform_int_distribution<int> n_1(0, N - 1);
  static std::uniform_int_distribution<int> n_2_1(0, N * 2 - 1);
  static std::uniform_int_distribution<int> n_n(0, N * N);

  compressed_matrix<int, N, N * 2> m;
  compressed_matrix<int, N * 2, N> n;

  std::random_device rd;

  for (int i = 0; i < N * N * 2; ++i)
    m.add(n_1(rd), n_2_1(rd), n_n(rd));

  for (int i = 0; i < N * N * 2; ++i)
    n.add(n_2_1(rd), n_1(rd), n_n(rd));

  // -----------------------------------------

  std::cout << _control_character("32;1m") "The sum of multipling matrix"
            << _control_character("0;35m") << std::endl;
  m.print();

  std::cout << _control_character("32;1m") "and" //
            << _control_character("0;35m") << std::endl;
  n.print();

  std::cout << _control_character("32;1m") "is" //
            << _control_character("0;35m") << std::endl;
  m.multiply(n).print();

  std::cout << std::endl;

  // -----------------------------------------

  std::cout << _control_character("32;1m") "The sum of multipling matrix"
            << _control_character("0;35m") << std::endl;
  n.print();

  std::cout << _control_character("32;1m") "and" //
            << _control_character("0;35m") << std::endl;
  m.print();

  std::cout << _control_character("32;1m") "is" //
            << _control_character("0;35m") << std::endl;
  n.multiply(m).print();

  return 0;
}
