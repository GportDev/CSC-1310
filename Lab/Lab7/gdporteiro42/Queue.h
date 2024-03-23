/*
  Author: Gabriel Porteiro
  Date: 03/10/2024
  Purpose: Create the class Queue
*/

#include <iostream>
#include <string>

using namespace std;

// QueueNode structure
struct QueueNode
{
  string riderName;
  QueueNode *next;

  QueueNode(string name)
  {
    riderName = name;
    next = nullptr;
  }
};

// Queue class
class Queue
{
private:
  QueueNode *head;
  QueueNode *tail;
  int numNodes;

public:
  Queue()
  {
    head = nullptr;
    tail = nullptr;
    numNodes = 0;
  }

  ~Queue();

  void enqueue(string name);
  string dequeue();
  bool isEmpty() const
  {
    if (head == nullptr)
    {
      return true;
    }

    return false;
  }
};

// Destructor definition
Queue::~Queue()
{

  while (!isEmpty())
  {
    QueueNode *temp = head;

    head = head->next;

    cout << "Oh shoot, I am sorry, our park is closed so " << temp->riderName << " will not get to ride today." << endl;

    delete temp;
  }
}

// Enqueue definition
void Queue::enqueue(string name)
{
  QueueNode *newNode = new QueueNode(name);

  if (isEmpty())
  {
    head = tail = newNode;
  }
  else
  {
    tail->next = newNode;
    tail = newNode;
  }

  numNodes++;
}

// Dequeue definition
string Queue::dequeue()
{
  if (isEmpty())
  {
    cout << "\n\nTHERE IS NO ONE IN LINE!" << endl;
    return "";
  }

  QueueNode *temp = head;
  string name = head->riderName;
  head = head->next;

  if (head == nullptr)
  {
    tail = nullptr;
  }

  delete temp;

  numNodes--;

  return name;
}
