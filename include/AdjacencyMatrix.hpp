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

#ifndef __adjacency_matrix_hpp
#define __adjacency_matrix_hpp 1

#include <iomanip>

#include "CompressedMatrix.hpp"
#include "SequenceQueue.hpp"

template <int max_vertex_number>
class adjacency_matrix
    : public compressed_matrix<int, max_vertex_number, max_vertex_number> {
protected:
  std::string vertices{};
  int vertices_number{};

public:
  adjacency_matrix() = default;

  adjacency_matrix(std::string vertices) {
    this->vertices = vertices;
    this->set_vertices_number();
  }

  virtual ~adjacency_matrix() = default;

  //----------------- vertices number ----------------------------//
  void set_vertices_number() { this->vertices_number = this->vertices.size(); }

  int get_vertices_number() { return this->vertices_number; }

  void print_vertices_number() {
    std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
        "The number of vertices: " SGR_RESET_ALL SGR_MAGENTA_FOREGROUND
              << this->vertices_number << std::endl;
  }
  //----------------- vertices number ----------------------------//

  //-------------------- edges number ----------------------------//
  int edges_number() { return this->get_size(); }

  void print_edges_number() {
    std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
        "The number of edges: " SGR_RESET_ALL SGR_MAGENTA_FOREGROUND
              << this->edges_number() << std::endl;
  }
  //-------------------- edges number ----------------------------//

  //-------------------------- vertex ----------------------------//
  bool add_vertex(char vertex) {
    for (auto v : this->vertices)
      if (v == vertex) {
        std::cout << SGR_BLINK_ON SGR_BOLD SGR_RED_FOREGROUND
                  << __PRETTY_FUNCTION__
                  << ": Warning for existing vertex!\n" SGR_BLINK_OFF;
        return false;
      }
    this->vertices += vertex;
    this->set_vertices_number();
    return true;
  }

  void delete_vertex(int index) {
    this->vertices.erase(size_t(index), 1);
    this->set_vertices_number();
    this->trim_edges_of_vertex(index);
  }

  void delete_vertex(char vertex) {
    this->delete_vertex(this->vertices.find_first_of(vertex));
  }
  //-------------------------- vertex ----------------------------//

  //-------------------------- edge ------------------------------//
  bool add_edge(int head, int end, int weight) {
    return this->add(head, end, weight);
  }

  bool delete_edge(int index) { return this->erase(index); }

  bool delete_edge(int head, int end) {
    return this->erase_position(head, end);
  }

  void trim_edges_of_vertex(int vertex) {
    for (int i{}; i < this->get_size(); ++i)
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
  //-------------------------- edge ------------------------------//

  //------------------------- search -----------------------------//
  /** @brief Get the next out of vertex[index] that not visited.
   *  @return <int> the index of vertex[index] out not visited
   *  @param index <int> the index of vertex to get next out
   *  @param visited(default -1) <int> index of last visited
   */// -1 means no vertices are visited
  int get_next_vertex(int index, int visited = -1) {
    // check whether the index of vertex vaild or not
    (index >= 0 and index < this->get_vertices_number()) and
            (visited >= -1 and visited < this->get_vertices_number())
        ? void(0) // -1 means no vertices are visited
        : std::exit(EXIT_FAILURE);
    for (int i{}; i < this->edges_number(); ++i)
      if (index == this->list[i].line         // next vertex at the same in
          and this->list[i].culomn > visited) // but skip last visited out
        return this->list[i].culomn;
    return -1; // no any out degree found
  }

  void depth_first_search(int index, bool *visited) {
    index < 0 ? std::exit(EXIT_FAILURE) : void(0);
    int tmp_index{-1};

    std::cout << this->vertices[unsigned(index)] << '\t';
    visited[index] = true;

    while ((tmp_index = this->get_next_vertex(index, tmp_index)) not_eq -1)
      visited[tmp_index] ? void(0) : depth_first_search(tmp_index, visited);
  }

  void depth_first_search() {
    auto visited = new bool[unsigned(get_vertices_number())]();
    for (int i{}; i < this->get_vertices_number(); ++i)
      visited[i] ? void(0) : this->depth_first_search(i, visited);
    delete[] visited;
  }

  // This method using queue just like previous `Pascal's Triangle`.
  void breadth_first_search(int index, bool *visited) {
    index < 0 ? std::exit(EXIT_FAILURE) : void(0);
    auto queue = new sequence_queue<int, max_vertex_number>(index);

    std::cout << this->vertices[unsigned(index)];
    visited[index] = true;

    int begin, end{-1};
    while (not queue->empty()) {
      begin = queue->back();
      while ((end = this->get_next_vertex(begin, end)) not_eq -1)
        if (not visited[end]) {
          std::cout << '\t' << this->vertices[unsigned(end)];
          visited[end] = queue->append(end);
        }
    }

    delete queue;
  }

  void breadth_first_search() {
    auto visited = new bool[unsigned(get_vertices_number())]();
    for (int i{}; i < this->get_vertices_number(); ++i)
      visited[i] ? void(0) : this->breadth_first_search(i, visited);
    delete[] visited;
  }
  //------------------------- search -----------------------------//

  //--------------------------- print ----------------------------//
  void print_matrix() {
    std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
        "Now print this adjacency matrix:\n" //
        SGR_RESET_ALL SGR_MAGENTA_FOREGROUND;
    for (int i{}, k = 0; i < this->get_vertices_number(); ++i) {
      std::cout << vertices[size_t(i)];
      for (int j{}; j < this->get_vertices_number(); ++j)
        std::cout << std::setw(6)
                  << ((this->list[k].line == i and //
                       this->list[k].culomn == j)
                          ? this->list[k++].data
                          : (i == j ? 0 : -1));
      std::cout << std::endl;
    }
  }

  void print() {
    this->print_vertices_number();
    this->print_edges_number();
    this->print_matrix();
  }
  //--------------------------- print ----------------------------//
};

#endif // !__adjacency_matrix_hpp
