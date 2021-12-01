/**
 * Copyright(C) 2021 Supdrewin <https://github.com/supdrewin>
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

void ListInitiate(SingleLinkedList **head) {
  if ((*head = (SingleLinkedList *)      //
       malloc(sizeof(SingleLinkedList))) //
      == nullptr)
    exit(EXIT_FAILURE);
  (*head)->next = nullptr;
}

int ListLength(SingleLinkedList *head) {
  SingleLinkedList *p = head;
  int size;
  for (size = 0; p->next != nullptr; size++)
    p = p->next;
  return size;
}

void ListGet(SingleLinkedList *head, //
             int i, ElemType *x) {   //
  SingleLinkedList *p;               //
                                     //
  for (p = head;                     //
       p->next != nullptr and        //
       i >= 0;
       i--)
    p = p->next;
  *x = p->data;
}

void ListInsert(SingleLinkedList *head,  //
                ElemType x) {            //
  SingleLinkedList *p, *q;               //
                                         //
  for (p = head;                         //
       p->next != nullptr;               //
       p = p->next)                      //
    if (x <= p->next->data)              //
      break;                             //
                                         //
  if ((q = (SingleLinkedList *)          //
       malloc(sizeof(SingleLinkedList))) //
      == nullptr)
    exit(EXIT_FAILURE);
  q->data = x;
  q->next = p->next;
  p->next = q;
}

bool ListDelete(SingleLinkedList *head,        //
                ElemType x) {                  //
  SingleLinkedList *p, *q;                     //
                                               //
  for (p = head;                               //
       p->next->next != nullptr;               // make sure it isn't null
       p = p->next)                            // \n         \n
    if (x == p->next->data)                    //  \n         \n
      break;                                   //   \n         \n
                                               //    \n         \n
  if (x != p->next->data) {                    //     \n         \n
    std::cerr << "ListDelete: Data not found!" //      \n         \n
              << std::endl;                    //       \n         \n
    return false;                              //        \n         \n
  }                                            //         \n         \n
                                               //          \n         \n
  q = p->next;                                 //           \n         \n
  p->next = q->next;                           // q->next = p->next->next
  free(q);
  return true;
}

void Destroy(SingleLinkedList **head) {
  SingleLinkedList *p;
  while (*head != nullptr) {
    p = *head;
    *head = (*head)->next;
    free(p);
  }
}
