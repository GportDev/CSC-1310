/*
  Title:    HashTable.h
  Author:   Gabriel Porteiro
  Date:     March 23, 2024
  Purpose:  Hold the HashTable class
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "HashEntry.h"
#include <iostream>

using namespace std;

class HashTable
{
private:
  HashEntry **table;
  int tableSize;

  int hashFunction(int key)
  {
    return key % tableSize;
  }

public:
  HashTable(int size)
  {
    tableSize = size;
    table = new HashEntry *[tableSize];

    for (int i = 0; i < tableSize; i++)
    {
      table[i] = nullptr;
    }
  }

  ~HashTable()
  {
    for (int i = 0; i < tableSize; i++)
    {
      HashEntry *entry = table[i];

      while (entry != nullptr)
      {
        HashEntry *prev = entry;

        entry = entry->getNext();

        delete prev;
      }
    }

    delete [] table;
  }

  void putValue(int key, Costume *value)
  {
    int hash = hashFunction(key);
    HashEntry *prev = nullptr;
    HashEntry *entry = table[hash];

    while (entry != nullptr && entry->getKey() != key)
    {
      prev = entry;
      entry = entry->getNext();
    }

    if (entry == nullptr)
    {
      entry = new HashEntry(key, value);
      if (prev == nullptr)
      {
        table[hash] = entry;
      }
      else
      {
        prev->setNext(entry);
      }
    }
    else
    {
      entry->setValue(value);
    }
  }

  void printHashTable()
  {
    for (int i = 0; i < tableSize; i++)
    {
      HashEntry *entry = table[i];

      cout << "Bucket " << i << ": ";

      while (entry != nullptr)
      {
        cout << "-> " << *(entry->getValue()) << " ";
        entry = entry->getNext();
      }
      cout << endl;
    }
  }
};

#endif