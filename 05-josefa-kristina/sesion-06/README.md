# sesion-06

# Capacitive sensing (sensar con capacitancia) 

Capacitancia como manera de medir distancia.

UNO R4 Capacitive touch
Biblioteca necesaria: Capacitive_touch 

Arduino UNO R4 wifi pinout:

![pinout](./imagenes/uno-r4-pinout.png)

Library Functions:

`CapacitiveTouch(uint8_t pin)` Construye un sensor capacitivo de tacto por el pin elegido.

`bool begin()` Inicializa el sensor y configura ek pin y el hardware.

`int read()` Lee el valor crudo del sensor y lo devuelve.

`bool isTouched()`  Chequea si el sensor está siendo tocado basado en los umbrales.

`void setThreshold(int threshold)` Determina los umbrales de detección para la sensibilidad del tacto.

`int getThreshold()` Recupera el umbral de detección actual. 

Aarón nos enseña que significa cada línea del ejemplo de capacitive touch en Arduino IDE.

Antes de correr el código conectar una sola pieza de cualquier material conductor al pin D0 de la placa.

```
//incluir la biblioteca de capacitive touch
#include "Arduino_CapacitiveTouch.h"

//touch button nombre fantasía que refiere a la patita D0
CapacitiveTouch touchButton = CapacitiveTouch(D0);
//
void setup() {
//prende el puerto serial en una velocidad especifica
  Serial.begin(9600);
  //si pasa algo dice "" y sino dice ""
  if(touchButton.begin()){
    Serial.println("Capacitive touch sensor initialized.");
  } else {
    Serial.println("Failed to initialize capacitive touch sensor. Please use a supported pin.");
    //quedarse pegado frente el fracaso
    while(true);
  }
// define el umbral o threshold en 2000

  touchButton.setThreshold(2000);
}
//loop ocurre en bucle despues del setup
void loop() {
  //asignar a valor lectura
  //el resultado de oreguntarle a touch button
  //read() me da el valor crudo
  // Read the raw value from the capacitive touch sensor.

  int sensorValue = touchButton.read();
  Serial.print("Raw value: ");
 //imprime valor lectura
  Serial.println(sensorValue);

  // Check if the sensor is touched (raw value exceeds the threshold).
  //se pregunta si el botón está siendo tocado
  if (touchButton.isTouched()) {
    //si lo está, imprime
    Serial.println("Button touched!");
  }
  //detente por 0,1 segundos.
  delay(100);
}


```





lunes 13 abril 2026

