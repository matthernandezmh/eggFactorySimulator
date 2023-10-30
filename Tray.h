#ifndef TRAY_H
#define TRAY_H
#include<iostream>
#include "Egg.h"

class Tray{
  public:
    //Constructor
    Tray();
    void place_front( Egg egg );
    void place_back( Egg eggVar ); //Places an egg in the last slot of the tray
    void remove( Egg eggVariable );
    //Same concept from the Egg class 
    friend std::ostream& operator<<( std::ostream& os, const Tray& rhs );
    friend bool operator==( const Tray& lhs, const Tray& rhs );
    //Destructor
    ~Tray();
  private:
    Egg* carton; //Creates a pointer of type Egg
    int capacity; //Holds the number of slots available on our tray
    int numEggs; //Holds the number of eggs there are in total
};

#endif
