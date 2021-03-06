/**
 * Copyright(C) 2021 Supdrewin <https://github.com/supdrewin>
 * main.cpp is part of Huffman Tree Example.
 * The Huffman Tree Example is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 * The Huffman Tree Example is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.If not, see <https://www.gnu.org/licenses/>.
 */

#include "HuffmanTree.hpp"

int main() {
  // letters and freq list of letters
  double freq[]{.07, .19, .02, .06, .32, .03, .21, .1};
  auto letters("abcdefgh");

  // weight type = double and node count = 8
  huffman_tree<double, __sizeof(freq)> ht(freq, letters);

  // print the tree
  std::cout << SGR_BOLD << SGR_GREEN_FOREGROUND << "Print the huffman tree:" //
            << SGR_RESET_ALL << SGR_MAGENTA_FOREGROUND << std::endl;
  ht.print();

  // generate code list
  ht.code_list_config();

  // print the list
  std::cout << SGR_BOLD << SGR_GREEN_FOREGROUND << "Print the code list:" //
            << SGR_RESET_ALL << SGR_MAGENTA_FOREGROUND << std::endl;
  ht.code_list_print();

  return 0;
}
