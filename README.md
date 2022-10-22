![Alt text](https://github.com/Dan2710/S.I.A-Sistema-Inteligente-de-Alumbrado/blob/main/Logo/Logo.png?raw=true?raw=true)
# Sistema Inteligente de Alumbrado
### [Maqueta virtual en Minecraft](#Virtual)
### [Maqueta física con Arduino](#Fisica)
<br>
<br>

## 1.	PROBLEMÁTICA

Según La Vanguardia, en 2016 Madrid pagó cerca de 82 millones de euros para alumbrar sus 243.055 lámparas. Esta cifra ha podido llegar a doblarse hoy en día con la gran subida de precio de la electricidad que lleva produciéndose desde hace años. 
Si hablamos de España, el consumo de energía en alumbrado público total supera los 5.000 GW/año. Esto abre una ventana de oportunidad para el ahorro en este ámbito tan importante para el servicio público en España.
Sumado a la gran cantidad de energía y su coste asociado, la contaminación lumínica es un problema de actualidad en España. Elisabeth Lahoz asegura en un artículo para DKV que solo el 4% de la población española habita en zonas de baja contaminación lumínica.
Esta problemática afecta tanto a grandes ciudades como a zonas rurales donde la gestión inteligente de la iluminación puede reducir drásticamente el consumo de calles iluminadas durante toda la noche con una densidad de usuarios en las vías muy baja.

<br>
<br>

## 2.	SITUACION ACTUAL

La transición a la tecnología LED es ya una realidad en el alumbrado público en España. A pesar de no ser posible encontrar muchos datos concretos sobre número de lámparas LED actuales, constantemente aparecen noticias de renovaciones de alumbrado hacia esta tecnología mucho más eficiente. De hecho, en los últimos días, el Ayuntamiento de Madrid ha dado luz verde a una renovación de más de 70.000 lámparas que se convertirán en lámparas LED. 
Esta tecnología es clave a la hora de emplear nuestra solución pues permite un rápido, eficaz y no costoso encendido y apagado de las lámparas frente al sobrecoste, desgaste y lentitud de encendido de antiguas tecnologías de alumbrado empleadas.
Además, España forma parte del acuerdo de la Agenda 2030. Se trata de un plan de acción a favor de las personas, el planeta y la prosperidad, que también tiene la intención de fortalecer la paz universal y el acceso a la justicia, según el propio Gobierno de España. En este plan se recogen una serie de objetivos para el año 2030 del que destaca la necesidad de reducir en un 32,5% la energía consumida respecto a la previsión realizada para cada país para dicho año. Por ello, las medidas y sistemas de ahorro energético cobran ahora, si cabe, aún más protagonismo.


![Alt text](https://github.com/Dan2710/S.I.A-Sistema-Inteligente-de-Alumbrado/blob/main/Presentaci%C3%B3n/Agenda2030.png?raw=true)

La Agenda 2030 concreta este y otros 17 objetivos de desarrollo sostenibles a alcanzar hasta antes de este año, figura 1. Nuestro sistema encajaría en los objetivos 3, 11 y 12, desde el ahorro de consumo de energía y la reducción de contaminación lumínica que afecta a la salud y bienestar de las personas.

<br>
<br>

## 3.	SOLUCIÓN PROPUESTA

La solución propuesta es un Sistema Inteligente de Alumbrado público. Se parte de un cambio de enfoque a la hora de gestionar el alumbrado público. Desde el control crepuscular u horario actual para el encendido de alumbrado proponemos la iluminación de la vía solo ante la detección de presencia de usuarios en la misma.
Este sistema es modular pues puede instalarse sobre la infraestructura actual en aquellas luminarias que se decida y escalable con un gran número de posibilidades empleando las evoluciones del sistema.
Se parte de un sistema básico y accesible que consta de un detector de presencia de usuarios en la vía para la activación del alumbrado por tramos. De esta forma se asegura un campo de visión por delante y por detrás del usuario en calzada y acera. Su instalación es rápida y sencilla con una puesta en marcha prácticamente inmediata. Cabe hacer hincapié aquí respecto a la seguridad que transmite una vía no iluminada. La respuesta es sencilla y reiteramos, siempre que haya un usuario en la vía esta estará iluminada
El siguiente paso es convertir este sistema en un generador de informes para la aplicación de Big Data y los análisis de datos correspondientes. La idea es registrar los encendidos y apagados de cada zona para generar datos sobre densidad de tráfico, horas punta, etc. Además, se puede evaluar la eficacia del sistema por su localización, por las activaciones realizadas y su impacto en distintos casos y condiciones. 
Por último, las posibilidades se multiplican empleando cámaras de visión artificial. La cantidad de datos recogidos sería mucho mayor y diversa y los análisis posibles mucho más exhaustivos. Desde la generación de mapas de puntos negros actualizados en tiempo real, hasta la búsqueda de patrones en estos lugares de concentración de accidentes para tratar de evitarlos. Detección de cuerpos extraños en la vía, accidentes, necesidad de mantenimiento, medición de mantenimientos realizados en distintos tramos y un largo etcétera con un sistema completo de registro y análisis de datos en vías públicas en búsqueda de una mayor seguridad y siempre con el objetivo principal de una mejor gestión de recursos.

<br>
<br>

## 4.	IMPACTO ESTIMADO
Para una implementación óptima del proyecto primero se requeriría un estudio representativo teniendo en cuenta entre otros factores del número de habitantes censados del en la población a estudiar, densidad de locales de ocio, grupo de edad de la población residente, día de la semana, número de coches censados en la población a estudiar… Estos datos están disponibles en portales virtuales como el del propio Ayuntamiento de Madrid.
La idea sería seleccionar una zona de estudio suficientemente representativa con distintas características y escenarios para medir el impacto en cada situación. Esto permitiría detectar qué lugares son óptimos para implementar esta tecnología para una posterior implementación a gran escala con mayor seguridad de éxito.

Este innovador sistema, permitirá un ahorro que en ciertas situaciones puede llegar hasta el 92%, aunque es lógico que esta cifra no se alcanza en todas las situaciones, podríamos estimar en un supuesto más realista en el que el caso 1 ocurriera un 10% del tiempo, el caso 2 un 20%, el caso 3 un 20% el caso 4 un 40% y no saliera rentable el 20% de las veces, podríamos tener un ahorro medio del 45%.<br>

![Alt text](https://github.com/Dan2710/S.I.A-Sistema-Inteligente-de-Alumbrado/blob/main/Presentaci%C3%B3n/Grafica%201.jpeg?raw=true)

Además tenemos una relación lineal entre el número de detecciones y el ahorro energético, dándonos cuenta de que para un tiempo de activación de 1.2m que estudiamos ahora mismo y con nuestro algoritmo de enciendido actual, tendríamos un ahorro hasta las 12 detecciones/hora.<br>

![Alt text](https://github.com/Dan2710/S.I.A-Sistema-Inteligente-de-Alumbrado/blob/main/Presentaci%C3%B3n/Grafica%202.jpeg?raw=true)

El coste de una farola LED varía entre 500€ y 800€, nuestra solución aportaría un coste al sistema aproximado del 10% al coste total. A partir de esto, podemos calcular el tiempo de retorno de la inversión.<br>
<br>
Estimando el coste de luz anual de una farola led de 100W como unos 54€, podríamos gracias al ahorro del 45% estimar el retorno de la inversión en unos 2 años. <br>

<br>
<br>

## 5.	POSIBLE VÍA DE IMPLEMENTACIÓN

Para una implementación óptima del proyecto primero se requeriría un estudio representativo teniendo en cuenta entre otros factores del número de habitantes censados del en la población a estudiar, densidad de locales de ocio, grupo de edad de la población residente, día de la semana, número de coches censados en la población a estudiar… Estos datos están disponibles en portales virtuales como el del propio Ayuntamiento de Madrid.
La idea sería seleccionar una zona de estudio suficientemente representativa con distintas características y escenarios para medir el impacto en cada situación. Esto permitiría detectar qué lugares son óptimos para implementar esta tecnología para una posterior implementación a gran escala con mayor seguridad de éxito.

<br>
<br>
<br>


<a name="Virtual"></a>

## Maqueta virtual realizada en Minecraft
#### Video

[![Alt text](https://img.youtube.com/vi/sBBjgOlI5Ro/0.jpg)](https://www.youtube.com/watch?v=sBBjgOlI5Ro)

Enlace para probar la maqueta virtual: [Google Drive](https://drive.google.com/drive/folders/1IZtVTOTjYdUPhnlAZZ3NCLk7LDjHiguk?usp=sharing)

<br>
<br>

<a name="Fisica"></a>

## Maqueta física realizada con Arduino

[![Alt text](https://img.youtube.com/vi/mNPs2FaPj2A/0.jpg)](https://www.youtube.com/watch?v=mNPs2FaPj2A)
<br>
![Alt text](https://github.com/Dan2710/S.I.A-Sistema-Inteligente-de-Alumbrado/blob/main/Arduino/1.jpeg?raw=true)
![Alt text](https://github.com/Dan2710/S.I.A-Sistema-Inteligente-de-Alumbrado/blob/main/Arduino/2.jpeg?raw=true)
![Alt text](https://github.com/Dan2710/S.I.A-Sistema-Inteligente-de-Alumbrado/blob/main/Arduino/3.jpeg?raw=true)

<br><br>
### Proyecto realizado por:
- Jose Luis Utrera
- Héctor Sabater
- Daniel Rosell
- José Javier Casado
- Miguel Ángel Adorna
- Adrián Pacheco

### para:
![image](https://user-images.githubusercontent.com/51410145/197330812-7299b227-3a70-41e8-bd4b-8044d6bf25ec.png)
