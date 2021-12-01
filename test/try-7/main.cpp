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
std::random_device rd;

#include "CompressedMatrix.hpp"

#define N 4

using MatrixNxN = CompressedMatrix<int, N, N>;

int main() {
  std::uniform_int_distribution<int> x(0, N - 1);
  std::uniform_int_distribution<int> y(0, N - 1);
  std::uniform_int_distribution<int> data(0, N * N);

  MatrixNxN m;
  MatrixNxN n;

  for (int i = 0; i < N * N; ++i)
    m.sym_add(x(rd), y(rd), data(rd));

  for (int i = 0; i < N * N; ++i)
    n.sym_add(x(rd), y(rd), data(rd));

  //////////////////////////////////////////////
  std::cout << "The sum of multipling matrix" //
            << std::endl;                     //
  m.print();                                  //
  std::cout << "and"                          //
            << std::endl;                     //
  n.print();                                  //
  std::cout << "is"                           //
            << std::endl;                     //
  m.multiply(n).print();                      //
  std::cout << '.'                            //
            << std::endl;                     //

  return 0;
}
