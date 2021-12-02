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
  sequence_queue<int, 100> queue(1);
  int x, y = 0;

  for (int i = 0; i < n; i++) {
    // Output an inverted triangle.
    for (int j = 0; j < n - i; j++)
      std::cout << "   ";

    // For output 1->\n->1.
    queue.append(0);

    for (int j = 0; j <= i + 1; j++) { // i j   j   i j   j   j   i j
      x = queue.del();                 // 0 0   1   1 0   1   2   2 0
      i < n ? queue.append(x + y) : 0; // y x y x y   x y x y x y   ...
                                       // 0 1 1 0 0   1 1 1 1 0 0   ...
      if ((y = x))                     // + + - + - + + - + - + - + ...
        std::cout << x << "    ";      // 0 1 1 1 0 0 1 1 2 1 1 0 0 ...
      else
        std::cout << std::endl;
    }
  }
}

int main() {
  __assert(argc == 2 and std::atoi(argv[1]) > 0);
  triangle(std::atoi(argv[1]));
  return 0;
}
