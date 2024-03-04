/*****************************************************************
  Filename:       LinkedList.h - Class Specification File for
                  LinkedList Template Class
  Date Created:   2/25/2024
  Author:         Gabriel Porteiro
  Purpose:        LAB 5 - A Singly-Linked List implemented in a
            LinkedList template class that contains a ListNode
            structure variable
******************************************************************/

#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
  struct ListNode
  {
    T value;
    ListNode *next;

    ListNode(const T& val, ListNode *nxt = nullptr)
    {
      value = val;
      next = nxt;
    }
  };

  ListNode *head;
  ListNode *tail;

public:
  LinkedList()
  {
    head = nullptr;
    tail = nullptr;
  }

  ~LinkedList();
  void appendNode(T value);
  void deleteNode(int position);
  void displayList() const;
};

// DEFINE ALL OTHER LinkedList class FUNCTIONS BELOW THIS LINE--------------------------------
template <typename T>
LinkedList<T>::~LinkedList()
{
  ListNode *currentNode = head;
  while (currentNode != nullptr)
  {
    ListNode *nextNode = currentNode->next;

    cout << "*****DELETING the node with address: " << currentNode << endl;

    delete currentNode;

    currentNode = nextNode;
  }
}

template <typename T>
void LinkedList<T>::appendNode(T value)
{
  ListNode *newNode = new ListNode(value);

  if (!head)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    tail->next = newNode;
    tail = newNode;
  }
}

template <typename T>
void LinkedList<T>::deleteNode(int position)
{
  ListNode *toDelete, *current, *previous;

  if (!head)
  {
    cout << "The list is empty. Cannot delete." << endl;
    return;
  }

  if (position == 0)
  {
    toDelete = head;

    cout << "-----DELETING the node with address: " << toDelete << endl;
    head = head->next;

    delete toDelete;

    if (!head)
      tail = nullptr;
  }
  else
  {
    current = head;
    previous = nullptr;

    for (int i = 0; current != nullptr && i < position; i++)
    {
      previous = current;
      current = current->next;
    }

    if (current)
    {
      cout << "-----DELETING the node with address: " << current << endl;

      previous->next = current->next;

      if (current == tail)
        tail = previous;

      delete current;
    }
    else
    {
      cout << "No node found at the given position." << endl;
    }
  }
}

template <typename T>
void LinkedList<T>::displayList() const
{
  if (!head)
  {
    cout << "There are no nodes in the list." << endl;
    return;
  }

  ListNode *current = head;

  while (current != nullptr)
  {
    cout << "Node value: " << current->value << endl;
    current = current->next;
  }
}

#endif