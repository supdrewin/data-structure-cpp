/**
 * Copyright(C) 2021 Supdrewin <https://github.com/supdrewin>
 * SequenceList.hpp is part of Sequence List Example.
 * The Sequence List Example is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 * The Sequence List Example is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __sequence_list_hpp
#define __sequence_list_hpp 1

#include "utility.hpp"

template <typename elem_type, size_t max_size> //
class sequence_list {
protected:
  elem_type list[max_size]; // store list member to here
  size_t __size;            // the size of sequence list,
                            // default to 0(empty)
public:
  sequence_list() : list(), __size() {}

  size_t size() { return this->__size; }
  bool empty() { return !this->__size; }

  bool insert(size_t index, elem_type push) {
    if (this->__size >= max_size)
      std::cerr << __PRETTY_FUNCTION__ << ": Too full to insert!" << std::endl;
    else if (index > this->__size)
      std::cerr << __PRETTY_FUNCTION__ << ": Invailed argument!" << std::endl;
    else {
      for (auto i{this->__size}; i > index; --i)
        this->list[i] = this->list[i - 1];
      this->list[index] = push;
      ++this->__size;
      return true;
    }
    return false;
  }

  bool erase(size_t index, elem_type *pop = nullptr) {
    if (this->__size == 0)
      std::cerr << __PRETTY_FUNCTION__ << ": Nothing to do!" << std::endl;
    else if (index > this->__size - 1)
      std::cerr << __PRETTY_FUNCTION__ << ": Invailed argument!" << std::endl;
    else {
      if (pop != nullptr)
        *pop = this->list[index];
      for (auto i{index}; i <= this->__size - 1; ++i)
        this->list[i] = this->list[i + 1];
      --this->__size;
      return true;
    }
    return false;
  }
};

#endif // !__sequence_list_hpp
