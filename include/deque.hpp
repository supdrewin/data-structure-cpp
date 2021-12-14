/** deque.hpp -*- C++ -*- Copyright (C) 2021 Supdrewin
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

#ifndef __deque_hpp
#define __deque_hpp 1

#include "array.hpp"

namespace my_cpp {

template <class value_type> class deque {
public:
  using size_type = unsigned long;

protected:
  size_type count, offset, __max_size;
  array<value_type> data;

public:
  deque() : count(0), offset(0), __max_size(2), data(__max_size) {}

  size_type size() const noexcept { return this->count; }

  size_type max_size() const noexcept { return this->__max_size; }

  void resize(size_type __n) {
    if (__n < count)
      __n = count;

    auto tmp = new value_type[__n];
    for (size_type i{}; i < count; ++i)
      tmp[i] = data[(i + offset) % __max_size];

    this->data.reset(tmp);
    this->__max_size = __n;
    this->offset = 0;
  }

  void shrink_to_fit() noexcept { this->resize(this->size()); }

  bool empty() const noexcept { return this->size() == 0; }

  value_type front() noexcept {
    return this->empty() ? static_cast<value_type>(0) : this->data[offset];
  }

  value_type back() noexcept {
    return this->empty() ? static_cast<value_type>(0)
                         : this->data[(count + offset - 1) % __max_size];
  }

  void push_front(value_type __v) {
    if (count == __max_size)
      this->resize(this->size() * 2);

    this->data[offset ? --offset : offset = __max_size - 1] = __v;
    ++this->count;
  }

  void push_back(value_type __v) {
    if (count == __max_size)
      this->resize(this->size() * 2);

    this->data[(count + offset) % __max_size] = __v;
    ++this->count;
  }

  void pop_front() {
    if (!this->empty()) {
      ++this->offset %= __max_size;
      --this->count;
    }
  }

  void pop_back() { this->empty() ? 0 : --this->count; }
};

} // namespace my_cpp

#endif // !__deque_hpp
