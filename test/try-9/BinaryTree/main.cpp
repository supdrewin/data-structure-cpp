/**
 * Copyright(C) 2021 Supdrewin <https://github.com/supdrewin>
 * main.cpp is part of Binary Tree Example.
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

#include <cstdio>

#include "BinaryTree.hpp"

int main() {
  binary_tree<char> bt('A');
  bt.root->lchild = new binary_tree<char>::node('B');
  bt.root->rchild = new binary_tree<char>::node('F');
  bt.root->lchild->lchild = new binary_tree<char>::node('C');
  bt.root->lchild->lchild->lchild = new binary_tree<char>::node('D');
  bt.root->lchild->lchild->rchild = new binary_tree<char>::node('E');
  bt.root->rchild->lchild = new binary_tree<char>::node('G');

  auto pre{bt.preorder_traversal()}, in{bt.inorder_traversal()},
      post{bt.postorder_traversal()}, level{bt.levelorder_traversal()};

  printf("The number of nodes: %d", static_cast<int>(level.size()));

  printf("\nPreorder Traversal:");
  for (auto _ : pre)
    printf("\t%c", _);

  printf("\nInorder Traversal:");
  for (auto _ : in)
    printf("\t%c", _);

  printf("\nPostorder Traversal:");
  for (auto _ : post)
    printf("\t%c", _);

  printf("\nLevelorder Traversal:");
  for (auto _ : level)
    printf("\t%c", _);

  return 0;
}
