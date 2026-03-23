// incluir bibliotecas
#include <stdio.h>
#include "pico/stdlib.h"

// mensajes
const char *mensajes[] = {
    "hola ",
    "dis9079",
    "2026",
    "primer semestre",
    "lunes marzo 23"};

// numero de mensajes en la lista
int total = sizeof(mensajes) / sizeof(mensajes[0]);

// inicializar contador
int i = 0;

// funcion principal main()
// es tipo int, porque retorna un valor entero
int main()
{
    // inicializar la comunicacion serial
    stdio_init_all();

    // bucle infinito
    while (true)
    {
        // imprimir el mensaje actual
        printf("%s\n", mensajes[i]);

        // esperar 1 segundo
        sleep_ms(1000);

        // incrementar el contador
        i = i + 1;

        // reiniciar el contador cuando llega a 0
        i = i % total;
    }
}
