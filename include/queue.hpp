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

namespace via {

template <class value_type> class queue {
public:
  using container_type = deque<value_type>;
  using size_type = typename container_type::size_type;

protected:
  container_type __queue;

public:
  queue() : __queue() {}

  bool empty() const { return __queue.empty(); }

  size_type size() const { return __queue.size(); }

  value_type front() { return __queue.front(); }

  value_type back() { return __queue.back(); }

  void push(value_type __v) { __queue.push_back(__v); }

  void pop() { __queue.pop_front(); }
};

} // namespace via

#endif // !__queue_hpp
