/**
 * Copyright(C) 2021 Supdrewin <WITHOUT ANY WARRANTY>
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

#if !defined(__sequence_queue_hpp)
#define __sequence_queue_hpp

#include "utility.hpp"

template <typename elem_type, int max_size> //
class sequence_queue {
protected:
  // Var `count' should le `MaxSize'.
  elem_type queue[max_size];
  int count = 0, front = 0;

public:
  // This constructor use x to init queue.
  sequence_queue(elem_type x) { this->append(x); }
  ~sequence_queue() {}

  int empty() { return this->count ? false : true; }

  bool append(elem_type x) {
    if (this->count > max_size)
      return false;

    /* ((count + front)) can gt 100.          */
    this->queue[                               //
        (this->count + this->front) % max_size //
    ] = x;

    this->count++;
    return true;
  }

  elem_type del() {
    if (this->empty())
      return elem_type(false);

    elem_type x = this->queue[this->front];
    ++this->front %= max_size;

    this->count--;
    return x;
  }
};

#endif // !__sequence_queue_hpp
