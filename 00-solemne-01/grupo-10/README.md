# grupo-10 
## Comunicaciones inalambricas

## integrantes

* Agustina Aceituno
* Ignacio Campos
* Antonia Fuentealba

## descripción del proyecto

El proyecto consiste en establecer una comunicación inalámbrica entre un Arduino y la plataforma en la nube Adafruit IO utilizando conexión WiFi.

El Arduino se conecta a una red WiFi y luego a Adafruit IO mediante credenciales (usuario y key). A través de esta conexión, el dispositivo puede enviar datos (por ejemplo, valores de sensores o contadores) a un feed en la nube, y también recibir información desde ese mismo feed para controlar acciones (como encender un LED).

Este sistema se basa en el paradigma de Internet de las Cosas (IoT), donde dispositivos físicos se conectan a internet para intercambiar datos en tiempo real.

![proceso](./imagenes/1solemne_final.png)
![proceso](./imagenes/adafruit1.png)
![proceso](./imagenes/adafruit2.png)

## Proceso

![proceso](./imagenes/1solemne_pruebas.png)
![proceso](./imagenes/solemne1.jpg)
![proceso](./imagenes/solemne2.jpg)
![proceso](./imagenes/solemne3.jpg)

## materiales usados en solemne-01

| Cantidad | Componente / Recurso | Función |
|----------|----------------------------|---------|
| 1 | Arduino UNO R4 WiFi | Placa principal utilizada para ejecutar el programa y conectarse a WiFi |
| 1 | Cable USB-C | Permite cargar el código desde el computador y alimentar la placa |
| 1 | Computador | Dispositivo para programar y subir el código al Arduino |
| 1 | Arduino IDE | Entorno de desarrollo utilizado para escribir y cargar el código |
| 1 | Librería Adafruit IO | Permite la comunicación entre el Arduino y la plataforma en la nube |
| 1 | Cuenta en Adafruit IO | Plataforma donde se envían, reciben y visualizan los datos |
| 1 | Red WiFi / Hotspot móvil | Proporciona conexión a internet para el funcionamiento del sistema |

## código usado con Adafruit IO

### código para enviar

```cpp
// // Adafruit IO Publish Example
//
// Adafruit invests time and resources providing this open source code.
// Please support Adafruit and open source hardware by purchasing
// products from Adafruit!
//
// Written by Todd Treece for Adafruit Industries
// Copyright (c) 2016 Adafruit Industries
// Licensed under the MIT license.
//
// All text above must be included in any redistribution.

// ejemplo para enviar / publish
// por montoyamoraga
// para disenoUDP
// basado en
// Adafruit IO Publish Example

// incluir archivo config.h
// hacer las modificaciones de este archivo
// NO subir a github
#include "config.h"

// esta variable entera
// sera un contador que aumenta
// durante el funcionamiento del software
int contador = 0;

// definir una variable que se llame nombreFeed
// que tenga un cierto valor
// mantener las doble comillas, cambiar grupoXX segun tu nombre de grupo
AdafruitIO_Feed *nombreFeed = io.feed("grupo10");

void setup()
{

  // prender la conexion serial
  // ojo con la velocidad de 115200 baud
  // cuando abras el monitor serial debes configurarlo
  // a este numero, porque el standard de fabrica es 9600 baud
  Serial.begin(115200);

  // estas lineas pausan el codigo
  // hasta que prendas el monitor serial
  // la lupita arriba a la derecha en Arduino IDE
  while (!Serial)
    ;

  // imprimir en consola
  Serial.print("conectando a Adafruit IO");

  // conectarse a io.adafruit.com
  io.connect();

  // esperar la conexion
  while (io.status() < AIO_CONNECTED)
  {
    // imprimir un punto cada medio segundo
    // mientras se conecta
    Serial.print(".");
    delay(500);
  }

  // demostrar que logramos conexion
  Serial.println();
  Serial.println(io.statusText());
}

void loop()
{

  // esta linea es necesaria
  // al principio de loop()
  // para mantener la conexion
  // y procesar datos que lleguen
  io.run();

  // enviar el contador a Adafruit IO
  // primero mostrar en monitor serial
  Serial.println("enviando -> " + String(contador));
  // despues enviar a la nube
  nombreFeed->save(contador);

  // incrementar el contador en 1
  contador = contador + 1;

  // Adafruit IO tiene una velocidad limitada
  // de escritura / publishing
  // usamos delay para pausar el codigo 3 segundos
  delay(3000);
}
```

#### Config.h

```cpp
// // reemplazar por las credenciales de aaron
// o por las de tu cuenta
#define IO_USERNAME  "udpmontoyamoraga"
#define IO_KEY       "xxxxxxxxxxxxxxxxxxxxxx"


// reemplazar por nombre y clave de la wifi
#define WIFI_SSID "pixel9"
#define WIFI_PASS "mateo123"

// comment out the following lines if you are using fona or ethernet
#include "AdafruitIO_WiFi.h"

#if defined(USE_AIRLIFT) || defined(ADAFRUIT_METRO_M4_AIRLIFT_LITE) ||         \
    defined(ADAFRUIT_PYPORTAL)
// Configure the pins used for the ESP32 connection
#if !defined(SPIWIFI_SS) // if the wifi definition isnt in the board variant
// Don't change the names of these #define's! they match the variant ones
#define SPIWIFI SPI
#define SPIWIFI_SS 10 // Chip select pin
#define NINA_ACK 9    // a.k.a BUSY or READY pin
#define NINA_RESETN 6 // Reset pin
#define NINA_GPIO0 -1 // Not connected
#endif
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS, SPIWIFI_SS,
                   NINA_ACK, NINA_RESETN, NINA_GPIO0, &SPIWIFI);
#else
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
#endif
```
![proceso](./imagenes/config.png)


## investigaciones individuales

[agustinaaceituno](./persona-01.md)

[persona-02.md](./persona-02.md)

[antfuentealba](./persona-03.md)

## bibliografía
