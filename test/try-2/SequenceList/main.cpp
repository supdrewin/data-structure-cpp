/**
 * Copyright(C) 2021 Supdrewin <https://github.com/supdrewin>
 * main.cpp is part of Sequence List Example.
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

#include "SequenceList.hpp"

struct people {
  std::string name{}, sex{};
  int age = 0;
};

struct patient : people {
  std::string number{}, symptom{};
};

// Define a sequence list of patients with 100 maxsize.
class sequencelist : public sequence_list<patient, 100> {
public:
  sequencelist(size_t n) { this->init(n); }
  ~sequencelist() {}

  void init(size_t n) {
    std::cout << RIS;

    n > 0 ? void(0) : std::exit(EXIT_FAILURE);
    auto tmp = new patient[n];

    for (size_t i{}; i < n; i++) {
      std::cout << "------Please insert the " << i + 1
                << "th patient's information" << std::endl;

      std::cout << "Please insert the " << i + 1 //
                << "th patient's number: ";
      std::cin >> tmp[i].number;

      std::cout << "Please insert the " << i + 1 //
                << "th patient's name: ";
      std::cin >> tmp[i].name;

      std::cout << "Please insert the " << i + 1 //
                << "th patient's age: ";
      std::cin >> tmp[i].age;

      std::cout << "Please insert the " << i + 1 //
                << "th patient's sex: ";
      std::cin >> tmp[i].sex;

      std::cout << "Please insert the " << i + 1 //
                << "th patient's symptom: ";
      std::cin >> tmp[i].symptom;

      this->insert(i, tmp[i]);

      std::cout << RIS;
    }

    delete[] tmp;
  }

  bool get(size_t i) {
    if (i > this->size() - 1) {
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

  int find(std::string name) {
    if (this->size() <= 0)
      std::cerr << __PRETTY_FUNCTION__ //
                << ": Nothing to do!"  //
                << std::endl;
    else
      for (size_t i{}; i < this->size(); ++i)
        if (name == this->list[i].name)
          return int(i);
    return -1;
  }
};

int main() {
  sequencelist mylist(5);

  std::cout << "****************** Database of patients *****************"
            << std::endl;

  std::cout << "number" << '\t' << "name" << '\t' << "age" << '\t' //
            << "sex" << '\t' << "symptom" << std::endl;

  for (size_t i{}; i < mylist.size(); ++i)
    mylist.get(i);

  std::cout << "*************** Following are My Homework ***************"
            << std::endl;

  std::cout << "Please insert the name of patient you want to find: ";

  std::string to_find;
  std::cin >> to_find;

  auto index{mylist.find(to_find)};

  if (index != -1)
    mylist.get(size_t(index));

  return 0;
}

// vim:set nu rnu cuc cul ts=2 sw=2 et si:
