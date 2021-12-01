/**
 * Copyright(C) 2021 Supdrewin <https://github.com/supdrewin>
 * main.cpp is part of Adjacency Matrix Example.
 * The Adjacency Matrix Example is free software: you can redistribute
 * it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * The Adjacency Matrix Example is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 * You should have received a copy of the GNU General Public License along
 * with this program.If not, see <https://www.gnu.org/licenses/>.
 */

#include "AdjacencyMatrix.hpp"

int main() {
  adjacency_matrix<6> am("abcdef");

  am.add_edge(2, 1, 2);
  am.add_edge(1, 3, 5);
  am.add_edge(1, 4, 30);
  am.add_edge(3, 2, 15);
  am.add_edge(2, 5, 8);
  am.add_edge(5, 4, 4);
  am.add_edge(6, 4, 10);
  am.add_edge(6, 5, 18);
  am.add_edge(3, 6, 7);

  am.print();

  return 0;
}
