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

int main(int, char **) {
  adjacency_matrix<6> graph("abcdef");

  graph.add_edge(1, 0, 2);
  graph.add_edge(0, 2, 5);
  graph.add_edge(0, 3, 30);
  graph.add_edge(2, 1, 15);
  graph.add_edge(1, 4, 8);
  graph.add_edge(4, 3, 4);
  graph.add_edge(5, 3, 10);
  graph.add_edge(5, 4, 18);
  graph.add_edge(2, 5, 7);

  graph.print();
  std::cout << "\n";

  std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
      "Depth First Search:\n" SGR_RESET_ALL SGR_MAGENTA_FOREGROUND;
  graph.depth_first_search();
  std::cout << "\n";

  std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
      "Breath First Search:\n" SGR_RESET_ALL SGR_MAGENTA_FOREGROUND;
  graph.breadth_first_search();
  std::cout << "\n\n";

  for (size_t i{}; i < graph.get_vertices_number(); ++i, std::cout << '\n') {
    graph.dijkstra(i);

    std::cout << SGR_BOLD SGR_GREEN_FOREGROUND "Path[" << i
              << "]: " SGR_RESET_ALL SGR_MAGENTA_FOREGROUND;
    for (size_t j{}; j < graph.get_vertices_number(); ++j)
      std::cout << graph.path[j] << '\t';
    std::cout << '\n';

    size_t j{};
    for (auto _ : graph) {
      std::cout << SGR_BOLD SGR_GREEN_FOREGROUND "Distance from " << graph[i]
                << " to " << _ << " is ";
      if (graph.distance[j] == -1)
        std::cout << SGR_RED_FOREGROUND "unavailable!!";
      else
        std::cout << SGR_RESET_ALL SGR_MAGENTA_FOREGROUND << graph.distance[j];
      std::cout << '\n';
      ++j;
    }
  }

  return 0;
}
