/*
  Detect and Turn from Obstacle.c

  Detect obstacles in the ActivityBot's path, and turn a random direction to avoid them.

*/

#include "simpletools.h"                      
#include "abdrive.h"                          
#include "ping.h"   
                          
typedef int bool;
#define true 1
#define false 0

int contador = 0;


int main()                                    // main function
{  
  
  bool b = true;
  
  while (b==true) {                       
  
      drive_speed(60, 60);  
      
      if (ping_cm(6) >= 15){
        
        drive_speed(0,0);
        drive_goto(15,15);   
        drive_goto(28,-28);               
        drive_goto(55,55);
                
      }        
    
      if (ping_cm(8) < 5) {   
                         
        pause(5);
        drive_speed(0,0);
      
        if (contador == 7){
        
          drive_goto(26, -27);
          contador = 0;                          
        
          if(ping_cm(8) < 5){
          
            drive_goto(-26, 27);
          
          }
        
        } else {
            
          drive_goto(-26, 27);
          contador += 1;    
      
        }  
      
        pause(5);  
      
      }  
      
    }                   
   
}
