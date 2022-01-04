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

#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

template <class tp> struct binary_tree {
  struct node {
    tp data;
    node *lchild, *rchild;
    node() : data(), lchild(), rchild() {}
    node(tp d) : data(d), lchild(), rchild() {}
  } * root;

  binary_tree() : root() {}
  binary_tree(tp d) : root(new node(d)) {}
  ~binary_tree() { destroy(); }

  void destroy() { destroy(root); }
  void destroy(node *cur) {
    cur->lchild ? destroy(cur->lchild) : void(0);
    cur->rchild ? destroy(cur->rchild) : void(0);
    delete cur;
  }

  std::vector<tp> preorder_traversal() {
    std::stack<node *> st;
    std::vector<tp> result;
    if (not root)
      return result;
    st.push(root);
    while (not st.empty()) {
      node *cur{st.top()};
      st.pop();
      result.push_back(cur->data);
      cur->rchild ? st.push(cur->rchild) : void(0);
      cur->lchild ? st.push(cur->lchild) : void(0);
    }
    return result;
  }

  std::vector<tp> inorder_traversal() {
    std::stack<node *> st;
    std::vector<tp> result;
    node *cur{root};
    while (cur or not st.empty())
      if (cur) {
        st.push(cur);
        cur = cur->lchild;
      } else {
        cur = st.top();
        st.pop();
        result.push_back(cur->data);
        cur = cur->rchild;
      }
    return result;
  }

  std::vector<tp> postorder_traversal() {
    std::stack<node *> st;
    std::vector<tp> result;
    if (not root)
      return result;
    st.push(root);
    while (not st.empty()) {
      node *cur{st.top()};
      st.pop();
      result.push_back(cur->data);
      cur->lchild ? st.push(cur->lchild) : void(0);
      cur->rchild ? st.push(cur->rchild) : void(0);
    }
    std::reverse(result.begin(), result.end());
    return result;
  }

  std::vector<tp> levelorder_traversal() {
    std::queue<node *> q;
    std::vector<tp> result;
    if (not root)
      return result;
    q.push(root);
    while (not q.empty()) {
      node *cur{q.front()};
      q.pop();
      result.push_back(cur->data);
      cur->lchild ? q.push(cur->lchild) : void(0);
      cur->rchild ? q.push(cur->rchild) : void(0);
    }
    return result;
  }
};

#endif // !__binary_tree_hpp
