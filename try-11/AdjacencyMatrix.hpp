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

#pragma once

#ifndef __adjacency_matrix_hpp
#define __adjacency_matrix_hpp

#include "../try-7/CompressedMatrix.hpp"

template <int max_vertex_number>
class adjacency_matrix
    : CompressedMatrix<int, max_vertex_number, max_vertex_number> {
protected:
  // edges;
  std::string vertices;
  int vertex_number, edge_number;

public:
  adjacency_matrix() : vertices(), vertex_number(0), edge_number(0) {
    this->init();
  }
  adjacency_matrix(std::string vertices) {
    this->vertices = vertices;
    this->set_vertex_number();
    this->init();
  }
  virtual ~adjacency_matrix() {}

  void init() {
    for (int i = 0; i < max_vertex_number; ++i)
      for (int j = 0; j < max_vertex_number; ++j)
        this->arr.data[i][j] = (i == j ? 0 : -1);
  }

  void set_vertex_number() { this->vertex_number = this->vertices.size(); }
  int get_vertex_number() { return this->vertex_number; }

  void add_vertex(char vertex) {
    this->vertices += vertex;
    this->set_vertex_number();
  }
  void delete_vertex() {}

  void print_edges_of_vertex(int vertex) {}
  void add_edge(int x, int y, int data) {
    this->add(x - 1, y - 1, data);
    this->c_arr();
  }
  void delete_edge() {}

  void print() {
    _print_info("The number of vertices:", "-n");
    std::cout << this->vertex_number << std::endl;

    _print_info("Now print this adjacency matrix:", );

    for (int i = 0; i < this->get_vertex_number(); ++i) {
      std::cout << vertices[i] << '\t';
      for (int j = 0; j < this->vertex_number; ++j, std::cout << '\t')
        std::cout << this->arr.data[i][j];

      std::cout << std::endl;
    }
  }
};

#endif // !__adjacency_matrix_hpp
