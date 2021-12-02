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

  am.add_edge(1, 0, 2);
  am.add_edge(0, 2, 5);
  am.add_edge(0, 3, 30);
  am.add_edge(2, 1, 15);
  am.add_edge(1, 4, 8);
  am.add_edge(4, 3, 4);
  am.add_edge(5, 3, 10);
  am.add_edge(5, 4, 18);
  am.add_edge(2, 5, 7);

  am.print();
  am.delete_edge(2);
  am.print();
  am.delete_vertex(2);
  am.print();
  am.delete_vertex(4);
  am.print();

  am.add_vertex('z');
  am.print();
  am.add_vertex('c');
  am.print();
  am.add_vertex('d');
  am.print();

  return 0;
}
