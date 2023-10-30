#ifndef EGG_H
#define EGG_H
#include<iostream>

class Egg {
  public:
    //Two constructors:
    Egg(float weight); //If the egg's weight is given 
    Egg(); //If the egg's weight is not given

    //Allows operator to access public and private members
    //Can be declared in public or private
    friend std::ostream& operator<<(std::ostream& os, const Egg& rhs);
    friend bool operator==( const Egg& lhs, const Egg& rhs);
  private:
    float eggWeight; //Holds the weight of our egg
    char eggSymbol; //Holds the symbol for the egg
    void setEggSymbol(float weight);
};
#endif
