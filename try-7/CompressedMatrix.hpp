/**
 * Copyright(C) 2021 Supdrewin <https://github.com/supdrewin>
 * CompressedMatrix.hpp is part of Compressed Matrix Example.
 * The Compressed Matrix Example is free software: you can redistribute
 * it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * The Compressed Matrix Example is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include "try-2/SequenceList.hpp"

template <typename data_type> //
struct elem_type {
  int x, y;
  data_type data;
};

template <typename data_type, int line, int culomn> //
class CompressedMatrix                              //
    : SequenceList<elem_type<data_type>, line * culomn> {
protected:
  int max_line_number = line, max_column_number = culomn;

  struct c_array {
    data_type data[line][culomn];
    // Constructor to init array.
    c_array() {
      for (int i = 0; i < line; ++i)
        for (int j = 0; j < culomn; ++j)
          this->data[i][j] = 0;
    }
  } arr;

public:
  CompressedMatrix() = default;
  ~CompressedMatrix() {}

  int empty() {
    if (this->size)
      return false;
    return true;
  }

  int get_size() { return this->size; }

  /** Convert compressed matrix to C-Style array.
   * @return arr <c_array> converted C-Style array
   * @param <void>
   */
  struct c_array c_arr() {
    for (int i = 0; i < this->size; ++i)
      arr.data[this->list[i].x][this->list[i].y] = //
          this->list[i].data;

    return arr;
  }

  /** Add data into position (x, y).
   * @return <boolean> whether func success or not
   * @param x <integer> the location of line
   * @param y <integer> the location of column
   * @param data <data_type> data adding
   */
  int add(int x, int y, data_type data) {
    // Check whether position (x, y) is vaild or not.
    if (x >= max_line_number or           //
        y >= max_column_number or         //
        x < 0 or                          //
        y < 0) {                          //
      std::cerr << __PRETTY_FUNCTION__    //
                << ": Position ("         //
                << x << ", " << y         //
                << ") is invaild to add!" //
                << std::endl;
      return false;
    }

    // Search first position ge (x, y) from list.
    for (int i = 0; i < this->size; ++i)
      if (x < this->list[i].x or    //
          (x == this->list[i].x and //
           y <= this->list[i].y)    //
      ) {
        // If the position has recorded, override it!
        if (x == this->list[i].x and //
            y == this->list[i].y)
          this->_delete(i);

        this->_insert( //
            i,
            elem_type<data_type>{
                x, y, data //
            }              //
        );
        return true;
      }

    // If not positions ge (x, y), add last!
    this->_insert( //
        this->size,
        elem_type<data_type>{
            x, y, data //
        }              //
    );
    return true;
  }

  /** Add data into position (x, y) and (y, x).
   * @return <boolean> whether func success or not
   * @param x <integer> the location of line
   * @param y <integer> the location of column
   * @param data <data_type> data adding
   */
  int sym_add(int x, int y, data_type data) {
    if (add(x, y, data) and //
        add(y, x, data))
      return true;
    return false;
  }

  /** Print the regular graph of compressed matrix.
   * @return <void>
   * @param <void>
   */
  void print() {
    for (int i = 0, k = 0; i < max_line_number; ++i) {
      for (int j = 0;             //
           j < max_column_number; //
           ++j, std::cout << '\t')
        if (this->list[k].x == i and //
            this->list[k].y == j)
          std::cout << this->list[k++].data;
        else
          std::cout << 0;

      std::cout << std::endl;
    }
  }

  /** Transpose this matrix and then return it.
   * @return matrix <CompressedMatrix> transposed matrix
   * @param <void>
   */
  CompressedMatrix tranpose() {
    CompressedMatrix matrix;

    matrix.max_line_number = this->max_column_number;
    matrix.max_column_number = this->max_line_number;
    matrix.size = this->size;

    if (!this->empty()) {
      for (int i = 0, k = 0; i < this->max_column_number; ++i)
        for (int j = 0; j < this->size; ++j)
          if (this->list[j].y == i) {
            matrix.list[k].x = this->list[j].y;
            matrix.list[k].y = this->list[j].x;
            matrix.list[k].data = this->list[j].data;

            ++k;
          }
    }

    return matrix;
  }
};
