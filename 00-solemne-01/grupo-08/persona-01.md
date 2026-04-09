# persona-01

investigaciones individuales

## sobre adafruit i/o

- instalación adafruit io 4 de abril (sacado de mi bitácora clase 4)

![instalacion](./imagenes/instalacionIndividual1.JPG)

- primero descargamos la biblioteca de adafruit io en arduino

![instalacion](./imagenes/instalacionIndividual2.JPG)

- nos aparece que incluye todas estas opciones, debemos aceptar

![instalacion](./imagenes/instalacionIndividual3.JPG)

- así termina la instalación, luego creamos nuestra cuenta en Adafruit

![cuenta](./imagenes/creandoCuentabraulio.JPG)

- creamos cuenta con nuestro correo, debiera aparecer un ícono amarillo arriba a la derecha, con mis credenciales, no me aparece nada

- descargar los archivos .ino y .h que dejo aarón en mi respectivo grupo 08 en github

- lo hice mal al principio, me dio este error

![error](./imagenes/error1config.JPG)

- después me acordé que el archivo .h debía estar al lado del .ino en pestañas, es decir, tenían que estar en la misma carpeta lol. Esto lo aprendí el año pasado pero se me había olvidado, si no estaban de esta forma el arduino no iba a encontrar el .h por más que lo tuviera descargado

![solucionerror](./imagenes/solucionErrorbraulio1.jpg)

- los puse en una misma carpeta, cerré arduino y lo abrí, ahora si me incluyó el .h

- antes de esto había abierto el .h en vscode y se veía así

![vscode](./imagenes/configBraulio.JPG)

- después caché que se abría en arduino e hice lo que mencioné anteriormente, reemplacé los enunciados IO USERNAME y IO KEY por VALORES SECRETOS

- probé el código y compiló, no me apareció el error de conectando a Adafruit IOFirmware version 0.3.0 is outdated. Latest version is 0.5.2 21:24:06.104 -> Please upgrade the WiFiS3 firmware, CORREGIR QUE SÍ ME APARECIÓ ESTE ERROR PERO LO SOLUCIONAMOS CON AARÓN LA MAÑANA DEL 6 DE ABRIL


**investigación individual 6 de abril 11 am**

- Adafruit IO es un servicio en la nube, lo que significa que ellos lo gestionan por ti. puede ser utilizado estando conectado a Internet y usado principalmente para guardar y recuperar datos, pero también permite otras cosas

- Mostrar datos en tiempo real en línea
- Compartir datos con otras personas
- Conectar proyectos electrónicos a Internet
- Controlar motores o leer sensores
- Integrarse con servicios como Slack, Discord, RSS o clima
- Conectar dispositivos entre sí
- Crear proyectos sin código (no-code)

- Adafruit IO nos permite hacer proyectos con uso de código o sin uso de código, en este último caso, se utiliza un FirmWare llamado "WipperSnapper"

¿cómo utilizar WipperSnapper? (no código)

- se debe cargar el firmware WipperSnapper en la placa, agregar las credenciales y conectarla la alimentación. La placa se registrará automáticamente en la cuenta de Adafruit IO.

código con adafruit IO

- adafruit IO también se puede utilizar con código, tienen librerías de CircuitPython, Arduino, Python y más, en nuestro caso utilizaremos las librerías para arduino, específicamente Adafruit IO Arduino

- información sacada de la página de adafruit io y traducida con IA

 **proceso con Aarón 6 de abril a las 12 pm en LID**

- en la mañana aarón me dijo que revisara bien las credenciales porque vió mi clave y efectivamente no eran las credenciales exactas, la password era la que me da la página, no la que yo le asigno a mi cuenta

- por obvios motivos no colocaré mis credenciales lol

- al colocar correctamente las credenciales y el nombre y la clave del wifi también tuve que actualizar el firmware, ya que, al colocar las credenciales bien, el código funcionó entonces ahora daba el error de actualizar firmware, que era lo que precisamente tenía que suceder, actualizamos la placa y salió "mal" al principio

- la actualización decía que el proceso había fallado, aarón dijo que lo habíamos logrado de igual modo, presionamos el botón de reiniciar el arduino, seguían saliendo puntos, borramos los mensajes del monitor serial y apareció un nuevo mensaje

![falloylogro](./imagenes/falloylogroBraulio.JPG)

- nos estábamos conectando a Adafruit IO, poco a poco comenzaron a aparecer estos mensajes

![enviandoada](./imagenes/enviandoAdafruitbraulio.JPG)

 *SENTIMOS LOS ESCALOFRÍOS*

 - luego aarón me dijo que abriera la página de adafruit io, nos fuimos a la parte de io, luego feeds y se había creado solo un feed llamado "grupo08", esto es porque en una parte del código asignamos ese nombre al grupo, por lo que, adafruit io lo detecta y lo crea solo

![adafruit](./imagenes/servidorAdafruitbraulio2.JPG)

- esto muestra un gráfico con datos en tiempo real que están siendo enviados desde nuestro arduino hacia adafruit IO

![adafruit2](./imagenes/servidorAdafruitbraulio.JPG)

- aquí vemos en detalle los datos que nos está enviando arduino, estos pueden aparecer por un largo periodo de tiempo, en este caso lo dejé toda la hora de almuerzo enviando datos y cuando volví, el proceso había llegado aprox hasta el dato 2600. Después de eso se detuvo, las cosas se crashean
   












## sobre artista, diseñadora o producto que usa electrónica o computación inalámbricas
