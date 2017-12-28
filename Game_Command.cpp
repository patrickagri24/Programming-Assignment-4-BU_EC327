#include "Game_Command.h"
#include "Model.h"
#include "Cart_Point.h"
#include "Person.h"
#include "Astronaut.h"
#include "Oxygen_Depot.h"
#include "Alien.h"
#include "Input_Handling.h"

#include <iostream>
#include "stdlib.h"
using namespace std;



//move function for astronaut
void do_move_A(Model& model,int id, Cart_Point loc )
{
  //gets the person we NEED
	Person * astro = model.get_Person_ptr(id);
  char state = astro -> get_state();
 
  if(astro != 0 && state == 'l')
  {
    cout << astro -> get_display_code() << astro -> get_id() << ": I can't move, I'm locked in!" << endl;
    return;
  }
  else if(astro != 0 && state == 'x')
  {
    cout << astro -> get_display_code() << astro -> get_id() << ": ...can't move...dead" << endl;
    return;
  }
  
  else if(astro != 0)
  {
    //checks location parameter
    Cart_Point out;
    out = astro -> get_location();

    if(out.x == loc.x  && out.y == loc.y)
    {
	      cout << "A1: I'm already there. See?" << endl;
        return;
    }

    astro -> start_moving(loc);
    return;
  }
  else
  {
    cout << "Invalid id" << endl;
    return;
  }
  
}

//alien move
void do_move_Al(Model& model,int id, Cart_Point loc )
{
  //gets the person we NEED
	Alien * astro = model.get_Alien_ptr(id);
  char state = astro -> get_state();
 
  if(astro != 0)
  {
    //checks location parameter
    Cart_Point out;
    out = astro -> get_location();

    if(out.x == loc.x  && out.y == loc.y)
    {
	      cout << "A1: I'm already there. See?" << endl;
        return;
    }

    astro -> start_moving(loc);
    return;
  }
  else
  {
    cout << "Invalid id" << endl;
    return;
  }
  
}






//work a depot function
void do_work(Model& model,int id1,int id2)
{
  //gets the person and depot we NEED
	Person * astro = model.get_Person_ptr(id1);
  Oxygen_Depot * depot = model.get_Oxygen_Depot_ptr(id2);
  
  char state = astro -> get_state();
 
  if(astro != 0 && state == 'l')
  {
    cout << astro -> get_display_code() << astro -> get_id() << ": I can't move, I'm locked in!" << endl;
    return;
  }
  else if(astro != 0 && state == 'x')
  {
    cout << astro -> get_display_code() << astro -> get_id() << ": ...can't move...dead" << endl;
    return;
  } 
  
  else if(astro != 0 && depot != 0)
  {
    astro -> start_supplying(depot);
    return;
  }
  else
  {
    cout << "Invalid id" << endl;
    return;
  }
}
  
  
//deposit moonstone function
void do_deposit(Model& model,int id1, int id2)
{
  //gets the person and station we NEED
	Person * astro = model.get_Person_ptr(id1);
  Space_Station * station = model.get_Space_Station_ptr(id2);
  
  char state = astro -> get_state();
 
  if(astro != 0 && state == 'l')
  {
    cout << astro -> get_display_code() << astro -> get_id() << ": I can't move, I'm locked in!" << endl;
    return;
  }
  else if(astro != 0 && state == 'x')
  {
    cout << astro -> get_display_code() << astro -> get_id() << ": ...can't move...dead" << endl;
    return;
  }
  
  else if(astro != 0 && station != 0)
  {
    astro -> start_depositing(station);
    return;
  }
  else
  {
    cout << "Invalid id" << endl;
    return;
  }

}
  
  
//stop command for astronaut
void do_stop_A(Model& model,int id)
{
  //gets the person and station we NEED
  Person * astro = model.get_Person_ptr(id);

  char state = astro -> get_state();
 
  
  if(astro != 0 && state == 'x')
  {
    cout << astro -> get_display_code() << astro -> get_id() << ": ...can't stop...dead" << endl;
    return;
  }
  else if(astro != 0 && state == 'l')
  {
    cout << astro -> get_display_code() << astro -> get_id() << ": can't stop. Locked in!" << endl;
    return;
  }
  
  else if(astro != 0)
  {
    astro -> stop();
    return;
  }
  else
  {
    cout << "Invalid id" << endl;
    return;
  }
  
}

//stop command for alien
void do_stop_Al(Model& model,int id)
{
  //gets the person and station we NEED
  Alien * astro = model.get_Alien_ptr(id);

 
  if(astro != 0)
  {
    astro -> stop();
    return;
  }
  else
  {
    cout << "Invalid id" << endl;
    return;
  }
  
}

//lock into station command
void do_lock(Model& model, int id1, int id2)
{
    //gets the person and station we NEED
	Person * astro = model.get_Person_ptr(id1);
  Space_Station * station = model.get_Space_Station_ptr(id2);
  
  char state = astro -> get_state();
 
  if(astro != 0 && state == 'l')
  {
    cout << astro -> get_display_code() << astro -> get_id() << ": I can't move, I'm locked in!" << endl;
    return;
  }
  else if(astro != 0 && state == 'x')
  {
    cout << astro -> get_display_code() << astro -> get_id() << ": ...can't move...dead" << endl;
    return;
  }
  else if(astro != 0 && station != 0)
  {
    astro -> go_to_station(station);
    return;
  }
  else
  {
    cout << "Invalid id" << endl;
    return;
  }

}

//go functin
void do_go(Model& model)
{
  cout << "Advancing one tick." << endl;  

  model.update();
  return;
}


//run function
void do_run(Model& model)
{
  cout << "Advancing to next event" << endl;

  for(int i = 0;i < 5;i++)
  {
    bool out = model.update();
    if(out == true)
    {
      goto finish;
    }
  }finish:
  
  return;
      
}


//quit program function
void do_quit(Model& model)
{
  //int id1 = 1;
  //int id2 = 2;
  
  cout << "Terminating program" << endl;
    
  /*
  Person * per1 = model.get_Person_ptr(id1);
  Person * per2 = model.get_Person_ptr(id2);
  
  per1 -> person_destruc();
  per2 -> person_destruc();
  
  
  Oxygen_Depot * depot1 = model.get_Oxygen_Depot_ptr(id1);
  Oxygen_Depot * depot2 = model.get_Oxygen_Depot_ptr(id2);
  
  depot1 -> Ox_destruc();
  depot2 -> Ox_destruc();
  
  
  Space_Station * station1 = model.get_Space_Station_ptr(id1);
  Space_Station * station2 = model.get_Space_Station_ptr(id2);
  
  station1 -> Space_destruc();
  station2 -> Space_destruc();
  */
  
  int people = model.get_people();
  int depots = model.get_depots();
  int stations = model.get_stations();
  int aliens = model.get_aliens();
  
  int start = 0;
  for(int i = 0;i < people;i++)
  {
    Person * per = model.get_Person_ptr(start);
    per -> person_destruc();
    
    start++;
  }
  
  for(int i = 0;i < depots;i++)
  {
    Oxygen_Depot * ox = model.get_Oxygen_Depot_ptr(start);
    ox -> Ox_destruc();
    
    start++;
  }
  
  for(int i = 0;i < stations;i++)
  {
    Space_Station * station = model.get_Space_Station_ptr(start);
    station -> Space_destruc();
    
    start++;
  }
  
  for(int i = 0;i < aliens;i++)
  {
    Alien * al = model.get_Alien_ptr(start);
    al -> Alien_destruc();
    
    start++;
  }
  
  
  
  
  
  
  cout << "Model destructed" << endl;
  
  

  exit(EXIT_SUCCESS);
  return;
}  

  

//do attack function
void do_attack(Model& model, int id1, int id2)
{
  Alien * roswell = model.get_Alien_ptr(id1);
  Person * nick = model.get_Person_ptr(id2);

  int aliens = model.get_aliens();
  int people = model.get_people();
  
  if(roswell != 0 && nick != 0 && 0 < id1 && id1 <= aliens && 0 < id2 && id2 <= people)
  {
    roswell -> start_attack(nick);
    return;
  }
  else
  {
    cout << "Invalid id number for one or both objects" << endl;
    return;
  }
  
}
  


  
  
  
  
  
  
  
  
  
  


