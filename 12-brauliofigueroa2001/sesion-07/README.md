# sesion-07

lunes 20 abril 2026

## primera parte

ocuparemos servo, proto, LDR y potenciómetro para hacer cosas con arduino

el servor tiene 3 cables, uno es para alimentación, otro es tierra y el otro es el pin para decirle "servo haz esto"

veremos materia directamente desde el libro que está haciendo aarón con misaa sobre electrónica, veremos el capítulo 13 de: componentes básicos

este libro lo podemos encontrar en dis udp en github, debería aparecer

en la protoboard el lado izquierdo es independiente del derecho, lo atraviesa la zanja lol, entonces lo divide

arduino a veces ocupa 5v o 3.3v, hay microcontroladores que utilizan 3,3v porque a veces si más voltaje hay, funcionan peor

lo que yo conecte en 1a se propaga hacia 1b, 1c, 1d, 1e. 1f está al otro lado del río por lo tanto no se propaga hasta allá

- primero conectaremos un potenciómetro al arduino

las patitas son programables

ajustar el potenciómetro para establecer 0 como mínimo y 1023 como máximo

código para lectura

```cpp
// ejemplo lectura potenciometro

// queremos que nuestro Arduino
// sea capaz de leer un potenciometro
// conectado a la entrada A0.

int lectura = 0;


void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  lectura = analogRead(A0);
  Serial.println(lectura);
}
```

- este primer código nos permite ver números de 0 a 1023 en el monitor serial mediante la manipulación del potenciómetro

- ahora añadiremos el servo?

- primero haremos que el potenciómetro controle el servo de modo alámbrico y después lo haremos inalámbrico

- si la patita no tiene sinusoide, no puede mover el servo, es este símbolo en el hardware de arduino ( ~ ) en este caso la patita de señal del servo es patita que debe ir conectado a los pines que tengan ese símbolo, lo conectaremos al pin 9 del arduino ~

**código 2**

```cpp
// ejemplo lectura potenciometro

// queremos que nuestro Arduino
// sea capaz de leer un potenciometro
// conectado a la entrada A0.


#include <Servo.h>


Servo miServo;

int lectura = 0;
int angulo = 0;


void setup()
{
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  // en que patita esta conectado el servo
  // conectemos a patita 9 digital
  miServo.attach(9);
  
}

void loop()
{
  // leer
  lectura = analogRead(A0);
  
  // imprimir en consola
  Serial.println(lectura);
  
  
  // toma el valor de lectura
  // que va originalmente entre 0 y 1023
  // y mapealo al rango 0 a 180
  angulo = map(lectura, 0, 1023, 0, 180);
    
  // pidele por favor al servo
  // que vaya a ese angulo
  miServo.write(angulo);
  
  // servo descansa un poquito
  // 15 milisegundos
  // la vida es dura
  delay(15);
    
}
```

- subir video/gif de el potenciómetro girando al motor


