#include <iostream>
#include "Tray.h"
#include "Egg.h"
#include "Harness.h"

Harness::Harness( Tray* ptrTray, Harness* ptrHarness )
  :pointerTray( ptrTray ), pointerHarness( ptrHarness )
{
}

Harness::~Harness()
{
  delete pointerTray;
}

std::ostream& operator<<( std::ostream& os, const Harness& rhs )
{
  os << " / \\ \n" << "/   \\\n" << *rhs.pointerTray;
  //os << ;
  return os;
}
