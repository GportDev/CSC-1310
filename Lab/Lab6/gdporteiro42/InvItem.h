/*
  Title: InvItem.h
  Author: Gabriel Porteiro
  Date: Feb 29, 2024
  Purpose: Create the class InvItem
*/

#ifndef INVITEM_H
#define INVITEM_H

#include <string>
using namespace std;

class InvItem
{
private:
  long serialNum;      // Serial number
  string manufactDate; // Manufacture date
  int lotNum;          // Lot number

public:
  // Default constructor
  InvItem()
  {
    serialNum = 0;
    manufactDate = "";
    lotNum = 0;
  }

  // Constructor
  InvItem(long s, string m, int lot)
  {
    serialNum = s;
    manufactDate = m;
    lotNum = lot;
  }

  void setSerialNum(long s)
  {
    serialNum = s;
  }

  void setManufactDate(string m)
  {
    manufactDate = m;
  }

  void setLotNum(int lot)
  {
    lotNum = lot;
  }

  long getSerialNum() const
  {
    return serialNum;
  }

  string getManufactDate()
  {
    return manufactDate;
  }

  int getLotNum() const
  {
    return lotNum;
  }
};

#endif