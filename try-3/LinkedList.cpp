/**
 * Copyright(C) 2021 Supdrewin <WITHOUT ANY WARRANTY>
 * LinkedList.cpp is part of Single Linked List Example.
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
using SingleLinkedList = //
    List::SingleNode<int>;

using std::cin;
using std::cout;
using std::endl;

int main(/* No needed here. */) {
  SingleLinkedList *head;
  int i, x;

  head->init(&head);

  // Insert integer 0 ~ 99 with 5 into single linked list.  //
  for (i = 0; i < 100; i += 5)                              //
    head->Insert(head, i);                                  //
                                                            //
  cout << "Singe linked list has 20 integers is generated:" //
       << endl;                                             //
  head->get(head, i, x);                                    //

  // --------------- Start Test List Delete --------------- //

  cout << "please insert integer you want to delete: ";
  cin >> x;

  cout << "Deleted integer: "           //
       << head->Delete(head, x) << endl //
       << "Remaining integers:" << endl;
  head->get(head, i, x);

  // --------------- Finish Test List Delete --------------- //

  // --------------- Start Test List Insert --------------- //

  cout << "Please insert a intege you want to add: ";
  cin >> x;

  head->Insert(head, x);

  cout << "Added integer: " << x << endl //
       << "Remaining integers:" << endl;
  head->get(head, i, x);

  // --------------- Finish Test List Insert --------------- //

  // Destroy list and then return:
  head->Destroy(&head);
  return 0;
}

// vim:set nu rnu cuc cul ts=2 sw=2 et si:
