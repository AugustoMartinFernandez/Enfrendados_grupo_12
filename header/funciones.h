#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <string>

using namespace std;

// Solo DECLARACIÓN de funciones
// Declaración de la función para imprimir el banner en ASCII Art
void imprimirBanner();
int mostrarMenu();
// Pide al usuario que ingrese un nombre mostrando el texto pasado en “mensaje” y valida que la cadena no quede vacia.
// Repite hasta que el usuario escriba algo.
string pedirNombre(string mensaje);
// Muestra un recuadro con el texto que le llega en 'mensaje', indicando al usuario  que responda con S o N. Se la usa dentro de confirmarSalida() para preguntar dos veces ¿Quieres salir? y luego ¿Estás seguro?.
char pedirLetra(string mensaje);
// Funcion para confirmar salida del Menu
bool confirmarSalida();
// Muestra el Titulo y Subtitulo de cada seccion Ejemplo: Titulo = Enfrendados
// de a Dos, Subtitulo = Has seleccionado jugar con 2 jugadores.
void mostrarSeccion(string titulo, string mensaje);
// Mostrara la seccion de Creditos, quienes desarrollaron Enfrendados
void mostrarCreditos();

#endif