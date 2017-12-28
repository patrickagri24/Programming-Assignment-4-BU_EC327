#ifndef INPUT_HANDLING_H
#define INPUT_HANDLING_H

using namespace std;

//default code in packet
class Invalid_Input
{
  public:
  
  Invalid_Input(char * in_ptr) : msg_ptr(in_ptr) {}
  
  const char * const msg_ptr;
  
  private:
  
  Invalid_Input();  //no default construction
  
};

#endif