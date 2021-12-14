/** queue.hpp -*- C++ -*- Copyright (C) 2021 Supdrewin
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

#ifndef __queue_hpp
#define __queue_hpp 1

#include "deque.hpp"

namespace my_cpp {

template <class _Tp> class queue {
public:
  using container_type = deque<_Tp>;
  using size_type = typename container_type::size_type;
  using value_type = typename container_type::value_type;

protected:
  container_type c;

public:
  queue() : c() {}

  bool empty() const { return c.empty(); }

  size_type size() const { return c.size(); }

  value_type front() { return c.front(); }

  value_type back() { return c.back(); }

  void push(value_type __v) { c.push_back(__v); }

  void pop() { c.pop_front(); }
};

} // namespace my_cpp

#endif // !__queue_hpp
