/**
 * Copyright(C) 2021 Supdrewin <https://github.com/supdrewin>
 * AdjacencyMatrix.hpp is part of Adjacency Matrix Example.
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

#if not defined(__adjacency_matrix_hpp)
#define __adjacency_matrix_hpp

#include <iomanip>

#include "CompressedMatrix.hpp"

template <int max_vertex_number>
class adjacency_matrix
    : public compressed_matrix<int, max_vertex_number, max_vertex_number> {
protected:
  // edges;
  std::string vertices;
  int vertices_number;

public:
  adjacency_matrix() : vertices(), vertices_number(0) {}
  adjacency_matrix(std::string vertices) {
    this->vertices = vertices;
    this->set_vertices_number();
  }
  virtual ~adjacency_matrix() {}

  void set_vertices_number() { this->vertices_number = this->vertices.size(); }
  int get_vertices_number() { return this->vertices_number; }

  int edges_number() { return this->get_size(); }

  bool add_vertex(char vertex) {
    for (auto v : this->vertices)
      if (v == vertex) {
        _print_info(__PRETTY_FUNCTION__ + ": Warning for exist vertex!", );
        return false;
      }

    this->vertices += vertex;
    this->set_vertices_number();
    return true;
  }
  void delete_vertex(int index) {
    this->vertices.erase(index, 1);
    this->set_vertices_number();
    this->trim_edges_of_vertex(index);
  }
  void delete_vertex(char vertex) {
    this->delete_vertex(this->vertices.find_first_of(vertex));
  }

  bool add_edge(int head, int end, int weight) {
    return this->add(head, end, weight);
  }
  bool delete_edge(int index) { return this->erase(index); }
  bool delete_edge(int head, int end) { return this->pos_erase(head, end); }

  void trim_edges_of_vertex(int vertex) {
    for (int i = 0; i < this->get_size(); ++i)
      if (this->list[i].line == vertex or //
          this->list[i].culomn == vertex)
        this->erase(i--);
      else {
        if (this->list[i].line > vertex)
          this->list[i].line--;
        if (this->list[i].culomn > vertex)
          this->list[i].culomn--;
      }
  }

  void print() {
    _print_info("The number of vertices:", "-n");
    std::cout << this->vertices_number << std::endl;

    _print_info("The number of edges:", "-n");
    std::cout << this->edges_number() << std::endl;

    _print_info("Now print this adjacency matrix:", );
    for (int i = 0, k = 0; i < this->get_vertices_number(); ++i) {
      std::cout << vertices[i];
      for (int j = 0; j < this->get_vertices_number(); ++j)
        std::cout << std::setw(6)
                  << ((this->list[k].line == i and //
                       this->list[k].culomn == j)
                          ? this->list[k++].data
                          : (i == j ? 0 : -1));
      std::cout << std::endl;
    }
  }
};

#endif // not defined(__adjacency_matrix_hpp)
