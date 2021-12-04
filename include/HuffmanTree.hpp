/**
 * Copyright(C) 2021 Supdrewin <https://github.com/supdrewin>
 * HuffmanTree.hpp is part of Huffman Tree Example.
 * The Huffman Tree Example is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 * The Huffman Tree Example is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __huffman_tree_hpp
#define __huffman_tree_hpp 1

#include <iomanip>

#include "utility.hpp"

template <typename weight_type, int node_count> //
class huffman_tree {
protected:
  // root node and the size of buffman tree - 1
  static const int root = (node_count - 1) * 2;

  // huffman tree node datastructure
  struct huffman_tree_node {
    int left_child, right_child, parent;
    weight_type weight, max_weight;

    std::string code{};

    // all parents and children are init as invaild
    huffman_tree_node()
        : left_child{-1}, right_child{-1}, parent{-1}, //
          weight{0}, max_weight{0} {}
    ~huffman_tree_node() {}
  } node[unsigned(root + 1)];
  // actual buffman tree

  struct code_node {
    char mark{};
    std::string code{};

    // print list node
    void print() {
      std::cout << std::setw(4) << this->mark          //
                << std::setw(node_count) << this->code //
                << std::endl;
    }

    code_node() = default;
    ~code_node() {}
  } code_list[unsigned(node_count)];

  // index of code list
  int code_index[unsigned(node_count)];

public:
  huffman_tree() = default;

  // constructor using weight array
  huffman_tree(weight_type *weight, std::string mark) {
    // get the max weight
    for (int i = 0; i < node_count; ++i)
      this->node->max_weight = __max(this->node->max_weight, weight[i]);

    for (int i = 0; i < node_count; ++i) {
      // init and make sure enough size
      this->node[i].weight = this->node->max_weight;

      for (int j = 0; j < node_count; ++j)
        // skip val not ge the last weight and avoid invaild compare
        if (i ? weight[j] == this->node[i - 1].weight : false) {
          // skip the same code index and break after uneq weight
          for (int k = i - 1; k >= 0; --k)
            if (j == this->code_index[k])
              break;
            else if (weight[j] != this->node[k].weight) {
              this->node[i].weight = weight[j];

              // init the code list and gen index for code node
              this->code_list[j].mark = mark.c_str()[j];
              this->code_index[i] = j;
              break;
            }
        } else if ((i ? weight[j] > this->node[i - 1].weight : true) and
                   this->node[i].weight >= weight[j]) {
          this->node[i].weight = weight[j];

          // init the code list and gen index for code node
          this->code_list[j].mark = mark.c_str()[j];
          this->code_index[i] = j;
        }
    }

    // the last tree nodes with their parent
    this->node[node_count].weight = //
        this->node[0].weight + this->node[1].weight;
    this->node[0].parent = this->node[1].parent = node_count;

    this->node[node_count].left_child = 0;
    this->node[0].code = std::string("0");

    this->node[node_count].right_child = 1;
    this->node[1].code = std::string("1");

    // each tree node with their parents and children
    for (int i = 1; i < node_count - 1; ++i) {
      this->node[node_count + i].weight =
          this->node[node_count + i - 1].weight + this->node[i + 1].weight;
      this->node[node_count + i - 1].parent = this->node[i + 1].parent =
          node_count + i;

      // judging left and right child trees
      if (this->node[node_count + i - 1].weight < this->node[i + 1].weight) {
        this->node[node_count + i].left_child = node_count + i - 1;
        this->node[node_count + i - 1].code = std::string("0");

        this->node[node_count + i].right_child = i + 1;
        this->node[i + 1].code = std::string("1");
      } else {
        this->node[node_count + i].left_child = i + 1;
        this->node[i + 1].code = std::string("0");

        this->node[node_count + i].right_child = node_count + i - 1;
        this->node[node_count + i - 1].code = std::string("1");
      }
    }
  }

  // do nothing here
  virtual ~huffman_tree() {}

  // method to get the max weight
  weight_type max_weight() { return this->node->max_weight; }

  // auto config a code list
  void code_list_config() {
    for (int i = 0; i < node_count; ++i)
      for (int j = i; j < root; j = this->node[j].parent)
        this->code_list[this->code_index[i]] //
            .code.insert(0, this->node[j].code);
  }

  // print the code list
  void code_list_print() {
    // print list head
    std::cout << std::setw(4) << "mark"          //
              << std::setw(node_count) << "code" //
              << std::endl;

    // print list body
    for (int i = 0; i < node_count; ++i)
      this->code_list[i].print();
  }

  // print as list format
  void print() {
    // print list head
    std::cout << std::setw(4) << "node"         //
              << std::setw(6) << "mark"         //
              << std::setw(8) << "weight"       //
              << std::setw(8) << "parent"       //
              << std::setw(12) << "left child"  //
              << std::setw(13) << "right child" //
              << std::endl;

    // print list body
    for (int i = 0; i < root + 1; ++i) {
      std::cout << std::setw(4) << i;

      std::cout << std::setw(6)
                << (i < node_count //
                        ? this->code_list[this->code_index[i]].mark
                        : '*');

      std::cout << std::setw(8) << this->node[i].weight;

      std::cout << std::setw(8);
      relative_vaild_print(this->node[i].parent);

      std::cout << std::setw(12);
      relative_vaild_print(this->node[i].left_child);

      std::cout << std::setw(13);
      relative_vaild_print(this->node[i].right_child);

      std::cout << std::endl;
    }
  }

  static void relative_vaild_print(int self) {
    if (self == -1)
      std::cout << '*';
    else
      std::cout << self;
  }
};

#endif // !__huffman_tree_hpp
