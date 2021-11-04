/**
 * Copyright(C) 2021 Supdrewin <WITHOUT ANY WARRANTY>
 * SequenceList.cpp is part of SequenceList Example.
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

#include "SequenceList.hpp"
#include "screen.hpp"

// If not N, give N to 10
// You can simply override
// it with `-D N=<integer>'
#ifndef N
#define N 10
#endif

struct people {
  std::string name, sex;
  int age = 0;
};

struct patient : people {
  std::string number, symptom;
};

// Define a sequence list of patients with 100 maxsize.
using sequencelist = SequenceList<patient, 100>;

template <> void sequencelist::init() {
  screen::clear();

  patient s[N];
  for (int i = 0; i < N; i++) {
    std::cout << "------请输入第" << i + 1 << "个病人的信息 " << std::endl;

    std::cout << "请输入第" << i + 1 << "个病人的病历号: ";
    std::cin >> s[i].number;

    std::cout << "请输入第" << i + 1 << "个病人的姓名: ";
    std::cin >> s[i].name;

    std::cout << "请输入第" << i + 1 << "个病人的年龄: ";
    std::cin >> s[i].age;

    std::cout << "请输入第" << i + 1 << "个病人的性别: ";
    std::cin >> s[i].sex;

    std::cout << "请输入第" << i + 1 << "个病人的症状: ";
    std::cin >> s[i].symptom;

    this->_insert(i, s[i]);

    screen::clear();
  }
}

template <> int sequencelist::get(int i) {
  if (i < 0 or i > this->size - 1) {
    std::cerr << __PRETTY_FUNCTION__        //
              << ": Invailed argument `i'!" //
              << std::endl;
    return false;
  }

  std::cout << this->list[i].number << '\t' //
            << this->list[i].name << '\t'   //
            << this->list[i].age << '\t'    //
            << this->list[i].sex << '\t'    //
            << this->list[i].symptom << std::endl;

  return true;
}

template <> int sequencelist::find(std::string x) {
  if (this->size <= 0)
    std::cerr << __PRETTY_FUNCTION__ //
              << ": Nothing to do!"  //
              << std::endl;
  else
    for (int i = 0; i < this->size; i++)
      if (x == this->list[i].name)
        return i;

  return -1;
}

int main() {
  sequencelist *mylist = new sequencelist();

  std::cout << "****************** Database of patients *****************"
            << std::endl;

  for (int i = 0; i < mylist->length(); i++)
    mylist->get(i);

  std::cout << "*************** Following are My Homework ***************"
            << std::endl;

  std::cout << "Please insert the name of patient you want to find: ";
  std::string find;
  std::cin >> find;

  mylist->get(mylist->find(find));

  delete mylist;
  return 0;
}

// vim:set nu rnu cuc cul ts=2 sw=2 et si:
