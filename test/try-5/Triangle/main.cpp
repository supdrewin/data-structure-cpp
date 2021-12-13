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

#include "SequenceQueue.hpp"

void triangle(int n) {
  sequence_queue<long> queue;
  int x, y{};

  queue.push(1);

  for (int i{}; i < n; i++) {
    // Output an inverted triangle.
    for (int j{}; j < n - i; j++)
      std::cout << "   ";

    // For output 1->\n->1.
    queue.push(0);

    for (int j = 0; j <= i + 1; j++) {
      x = queue.back();
      queue.pop();
      i < n ? queue.push(x + y) : void(0);

      if ((y = x))
        std::cout << x << "    ";
      else
        std::cout << std::endl;
    }
  }
}

int __main() {
  __assert(argc == 2 and atoi(argv[1]) > 0);
  triangle(atoi(argv[1]));
  return 0;
}
