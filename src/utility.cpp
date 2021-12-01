/** utility.cpp -*- C++ -*- Copyright (C) 2021 Supdrewin
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

#include "utility.hpp"

void _assert_fail(std::string assertion, std::string file, unsigned int line,
                  std::string function, std::string program) {
  std::cerr << std::string(program).substr(
                   std::string(program).find_last_of(_path_separator) + 1)
            << ": " << file << ':' << line << ": " << function
            << ": Assertion `" << assertion << "' failed." << std::endl;
  std::exit(EXIT_FAILURE);
}
