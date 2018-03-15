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

//Contador de los giros a la derecha consecutivos
int contador = 0;

int main()
{  
  
  //Se declara una variable booleana.
  bool b = true;
  
  while (b==true) {                       
  
    drive_speed(60, 60);  //El robot maneja a esta velocidad constante.    
    
      //Si el robot ya hizo 7 giros consecutivos a la derecha, significa que esta en una isla.
      //por lo tanto...
      if (contador==7) {
        
        //El parallax avanza hacia adelante, sin importar si hay pared a la derecha o no.
        while (ping_cm(8)>=5) {
                        
            drive_speed(60, 60);           
            
        }
        
        //Si hay una pared enfrente...
        if (ping_cm(8) < 5) {
          
            //El parallax se detiene y gira a la izquierda.
            drive_speed(0,0);
            drive_goto(-28,28);
          
        }
                 
          //Se le hace un reset al contador.                     
          contador = 0;
             
      }        
      
      //Si de repente el sensor de la derecha deja de detectar una pared...
      if (ping_cm(6) >= 15){
        
        //Se detiene, gira a la derecha y luego se mueve hacia adelante
        //para evitar que se estrelle contra la pared.
        drive_speed(0,0);
        drive_goto(15,15);   
        drive_goto(28,-28);               
        drive_goto(55,55);
        
        //Se agrega uno al contador para verificar si se encuentra en
        //una isla o lugar sin salida.
        contador +=1;
                
      }        
    
      //Si hay un obstaculo frente al parallax...
      if (ping_cm(8) < 5) {   
                         
        //Se detiene y gira a la izquierda.                                                 
        pause(5);
        drive_speed(0,0);   
        drive_goto(-28,28);                                                       
        pause(5); 
        
        //Pone el contador en 0 debido a que no se encuentra en una isla.
        contador = 0; 
        
        }                             
    }                      
}
