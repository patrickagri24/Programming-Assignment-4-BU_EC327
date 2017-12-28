#include "Alien.h"

#include "Game_Object.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"

#include <iostream>
using namespace std;

//default alien constructor
Alien::Alien(): Game_Object('X')
{
  attack_strength = 2;
  
  range = 2.0;
  
  this -> target = NULL;
  
  speed = 5;
  
  cout << "Alien default constructed" << endl;
  
}

//non-default constructor
Alien::Alien(int in_id, Cart_Point in_loc): Game_Object(in_loc, in_id, 'X')
{
  id_num = in_id;
  
  location = in_loc;
  
  attack_strength = 2;
  
  range = 2.0;
  
  this -> target = NULL;
  
  speed = 5;
  
  cout << "Alien constructed" << endl;
  
}


//start attack function
void Alien::start_attack(Person * in_target)
{
  
  //gives the alien a destination
  //setup_destination(in_target -> get_location());
  
  
  Cart_Point test = in_target -> get_location();
  //cout << test << endl;
  double dist = cart_distance(test, location);
  
 // cout << dist << endl;
  
  //if the distance is less than or equal to range, the alien will attack
  if(dist <= range)
  {
    cout << display_code << id_num << ": Smash!" << endl;
    state = 'a';
    
    target = in_target;
    return;
  }
  else
  {
    cout << display_code << id_num << ": Target is out of range" << endl;
    return;
  }
  
}


//alien update
bool Alien::update()
{
  switch(state)
  {
    case 's':
    {
      return false;
    }
    
    case 'm':
    {
      bool out = update_location();
        
        if(out == true)
        {
          state = 's';
         // amount_moonstones++;
         // amount_oxygen--;
          return true;
        }
        
        else
        {
          /*if(health < 3)
          {
            display_code = tolower(display_code);
          }
                    
          if(amount_oxygen == 0)
	        {
	        cout << "I can't move, I'm out of oxygen" << endl;
	        state = 'x';
	        return true;
	        }
	        amount_moonstones++;
          amount_oxygen--;*/
          return false;
        }
        
    }
    
    case 'a':
    {
      
      double dist = cart_distance(target -> get_location(), location);
      
      if(dist > range)
      {
        cout << display_code << id_num << ": Unsuccessful attack, out of range." << endl;
        cout << display_code << id_num << ": Chaaaaaaarge." << endl;
        
        state = 's';
        
        return true;
      }
      
      else if(dist <= range)
      {
        bool out = target -> is_alive();
        
        if(out == false)
        {
          cout << display_code << id_num << ": I triumph!" << endl;
          
          state = 's';
          
          return true;
        }
        
        else
        {
          cout << display_code << id_num << ": Take that!" << endl;
          
          target -> take_hit(attack_strength);
          
          return false;
        }
      }
      
    }
    
  }
  
}


//alien show status
void Alien::show_status()
{
  
  cout << "Alien status: ";
  
  //first performs game object show status
  Game_Object::show_status();
  
  //switch statement
  switch(state)
  {
  
    case 's':
    {
      cout << " is stopped and is awaiting attack";
      break;
    }
    case 'm':
    {
      cout << " moving at speed of " << speed << " towards " << "(" << destination.x << "," << destination.y << ") at each step of <" << delta.x << "," << delta.y << ">";
      break;
    }
    case 'a':
    {
      cout << " is attacking astronaut " << target -> get_display_code() << target -> get_id();
      break;
    }
    
  }

 return;
}


//starts moving
void Alien::start_moving(Cart_Point dest)
{

  //sets up destination
  setup_destination(dest);

  


  state = 'm';
  
  cout << "Moving " << id_num << " to " << destination << endl;
  cout << display_code << id_num << ": On my way." << endl;
  
  return;
}


//Alien stop
void Alien::stop()
{
  state = 's';
  
  cout << "Stopping " << id_num << endl;
  cout << display_code << id_num << ": All right" << endl;
  
  return;
  
}



//Alien update location function
bool Alien::update_location()
{
  if((abs(destination.x - location.x) <= abs(delta.x)) && (abs(destination.y - location.y) <= abs(delta.y)))
  {
    location.x = destination.x;
    location.y = destination.y;
    
    cout << display_code << id_num << ": I'm there!" << endl;
    
    return true;
  }
 
  else 
  {
    location.x = location.x + delta.x;
    location.y = location.y + delta.y;
    
  
    
    cout << display_code << id_num << ": step..." << endl;
    return false;
  }
  
  
}


//Setup destination
void Alien::setup_destination(Cart_Point dest)
{
  
   destination = dest;
   
   delta = ((destination - location ) * (speed / cart_distance(destination, location)));
  
  
 return; 
}

//alien destruc
void Alien::Alien_destruc()
{
  cout << "Alien destructed" << endl;
  
  Game_Object::Game_Obj_destruc();
  
  return;
}





