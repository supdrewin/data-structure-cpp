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

#include <memory>

namespace my_cpp {

template <class _Tp> class deque {
public:
  using size_type = unsigned;
  using value_type = _Tp;
  using reference = value_type &;
  using const_reference = const value_type &;

protected:
  size_type __count, __offset, __max_size;
  std::unique_ptr<value_type[]> __data;

public:
  deque()
      : __count(0), __offset(0), __max_size(2),
        __data(new value_type[__max_size]) {}

  size_type size() const noexcept { return this->__count; }

  size_type max_size() const noexcept { return this->__max_size; }

  void resize(size_type __n) {
    if (__n < __count)
      __n = __count;

    auto tmp = new value_type[__n];
    for (unsigned i{}; i < __count; ++i)
      tmp[i] = __data[i + __offset];

    this->__data.reset(tmp);
    this->__max_size = __n;
    this->__offset = 0;
  }

  void shrink_to_fit() noexcept { this->resize(this->size()); }

  bool empty() const noexcept { return this->size() == 0; }

  reference operator[](size_type __i) noexcept { return this->__data[__i]; }

  const_reference operator[](size_type __i) const noexcept {
    return this->__data[__i];
  }

  // reference at(size_type __i) noexcept {}

  // const_reference at(size_type __i) const noexcept {}

  value_type front() noexcept {
    return this->empty() ? static_cast<value_type>(0) : this->__data[__offset];
  }

  // const_reference front() const noexcept {}

  value_type back() noexcept {
    return this->empty() ? static_cast<value_type>(0)
                         : this->__data[__count + __offset - 1];
  }

  // const_reference back() const noexcept {}

  // void push_front(value_type __v) {}

  void push_back(value_type __v) {
    if (__count + __offset == __max_size)
      this->resize(this->size() * 2);

    this->__data[__count + __offset] = __v;
    ++this->__count;
  }

  void pop_front() {
    if (!this->empty()) {
      ++this->__offset;
      --this->__count;
    }
  }

  void pop_back() { this->empty() ? 0 : --this->__count; }
};

} // namespace my_cpp

#endif // !__deque_hpp
