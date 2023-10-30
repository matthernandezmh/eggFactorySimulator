#include "Egg.h"
#include<iostream>

//Defines Egg's first constructor
Egg::Egg(float weight)
  : eggWeight(weight) //Assigns the given weight to our private member 
{
  setEggSymbol(eggWeight);
}

//Defines Egg's second constructor
Egg::Egg()
  : eggWeight(0) //Assigns 0 to our private member since no weight was given
{
  setEggSymbol(eggWeight);
}

void Egg::setEggSymbol( float weight ){
  if( eggWeight < 1.25 && eggWeight >= 0 ){
    eggSymbol = 'E';
  }

  else if( eggWeight < 1.5 && eggWeight >= 1.25 ){
    eggSymbol = '.';
  }

  else if( eggWeight < 1.75 && eggWeight >= 1.5 ){
    eggSymbol = '*';
  }

  else if( eggWeight < 2.0 && eggWeight >= 1.75 ){
    eggSymbol = 'o';
  }

  else if( eggWeight < 2.25 && eggWeight >= 2.0 ){
    eggSymbol = 'O';
  }

  else if( eggWeight < 2.5 && eggWeight >= 2.25 ){
    eggSymbol = '0';
  }

  else if( eggWeight >= 2.5 ){
    eggSymbol = '@';
  }
}

//Defines what changes we want to make to the insertion operator
//Take note of the parameters
std::ostream& operator<<(std::ostream& os, const Egg& rhs)
{
  os << rhs.eggSymbol;
  //We must return os
  return os;
}

bool operator==( const Egg& lhs, const Egg& rhs){
  return lhs.eggSymbol == rhs.eggSymbol;
}
