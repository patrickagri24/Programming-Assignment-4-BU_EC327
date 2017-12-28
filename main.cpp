#include <iostream>
#include <cmath>
#include "stdlib.h"
#include <string>


#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"
#include "Astronaut.h"
#include "Model.h"
#include "Game_Command.h"
#include "View.h"
#include "Alien.h"
#include "Input_Handling.h"

using namespace std;

int main()
{

//outputs the main header
cout << "EC327: Introduction to Software Engineering" << endl;
cout << "Fall 2017" << endl;
cout << "Programming Assignment 4" << endl;



//Begins the game
Model model;
View view;

//creates all the variables we will need
char code;
int id1;
int id2;
double locationx;
double locationy;
Cart_Point locationMain;

//for adding a character
char newchar;

//shows all the statuses

model.show_status();
model.display(view);

//creates do while loop, will have dummy variable that will not change so loop will keep iterating
int dummy = 1;
while(dummy == 1)
{
  try
  {  
	cout << "Enter command: ";
	cin >> code;
 
	 //tests for main cin fail
	 if(cin.fail())
	 {
	   cin.clear();
	   throw Invalid_Input("Invalid game command, try again!");
	 }
 
  	//error handling

   

	  //generates switch statement for whatever is inputted
	switch(code)
  	{
  	case 'm':
	{
  		
		cin >> id1 >> locationx >> locationy;
	
		if(cin.fail() == true){
			//cin.fail();
			cin.clear();
			throw Invalid_Input("Invalid attempt to move!");
			cin.clear();
		}

		locationMain.x = locationx;
		locationMain.y = locationy;

		cout <<  "Move Astronaut (enter 'a') or Alien (enter 'x'): ";
          	char character2;
          	cin >> character2;
        	
		if(character2 != 'a' && character2 != 'x'){
			//cin.fail();
			cin.clear();
			throw Invalid_Input("Invalid entry, expected an 'a' for astronaut or 'x' for alien!");
			cin.clear();
		}
		
			if(character2 == 'a')
          		{
        
				do_move_A(model,id1, locationMain);
				model.display(view);
	
            			break;
          
          		}
          		else if(character2 == 'x')
         		 {
          
           			 do_move_Al(model,id1, locationMain);
           			 model.display(view);
          
           			 break;
         		 }

		
		
		
      	}
       
	case 'w':
	{
		cin >> id1 >> id2;


		if(cin.fail() == true){
			//cin.fail();
			cin.clear();
			throw Invalid_Input("Invalid attempt to work a depot!");
			cin.clear();
      
		}		


		do_work(model,id1,id2);

		model.display(view);

		break;
	}
	  	
	case 'd':
	{
		cin >> id1 >> id2;
   
     		if(cin.fail() == true){
			//cin.fail();
			cin.clear();
			throw Invalid_Input("Invalid attempt to deposit!");
			cin.clear();
      
		}	

		do_deposit(model,id1,id2);

		model.display(view);
		
		break;
	}
	  	

	case 's':
	{

		cin >> id1;
   
  		 if(cin.fail() == true){
			//cin.fail();
			cin.clear();
			throw Invalid_Input("Invalid attempt to stop!");
			cin.clear();
      
		}	

		cout <<  "Stop Astronaut (enter 'a') or Alien (enter 'x'): ";
        
		char character2;
		cin >> character2;
   
   		if(character2 != 'a' && character2 != 'x'){
			//cin.fail();
			cin.clear();
			throw Invalid_Input("Invalid entry, expected an 'a' for astronaut or 'x' for alien!");
			cin.clear();
      
		}	
      
      
		if(character2 == 'a')
        	{
			do_stop_A(model,id1);

			model.display(view);

			break;
        	}
        	else if(character2 == 'x')
        	{
          
			do_stop_Al(model,id1);
        
			model.display(view);
        
          		break;
       		}

	}
	
	case 'l':
	{
	  	  
		cin >> id1 >> id2;
   
   		if(cin.fail() == true)
		{
			//cin.fail();
			cin.clear();
			throw Invalid_Input("Invalid attempt to lock!");
			cin.clear();
      
		}	

		do_lock(model,id1,id2);

		model.display(view);

		break;
	}
     
	case 'g':
	{
		if(cin.fail() == true)
		{
			//cin.fail();
			cin.clear();
			throw Invalid_Input("Invalid attempt to go!");
			cin.clear();
      
		}

		do_go(model);

		model.show_status();
		  
		model.display(view);

		//do_go(model);

		break;
    	}

	case 'r':
	{
		if(cin.fail() == true)
		{
			//cin.fail();
			cin.clear();
			throw Invalid_Input("Invalid attempt to run!");
			cin.clear();
      
		}
		

		do_run(model);

		model.show_status();

		model.display(view);

      

		break;
	}
		

	case 'q':
	{

		if(cin.fail() == true)
		{
			//cin.fail();
			cin.clear();
			throw Invalid_Input("Invalid attempt to quit!");
			cin.clear();
      
		}		
  
		do_quit(model);
		break;
	}
   
	case 'a':
	{
      
		cin >> id1 >> id2;
   
   		if(cin.fail() == true)
		{
			//cin.fail();
			cin.clear();
			throw Invalid_Input("Invalid attempt to attack!");
			cin.clear();
      
		}	
      
		do_attack(model,id1,id2);
      
		model.display(view);
      
		break;
      
	}
    
	case 'n':
    	{
      
		cin >> newchar >> id1 >> locationx >> locationy;
   
   		if(cin.fail() == true)
		{
			//cin.fail();
			cin.clear();
			throw Invalid_Input("Invalid command to create new object!");
			cin.clear();
		}	

		locationMain.x = locationx;
      
		locationMain.y = locationy;
                
		model.handle_new_command(model,newchar,id1,locationMain);
      
		model.display(view);
      
		break;
    	}

	default:
	{
		 //cin.clear();
		 //cin.ignore();
		
   		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
   		 //std::cin.ignore(1000, '\n');
   
    		throw Invalid_Input(" Invalid game command, try again!");
		
		cin.clear();
		cin.ignore();

		break;
	}

	}
  
	}
  
	//catch statement
	catch(Invalid_Input& except)
	{
    		std::cin.ignore(1000, '\n');
		cout << "Invalid input - " << except.msg_ptr << endl;
    
		continue;
    
	} 




}


return 0;
}
