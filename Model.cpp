#include "Model.h"
#include "Game_Object.h"
#include "Person.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Cart_Point.h"
#include "Astronaut.h"
#include "Alien.h"
#include "stdlib.h"
#include "View.h"

#include <list> 

#include <iostream>
using namespace std;

//Default constructor
Model::Model()
{
  time = 0;
  
  count_down = 10;
 
  //Makes astroanut  1
  Cart_Point one(5,1);
  int idOne = 1;

  Astronaut * Neilptr = new Astronaut(one, idOne);
 
  object_ptrs.push_front(Neilptr);
  active_ptrs.push_front(Neilptr);
  person_ptrs.push_front(Neilptr);

  //Makes astronaut 2
  Cart_Point two(10,1);
  int idTwo = 2;

  Astronaut * Buzzptr = new Astronaut(two, idTwo);
  
  object_ptrs.push_back(Buzzptr);
  active_ptrs.push_back(Buzzptr);
  person_ptrs.push_back(Buzzptr);

  //Makes Oxygen Depot 1
  Cart_Point three(1,20);
  int idThree = 1;

  Oxygen_Depot * Moon1ptr = new Oxygen_Depot(three, idThree);

  object_ptrs.push_back(Moon1ptr);
  active_ptrs.push_back(Moon1ptr);
  depot_ptrs.push_front(Moon1ptr);


  //Makes Oxygen Depot 2
  Cart_Point four(10,20);
  int idFour = 2;

  Oxygen_Depot * Moon2ptr = new Oxygen_Depot(four, idFour);

  object_ptrs.push_back(Moon2ptr);
  active_ptrs.push_back(Moon2ptr);
  depot_ptrs.push_back(Moon2ptr);
  

  //Make space station 1
  Space_Station * Apollo = new Space_Station;

   

  object_ptrs.push_back(Apollo);
  active_ptrs.push_back(Apollo);
  station_ptrs.push_front(Apollo);
 

  //makes space station2
  Cart_Point five(5,5);
  int idFive = 2;
 
  Space_Station * Apollo11 = new Space_Station(five, idFive);

  object_ptrs.push_back(Apollo11);
  active_ptrs.push_back(Apollo11);
  station_ptrs.push_back(Apollo11);
  
  
  //makes alien one
  Cart_Point six(7,14);
  int idSix = 1;
  
  Alien * yung_k = new Alien(idSix, six);
  
  object_ptrs.push_back(yung_k);
  active_ptrs.push_back(yung_k);
  alien_ptrs.push_front(yung_k);
  
  
  //makes alien two
  Cart_Point seven(7,5);
  int idSeven = 2;
  
  Alien * ko_k = new Alien(idSeven, seven);
  
  object_ptrs.push_back(ko_k);
  active_ptrs.push_back(ko_k);
  alien_ptrs.push_back(ko_k);
  

  //initializes other variables
  num_objects = 7;
  num_persons = 2;
  num_depots = 2;
  num_stations = 2;
  num_aliens = 2;

  cout << "Model default constructed" << endl;
  
  

  
}



//Default destructor
Model::~Model()
{
  
  //deletes game object pointers
  list<Game_Object *>::iterator it1;
  for(it1 = object_ptrs.begin(); it1 != object_ptrs.end(); ++it1)
  {
    object_ptrs.pop_back();
  }
  
  
  //deletes person pointers
  list<Person *>::iterator it2;
  for(it2 = person_ptrs.begin(); it2 != person_ptrs.end(); ++it2)
  {
    person_ptrs.pop_back();
  }
  
  //deletes depot pointers
  list<Oxygen_Depot *>::iterator it3;
  for(it3 = depot_ptrs.begin(); it3 != depot_ptrs.end(); ++it3)
  {
    depot_ptrs.pop_back();
  }
  
  //deletes station pointers
  list<Space_Station *>::iterator it4;
  for(it4 = station_ptrs.begin(); it4 != station_ptrs.end(); ++it4)
  {
    station_ptrs.pop_back();
  }
  
  //deletes alien pointers
  list<Alien *>::iterator it5;
  for(it5 = alien_ptrs.begin(); it5!= alien_ptrs.end(); ++it5)
  {
    alien_ptrs.pop_back();
  } 
  

  cout << "Model destructed" << endl;
  

}



//gets person pointer
//come here for seg fault errors
Person * Model::get_Person_ptr(int id)
{
  
  list<Person *>::iterator it = person_ptrs.begin();
  
  if(id == 1)
  {
    return *it;
  }
  else
  {
    advance(it,id-1);
  
    return *it;
  }


}



//gets oxygen depot pointer
//come here for seg fault errors
Oxygen_Depot * Model::get_Oxygen_Depot_ptr(int id)
{
  
  list<Oxygen_Depot *>::iterator it = depot_ptrs.begin();
  
  if(id == 1)
  {
    return *it;
  }
  else
  {
  
    advance(it,id-1);
  
    return *it;
  }
  

}




//gets space station pointers
//come here for seg fault errors
Space_Station * Model::get_Space_Station_ptr(int id)
{
 
  list<Space_Station *>::iterator it = station_ptrs.begin();
  
  if(id == 1)
  {
    return *it;
  }
  else
  {
  
    advance(it,id-1);
  
    return *it;
  }
 
}




//get alien pointer
Alien * Model::get_Alien_ptr(int id)
{
  
  list<Alien *>::iterator it = alien_ptrs.begin();
  
  if(id == 1)
  {
    return *it;
  }
  else
  {
    advance(it,id-1);
  
    return *it;
  }
  
}



//update function
bool Model::update()
{
  //increments time and decrements count down
  time++;
  
  //defines variables we will use
  bool out;
  
  int station1_num;
  int station2_num;
  
  int counter = 0;
  int counter2 = 0;
  
  double ox1;
  double ox2;
  
  int STATIONS = 0;
  int bodycount = 0;
  
  //better algorithym for updating
  
  for(list<Game_Object *>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); ++it)
  {
    
    out = (*it) -> update();
    if(out == true)
    {counter++;}
      
  }
  
  //will check if anything is dead, and if so will delete
  for(list<Game_Object *>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); ++it)
  {
    if( (*it) -> get_state() == 'x' && num_objects != 0)
    {
       it = active_ptrs.erase(it);
       
       cout << "An object was removed because it is dead" << endl;
    }
  }
  
    
  //will test for who is alive
  list<Person *>::iterator it2;
  
  for(it2 = person_ptrs.begin(); it2 != person_ptrs.end(); ++it2)
  {  
    int test = num_persons;
    
    bool out = (*it2) -> is_alive();
    if(out == false)
    {
      counter2++;
      
      //now will make a new num persons
      test = test - counter2;
      if(test <= 0)
      {
        cout << "You have no more astronauts! You lose!" << endl;
        exit(EXIT_SUCCESS);
      }
      
    }
      
  }
  
  //seeing if both astronauts have oxygen
  list<Person *>::iterator it4;
  for(it4 = person_ptrs.begin();it4 != person_ptrs.end();++it4)
  {
    
    //sets another variable to manage people
    int people = num_persons;
    
    bool out = (*it4) -> is_alive();
    if(out == true)
    {
      people--;
      if(people == 0)
      {
        cout << "All of your astronauts are dead! You lose!" << endl;
        exit(EXIT_SUCCESS);
      }
    }
  }
 
  
  //tests to see if all the space stations are updated
  for(list<Space_Station *>::iterator it = station_ptrs.begin();it != station_ptrs.end();++it)
  {
    
    char out = (*it) -> get_state();
    if(out == 'u')
    {
      STATIONS++;
        
    }
  }
  
  //now performs necessary operations
  if(STATIONS == num_stations)
  {
    
    for(list<Space_Station *>::iterator it5 = station_ptrs.begin();it5 != station_ptrs.end();++it5)
    {
      
      
      
      int out = (*it5) -> get_astronauts();
      
      if(out > 0)
      {
        bodycount++;
        //cout << "Bodycount: " << bodycount << endl;
        //cout << "People: " << num_persons << endl;
      }
    
        
    }

 	//now evaluate what we have for numbers
    if(bodycount == num_stations)
        {
          if(count_down >= 1)
          {
            cout << "Ready for takeoff? " << count_down << "..." << endl;
            cout << "Blast Off! You Win!" << endl;
            exit(EXIT_SUCCESS);
     	      return true;
          }
          else if(count_down < 1)
          {
            cout << "Unmanned takeoff... You lose!" << endl;
            exit(EXIT_SUCCESS);
          }
        }
      
    if(count_down < 1)
    {
       cout << "Unmanned takeoff... You lose!" << endl;
       exit(EXIT_SUCCESS);
    }
      
      cout << "Ready for takeoff? " << count_down << "..." << endl;
      cout << "Missing astronauts!" << endl;
      count_down--;
    
  }
  
  //will evaluate whether or not to return true
  if(counter > 0)
  {
    return true;
  }
  else
  {
    return false;
  }
  
    
}
  
  


//model display
void Model::display(View &view)
{

    
    view.clear();
    
    list<Game_Object *>::iterator it;
    for(it = active_ptrs.begin(); it != active_ptrs.end(); ++it)
    {
     //here we will not plot an object if it is dead
         
      view.plot((*it));
          
    }


    view.draw();

return;
}



//Shows status
void Model::show_status()
{

  cout << "Time: " << time << endl;
  
  list<Game_Object *>::iterator it;

  for(it = object_ptrs.begin(); it != object_ptrs.end(); ++it)
  {
    (*it) -> show_status();
    cout << endl;
  }
  
  
  return;


}


//handle new command command
void Model::handle_new_command(Model& model, char type, int id, Cart_Point location)
{
  //will determine what to add
  if(type == 'd')
  {
    if(id > num_depots && id < 10 && id > 0)
    {
    
    Oxygen_Depot * newDep = new Oxygen_Depot(location,id);
    
    object_ptrs.push_back(newDep);
    active_ptrs.push_back(newDep);
    depot_ptrs.push_back(newDep);
    
    num_depots++;
    
    num_objects++;
    
    }
    
    else
    {
      cout << "The depot you are trying to add either already exists or has an ID Number that is invalid." << endl;
    }
    
    
  }
  else if(type == 's')
  {
    if(id > num_stations && id < 10 && id > 0)
    {
    
    Space_Station * newStation = new Space_Station(location,id);
    
    object_ptrs.push_back(newStation);
    active_ptrs.push_back(newStation);
    station_ptrs.push_back(newStation);
    
    num_stations++;
    num_objects++;
    }
    else
    {
      cout << "The station you are trying to add either already exists or has an ID Number that is invalid." << endl;
    }
  }
  else if(type == 'a')
  {
    if(id > num_persons && id < 10 && id > 0)
    {
    
    Astronaut * newPers = new Astronaut(location,id);
    
    object_ptrs.push_back(newPers);
    active_ptrs.push_back(newPers);
    person_ptrs.push_back(newPers);
    
    num_persons++;
    num_objects++;
    }
    
    else
    {
      cout << "The astronaut you are trying to add either already exists or has an ID Number that is invalid." << endl;
    }
  }
  else if(type == 'x')
  {
    if(id > num_aliens && id < 10 && id > 0)
    {
    
    Alien * newAlien = new Alien(id,location);
    
    object_ptrs.push_back(newAlien);
    active_ptrs.push_back(newAlien);
    alien_ptrs.push_back(newAlien);
    
    num_aliens++;
    num_objects++;
    }
    else
    {
      cout << "The alien you are trying to add either already exists or has an ID Number that is invalid." << endl;
    }
  }
  
  return;
  
}

//the getters as outlined in model.h
int Model::get_people()
{
  return num_persons;
}

int Model::get_depots()
{
  return num_depots;
}

int Model::get_stations()
{
  return num_stations;
}

int Model::get_aliens()
{
  return num_aliens;
}







