/**
 * Copyright(C) 2021 Supdrewin <https://github.com/supdrewin>
 * SequenceQueue.hpp is part of Sequence Queue Example.
 * The Sequence Queue Example is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 * The Sequence Queue Example is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __sequence_queue_hpp
#define __sequence_queue_hpp 1

#include "utility.hpp"

template <typename __elems_type> //
class sequence_queue {
private:
  using size_type = unsigned;
  using value_type = __elems_type;

protected:
  size_type __count, __offset, __max_size;
  std::unique_ptr<value_type[]> __data;

  bool resize(size_type _s) {
    if (_s < __count)
      return false;

    auto tmp = new value_type[_s];
    for (unsigned i{}; i < __count; ++i)
      tmp[i] = __data[i + __offset];

    this->__data.reset(tmp);
    this->__max_size = _s;
    this->__offset = 0;
    return true;
  }

public:
  sequence_queue()
      : __count(0), __offset(0), __max_size(2), //
        __data(new value_type[__max_size]) {}
  ~sequence_queue() = default;

  inline bool empty() const { return this->size() == 0; }
  inline size_type size() const { return this->__count; }

  inline value_type front() {
    return this->empty() ? static_cast<value_type>(0)
                         : this->__data[__count + __offset - 1];
  }

  inline value_type back() {
    return this->empty() ? static_cast<value_type>(0) //
                         : this->__data[__offset];
  }

  void push(value_type _v) {
    if (__count + __offset == __max_size)
      this->resize(this->size() * 2);

    this->__data[__count + __offset] = _v;
    ++this->__count;
  }

  void pop() {
    if (this->empty())
      return;

    ++this->__offset;
    --this->__count;
  }

  void swap() {}
};

#endif // !__sequence_queue_hpp
