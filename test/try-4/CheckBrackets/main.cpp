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

#include "stack.hpp"
#include "utility.hpp"

bool check(std::string expr) {
  my_cpp::stack<char> stack;

  for (size_t i = 0; expr[i]; i++)
    if (expr[i] == '[' or // push `[' and `(' into stack
        expr[i] == '(')
      stack.push(expr[i]);
    else if (expr[i] == ']') // important for check `[]'
      if (stack.top() != '[')
        return false;
      else
        stack.pop();
    else if (expr[i] == ')') // important for check `()'
      if (stack.top() != '(')
        return false;
      else
        stack.pop();
    else // close condition
      continue;

  return (stack.empty() ? true : false);
}

int __main() {
  __assert(argc == 2); // I'm actually NOT interactive.
  std::string expr(argv[1]);

  if (check(expr))
    std::cout << "Expression `" << expr << "' is vaild!" << std::endl;
  else
    std::cerr << "Expression `" << expr << "' is invaild!" << std::endl;

  return 0;
}
