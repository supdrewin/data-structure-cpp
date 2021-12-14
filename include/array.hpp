/** array.hpp -*- C++ -*- Copyright (C) 2021 Supdrewin
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

#ifndef __array_hpp
#define __array_hpp

namespace my_cpp {

template <class _Tp> class array {
public:
  using container_type = array;
  using size_type = unsigned long;
  using value_type = _Tp;
  using reference = value_type &;

protected:
  size_type __max_size;
  value_type *data;

public:
  array() : __max_size(), data(new value_type[__max_size]()) {}

  array(size_type __n) : __max_size(__n), data(new value_type[__max_size]()) {}

  array(const container_type &__arr) { this->operator=(__arr); }

  ~array() { this->reset(); }

  size_type size() { return this->__max_size; }

  value_type *begin() { return &this->operator[](0); }

  value_type *end() { return &this->operator[](__max_size); }

  reference at(size_type __i) {
    if (__i >= __max_size)
      this->resize(__i + 1);
    return this->data[__i];
  }

  void resize(size_type __n) {
    __n < __max_size ? __max_size = __n : 0;
    auto tmp = new value_type[__n]();

    for (size_type i{}; i < __max_size; ++i)
      tmp[i] = this->operator[](i);

    this->__max_size = __n;
    this->reset(tmp);
  }

  void reset(value_type *__v = nullptr) {
    delete[] this->data;
    this->data = __v;
  }

  container_type &operator=(const container_type &__arr) {
    this->__max_size = __arr.__max_size;
    this->reset(__arr.data);
    return *this;
  }

  reference operator[](size_type __i) { return this->data[__i]; }
};

} // namespace my_cpp

#endif // !__array_hpp
