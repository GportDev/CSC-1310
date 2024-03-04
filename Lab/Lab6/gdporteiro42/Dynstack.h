/*
  Title: Dynstack.h
  Author: Gabriel Porteiro
  Date:
  Purpose:
*/

#ifndef DYNSTACK_H
#define DYNSTACK_H

#include <iostream>

using namespace std;

template <typename T>
class DynamicStack
{
private:
  struct StackNode
  {
    T value;
    StackNode *next;

    StackNode(T val, StackNode *nxt = nullptr)
    {
      this->value = val;
      this->next = nxt;
    }
  };

  StackNode *top;

public:
  // Constructor
  DynamicStack()
  {
    top = nullptr;
  }

  // Destructor
  ~DynamicStack()
  {
    StackNode *nodePtr = top, *nextNode;

    while (nodePtr != nullptr)
    {
      nextNode = nodePtr->next;

      delete nodePtr;

      nodePtr = nextNode;
    }
  };

  // Add a new node into the end the stack
  void push(T value)
  {
    StackNode *newNode = new StackNode(value, top);
    top = newNode;
  };

  // Remove a node from the end of the stack
  void pop(T &value)
  {
    if (isEmpty())
    {
      cout << "The stack is empty. \n";
      return;
    }

    StackNode *temp = top;
    value = top->value;
    top = top->next;

    delete temp;
  };

  // Verify if the stack is empty
  bool isEmpty() const
  {
    return top == nullptr;
  };
};

#endif