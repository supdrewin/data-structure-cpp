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
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __compressed_matrix_hpp
#define __compressed_matrix_hpp 1

#include "SequenceList.hpp"

template <typename data_type> //
struct elem_type_of_compressed_matrix {
  int line, culomn;
  data_type data;
};

template <typename data_type, int max_line_number, int max_culomn_number>
class compressed_matrix
    : public sequence_list<elem_type_of_compressed_matrix<data_type>,
                           max_line_number * max_culomn_number> {
protected:
  struct c_array {
    data_type data[static_cast<unsigned>(max_line_number)]
                  [static_cast<unsigned>(max_culomn_number)];
    // Constructor to init array.
    c_array() {
      for (int i = 0; i < max_line_number; ++i)
        for (int j = 0; j < max_culomn_number; ++j)
          this->data[i][j] = data_type(0);
    }
  };

public:
  compressed_matrix() = default;
  virtual ~compressed_matrix() {}

  bool empty() { return !this->size; }
  int get_size() { return this->size; }

  /** @brief Convert compressed matrix to C-Style array.
   *  @return arr <c_array> converted C-Style array
   *  @param <void>
   */
  c_array c_arr() {
    c_array arr;
    for (int i = 0; i < this->size; ++i)
      arr.data[this->list[i].line][this->list[i].culomn] = //
          this->list[i].data;
    return arr;
  }

  /** @brief Add data into position (x, y).
   *  @return <boolean> whether func success or not
   *  @param line <integer> the location of line
   *  @param culomn <integer> the location of column
   *  @param data <data_type> data adding
   */
  bool add(int line, int culomn, data_type data) {
    // Check whether position (line, culomn) is vaild or not.
    if (line >= max_line_number or culomn >= max_culomn_number or //
        line < 0 or culomn < 0) {
      std::cerr << __PRETTY_FUNCTION__ << ": Position (" << line << ", "
                << culomn << ") is invaild to add!" << std::endl;
      return false;
    }

    // Search first position ge (line, culomn) from list.
    for (int i = 0; i < this->size; ++i)
      if (line < this->list[i].line or
          (line == this->list[i].line and culomn <= this->list[i].culomn)) {
        // If the position has recorded, override it.
        if (line == this->list[i].line and culomn == this->list[i].culomn)
          this->erase(i);

        this->insert(i, //
                     elem_type_of_compressed_matrix<data_type>{
                         line,   //
                         culomn, //
                         data    //
                     }           //
        );
        return true;
      }

    // If not positions ge (line, culomn), add last.
    this->insert(this->size, //
                 elem_type_of_compressed_matrix<data_type>{
                     line,   //
                     culomn, //
                     data    //
                 }           //
    );
    return true;
  }

  /** @brief Add data into position (x, y) and (y, x).
   *  @return <boolean> whether func success or not
   *  @param line <integer> the location of line
   *  @param culomn <integer> the location of column
   *  @param data <data_type> data adding
   */
  bool sym_add(int line, int culomn, data_type data) {
    return ((add(line, culomn, data) and //
             add(culomn, line, data))
                ? true
                : false);
  }

  /** @brief erase data located on (line, culomn)
   *  @return <boolean> erase operation's status
   *  @param line <integer> the location of line
   *  @param culomn <integer> the location of column
   */
  bool erase_position(int line, int culomn) {
    for (int i = 0; i < this->get_size(); ++i)
      if (this->list[i].line == line and //
          this->list[i].culomn == culomn)
        return this->erase(i);
    return false;
  }

  /** @brief Print the regular graph of compressed matrix.
   *  @return <void>
   *  @param <void>
   */
  void print() {
    for (int i = 0, k = 0; i < max_line_number; ++i) {
      for (int j = 0; j < max_culomn_number; ++j, std::cout << '\t')
        std::cout << ((this->list[k].line == i and this->list[k].culomn == j)
                          ? this->list[k++].data
                          : 0);
      std::cout << std::endl;
    }
  }

  /** @brief Transpose this matrix and then return it.
   *  @return tmp <CompressedMatrix> transposed matrix
   *  @param <void>
   */
  compressed_matrix<data_type, max_culomn_number, max_line_number> tranpose() {
    compressed_matrix<data_type, max_culomn_number, max_line_number> tmp;

    if (not this->empty())
      for (int i = 0; i < this->size; ++i)
        tmp.add(this->list[i].culomn, this->list[i].line, this->list[i].data);

    return tmp;
  }

  /** @brief Multipling this with other matrix object.
   *  @return tmp <CompressedMatrix> matrix obj after multipling
   *  @param matrix <CompressedMatrix> a matrix to be multiplied
   */
  compressed_matrix<data_type, max_line_number, max_line_number> operator*(
      compressed_matrix<data_type, max_culomn_number, max_line_number> matrix) {
    compressed_matrix<data_type, max_line_number, max_line_number> tmp;
    auto a = this->c_arr();
    auto b = matrix.c_arr();

    for (int i = 0, sum = 0; i < max_line_number; ++i)
      for (int j = 0; j < max_line_number; ++j, sum = 0) {
        for (int k = 0; k < max_culomn_number; ++k)
          sum += a.data[i][k] * b.data[k][j];
        tmp.add(i, j, sum);
      }

    return tmp;
  }
};

#endif // !__compressed_matrix_hpp
