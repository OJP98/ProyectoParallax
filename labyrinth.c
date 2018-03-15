#include "simpletools.h"                    
#include "abdrive.h" 
#include "ping.h"                        


int infrared,frontsensor, Loop, turn;


int main()                   
{
                     
  low(27);
  Loop=0;
  turn=60;


  while (1){
   frontsensor = ping_cm(10);                        
    freqout(1, 1, 28000);                     
    infrared = input(1);    


    if ((infrared==1)){
      drive_speed(turn, turn);
      pause(40);
      drive_speed(90, 30);
      pause(860);
      Loop++; } 

    else if ((infrared==0) && (DistanciaUS > 4) && (DistanciaUS < 8) ){
      drive_speed(1, 1);
      pause(100);
      drive_speed(-turn, turn); 
      pause(320);
      Loop=0; }

}
    else if ((infrared==0)){
      drive_speed(turn, turn);
      pause(20);
      Loop=0; }  

   //near wall
    if ((DistanciaUS <5) ){
      drive_speed(-10, -10);  // backwards
      pause(1000);
      drive_speed(1, 1);
      pause(100);
      drive_speed(-turn, turn);  // left
      pause(150);
      drive_speed(60, 60);   
      pause(500);
      Loop=0; }

  //turn counter
    if (Loop>=4){
      drive_speed(78, 22);
      pause(100);
      while((infrared==1) && (DistanciaUS>5)){
        drive_speed(60, 60);
       frontsensor = ping_cm(10);
        freqout(1, 1, 25000);
        infrared = input(1); }     
      Loop=0;   
    }
  }  
}