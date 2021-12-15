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

namespace via {

template <class value_type> class array {
public:
  using container_type = array;
  using size_type = unsigned long;
  using reference = value_type &;

protected:
  size_type __size;
  value_type *data;

public:
  array() : __size(), data(new value_type[__size]()) {}

  array(size_type __n) : __size(__n), data(new value_type[__size]()) {}

  array(const container_type &__arr) { this->operator=(__arr); }

  ~array() { this->reset(); }

  size_type size() const noexcept { return this->__size; }

  value_type *begin() noexcept { return &this->operator[](0); }

  value_type *end() noexcept { return &this->operator[](__size); }

  reference at(size_type __i) {
    if (__i >= __size)
      this->resize(__i + 1);
    return this->data[__i];
  }

  void resize(size_type __n) {
    __n < __size ? __size = __n : 0;
    auto tmp = new value_type[__n]();

    for (size_type i{}; i < __size; ++i)
      tmp[i] = this->operator[](i);

    this->__size = __n;
    this->reset(tmp);
  }

  void reset(value_type *__v = nullptr) noexcept {
    delete[] this->data;
    this->data = __v;
  }

  container_type &operator=(const container_type &__arr) noexcept {
    this->__size = __arr.__size;
    this->reset(__arr.data);
    return *this;
  }

  reference operator[](size_type __i) const { return this->data[__i]; }
};

} // namespace via

#endif // !__array_hpp
