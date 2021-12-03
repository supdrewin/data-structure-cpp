/**
 * Copyright(C) 2021 Supdrewin <https://github.com/supdrewin>
 * BinaryTree.hpp is part of Binary Tree Example.
 * The Binary Tree Example is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * The Binary Tree Example is distributed in the hope that it will be useful
 * , but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHAN-
 * TABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
 * License for more details.
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __binary_tree_hpp
#define __binary_tree_hpp 1

template <typename _data> //
class binary_tree {
protected:
  struct node {
    _data data;
    node *left, *right;
    node() : left(nullptr), right(nullptr) {}
    node(_data d, node *l = nullptr, node *r = nullptr)
        : data(d), left(l), right(r) {}
    ~node() {}
  } * root;

public:
  binary_tree() : root(nullptr) { this->create(); };
  ~binary_tree() { this->destroy(); }

  inline bool empty() { return this->root ? false : true; }

  // TODO:...

  int create() { create(this->root); }
  int create(node *n) {}

  int destroy() { return this->root ? destroy(this->root) : false; }
  int destroy(node *n) { return n ? destroy(n) : false; }
};

#endif // !__binary_tree_hpp
