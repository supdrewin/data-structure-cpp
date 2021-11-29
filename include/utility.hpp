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

#if defined(__cplusplus)

#pragma once

#if !defined(__utility_hpp)
#define __utility_hpp 1

#include <iostream>

#if !defined(main)
#define main(...) main(int argc, char **argv)
#endif // !defined(main)

#if !defined(max)
#define max(a, b) (((a) < (b)) ? (b) : (a))
#endif // !defined(max)

#if !defined(min)
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif // !defined(min)

#if !defined(__sizeof)
#define __sizeof(arr) sizeof(arr) / sizeof(*(arr))
#endif // !defined(__sizeof)

#if defined(unix) or defined(linux)

#if !defined(_clear_screen)
#define _clear_screen std::system("clear")
#endif // !defined(_clear_screen)

#if !defined(_color_picker)
#define _color_picker(code) std::string("\e[") + code + 'm'
#endif // !defined(_color_picker)

#if !defined(_path_separator)
#define _path_separator '/'
#endif // !defined(_path_separator)

#if !defined(_print_info)
#define _print_info(msg, argv)                                                 \
  std::system(std::string("echo\t" + std::string(argv) + "\t'" +               \
                          _color_picker("32;1") + msg +                        \
                          _color_picker("0;35") + "\t'")                       \
                  .c_str());
#endif // !defined(_print_info)

#elif defined(_WIN32) or defined(_WIN64)

#if !defined(_clear_screen)
#define _clear_screen std::system("cls")
#endif // !defined(_clear_screen)

#if !defined(_color_picker)
#define _color_picker(code) std::string("[") + code + 'm'
#endif // !defined(_color_picker)

#if !defined(_path_separator)
#define _path_separator '\\'
#endif // !defined(_path_separator)

#if !defined(_print_info)
#define _print_info(msg, ...)                                                  \
  std::system(std::string("echo\t" + _color_picker("32;1") + msg +             \
                          _color_picker("0;35") + '\t')                        \
                  .c_str());
#endif // !defined(_print_info)

#endif // defined(unix) or defined(linux)

#if !defined(assert)

#if defined(_path_separator)

#undef __assert_fail
inline void __assert_fail(std::string assertion, std::string file,
                          unsigned int line, std::string function,
                          std::string program) {
  std::cerr << std::string(program).substr(
                   std::string(program).find_last_of(_path_separator) + 1)
            << ": " << file << ':' << line << ": " << function
            << ": Assertion `" << assertion << "' failed." << std::endl;
  std::abort();
}
#endif // defined(_path_separator)

#define assert(expr)                                                           \
  (static_cast<bool>(expr) ? void(0)                                           \
                           : __assert_fail(#expr, __FILE__, __LINE__,          \
                                           __PRETTY_FUNCTION__, argv[0]))
#endif // !defined(assert)

#endif // !defined(__utility_hpp)

#endif // defined(__cplusplus)
