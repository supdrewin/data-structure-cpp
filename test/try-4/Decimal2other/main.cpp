/**
 * Copyright(C) 2021 Supdrewin <https://github.com/supdrewin>
 * Decimal2other.cpp is part of Sequence Stack Example.
 * The Sequence Stack Example is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 * The Sequence Stack Example is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABI-
 * LITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include "SequenceStack.hpp"

void convert(int decimal, int scale) {
  if (scale < 2)
    std::exit(EXIT_FAILURE);

  SequenceStack<char, 100> stack;

  char sign = '+';
  if (decimal < 0) {
    decimal = -decimal;
    sign = '-';
  }

  // Converting integer to C-style string.
  for (int TMP, tmp; decimal; decimal /= scale) {
    TMP = ((tmp = decimal % scale) < 10 ? 48 : 87);
    stack.push(TMP + tmp);
  }

  std::cout << sign;

  while (!stack.empty())
    std::cout << stack.pop();
  std::cout << std::endl;
}

int __main() {
  if (argc == 3)
    convert(std::atoi(argv[1]), std::atoi(argv[2]));
  else // OK, now show user-friendly tips.
    std::cerr << "Synopsis:" << std::endl
              << "\tDecimal2other <arg1> <arg2>" << std::endl
              << "Options:" << std::endl
              << "\targ1: a decimal to convert" << std::endl
              << "\targ2: the conversion to use" << std::endl;
  return 0;
}
