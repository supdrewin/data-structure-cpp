/** sort.hpp -*- C++ -*- Copyright (C) 2021 Supdrewin
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

#ifndef __sort_hpp
#define __sort_hpp 1

#include <algorithm>

namespace via {

template <typename type> struct base_data {
  type key{}; //* a minimal member to be sorted

  base_data &operator=(type right) {
    this->key = right;
    return *this;
  }

  bool operator>(base_data right) { return (this->key > right.key); }
  bool operator<(base_data right) { return (this->key < right.key); }
  bool operator>=(base_data right) { return (this->key >= right.key); }
  bool operator<=(base_data right) { return (this->key <= right.key); }
  bool operator==(base_data right) { return (this->key == right.key); }
  bool operator!=(base_data right) { return (this->key != right.key); }
};

template <typename type, unsigned size> struct array {
  base_data<type> elems[size];

  //! begin with it's head, and end after the last one
  base_data<type> *begin() { return &(this->elems[0]); }
  base_data<type> *end() { return &(this->elems[size]); }

  void bubble_sort() {
    for (int i{1}, flag{1}; i < int(size) and flag; ++i) {
      flag = 0;

      for (int j{}; j < int(size) - i; ++j)
        if (this->elems[j] > this->elems[j + 1]) {
          flag = 1;

          base_data<type> tmp{this->elems[j]};
          this->elems[j] = this->elems[j + 1];
          this->elems[j + 1] = tmp;
        }
    }
  }

  void insert_sort() {
    for (int i{1}, j; i < int(size); ++i) {
      base_data<type> tmp = this->elems[i];

      for (j = i - 1; j >= 0 and tmp < this->elems[j]; --j)
        this->elems[j + 1] = this->elems[j];
      this->elems[j + 1] = tmp;
    }
  }

  void quick_sort(int low = 0, int high = size - 1) {
    base_data<type> tmp{this->elems[low]};
    int _l{low}, _h{high};

    while (_l < _h) {
      while (_l < _h and tmp <= this->elems[_h])
        --_h;
      if (_l < _h)
        this->elems[_l++] = this->elems[_h];

      while (_l < _h and tmp >= this->elems[_l])
        ++_l;
      if (_l < _h)
        this->elems[_h--] = this->elems[_l];
    }

    //! _l should always eq _h
    this->elems[_l] = tmp;

    if (low < _l - 1)
      this->quick_sort(low, _l - 1);
    if (_l + 1 < high)
      this->quick_sort(_l + 1, high);
  }

  void select_sort() {
    for (int i{}, pos; i < int(size) - 1; ++i) {
      pos = i;

      for (int j{i + 1}; j < int(size); ++j)
        if (this->elems[j] < this->elems[pos])
          pos = j;

      if (pos != i) {
        base_data<type> tmp = this->elems[i];
        this->elems[i] = this->elems[pos];
        this->elems[pos] = tmp;
      }
    }
  }

  void shell_sort() {
    unsigned tmp_size{size}, loop{};

    while (tmp_size /= 2)
      ++loop;

    auto span{new int[loop]};
    *span = size / 2;

    for (unsigned i{1}; i < loop; ++i)
      span[i] = span[i - 1] / 2;

    for (unsigned time{}; time < loop; ++time)
      for (int group{}; group < span[time]; ++group)
        for (int member{group}, i; member + span[time] < int(size);
             member += span[time]) {
          base_data<type> tmp = this->elems[member + span[time]];

          for (i = member; i >= 0 and tmp < this->elems[i]; i -= span[time])
            this->elems[i + span[time]] = this->elems[i];
          this->elems[i + span[time]] = tmp;
        }

    delete[] span;
  }
};

template <typename type, unsigned size>
inline void sort(array<type, size> &arr, bool reverse = false) {
  std::sort(arr.begin(), arr.end(),
            [reverse](base_data<type> &a, base_data<type> &b) {
              return (reverse ? a > b : a < b);
            });
}

} // namespace via

#endif // !__sort_hpp
