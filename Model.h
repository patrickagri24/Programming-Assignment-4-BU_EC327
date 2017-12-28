#ifndef MODEL_H
#define MODEL_H

#include "Person.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Game_Object.h"
#include "Astronaut.h"
#include "Cart_Point.h"
#include "Alien.h"
#include "View.h"
#include "Input_Handling.h"
#include <list>


//Model class
class Model
{
  //friend class Game_Command;
  
  //public members
  public:
    
    
    
    //Default constructor
    Model();
    
    //Default destructor
    ~Model();
    
    //Pointers
    Person * get_Person_ptr(int);
    
    Oxygen_Depot * get_Oxygen_Depot_ptr(int);
    
    Space_Station * get_Space_Station_ptr(int);
    
    Alien * get_Alien_ptr(int);
    
    bool update();
    
    //come back when can
   void display(View&);
   
   void show_status();
   
   void handle_new_command(Model&, char, int, Cart_Point);
   
   //these are all getters for the numbers of each of these variables
   //these are used because the variables are private and these are not to 
   //be confused with get person ptr, they only return ints
   int get_people();
   
   int get_depots();
   
   int get_stations();
   
   int get_aliens();
   
   
   
   //Private
   private:
   
   int time;
   
   int count_down;
   
   //equivalent game object list
   list<Game_Object *> object_ptrs;
   
   //list of active members
   list<Game_Object *> active_ptrs;
   
   int num_objects;
  
   //equivalent person list
   list<Person *> person_ptrs;
   
   int num_persons;

   //equivalent ox depot list
   list<Oxygen_Depot *> depot_ptrs;
   
   int num_depots;
 
   //equivalent space station list
   list<Space_Station *> station_ptrs;
   
   int num_stations;
   
   list<Alien *> alien_ptrs;

   int num_aliens;
   
   
   
};

#endif
   
   
   
