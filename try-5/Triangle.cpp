/**
 * Copyright(C) 2021 Supdrewin <WITHOUT ANY WARRANTY>
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

using std::cout;
using std::endl;

void triangle(int n) {
  SequenceQueue<int, 100> queue(1);
  int x, y = 0;

  for (int i = 0; i < n; i++) {
    // Output an inverted triangle.
    for (int j = 0; j < n - i; j++)
      cout << "   ";

    // For output 1->\n->1.
    queue.Append(0);

    // i j   j   i j   j   j   i j
    // 0 0   1   1 0   1   2   2 0
    // y x y x y   x y x y x y   ...
    // 0 1 1 0 0   1 1 1 1 0 0   ...
    // + + - + - + + - + - + - + ...
    // 0 1 1 1 0 0 1 1 2 1 1 0 0 ...
    for (int j = 0; j <= i + 1; j++) {
      x = queue.Delete();
      if (i < n)
        queue.Append(x + y);

      if ((y = x))
        cout << x << "    ";
      else
        cout << endl;
    }
  }
}

int main(int argc, char **argv) {
  if (argc != 2 or atoi(argv[1]) <= 0)
    return EXIT_FAILURE;

  triangle(atoi(argv[1]));
  return 0;
}
