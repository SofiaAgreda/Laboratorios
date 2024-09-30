// Definir arrays para los pines de los LEDs de cada semáforo
int LED_Green[] = {2, 5, 8, 11};
int LED_Yellow[] = {3, 6, 9, 12};
int LED_Red[] = {4, 7, 10, 13};

void setup() {
  // Configurar los pines como salidas
  for (int i = 0; i < 4; i++) {
    pinMode(LED_Green[i], OUTPUT);
    pinMode(LED_Yellow[i], OUTPUT);
    pinMode(LED_Red[i], OUTPUT);
  }
}

void loop() {
  // Ciclo infinito 
  while (true) {
    fase(0, 1, 2, 3);  // Fase 1: Semáforo 1 verde, 2 y 3 rojos
    fase(1, 0, 2, 3);  // Fase 2: Semáforo 2 verde, 1 y 3 rojos
    fase(2, 0, 1, 3);  // Fase 3: Semáforo 3 verde, 1 y 2 rojos
    fase(3, 0, 1, 2);  // Fase 4: Semáforo 4 verde, 1 y 3 rojos
  }
}

void fase(int verde, int rojo1, int rojo2, int rojo3) {
  // Encender los LEDs rojos de otros semáforos
  digitalWrite(LED_Red[rojo1], HIGH);
  digitalWrite(LED_Red[rojo2], HIGH);
  digitalWrite(LED_Red[rojo3], HIGH);

  // Encender LED verde del semáforo actual
  digitalWrite(LED_Green[verde], HIGH);
  delay(5000);  

  // Apagar LED verde y un LED rojo
  digitalWrite(LED_Green[verde], LOW);
  int nextRed1 = (verde + 1) % 4; 
  
  digitalWrite(LED_Red[nextRed1], LOW);
  

  // Cambiar a amarillo para el semáforo actual
  digitalWrite(LED_Yellow[verde], HIGH);

  // Encender los LEDs amarillos de los semáforos correspondientes
  int nextYellow1 = (verde + 1) % 4; // El siguiente semáforo en amarillo
  
  digitalWrite(LED_Yellow[nextYellow1], HIGH);
  
  delay(2000);  
  
  // Apagar todos los LEDs amarillos
  digitalWrite(LED_Yellow[verde], LOW);
  digitalWrite(LED_Yellow[nextYellow1], LOW);


  // Apagar los LEDs rojos restantes
  digitalWrite(LED_Red[rojo2], LOW);
  digitalWrite(LED_Red[rojo3], LOW);
  }
  