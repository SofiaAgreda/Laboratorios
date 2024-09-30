#define LED1_RED 2
#define LED1_BLUE 3
#define LED1_GREEN 4

#define LED2_RED 5
#define LED2_BLUE 6
#define LED2_GREEN 7

#define LED3_RED 8
#define LED3_BLUE 9
#define LED3_GREEN 10

//interruptor
#define SWITCH_PIN 13

void setup()
{
  //refactor
  digitalWrite(LED1_RED,OUTPUT);
  digitalWrite(LED1_BLUE,OUTPUT);
  digitalWrite(LED1_GREEN,OUTPUT);
  
  digitalWrite(LED2_RED,OUTPUT);
  digitalWrite(LED2_BLUE,OUTPUT);
  digitalWrite(LED2_GREEN,OUTPUT);
  
  digitalWrite(LED3_RED,OUTPUT);
  digitalWrite(LED3_BLUE,OUTPUT);
  digitalWrite(LED3_GREEN,OUTPUT);
  
  //interuptor
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  
}

void led1_Colors(int r, int g, int b)
{
  analogWrite(LED1_RED,r);
  analogWrite(LED1_BLUE,g);
  analogWrite(LED1_GREEN,b);
}
void led2_Colors(int r, int g, int b)
{
  analogWrite(LED2_RED,r);
  analogWrite(LED2_BLUE,g);
  analogWrite(LED2_GREEN,b);
}
void led3_Colors(int r, int g, int b)
{
  analogWrite(LED3_RED,r);
  analogWrite(LED3_BLUE,g);
  analogWrite(LED3_GREEN,b);
}
void loop(){
   if (digitalRead(SWITCH_PIN) == LOW) // Si el interruptor está encendido
  {
  
// Semáforo 1 en verde
  led1_Colors(0,0,255); // Verde
  led2_Colors(255, 0, 0); // Rojo
  led3_Colors(255, 0, 0); // Rojo
  delay(1000);
  
  // Semáforo 2 en verde
  led1_Colors(255, 0, 0); // Rojo
  led2_Colors(0,0,255); // Verde
  led3_Colors(255, 0, 0); // Rojo
  delay(1000);
  
  // Semáforo 3 en verde
  led1_Colors(255, 0, 0); // Rojo
  led2_Colors(255, 0, 0); // Rojo
  led3_Colors(0,0,255); // Verde
  delay(1000);
     
}else // Si el interruptor está apagado
  {
    led1_Colors(255,0,255); // Amarillo
      led2_Colors(255,0,255); // Amarillo
      led3_Colors(255,0,255); // Amarillo
      delay(500); // Encendido
      led1_Colors(0, 0, 0); // Apagar
      led2_Colors(0, 0, 0); // Apagar
      led3_Colors(0, 0, 0); // Apagar
      delay(500); // Apagado
     
     }
  }
