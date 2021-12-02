/**
 * Copyright(C) 2021 Supdrewin <https://github.com/supdrewin>
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

#if not defined(__linked_list_hpp)
#define __linked_list_hpp

#include "utility.hpp"

using ElemType = int;
typedef struct SingleNode {
  ElemType data;
  struct SingleNode *next;
} SingleLinkedList;

void ListInitiate(SingleLinkedList **head);
int ListLength(SingleLinkedList *head);
void ListGet(SingleLinkedList *head, int i, ElemType *x);
void ListInsert(SingleLinkedList *head, ElemType x);
bool ListDelete(SingleLinkedList *head, ElemType x);
void Destroy(SingleLinkedList **head);

#endif // not defined(__linked_list_hpp)
