#ifndef ALIEN_H
#define ALIEN_H

#include "Game_Object.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"

//defines alien class
class Alien: public Game_Object
{
  
  //public members
  public:
  
  //default constructor
  Alien();
  
  //non-default constructor
  Alien(int, Cart_Point);
  
  void start_attack(Person * in_target);
  
  bool update();
  
  void show_status();
  
  void start_moving(Cart_Point);
    
  void stop();
  
  bool update_location();
    
  void setup_destination(Cart_Point);
  
  void Alien_destruc();
  
  
  //private members
  private:
  
  int attack_strength;
  
  double range;
  
  Person * target;
  
  double speed;
  
  Cart_Point destination;
  
  Cart_Vector delta;
  
};

#endif 
  
  
  
  
  
  