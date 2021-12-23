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
 * with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __adjacency_matrix_hpp
#define __adjacency_matrix_hpp 1

#include "CompressedMatrix.hpp"
#include "array.hpp"
#include "queue.hpp"

template <size_t max_vertex_number>
class adjacency_matrix
    : public compressed_matrix<int, max_vertex_number, max_vertex_number> {
protected:
  std::string vertices;
  size_t vertices_number;

public:
  via::array<int> distance, path;

  adjacency_matrix() : vertices(), vertices_number(), distance(), path() {}

  adjacency_matrix(std::string v)
      : vertices(v), vertices_number(), distance(), path() {
    this->set_vertices_number();
  }

  //----------------- vertices number ----------------------------//
  void set_vertices_number() { this->vertices_number = this->vertices.size(); }

  size_t get_vertices_number() { return this->vertices_number; }

  void print_vertices_number() {
    std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
        "The number of vertices: " SGR_RESET_ALL SGR_MAGENTA_FOREGROUND
              << this->vertices_number << std::endl;
  }
  //----------------- vertices number ----------------------------//

  //-------------------- edges number ----------------------------//
  size_t edges_number() { return size_t(this->get_size()); }

  void print_edges_number() {
    std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
        "The number of edges: " SGR_RESET_ALL SGR_MAGENTA_FOREGROUND
              << this->edges_number() << std::endl;
  }
  //-------------------- edges number ----------------------------//

  //-------------------------- vertex ----------------------------//
  bool add_vertex(char vertex) {
    for (auto _ : this->vertices)
      if (_ == vertex) {
        std::cout << SGR_BLINK_ON SGR_BOLD SGR_RED_FOREGROUND
                  << __PRETTY_FUNCTION__
                  << ": Warning for existing vertex!\n" SGR_BLINK_OFF;
        return false;
      }
    this->vertices += vertex;
    this->set_vertices_number();
    return true;
  }

  void delete_vertex(size_t index) {
    this->vertices.erase(index, 1);
    this->set_vertices_number();
    this->trim_edges_of_vertex(index);
  }

  void delete_vertex(char vertex) {
    this->delete_vertex(this->vertices.find_first_of(vertex));
  }

  auto begin() { return this->vertices.begin(); }
  auto end() { return this->vertices.end(); }

  auto &operator[](size_t __i) { return this->vertices[__i]; }
  //-------------------------- vertex ----------------------------//

  //-------------------------- edge ------------------------------//
  bool add_edge(size_t head, size_t end, int weight) {
    return this->add(head, end, weight);
  }

  bool delete_edge(size_t index) { return this->erase(index); }

  bool delete_edge(size_t head, size_t end) {
    return this->erase_position(head, end);
  }

  void trim_edges_of_vertex(size_t vertex) {
    for (size_t i{}; i < this->edges_number(); ++i)
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

  //-------------------------- path ------------------------------//
  void dijkstra(size_t index) {
    via::array<bool> mark(this->get_vertices_number());

    this->distance.resize(this->get_vertices_number());
    this->distance.fill(-1);

    this->path.resize(this->get_vertices_number());
    this->path.fill(-1);

    for (size_t i{}; i < this->get_vertices_number(); ++i) {
      for (size_t j{}; j < this->edges_number(); ++j)
        if (this->list[j].line == index and this->list[j].culomn == i) {
          this->distance[i] = this->list[j].data;
          break;
        }

      if (i != index and this->distance[i] != -1)
        this->path[i] = int(index);
    }

    this->distance[index] = 0;
    mark[index] = true;

    for (size_t i{1}; i < this->get_vertices_number(); ++i) {
      size_t close{};
      int min{-1};

      for (size_t j{}; j < this->get_vertices_number(); ++j)
        if (not mark[j] and this->distance[j] != -1)
          if (this->distance[j] < min or min == -1) {
            min = this->distance[j];
            close = j;
          }

      if (min == -1)
        return;

      mark[close] = true;

      for (size_t j{}; j < this->get_vertices_number(); ++j)
        for (size_t k{}; k < this->edges_number(); ++k)
          if (this->list[k].line == close and this->list[k].culomn == j)
            if (not mark[j] and (this->distance[j] == -1 or
                                 this->distance[close] + this->list[k].data <
                                     this->distance[j])) {
              this->distance[j] = this->distance[close] + this->list[k].data;
              this->path[j] = int(close);
              break;
            }
    }
  }
  //-------------------------- path ------------------------------//

  //------------------------- search -----------------------------//
  /** @brief Get the next out of vertex[index] that not visited.
   *  @return <int> the index of vertex[index] out not visited
   *  @param index <int> the index of vertex to get next out
   *  @param visited(default -1) <int> index of last visited
   */// -1 means no vertices are visited
  int get_next_vertex(size_t index, int visited = -1) {
    // check whether the index of vertex vaild or not
    (index < this->get_vertices_number()) and
            (visited >= -1 and visited < int(this->get_vertices_number()))
        ? void(0) // -1 means no vertices are visited
        : std::exit(EXIT_FAILURE);
    for (size_t i{}; i < this->edges_number(); ++i)
      if (index == this->list[i].line and      // next vertex at the same in
          int(this->list[i].culomn) > visited) // but skip last visited out
        return this->list[i].culomn;
    return -1; // no any out degree found
  }

  void depth_first_search(size_t index, bool *visited) {
    int tmp_index{-1};

    std::cout << this->vertices[index] << '\t';
    visited[index] = true;

    while ((tmp_index = this->get_next_vertex(index, tmp_index)) >= 0)
      not visited[tmp_index]
          ? this->depth_first_search(size_t(tmp_index), visited)
          : void(0);
  }

  void depth_first_search() {
    auto visited = new bool[get_vertices_number()]();
    for (size_t i{}; i < this->get_vertices_number(); ++i)
      visited[i] ? void(0) : this->depth_first_search(i, visited);
    delete[] visited;
  }

  // This method using queue just like previous `Pascal's Triangle`.
  void breadth_first_search(size_t index, bool *visited) {
    via::queue<size_t> queue;
    queue.push(index);

    std::cout << this->vertices[index];
    visited[index] = true;

    int begin, end{-1};
    while (not queue.empty()) {
      begin = queue.front();
      queue.pop();

      while ((end = this->get_next_vertex(size_t(begin), end)) >= 0)
        if (not visited[end]) {
          std::cout << '\t' << this->vertices[size_t(end)];
          queue.push(size_t(end));
          visited[end] = true;
        }
    }
  }

  void breadth_first_search() {
    auto visited = new bool[get_vertices_number()]();
    for (size_t i{}; i < this->get_vertices_number(); ++i)
      visited[i] ? void(0) : this->breadth_first_search(i, visited);
    delete[] visited;
  }
  //------------------------- search -----------------------------//

  //--------------------------- print ----------------------------//
  void print_matrix() {
    std::cout << SGR_BOLD SGR_GREEN_FOREGROUND
        "Now print this adjacency matrix:\n" //
        SGR_RESET_ALL SGR_MAGENTA_FOREGROUND;
    for (size_t i{}, k = 0; i < this->get_vertices_number(); ++i) {
      std::cout << vertices[size_t(i)];
      for (size_t j{}; j < this->get_vertices_number(); ++j)
        printf("%6d", ((this->list[k].line == i and this->list[k].culomn == j)
                           ? this->list[k++].data
                           : (i == j ? 0 : -1)));
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
