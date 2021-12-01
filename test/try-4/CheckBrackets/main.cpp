/**
 * Copyright(C) 2021 Supdrewin <https://github.com/supdrewin>
 * CheckBrackets.cpp is part of Linked Stack Example.
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

int check(std::string exp) {
  SequenceStack<char, 100> stack;

  for (int i = 0; exp[i]; i++)
    if (exp[i] == '[' or // push `[' and `(' into stack
        exp[i] == '(')
      stack.push(exp[i]);
    else if (exp[i] == ']') // important for check `[]'
      if (stack.top() != '[')
        return false;
      else
        stack.pop();
    else if (exp[i] == ')') // important for check `()'
      if (stack.top() != '(')
        return false;
      else
        stack.pop();
    else
      continue;

  if (stack.empty())
    return true;
  return false;
}

int main() {
  __assert(argc == 2); // I'm actually NOT interactive.

  std::string expr(argv[1]);

  if (check(expr))
    std::cout << "Expression `" //
              << expr           //
              << "' is vaild!" << std::endl;
  else
    std::cerr << "Expression `" //
              << expr           //
              << "' is invaild!" << std::endl;

  return 0;
}
