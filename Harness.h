#ifndef HARNESS_H
#define HARNESS_H
#include<iostream>
#include "Egg.h"
#include "Tray.h"

struct Harness{
  Harness( Tray* ptrTray, Harness* ptrHarness );
  friend std::ostream& operator<<( std::ostream& os, const Harness& rhs );
  ~Harness();
  Tray* pointerTray; //Creates a pointer of type Tray 
  Harness* pointerHarness; //Creates a pointer of type Harness
};

#endif
