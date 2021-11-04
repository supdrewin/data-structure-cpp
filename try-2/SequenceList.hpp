/**
 * Copyright(C) 2021 Supdrewin <WITHOUT ANY WARRANTY>
 * SequenceList.hpp is part of SequenceList Example.
 * The SequenceList Example is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 * The SequenceList Example is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __SEQUENCE_LIST_HPP
#define __SEQUENCE_LIST_HPP

#include <iostream>

template <typename elem_type, int max_size> //
class SequenceList {
protected:
  elem_type list[max_size]; // store list member to here
  int size = 0;             // the size of sequence list,
                            // default to 0(empty)

public:
  SequenceList() { this->init(); }
  ~SequenceList() {}

  void init() {}
  int get(int) {}
  int find(std::string) {}

  int length() { return this->size; }

  int _insert(int i, elem_type x) {
    if (this->size >= max_size)
      std::cerr << __PRETTY_FUNCTION__     //
                << ": Too full to insert!" //
                << std::endl;
    else if (i < 0 or i > this->size)
      std::cerr << __PRETTY_FUNCTION__        //
                << ": Invailed argument `i'!" //
                << std::endl;
    else {
      for (int j = this->size; j > i; j--)
        this->list[j] = this->list[j - 1];

      this->list[i] = x;
      this->size++;
      return true;
    }
    return false;
  }

  int _delete(int i, elem_type *x = nullptr) {
    if (this->size <= 0)
      std::cerr << __PRETTY_FUNCTION__ //
                << ": Nothing to do!"  //
                << std::endl;
    else if (i < 0 or i > this->size - 1)
      std::cerr << __PRETTY_FUNCTION__        //
                << ": Invailed argument `i'!" //
                << std::endl;
    else {
      if (x != nullptr)
        *x = this->list[i];

      for (int j = i + 1; j <= this->size - 1; j++)
        this->list[j - 1] = this->list[j];

      this->size--;
      return true;
    }
    return false;
  }
};

#endif /* __SEQUENCE_LIST_HPP */

// vim:set nu rnu cuc cul ts=2 sw=2 et si:
