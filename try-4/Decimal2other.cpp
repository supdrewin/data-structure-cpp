/**
 * Copyright(C) 2021 Supdrewin <WITHOUT ANY WARRANTY>
 * Decimal2other.cpp is part of Linked Stack Example.
 * The Linked Stack Example is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 * The Linked Stack Example is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.If not, see <https://www.gnu.org/licenses/>.
 */

#include "LinkedStack.hpp"

using std::cerr;
using std::cout;
using std::endl;

void convert(int decimal, int scale) {
  SequenceStack<char, 100> stack;
  char TMP, sign = '+';

  if (decimal < 0) {
    decimal = -decimal;
    sign = '-';
  }

  // Just coverting integer to C_String.
  for (int tmp; decimal; decimal /= scale) {
    if ((tmp = decimal % scale) < 10)
      TMP = tmp + 48;
    else
      TMP = tmp + 87;

    stack.push(TMP);
  }

  cout << sign;

  while (!stack.empty())
    cout << stack.pop();

  cout << endl;
}

int main(int argc, char **argv) {
  if (argc == 3)
    convert(atoi(argv[1]), atoi(argv[2]));
  else
    // OK, now show user-friendly tips.
    cerr << "Synopsis:" << endl
         << "\tDecimal2other <arg1> <arg2>" << endl
         << "Options:" << endl
         << "\targ1: a decimal to convert" << endl
         << "\targ2: the conversion to use" << endl;

  return 0;
}
