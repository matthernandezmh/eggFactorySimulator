#include <iostream>
#include "Tray.h"
#include "Egg.h"

//Defines the Tray constructor
Tray::Tray()
  //carton points to a new Egg array of size 2
  //initializes capacity to have 2 slots
  //sets the current number of eggs to 0
  :carton( new Egg[2] ), capacity(2), numEggs(0)
{
}

//Defines the Tray destructor
Tray::~Tray()
{
  delete [] carton; //Releases an array of Egg classes from memory
}

void Tray::place_front( Egg egg )
{
  if( numEggs==capacity ){
    capacity += 2;
    Egg* newEgg = new Egg[capacity];
    for( int index = 0; index < numEggs; ++index ){
      newEgg[index] = carton[index];
    }
    delete [] carton;
    carton = newEgg;
  }
  for( int i = numEggs; i > 0; --i ){
    carton[i] = carton[i-1];
  }
  carton[0] = egg;
  numEggs++;
}

//Defines the place member function in the Tray class 
void Tray::place_back( Egg eggVar )
{
  //Only runs when the number of eggs is the same as the number of slots
  if( numEggs==capacity ){
    //Increases the number of slots by 2
    capacity += 2;
    //Declares a pointer of type Egg called userEgg
    Egg* userEgg;
    //Assigns a new Egg array of size capacity to userEgg
    userEgg = new Egg[capacity];
    //Loop that copies the eggs from the current array to our new array
    for( int index = 0; index < capacity; ++index ){
      userEgg[index] = carton[index];
    }
    //Releases the old arrays from carton's memory
    delete [] carton;
    //Assigns the new arrays to carton
    carton = userEgg;
  }
  carton[numEggs++] = eggVar;
}

void Tray::remove( Egg eggVariable )
{
  for( int i = 0; i<numEggs; ++i ){
    if( carton[i] == eggVariable ){
      for( int j = i; j < numEggs - 1; ++j ){
        carton[j] = carton[j+1];
      }
      --numEggs;
      --i;
    }
  }
}

//Defines what changes we want to make to our insertion operator
std::ostream& operator<<( std::ostream& os, const Tray& rhs )
{
  int counter = 0;
  os << "+---+\n"; //Prints the top line
  for( int i = 0; i < rhs.capacity; i += 2 ){
    os << "|";
    if( i < rhs.numEggs ){ //Checks if there is an Egg in this spot
      os << rhs.carton[i]; //Prints the Egg at that spot if so
    }
    else{
      os << " "; //Prints a space otherwise
    }
    os << "|";

    if(i+1 < rhs.numEggs){ //Checks if there is an egg in this spot
      os << rhs.carton[i+1]; //Prints the Egg at that spot if so
    }
    else{
      os << " "; //Prints a space otherwise
    }
    os << "|\n";
    //If we're not at the end of the carton, print "|-+-|\n"
    if( ( rhs.capacity / 2 ) > 1 && counter < rhs.capacity/2 - 1 ){
      os << "|-+-|\n";
      ++counter;
    }
  }
  os << "+---+\n"; //Prints the bottom line
  return os;
}

bool operator==( const Tray& lhs, const Tray& rhs )
{
  enum egg_categories {SMALLER, PEEWEE, SMALL, MEDIUM, LARGE, XLARGE, JUMBO};
  Egg smaller(1.00);
  Egg peewee(1.25);
  Egg small(1.50);
  Egg medium(1.75);
  Egg large(2.00);
  Egg xlarge(2.25);
  Egg jumbo(2.5);
  if( rhs.capacity != lhs.capacity ){
    return false;
  }
  else{
    int lhs_count[7]{0}, rhs_count[7]{0};
    for( int i=0; i<lhs.numEggs; ++i ){
      if( lhs.carton[i] == smaller )
        ++lhs_count[SMALLER];
      if( rhs.carton[i] == smaller )
        ++rhs_count[SMALLER];
    }
    for( int i=0; i<lhs.numEggs; ++i ){
      if( lhs.carton[i] == peewee )
        ++lhs_count[PEEWEE];
      if( rhs.carton[i] == peewee )
        ++rhs_count[PEEWEE];
    }
    for( int i=0; i<lhs.numEggs; ++i ){
      if( lhs.carton[i] == small )
        ++lhs_count[SMALL];
      if( rhs.carton[i] == small )
        ++rhs_count[SMALL];
    }
    for( int i=0; i<lhs.numEggs; ++i ){
      if( lhs.carton[i] == medium )
        ++lhs_count[MEDIUM];
      if( rhs.carton[i] == medium )
        ++rhs_count[MEDIUM];
    }
    for( int i=0; i<lhs.numEggs; ++i ){
      if( lhs.carton[i] == large )
        ++lhs_count[LARGE];
      if( rhs.carton[i] == large )
        ++rhs_count[LARGE];
    }
    for( int i=0; i<lhs.numEggs; ++i ){
      if( lhs.carton[i] == xlarge )
        ++lhs_count[XLARGE];
      if( rhs.carton[i] == xlarge )
        ++rhs_count[XLARGE];
    }
    for( int i=0; i<lhs.numEggs; ++i ){
      if( lhs.carton[i] == jumbo )
        ++lhs_count[JUMBO];
      if( rhs.carton[i] == jumbo )
        ++rhs_count[JUMBO];
    }
    for( int index = 0; index < 7; ++index ){
      if( lhs_count[index] != rhs_count[index] ){
        return false;
      }
    }
    //etc...
    //And finally...loop 7 times to compare lhs_count[i] to rhs_count[i]
    //if they're not equal, return false
    //if you reach end of loop, then return true
  }   //ends else statement
  return true;
}
