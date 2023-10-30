#include<iostream>
#include "Egg.h"
#include "Tray.h"
#include "Harness.h"
using namespace std;

#if __has_include("memory_replacement.h")
#include "memory_replacement.h"
#endif

int main()
{
  Egg smaller(1.24);
  Egg peewee(1.25);
  Egg small(1.5);
  Egg medium(1.75);
  Egg large(2.0);
  Egg xlarge(2.25);
  Egg jumbo(2.5);

  { /* harness empty tray */
    Harness alpha(new Tray, nullptr);
    cout << "Harness around empty tray:\n\n" << alpha;
  }

  {
    Tray* ptr=new Tray;
    ptr->place_back(smaller);
    ptr->place_back(peewee);
    ptr->place_back(small);
    ptr->place_back(medium);
    ptr->place_back(large);
    ptr->place_back(xlarge);
    ptr->place_back(jumbo);
    Harness gamma(ptr, nullptr);

    ptr=new Tray;
    ptr->place_back(jumbo);
    ptr->place_back(medium);
    ptr->place_back(jumbo);
    ptr->place_back(jumbo);
    Harness beta(ptr, &gamma);

    ptr=new Tray;
    ptr->place_back(jumbo);
    ptr->place_back(medium);
    ptr->place_back(medium);
    ptr->place_back(medium);
    ptr->place_back(large);
    ptr->place_back(large);
    ptr->place_back(large);
    ptr->place_back(small);
    Harness alpha(ptr, &beta);

    cout << "\n\n\nThree trays harnessed together:\n\n" << alpha << beta << gamma;
  }

  return 0;
}
