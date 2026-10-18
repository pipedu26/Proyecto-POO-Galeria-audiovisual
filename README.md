# Proyecto-POO Galeria de producciones audiovisuales e interactivas

##Descripción del Proyecto
Este proyecto es un sistema de administración desarrollado en C++ para una organización cultural que gestiona una galería de producciones audiovisuales e interactivas. El sistema permite controlar la distribución de exposiciones (realidad virtual, cortometrajes, videojuegos, etc.) en diferentes salas, administrar el ingreso de visitantes, y llevar un registro detallado de los ingresos y recaudos financieros.

## Integrantes del grupo

| Nombre completo| Código | Correo instituciona | Usuario de GitHub |
| --- | --- | --- | --- |
| Juan Felipe Duran Chaparro | 9035667 | pipedu26@javerianacali.edu.co | pipedu26 |
| Marian Guzman Agudelo | 9039850 | marianaguzman31@javerianacali.edu.co | Mariana-Guzman |
| Yuliana Hincapie Duarte | 9036860 | 1107851388@javerianacali.edu.co | Yulekonk |

## Funcionalidades Principales

*   **Gestión de Salas:** Creación de salas con características específicas (nombre, tipo de exposición, dimensiones en filas y columnas, y precio de ingreso). Las salas cambian de estado automáticamente (*En construcción*, *Disponible*, *Llena*).
*   **Distribución de Exposiciones:** Instalación, retiro y traslado de exposiciones entre salas. El sistema valida la compatibilidad del tipo de exposición, la disponibilidad de espacio y la existencia de las entidades involucradas.
*   **Control de Visitantes:** Registro de visitantes con un presupuesto asignado. El sistema valida el dinero disponible y el estado de la sala antes de autorizar el ingreso, registrando la transacción en un historial.
*   **Gestión Financiera y Estadísticas:** Seguimiento del recaudo generado por cada sala y por la galería en general. Permite consultar la sala con mayores ingresos, buscar la ubicación exacta de una exposición por su código, y obtener métricas globales en tiempo real.

## Estructura del Sistema

El diseño del sistema se basa en el paradigma de Programación Orientada a Objetos (POO), implementando las siguientes clases principales:

*   `Galeria`: Clase controladora que administra las colecciones de salas, visitantes y exposiciones globales.
*   `Sala`: Representa un espacio físico estructurado como una matriz bidimensional. Controla su propio estado, el recaudo y las exposiciones que alberga.
*   `Exposicion`: Contiene la información de una obra (código único, nombre, autor, tipo y descripción).
*   `Visitante`: Mantiene el perfil del usuario, su dinero disponible y su historial de visitas.
*   `Visita` (Conceptual/Implementado en historial): Registra los datos de un ingreso exitoso para mantener la consistencia histórica ante cambios de precios.

## Requisitos Previos

*   Compilador de C++ compatible con el estándar C++17 o superior (ej. GCC, Clang, MSVC).
*   Entorno de terminal o línea de comandos (Linux, macOS, o MSYS2/MinGW en Windows).

## Compilación y Ejecución

1.  Abre una terminal y navega hasta el directorio donde se encuentra el archivo fuente (por ejemplo, `galeria.cpp`).
2.  Ejecuta el siguiente comando para compilar el código:
    ```bash
    g++ galeria.cpp -o galeria -std=c++17
    ```
3.  Una vez compilado sin errores, ejecuta el programa con:
    *   En Linux/macOS: `./galeria`
    *   En Windows: `galeria.exe`
