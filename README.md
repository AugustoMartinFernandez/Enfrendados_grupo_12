# Enfrendados - El Juego de Dados

¡Bienvenidos a **Enfrendados**, el juego de dados para dos jugadores!  
Este programa fue desarrollado por el equipo '12' para la materia Programación I, año 2025 - Primer Cuatrimestre.

## Descripción general

Enfrendados es un juego interactivo que permite a dos jugadores competir lanzando dados y demostrando su suerte. El programa cuenta con un menú principal desde donde se puede:

- Jugar con dos jugadores  
- Consultar estadísticas (en desarrollo)  
- Ver los créditos del equipo desarrollador  
- Salir del juego

## Menú principal

Al iniciar el programa, se muestra una pantalla de bienvenida donde se solicita el nombre del primer jugador. Luego, se despliega el menú principal con las siguientes opciones:

1. **Jugar con 2 jugadores**  
   - Se solicita el nombre del segundo jugador.  
   - Se muestran ambos nombres registrados.  
   - (Aquí se integrará la lógica del juego desarrollada por el equipo).  

2. **Estadísticas**  
   - Actualmente muestra un mensaje de carga (en desarrollo).  

3. **Créditos**  
   - Muestra la información del equipo que desarrolló el juego, con la distribución del trabajo.  

0. **Salir**  
   - Pregunta dos veces para confirmar la salida del programa.

## Créditos

Desarrollado por el equipo **'12'**:

| Integrante                | Legajo | Responsabilidad          |
|---------------------------|--------|-------------------------|
| Fernandez, Augusto Martin | 12345  | Menú y Créditos         |
| Canela, Gabriela Maribel  | 12346  | Lógica del Juego        |
| Gimenez, Lautaro Nehuen   | 12347  | Funciones de Dados      |
| Lavini, Ignacio German    | 12348  | Validaciones            |

## Cómo ejecutar

1. Compilar el programa (por ejemplo, con g++):  
g++ src/main.cpp src/funciones.cpp -o Enfrendados.exe

text

2. Ejecutar el programa:  
./Enfrendados.exe

text

## Estructura del código relevante al menú y créditos

- **main.cpp**  
Controla el flujo principal, muestra el menú, recibe opciones y llama a funciones correspondientes.  

- **funciones.cpp / funciones.h**  
Contienen funciones para:  
- Pedir y validar nombres  
- Mostrar banners y secciones  
- Confirmar salida  
- Mostrar créditos  

## Nota final

Este README está enfocado en las funcionalidades del menú y la sección de créditos que fueron desarrollados por Martin Fernandez, que son las partes ya implementadas y probadas. La lógica del juego y estadísticas están en desarrollo y serán integradas próximamente.

---

¡Gracias por jugar y colaborar en Enfrendados!

---

*Proyecto desarrollado por el equipo '12' para la materia Programación I, 2025.*
