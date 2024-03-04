/*
  Author:  Gabriel Porteiro
  Date:    Feb 17, 2024
  Purpose: Create a linked list class
*/

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

using namespace std;

struct ListNode
{
  // Holds the value of this node
  string value;

  // Points to the next node in the list
  ListNode *next;

  ListNode(string nodeValue, ListNode *nextNode)
  {
    value = nodeValue;
    next = nextNode;
  }
};

class List
{
private:
  ListNode *head;
  ListNode *tail;

public:
  List()
  {
    head = nullptr;
    tail = nullptr;
  };

  ~List()
  {
    ListNode *currentNode = head;

    while (currentNode != nullptr)
    {
      ListNode *nextNode = currentNode->next;

      delete currentNode;

      currentNode = nextNode;
    }
  };

  void appendNode(string nodeValue)
  {
    ListNode *newNode = new ListNode(nodeValue, nullptr);

    // When the linked list still empty, all the nodes are the same, the first one (and last)
    if (head == nullptr)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      // Points the tail next node to the new node
      tail->next = newNode;

      // Transform the new node in the tail
      tail = newNode;
    }
  };

  void insertNode(string nodeValue)
  {
    ListNode *newNode = new ListNode(nodeValue, nullptr);
    ListNode *currentNode = head;

    // Insert the node in the begging
    if (head == nullptr || head->value >= nodeValue)
    {
      newNode->next = head;
      head = newNode;

      // If the list is empty
      if (tail == nullptr)
      {
        tail = newNode;
      }
    }
    else
    {

      // Travels through the list while the current node is not the and not the position of our newNode
      while (currentNode->next != nullptr && currentNode->next->value < nodeValue)
      {
        currentNode = currentNode->next;
      }

      newNode->next = currentNode->next;
      currentNode->next = newNode;

      // Insert the new node at the end
      if (newNode->next == nullptr)
      {
        tail = newNode;
      }
    }
  };

  void deleteNode(string nodeValue)
  {
    ListNode *tempNode;
    ListNode *currentNode;

    if (head == nullptr)
      return;

    // Compare the nodeValue and delete the head if the same
    if (head->value == nodeValue)
    {
      tempNode = head;
      head = head->next;

      delete tempNode;

      // If the deletion transform the head into nullPtr, the list must be empty
      if (head == nullptr)
      {
        tail = nullptr;
      }

      return;
    }

    currentNode = head;

    // Travels through the list while the current is not the tail and the next is not the target
    while (currentNode->next != nullptr && currentNode->next->value != nodeValue)
    {
      currentNode = currentNode->next;
    }

    // If the current does not have a next one, i.e. is the tail
    if (currentNode->next != nullptr)
    {
      tempNode = currentNode->next;

      currentNode->next = tempNode->next;

      if (tempNode->next == nullptr)
      {
        tail = currentNode;
      }

      delete tempNode;
    }
  };

  void displayList() const
  {
    ListNode *currentNode = head;

    // Travels through the list printing each node
    while (currentNode != nullptr)
    {
      cout << currentNode->value << endl;

      currentNode = currentNode->next;
    }
  };
};

#endif