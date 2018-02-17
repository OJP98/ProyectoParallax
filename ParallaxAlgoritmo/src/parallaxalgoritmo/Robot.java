/*
 * Robot.java
 * Funciones del robot.
 * Andrea Arguello 17801
 * Oscar Juarez 17315
 * Mario Sarmientos 17055
 * 16/02/2018
 */
package parallaxalgoritmo;

/**
 *
 * @author cooli
 */
public class Robot {
    
    //Atributos
    private int direccion; //grados a los que girará el robor
    private int xposition; //posicion en x
    private int yposition; //posicion en y
    private int giros;
    
    /**
     * Constructor
     */
    public Robot(){
        direccion=180; //se mueve hacia el frente
        xposition=0;
        yposition=9;
    }
    
    /**
     * Gira a la derecha
     */
    public void turnRight(){
        int counter=0;
        while(counter<3){
            turnLeft();
            counter++;
        }
    }
    
    /**
     * Gira a la izquierda
     */
    public void turnLeft(){
        if(direccion<=180){
        direccion+=90;}
        else if(direccion==270){
            direccion=0;
        }
    }
    
    /**
     * Sigue la pared
     * @param rightClear si tiene pared o no a la derecha
     * @param frontClear si tiene pared o no al frente
     */
     public void followWall(boolean rightClear, boolean frontClear){
        if(giros==7){
            if(frontIsClear(frontClear)){
                move();
            }
            else{
                    turnLeft();
                    }
        }
        else if(rightIsClear(rightClear)){
            turnRight();
            move();
            giros+=1;
        }
        else if(frontIsClear(frontClear)){
         move();   
        }
        else{
            turnLeft();
            giros=0;
        }
    }    
    
     /**
      * Chequea si tiene pared o no a la derecha
      * @param input tiene pared o no
      * @return true or false
      */
    public boolean rightIsClear(boolean input){
        boolean clear=input;
        return clear;
    }
    
    /**
      * Chequea si tiene pared o no al frente
      * @param input tiene pared o no
      * @return true or false
      */
    public boolean frontIsClear(boolean input){
        boolean clear=input;
        return clear;
    }
    
    /**
     * Hace que cambie su posicion basandose en coordenadas dependiendo de la direccion
     */
    public void move(){
        if(direccion==90){
            xposition+=1;
        }
        if(direccion==180){
            xposition-=1;
        }
        if(direccion==270){
            yposition-=1;
        }
        if(direccion==0 || direccion==360){
            yposition+=1;
        }
    }
    
    public String getCoordenadas(){
        return String.valueOf(xposition) + "," + String.valueOf(yposition);
    }
}

