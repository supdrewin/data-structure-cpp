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

#pragma once
#include <iostream>

template <typename ElemType, int MaxSize> //
class SequenceQueue {
protected:
  // Var `count' should le `MaxSize'.
  ElemType queue[MaxSize];
  int count = 0, front = 0;

public:
  // This constructor use x to init queue.
  SequenceQueue(ElemType x) { this->Append(x); }
  ~SequenceQueue() {}

  int empty() {
    if (!this->count)
      return true;
    return false;
  }

  int Append(ElemType x) {
    if (this->count > MaxSize)
      return false;

    /* ((count + front)) can gt 100.          */
    this->queue[                              //
        (this->count + this->front) % MaxSize //
    ] = x;

    this->count++;
    return true;
  }

  ElemType Delete() {
    if (this->empty())
      return (ElemType) false;

    ElemType x = this->queue[this->front];
    ++this->front %= MaxSize;

    this->count--;
    return x;
  }
};
