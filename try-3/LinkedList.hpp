/**
 * Copyright(C) 2021 Supdrewin <WITHOUT ANY WARRANTY>
 * LinkedList.hpp is part of Single Linked List Example.
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

#ifndef __linked_list_hpp
#define __linked_list_hpp

#include <iostream>

inline namespace List {
template <typename ElemType> //
struct SingleNode {
  struct SingleNode *next;
  ElemType data;

  void init(SingleNode **head) {
    if ((*head = (SingleNode *)      //
         malloc(sizeof(SingleNode))) //
        == nullptr)
      exit(EXIT_FAILURE);

    (*head)->next = nullptr;
  }

  int size(SingleNode *head) {
    SingleNode *p = head;
    int size;

    for (size = 0; p->next != nullptr; size++)
      p = p->next;

    return size;
  }

  void get(SingleNode *head,    //
           int i,               //
           ElemType *x) {       //
    SingleNode *p;              //
                                //
    for (p = head;              //
         p->next != nullptr and //
         i >= 0;
         i--)
      p = p->next;

    *x = p->data;
  }

  void get(SingleNode *head, //
           int i,            //
           ElemType &x) {
    for (i = 0; i < head->size(head); i++) {
      head->get(head, i, &x);
      std::cout << x << '\t';

      if (!((i + 1) % 5) and i or //
          i == head->size(head) - 1)
        std::cout << std::endl;
    }
  }

  void Insert(SingleNode *head,      //
              ElemType x) {          //
    SingleNode *p, *q;               //
                                     //
    for (p = head;                   //
         p->next != nullptr;         //
         p = p->next)                //
      if (x <= p->next->data)        //
        break;                       //
                                     //
    if ((q = (SingleNode *)          //
         malloc(sizeof(SingleNode))) //
        == nullptr)
      exit(EXIT_FAILURE);

    q->data = x;
    q->next = p->next;
    p->next = q;
  }

  ElemType Delete(SingleNode *head,    //
                  ElemType x) {        //
    SingleNode *p, *q;                 //
                                       //
    for (p = head;                     //
         p->next->next != nullptr;     // make sure it isn't null
         p = p->next)                  // \n         \n
      if (x == p->next->data)          //  \n         \n
        break;                         //   \n         \n
                                       //    \n         \n
    if (x != p->next->data) {          //     \n         \n
      std::cerr << __func__            //      \n         \n
                << ": Data not found!" //       \n         \n
                << std::endl;          //        \n         \n
      return (ElemType) false;         //         \n         \n
    }                                  //          \n         \n
                                       //           \n         \n
    q = p->next;                       //            \n         \n
    p->next = q->next;                 // q->next = p->next->next

    free(q);
    return x;
  }

  void Destroy(SingleNode **head) {
    SingleNode *p;

    while (*head != nullptr) {
      p = *head;
      *head = (*head)->next;

      free(p);
    }
  }
};
} // namespace List

#endif /* __linked_list_hpp */

// vim:set nu rnu cuc cul ts=2 sw=2 et si:
