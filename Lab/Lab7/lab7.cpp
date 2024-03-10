/*
  Author: Gabriel Porteiro
  Data: 03/10/2024
  Purpose: Create the program for the Horror rollercoaster menu
*/

#include <iostream>
#include <fstream>
#include "Queue.h"

int main()
{
  Queue regularPassQueue, instantPassQueue;
  int choice, passType;
  string name;

  do
  {
    cout << "\n\n\t1) \tADD A RIDER TO WAIT LINE.\n";
    cout << "\t2) \tREMOVE RIDER FROM LINE.\n";
    cout << "\t3) \tDONE FOR THE DAY.\n";
    cout << "CHOOSE 1-3: ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    // Add a rider
    case 1:
      cout << "\t\tWhat is your name?  ";
      getline(cin, name);

      cout << "\t\t" << name << ", do you have a(n): " << endl;
      cout << "\t\t1) Normal Pass?" << endl;
      cout << "\t\t2) Instant Pass?" << endl;
      cout << "\t\tCHOOSE 1 or 2:  ";

      cin >> passType;
      cin.ignore();

      while (passType != 1 && passType != 2)
      {
        cout << "\t\tOOPS! That ain't right. CHOOSE 1 or 2:  ";

        cin >> passType;
        cin.ignore();
      }

      if (passType == 2)
      {
        instantPassQueue.enqueue(name);
      }
      else
      {
        regularPassQueue.enqueue(name);
      }
      break;
    // Remove a rider
    case 2:
      if (!instantPassQueue.isEmpty())
      {
        cout << "\t\t" << instantPassQueue.dequeue() << ", InstantPass holder, YOU ARE RIDING!" << endl;
      }
      else if (!regularPassQueue.isEmpty())
      {
        cout << "\t\t" << regularPassQueue.dequeue() << ", normal pass holder, YOU ARE RIDING!" << endl;
      }
      else
      {
        cout << "\n\tTHERE IS NO ONE IN LINE!" << endl;
      }

      break;
    // End the program
    case 3:
      cout << "\n\nEnding the program. Have a spooky day!" << endl;
      break;
    default:
      cout << "\n\nInvalid choice. Please enter a valid option." << endl;
    }
  } while (choice != 3);

  return 0;
}
