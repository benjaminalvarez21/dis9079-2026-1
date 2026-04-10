# friendshipisfriend-02

## integrantes

* Magdalena Balart
* Jesus Miranda
* Carla Nuñez

## descripción del proyecto

## materiales usados en solemne-01

## código usado con Adafruit IO

### código para enviar

```cpp
// rellenar
```

### código para recibir

```cpp
#include "config.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C   // este depende de la pantalla parece

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//feed
AdafruitIO_Feed *mensajeFeed = io.feed("mensaje");

// funcion que escribe texto en la pantalla
void mostrarMensaje(String texto) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Mensaje:");
  display.println();
  display.println(texto);
  display.display();
}

// callback: se ejecuta cuando llega un mensaje nuevo
void handleMessage(AdafruitIO_Data *data) {
  String texto = data->toString();

  Serial.print("recibido <- ");
  Serial.println(texto);

  mostrarMensaje(texto);
}

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Wire.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("No se pudo iniciar la OLED");
    while (true);
  }

  display.clearDisplay();
  display.display();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Conectando a");
  display.println("Adafruit IO...");
  display.display();

  // este para conectar a adafruit se enoja
  io.connect();

  // suscribirse al feed
  mensajeFeed->onMessage(handleMessage);

  while (io.status() < AIO_CONNECTED) {
    Serial.println(io.statusText());
    delay(1000);
  }

  Serial.println("Adafruit IO connected.");

  // pedir el valor actual del feed al conectarse
  mensajeFeed->get();
}

void loop() {
  io.run();
}
```

## investigaciones individuales

rellenar en el mismo orden que los integrantes del grupo

[persona-01.md](./persona-01.md) 
[persona-02.md](./persona-02.md)
[persona-03.md](./persona-03.md)

## bibliografía
