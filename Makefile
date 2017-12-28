GCC = g++

OBJS = Cart_Point.o Cart_Vector.o Game_Object.o Oxygen_Depot.o Space_Station.o Person.o Astronaut.o Model.o Game_Command.o View.o Alien.o Input_Handling.o main.o

default: PA4

PA4: $(OBJS)
	$(GCC) -o PA4 $(OBJS)

Cart_Point.o:Cart_Point.cpp Cart_Point.h Cart_Vector.h
	$(GCC) -c Cart_Point.cpp -o Cart_Point.o

Cart_Vector.o:Cart_Vector.cpp Cart_Vector.h 
	$(GCC) -c Cart_Vector.cpp -o Cart_Vector.o

Game_Object.o:Game_Object.cpp Game_Object.h Cart_Point.h Cart_Vector.h
	$(GCC) -c Game_Object.cpp -o Game_Object.o

Oxygen_Depot.o:Oxygen_Depot.cpp Oxygen_Depot.h Game_Object.h Cart_Point.h
	$(GCC) -c Oxygen_Depot.cpp -o Oxygen_Depot.o

Space_Station.o:Space_Station.cpp Space_Station.h Game_Object.h Cart_Point.h
	$(GCC) -c Space_Station.cpp -o Space_Station.o

Person.o:Person.cpp Person.h Cart_Point.h Cart_Vector.h Game_Object.h Oxygen_Depot.h Space_Station.h
	$(GCC) -c Person.cpp -o Person.o

Astronaut.o:Astronaut.cpp Astronaut.h Cart_Point.h Oxygen_Depot.h Space_Station.h Person.h
	$(GCC) -c Astronaut.cpp -o Astronaut.o

Model.o:Model.cpp Model.h Cart_Point.h Game_Object.h Oxygen_Depot.h Space_Station.h Person.h Astronaut.h View.h Alien.h Input_Handling.h
	$(GCC) -c Model.cpp -o Model.o

Game_Command.o:Game_Command.cpp Game_Command.h Model.h Cart_Point.h Person.h Astronaut.h Oxygen_Depot.h Alien.h Input_Handling.h
	$(GCC) -c Game_Command.cpp -o Game_Command.o

View.o:View.cpp View.h Game_Object.h Cart_Point.h 
	$(GCC) -c View.cpp -o View.o

Alien.o:Alien.cpp Alien.h Game_Object.h Person.h Cart_Point.h Cart_Vector.h
	$(GCC) -c Alien.cpp -o Alien.o

Input_Handling.o:Input_Handling.cpp Input_Handling.h
	$(GCC) -c Input_Handling.cpp -o Input_Handling.o

main.o:main.cpp Cart_Point.o Cart_Vector.o Game_Object.o Oxygen_Depot.o Space_Station.o Person.o Astronaut.o Model.o Game_Command.o View.o Input_Handling.o Alien.o
	$(GCC) -c main.cpp -o main.o

clean:
	rm $(OBJS) PA4

