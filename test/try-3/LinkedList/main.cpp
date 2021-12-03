/**
 * Copyright(C) 2021 Supdrewin <https://github.com/supdrewin>
 * main.cpp is part of Single Linked List Example.
 * The Single Linked List Example is free software: you can redistribute
 * it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * The Single Linked List Example is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.If not, see <https://www.gnu.org/licenses/>.
 */

#include "LinkedList.hpp"

/* Overload function `void ListGet(SingleLinkedList *, int, ElemType &)'. */
void ListGet(SingleLinkedList *head, int i, ElemType &x) {
  for (i = 0; i < ListLength(head); i++) {
    ListGet(head, i, &x);         // void ListGet(SingleLinkedList *,
    std::cout << x << "\t";       //              int,
    if ((!((i + 1) % 5) and i) or //              ElemType *)
        i == ListLength(head) - 1)
      std::cout << std::endl;
  }
}

int main() {
  int i, x;

  SingleLinkedList *head;
  ListInitiate(&head);

  //////* Insert 20 integer 0 ~ 100 into single linked list. */////
  for (i = 0; i < 100; i += 5)                                   //
    ListInsert(head, i);                                         //
                                                                 //
  std::cout << "Singe linked list has 20 integers is generated:" //
            << std::endl;                                        //
  ListGet(head, i, x);                                           //

  // --------------- Start Test List Delete ---------------- //
  std::cout << "please insert integer you want to delete: "; //
  std::cin >> x;                                             //
  ListDelete(head, x);                                       //
  std::cout << "Deleted integer: " << x << std::endl         //
            << "Remaining integers:" << std::endl;           //
  ListGet(head, i, x);                                       //
  // --------------- Finish Test List Delete --------------- //

  // -------------- Start Test List Insert --------------- //
  std::cout << "Please insert a intege you want to add: "; //
  std::cin >> x;                                           //
  ListInsert(head, x);                                     //
  std::cout << "Added integer: " << x << std::endl         //
            << "Remaining integers:" << std::endl;         //
  ListGet(head, i, x);                                     //
  // -------------- Finish Test List Insert -------------- //

  // Destroy list and then return:
  Destroy(&head);
  return 0;
}
