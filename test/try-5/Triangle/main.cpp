/**
 * Copyright(C) 2021 Supdrewin <https://github.com/supdrewin>
 * Triangle.cpp is part of Sequence Queue Example.
 * The Sequence Queue Example is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 * The Sequence Queue Example is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.If not, see <https://www.gnu.org/licenses/>.
 */

#include "queue.hpp"
#include "utility.hpp"

void triangle(int n) {
  my_cpp::queue<long> tmp_queue;
  tmp_queue.push(1);

  int x, y{};

  for (int i{}; i < n; i++) {
    // Output an inverted triangle.
    for (int j{}; j < n - i; j++)
      std::cout << "   ";

    // For output 1->\n->1.
    tmp_queue.push(0);

    for (int j = 0; j <= i + 1; j++) {
      x = tmp_queue.front();
      tmp_queue.pop();
      i < n ? tmp_queue.push(x + y) : void(0);

      if ((y = x))
        std::cout << x << "    ";
      else
        std::cout << std::endl;
    }
  }
}

int __main() {
  __assert(argc == 2 and         //
           atoi(argv[1]) > 0 and //
           atoi(argv[1]) < 35);
  triangle(atoi(argv[1]));
  return 0;
}
