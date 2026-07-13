#ifndef FUNCIONESINTERFAZUSUARIO_H
#define FUNCIONESINTERFAZUSUARIO_H
#include <iostream>
#include <string>

/*
- Solicita al usuario que ingrese un nombre mostrando el mensaje indicado.
- Valida que el nombre no este vacío y repite la solicitud hasta que
- se ingrese un nombre valido.
El metodo .empty() verifica si una cadena de texto esta vacia.
- Retorna true si la cadena no contiene ningun caracter (longitud 0),
- y false si tiene uno o mas caracteres.
*/
std::string pedirNombre(std::string mensaje);

// Pausa portable (reemplaza a system("pause")): espera a que el usuario apriete ENTER.
void pausar();

// Pantalla de bienvenida inicial
void mostrarBienvenida();

// Pantalla de bienvenida jugador inicial
void imprimirBannerBienvenida(std::string nombre);

// Declaración de la función para imprimir el banner en ASCII Art
void imprimirBanner();

/*
 - Muestra en pantalla el menu principal del juego con las opciones disponibles.
 - Solicita al usuario que ingrese una opcion numerica y ejecuta la accion.
*/
bool mostrarMenu(std::string jugadores[], int puntos[]);

/*
--> Imprime en consola un recuadro con el 'titulo' pasado como parametro, centrado entre bordes,
--> seguido de un texto explicativo proporcionado en 'mensaje'.
-> Texto principal que identifica la sección (por ejemplo, "ESTADISTICAS").
-> Texto adicional o subtitulo que aclara que está sucediendo en esa seccion.
*/
void mostrarSeccion(std::string, std::string);
// Mostrara la seccion de Creditos, quienes desarrollaron Enfrendados

void bannerJugadorDos();

void bannerJugadoresRegistrados(std::string, std::string);

void bannerSorteo();

void mostrarCreditos();

/*
 --> Imprime en consola un recuadro con el texto recibido en 'mensaje'
 --> seguido de "(S/N):", lee un caracter de la entrada estandar
 --> y lo retorna. Se utiliza para preguntas de confirmacion.
 */
char pedirLetra(std::string mensaje);

// Muestra el marcador actual de ambos jugadores y quien va ganando,
// o avisa si todavia no se jugo ninguna partida.
void mostrarEstadisticas(const std::string jugadores[], const int puntos[]);

/*
--> Pregunta al usuario si desea salir del programa, pidiendo confirmacion en dos pasos:
--> 1) "Quieres salir del programa?" (S/N)
--> 2) Si responde 'S', pregunta "Estas seguro?" (S/N)
-> Segun las respuestas, imprime mensajes de salida o cancelacion,
-> hace una pausa y devuelve true (para salir) o false.
 */
bool confirmarSalida();

#endif
