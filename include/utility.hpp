/** utility.hpp -*- C++ -*- Copyright (C) 2021 Supdrewin
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

#ifndef __utility_hpp
#define __utility_hpp 1

#include "console_codes.hpp"

#undef __main
#define __main(...) main(int argc, char **argv)

#undef _program_name
#define _program_name argv[0]

#undef __max
#define __max(a, b) (((a) < (b)) ? (b) : (a))

#undef __min
#define __min(a, b) (((a) < (b)) ? (a) : (b))

#undef __sizeof
#define __sizeof(arr) sizeof(arr) / sizeof(*(arr))

#ifdef _WIN32

#undef _path_separator
#define _path_separator '\\'

#else

#undef _path_separator
#define _path_separator '/'

#endif // _WIN32

#ifdef __cplusplus
#include <iostream>

#ifdef _WIN32

#undef _clear_screen
#define _clear_screen std::system("cls")

#else

#undef _clear_screen
#define _clear_screen std::system("clear")

#endif // _WIN32

#undef _assert_fail
void _assert_fail(std::string assertion, std::string file, unsigned int line,
                  std::string function, std::string program);

#undef _ASSERT_FAIL
#define _ASSERT_FAIL(expr)                                                     \
  _assert_fail(#expr, __FILE__, __LINE__, __PRETTY_FUNCTION__, _program_name)

#undef __assert
#define __assert(expr) (static_cast<bool>(expr) ? void(0) : _ASSERT_FAIL(expr))

#endif // __cplusplus

#endif // !__utility_hpp
