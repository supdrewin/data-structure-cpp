/**
 * Copyright(C) 2021 Supdrewin <https://github.com/supdrewin>
 * SequenceStack.hpp is part of Sequence Stack Example.
 * The Sequence Stack Example is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 * The Sequence Stack Example is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABI-
 * LITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <https://www.gnu.org/licenses/>.
 */

#if !defined(__sequence_stack_hpp)
#define __sequence_stack_hpp

#include "utility.hpp"

template <typename elem_type, int max_size> //
class SequenceStack {
protected:
  elem_type stack[max_size];
  int size = 0;

public:
  int empty() {
    if (this->size <= 0)
      return true;
    return false;
  }

  int push(elem_type x) {
    if (this->size >= max_size) {
      std::cerr << "push: Too full to push!" //
                << std::endl;
      return false;
    }

    this->stack[this->size] = x;
    this->size++;
    return true;
  }

  elem_type pop() {
    if (this->size <= 0) {
      std::cerr << "pop: Stack is empty!" //
                << std::endl;
      return elem_type(false);
    }

    this->size--;
    return this->stack[this->size];
  }

  elem_type top() {
    if (this->size <= 0) {
      std::cerr << "top: Stack is empty!" //
                << std::endl;
      return elem_type(false);
    }

    return this->stack[this->size - 1];
  }
};

#endif // !defined(__sequence_stack_hpp)
