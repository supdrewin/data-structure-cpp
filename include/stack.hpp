/** stack.hpp -*- C++ -*- Copyright (C) 2021 Supdrewin
 * This file is part of the Data Structure Cpp Project.
 * This Cpp project is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 * This Cpp project is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __stack_hpp
#define __stack_hpp 1

#include "deque.hpp"
namespace my_cpp {

template <class value_type> class stack {
public:
  using container_type = deque<value_type>;
  using size_type = typename container_type::size_type;

protected:
  container_type __stack;

public:
  stack() : __stack() {}

  bool empty() const { return __stack.empty(); }

  size_type size() const { return __stack.size(); }

  value_type top() { return __stack.back(); }

  void push(value_type __v) { __stack.push_back(__v); }

  void pop() { __stack.pop_back(); }
};

} // namespace my_cpp

#endif // !__stack_hpp
