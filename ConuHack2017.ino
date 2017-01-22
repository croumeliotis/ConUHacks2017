//ConUHacks 2017 Submission
//breadBox - Arduino Videogame Console
/*
 */
//Created by John-Nicholas Cheng-Tarantino, William Bergamin, Zachary Bys, Constantina Roumeliotis

#include <math.h>
#include <arduino.h>
#include <stdlib.h>

//Declaration of variables
int delayTime = 190;
int negativeSize = 10;
int positiveSize = 16;
int arrayNegative[] = {40,41,42,43,44,45,46,47,48,49};
int arrayPositive[] = {36,37,22,23,24,25,26,27,28,29,30,31,32,33,34,35};
int Y=15;
int X=0;
int eX=4;
int eY=9;


                                                                                                    //WHITE=52
                                                                                                    //YELLOW=51
                                                                                                    //GREEN=50
                                                                                                    //BLUE=53

//Opening animation
void openingSequence(){
  for(int i=0;i<15;i+=3){
    digitalWrite(arrayPositive[i],HIGH);
    digitalWrite(arrayPositive[i+1],HIGH);
    digitalWrite(arrayPositive[i+2],HIGH);
    for(int j=0;j<10;j++){
      digitalWrite(arrayNegative[j],LOW);
      delay(60);
      digitalWrite(arrayNegative[j],HIGH);
    }
    digitalWrite(arrayPositive[i],LOW);
    digitalWrite(arrayPositive[i+1],LOW);
    digitalWrite(arrayPositive[i+2],LOW); 
  } 
}

//Unused code
void printScoreSerial(int score){
  Serial.print("\t!Game Over!\n\n");
  Serial.print("Your final score was: ");
  Serial.print(score);
  return;
}

//Bool to change the position of the character
bool moveCharacter(int &characterY, int &characterX){
    
    if (digitalRead(51) == HIGH){
         if(characterX != 0){
            characterX--;
         }
         return true;
    }if (digitalRead(52) == HIGH){
         if(characterX != 9){
          characterX++;
         }
         return true;
    }if (digitalRead(53) == HIGH){
         if(characterY != 15){
          characterY++;
         }
         return true;
    }if (digitalRead(50) == HIGH){
         if(characterY != 0){
          characterY--;
         }
         return true;
    }
    return false;
}

//Displays the position of the character on the board
int printOut(int board[16][10], int arrayPositive[], int arrayNegative[]){
  for(int i=0;i<16;i++){
    for(int j=0;j<10;j++){
      if(board[i][j] = 1){
         digitalWrite(arrayPositive[i],HIGH);
         digitalWrite(arrayNegative[j],LOW);
        
         return 0;
      }
    }
  }
}

//Function that loops through pins to output
void startPins(int pins[], int pinsize){
  for(int i = 0; i < pinsize; i++){
    pinMode(pins[i], OUTPUT);
  }
}

//Function that loops through two seperate arrays and makes them high/low
void settingHighLow(int arrayNegative[],int negativeSize, int arrayPositive[], int positiveSize){
  for(int i = 0; i < negativeSize; i++){
    digitalWrite(arrayNegative[i], HIGH);
  }

  for(int j = 0;j < positiveSize; j++){
    digitalWrite(arrayPositive[j], LOW);
  }
}

//Sets up the positions of all LEDs
void setup() {
int board[16][10];
for(int i=0;i<16;i++){
  for(int j=0;j<10;j++){
    board[i][j] = 0;
  }
}

startPins(arrayNegative, negativeSize);
startPins(arrayPositive, positiveSize);
settingHighLow(arrayNegative,negativeSize,arrayPositive,positiveSize);

/*for(int i=0;i<16;i++){                                  
  digitalWrite(arrayPositive[i],HIGH);
  for(int j=0;j<10;j++){                                  //TEST RUN STARTING FROM TOP LEFT CORNER
    digitalWrite(arrayNegative[j],LOW);
    delay(200);
    digitalWrite(arrayNegative[j],HIGH);
  }
  digitalWrite(arrayPositive[i],LOW);
}*/
                                                                                                    //WHITE=52
                                                                                                    //YELLOW=51
Serial.begin(9600);                                                                                              //GREEN=50
                                                                                                    //BLUE=53
pinMode(51,INPUT);
pinMode(50,INPUT);
pinMode(52,INPUT);
pinMode(53,INPUT);
long counter=0;
int enemyMove;
int catchCount=0;
randomSeed(analogRead(0));
openingSequence();
delay(1000);
while(1){
 
 
 digitalWrite(arrayPositive[Y],HIGH);
 digitalWrite(arrayNegative[X],LOW);
 delayMicroseconds(delayTime);
 digitalWrite(arrayPositive[Y],LOW);
 digitalWrite(arrayNegative[X],HIGH);
 delayMicroseconds(delayTime);
 digitalWrite(arrayPositive[eY],HIGH);
 digitalWrite(arrayNegative[eX],LOW);
 delayMicroseconds(delayTime);
 digitalWrite(arrayPositive[eY],LOW);
 digitalWrite(arrayNegative[eX],HIGH);
 delayMicroseconds(delayTime);

//Use random function to move oponent on the board
if (counter%130 == 0){moveCharacter(Y,X);
}
randomSeed(analogRead(0));    
if (counter%150 == 0){  
    enemyMove = random(5);
     if (enemyMove==0){
      if (eY != 15){
        eY++;
      }
    } else if (enemyMove==1){
      if (eY != 0){
        eY--;
      }
    } else if (enemyMove==2){
      if (eX != 9){
        eX++;
      }
    } else if (enemyMove==3){
      if (eX != 0){
        eX--;
      }
    }  
} 
if(counter%200==0){
  if(eY == Y && eX == X){
  catchCount++;
   Y=15;
   X=0;
   eX=4;
   eY=9;
   delay(1000);
}
}
if(catchCount==3){
  break;
}
    counter++;  
    }
}


//After winning, the code will run a closing sequence for the game
void loop() {
 openingSequence();
}


