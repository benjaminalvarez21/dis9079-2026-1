# Luisa Toro
investigaciones individuales

## Sobre adafruit i/o
Investigación Profunda: Ecosistema Adafruit IO y Capa de Transporte

Mi investigación para la Solemne 01 se centró en entender por qué migramos de un broker local (Mosquitto) a uno basado en la nube como Adafruit IO.

Hallazgos Técnicos Clave:

* **Protocolo y Puertos:** A diferencia de Mosquitto local (que nos dio problemas de permisos en el puerto 1883), Adafruit IO permite conexiones vía MQTT sobre WebSockets (puerto 443). Esto es fundamental porque el tráfico se ve como tráfico web normal (HTTPS), saltándose los firewalls de Windows que nos bloquearon en la clase pasada.
* **Arquitectura de Datos (Feeds):** Entendí que Adafruit IO organiza todo por "Feeds". No es solo enviar un dato al aire; es una base de datos de series temporales. Esto significa que si mi Arduino se desconecta un segundo de la WiFi de la U, Adafruit guarda el último estado (Last Will and Testament), lo que hace que la comunicación sea mucho más robusta que un broker simple.
* **Seguridad y AIO Key:** Investigué que la AIO Key funciona como un token de autenticación dinámico. A diferencia de un usuario/pass normal, este token permite revocar el acceso sin cambiar la cuenta, lo cual es vital si llegamos a compartir código en GitHub (aunque el profe fue súper enfático en que no las subamos).

* **Proceso de Instalación:** Configuré el entorno instalando la suite completa de Adafruit IO Arduino (v4.3.4). Tuve que gestionar manualmente las dependencias de HttpClient y Adafruit_MQTT, asegurándome de que la placa Arduino WiFiS3 sea reconocida correctamente por el Library Manager para evitar errores de compilación por falta de headers.

# Registro
<img src="https://github.com/user-attachments/assets/5a4465ad-acee-497f-9a16-1e36107cf345" width="800" alt="Profundización Int Ina 06 04">
<img src="https://github.com/user-attachments/assets/8a412aa3-3d25-41ac-8fec-88104af41b5c" width="800" alt="Profundización Int Ina 06 04">
<img src="https://github.com/user-attachments/assets/144cc0da-1ca5-4d6b-b12d-6a9143d01472" width="800" alt="Profundización Int Ina 06 04">

Bonus :)
1. Integración con Webhooks y Dashboards: Investigué que Adafruit IO no solo recibe datos, sino que permite crear Dashboards visuales en tiempo real sin escribir código extra. Además, tiene integración con Webhooks, lo que permitiría enviar una alerta a mi celular o un correo si mi sensor detecta algo crítico, expandiendo la interacción fuera de la placa.
2. Limitaciones del Plan Free (Rate Limiting): Es importante notar que el plan gratuito tiene un límite de 30 datos por minuto y almacenamiento de datos por 30 días. Para nuestro proyecto esto es suficiente, pero entender estas limitaciones es vital para no "spamear" el broker y evitar que la cuenta sea bloqueada por exceso de tráfico.



📖Glosario Técnico de Interacción en la Nube

* **Dashboards (Tableros de control):** Es la interfaz gráfica de Adafruit IO. Permite crear botones, interruptores, medidores (gauges) y gráficos de línea para visualizar los datos del Arduino en tiempo real desde cualquier navegador, sin tener que programar una página web desde cero. Es "Low-Code" puro.
* **Webhooks:** Es una forma de "avisar" a otras aplicaciones que algo pasó en mi Arduino. Por ejemplo, si un sensor de temperatura sube mucho, Adafruit IO puede disparar un Webhook que le mande un mensaje a mi Telegram o active una ampolleta inteligente en otra parte de la casa.
* **Rate Limiting (Limitación de tasa):** Es la regla de tránsito de los brokers. El plan gratuito de Adafruit permite 30 "puntos" por minuto. Si mi código envía datos cada 1 segundo, voy a bloquear la cuenta. Esto me obliga a programar con delay() o millis() de forma inteligente para no saturar la red.
* **Last Will and Testament (LWT)**: Es una función de MQTT donde el Arduino le dice al broker: "Si me desconecto de la WiFi de la U de la nada, por favor avísale a todos que estoy offline". Esto asegura que el sistema siempre sepa el estado real de la conexión.


📖Conceptos de Control y Conexión

* **delay():** Es una función que "congela" el Arduino por un tiempo determinado (en milisegundos). El problema es que mientras está en delay, el Arduino no puede hacer nada más: ni leer sensores, ni recibir mensajes de Adafruit. Es como si se quedara dormido.
* **millis():** Es un cronómetro interno que empieza a contar desde que prendes el Arduino. A diferencia del delay, usar millis permite que el código siga corriendo y solo haga una acción cuando pase cierto tiempo. Es fundamental para que el Arduino no pierda la conexión con la nube mientras espera para enviar el siguiente dato.
* **Offline (Fuera de línea):** Significa que el dispositivo perdió su conexión a internet o al broker MQTT. En nuestro proyecto, esto suele pasar por micro-cortes en la WiFi de la U o si la placa se queda sin energía. Es clave programar una reconexión automática para no perder datos.
  Es mejor usar millis() porque así el Arduino puede estar atento a lo que le mandas desde el Dashboard de Adafruit mientras espera para enviar sus propios datos.


## 🎨 Referente Artístico: Rafael Lozano-Hemmer

Para la Solemne 01 elegí a Rafael Lozano-Hemmer (mexicano-canadiense), un artista que es pionero en el uso de la computación distribuida y la electrónica para crear intervenciones urbanas masivas.

Obra Analizada: Pulse Topology (2021) Esta instalación consta de 3,000 bombillas suspendidas que parpadean al ritmo del corazón de los visitantes. No es una luz estática; es un sistema vivo que reacciona en tiempo real.

<img src="https://github.com/user-attachments/assets/a8eb22a0-2935-4988-a1a1-4b3c33b3af83" width="800" alt="Profundización Int Ina 06 04">
<img src="https://github.com/user-attachments/assets/09070939-b8b0-4e22-b1ec-9fe7a4322a28" width="800" alt="Profundización Int Ina 06 04">

¿Por qué es clave para Interacciones Inalámbricas?

* **Redes de Sensores (WSN):** Lozano-Hemmer utiliza sensores de pulso inalámbricos. Lo que me fascina es la latencia (el retraso del dato). En esta obra, el dato del corazón debe viajar por el aire, procesarse y encender una luz casi instantáneamente. Si el protocolo inalámbrico falla o tiene mucho "lag", la conexión emocional del espectador con la obra se rompe.
* **Datos en la Nube y Escalabilidad:** Al igual que nosotros usamos Adafruit IO para gestionar datos, él usa sistemas que manejan miles de eventos por segundo. Esto me hace reflexionar sobre el Rate Limiting: ¿Cómo escalas una interacción para 3,000 luces sin colapsar la red?
* **Hardware Invisible:** La tecnología inalámbrica permite que el hardware "desaparezca". El espectador no ve cables, solo ve la reacción. Mi meta en este ramo es lograr esa misma fluidez: que el protocolo (MQTT/Adafruit) sea el puente invisible que permita que mi diseño se sienta orgánico y no "mecánico".

Y para finalizar :)
# Análisis de Capas de Interacción:

1. Biometría Inalámbrica: Lo que hace única a esta obra es que transforma un dato biológico (el pulso) en un paquete de datos digital. En nuestro curso, esto es equivalente a lo que haremos al conectar un sensor al Arduino: convertir una señal analógica en un mensaje MQTT que viaja por el aire. Lozano-Hemmer usa la biometría para que la interfaz sea el propio cuerpo, eliminando teclados o botones.
2. El Concepto de "Antimonumento": El artista define sus obras como antimonumentos porque no son estáticos. Dependen 100% de la conectividad. Si el sistema inalámbrico se cae, la obra desaparece. Esto refuerza lo que aprendimos con los "chascarros" del profe: en la computación física, la estabilidad de la red es tan importante como el diseño del objeto mismo.
