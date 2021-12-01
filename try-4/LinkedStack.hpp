/**
 * Copyright(C) 2021 Supdrewin <WITHOUT ANY WARRANTY>
 * LinkedStack.hpp is part of Linked Stack Example.
 * The Linked Stack Example is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 * The Linked Stack Example is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <iostream>

template <typename ElemType, int MaxSize> //
class SequenceStack {
protected:
  ElemType stack[MaxSize];
  int size = 0;

public:
  int empty() {
    if (this->size <= 0)
      return true;
    return false;
  }

  int push(ElemType x) {
    if (this->size >= MaxSize) {
      std::cerr << "push: Too full to push!" //
                << std::endl;
      return false;
    }

    this->stack[this->size] = x;
    this->size++;
    return true;
  }

  ElemType pop() {
    if (this->size <= 0) {
      std::cerr << "pop: Stack is empty!" //
                << std::endl;
      return (ElemType) false;
    }

    this->size--;
    return this->stack[this->size];
  }

  ElemType top() {
    if (this->size <= 0) {
      std::cerr << "top: Stack is empty!" //
                << std::endl;
      return (ElemType) false;
    }

    return this->stack[this->size - 1];
  }
};
