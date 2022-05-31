#include <Servo.h>

#define MAX_SIGNAL 2000
#define MIN_SIGNAL 1000
#define MOTOR_PIN9 9
#define MOTOR_PIN8 8
#define MOTOR_PIN7 7
#define MOTOR_PIN6 6
#define SPEED_MIN 1050
#define SPEED_MAX 1300
#define SPEED_NORMAL 1100
#define SPEED_TEST 1200

int DELAY = 1000;

Servo motor9;
Servo motor8;
Servo motor7;
Servo motor6;

void setup() {
  Serial.begin(9600);
  delay(1500);
  Serial.println("Program begin...");
  delay(1000);
  Serial.println("This program will start the ESC.");

  motor9.attach(MOTOR_PIN9);
  motor8.attach(MOTOR_PIN8);
  motor7.attach(MOTOR_PIN7);
  motor6.attach(MOTOR_PIN6);


  Serial.print("Now writing maximum output: (");Serial.print(MAX_SIGNAL);Serial.print(" us in this case)");Serial.print("\n");
  Serial.println("Turn on power source, then wait 2 seconds and press Enter");
  motor9.writeMicroseconds(MAX_SIGNAL);
  motor8.writeMicroseconds(MAX_SIGNAL);
  motor7.writeMicroseconds(MAX_SIGNAL);
  motor6.writeMicroseconds(MAX_SIGNAL);


  // Wait for input
  while (!Serial.available());
  Serial.read();

  // Send min output
  Serial.println("\n");
  Serial.println("\n");
  Serial.print("Sending minimum output: (");Serial.print(MIN_SIGNAL);Serial.print(" us in this case)");Serial.print("\n");
  motor9.writeMicroseconds(MIN_SIGNAL);
  motor8.writeMicroseconds(MIN_SIGNAL);
  motor7.writeMicroseconds(MIN_SIGNAL);
  motor6.writeMicroseconds(MIN_SIGNAL);
  Serial.println("The ESC is calibrated");
  Serial.println("----");
  Serial.println("Now, type a values between 1000 and 2000 and press enter");
  Serial.println("and the motor will start rotating.");
  Serial.println("Send 1000 to stop the motor and 2000 for full throttle");

}

int direcao = 0;
void loop() {
   
  if (Serial.available() > 0)
  {
    direcao = Serial.parseInt();
    //int DELAY = Serial.parseInt();
    //if (DELAY > 999)
    //{
      
      Fdirecao();
      /*
      motor9.writeMicroseconds(DELAY);
      motor8.writeMicroseconds(DELAY);
      motor7.writeMicroseconds(DELAY);
      motor6.writeMicroseconds(DELAY);
      float SPEED = (DELAY-1000)/10;
      Serial.print("\n");
      Serial.println("Motor speed:"); Serial.print("  "); Serial.print(SPEED); Serial.print("%"); */
    //}     
  }
}

void Fdirecao(){
    if(direcao == 1){
      motor9.writeMicroseconds(SPEED_TEST);
      motor8.writeMicroseconds(SPEED_NORMAL);
      motor7.writeMicroseconds(SPEED_MIN);
      motor6.writeMicroseconds(SPEED_MAX);
      Serial.println("Frente");
      }
     if(direcao == 2){
      motor9.writeMicroseconds(SPEED_TEST);
      motor8.writeMicroseconds(SPEED_MAX);
      motor7.writeMicroseconds(SPEED_MIN);
      motor6.writeMicroseconds(SPEED_NORMAL);
      Serial.println("Direita");
      }
      if(direcao == 3){
      motor9.writeMicroseconds(SPEED_TEST);
      motor8.writeMicroseconds(SPEED_MAX);
      motor7.writeMicroseconds(SPEED_NORMAL);
      motor6.writeMicroseconds(SPEED_NORMAL);
      Serial.println("Trás");
      }
      if(direcao == 4){
      motor9.writeMicroseconds(SPEED_TEST);
      motor8.writeMicroseconds(SPEED_NORMAL);
      motor7.writeMicroseconds(SPEED_NORMAL);
      motor6.writeMicroseconds(SPEED_MAX);
      Serial.println("Esquerda");
      }
      if(direcao == 5){
      motor9.writeMicroseconds(SPEED_TEST);
      motor8.writeMicroseconds(SPEED_NORMAL);
      motor7.writeMicroseconds(SPEED_NORMAL);
      motor6.writeMicroseconds(SPEED_NORMAL);
      Serial.println("Estável");
      }
      if(direcao == 6){
      motor9.writeMicroseconds(SPEED_MAX);
      motor8.writeMicroseconds(SPEED_MIN);
      motor7.writeMicroseconds(SPEED_MAX);
      motor6.writeMicroseconds(SPEED_MIN);
      Serial.println("Cima");
      }
      if(direcao == 7){
      motor9.writeMicroseconds(SPEED_TEST);
      motor8.writeMicroseconds(SPEED_MAX);
      motor7.writeMicroseconds(SPEED_MIN);
      motor6.writeMicroseconds(SPEED_MAX);
      Serial.println("Baixo");
      }
}
