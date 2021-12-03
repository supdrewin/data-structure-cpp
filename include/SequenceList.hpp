/**
 * Copyright(C) 2021 Supdrewin <WITHOUT ANY WARRANTY>
 * SequenceList.hpp is part of Sequence List Example.
 * The Sequence List Example is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 * The Sequence List Example is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.If not, see <https://www.gnu.org/licenses/>.
 */

#if not defined(__sequence_list_hpp)
#define __sequence_list_hpp

#include "utility.hpp"

template <typename elem_type, int max_size> //
class sequence_list {
protected:
  elem_type list[max_size]; // store list member to here
  int size = 0;             // the size of sequence list,
                            // default to 0(empty)

public:
  sequence_list() = default;
  virtual ~sequence_list() {}

  inline int get_size() { return this->size; }

  bool insert(int index, elem_type push) {
    if (this->size >= max_size)
      std::cerr << __PRETTY_FUNCTION__ << ": Too full to insert!" << std::endl;
    else if (index < 0 or index > this->size)
      std::cerr << __PRETTY_FUNCTION__ << ": Invailed argument!" << std::endl;
    else {
      for (int i = this->size; i > index; --i)
        this->list[i] = this->list[i - 1];
      this->list[index] = push;
      this->size++;
      return true;
    }
    return false;
  }

  bool erase(int index, elem_type *pop = nullptr) {
    if (this->size <= 0)
      std::cerr << __PRETTY_FUNCTION__ << ": Nothing to do!" << std::endl;
    else if (index < 0 or index > this->size - 1)
      std::cerr << __PRETTY_FUNCTION__ << ": Invailed argument!" << std::endl;
    else {
      if (pop != nullptr)
        *pop = this->list[index];
      for (int i = index; i <= this->size - 1; ++i)
        this->list[i] = this->list[i + 1];
      this->size--;
      return true;
    }
    return false;
  }
};

#endif // not defined(__sequence_list_hpp)
// vim:set nu rnu cuc cul ts=2 sw=2 et si:
