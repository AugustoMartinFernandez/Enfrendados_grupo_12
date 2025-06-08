#ifndef FUNCIONESINTERFAZUDUARIO_H
#define FUNCIONESINTERFAZUDUARIO_H
#include <iostream>
#include <string>

using namespace std;

/*
- Solicita al usuario que ingrese un nombre mostrando el mensaje indicado.
- Valida que el nombre no este vacío y repite la solicitud hasta que
- se ingrese un nombre valido.
El metodo .empty() verifica si una cadena de texto esta vacia.
- Retorna true si la cadena no contiene ningun caracter (longitud 0),
- y false si tiene uno o mas caracteres.
*/
string pedirNombre(string mensaje);

// Pantalla de bienvenida inicial
void mostrarBienvenida();

// Pantalla de bienvenida jugador unicial
void imprimirBannerBienvenida(string nombre);

// Declaración de la función para imprimir el banner en ASCII Art
void imprimirBanner();

/*
 - Muestra en pantalla el menu principal del juego con las opciones disponibles.
 - Solicita al usuario que ingrese una opcion numerica y ejecuta la accion.
*/
bool mostrarMenu(string jugadores[]);

/*
--> Imprime en consola un recuadro con el 'titulo' pasado como parametro, centrado entre bordes,
--> seguido de un texto explicativo proporcionado en 'mensaje'. Luego llama a system("pause")
--> para que el usuario pueda leer el contenido antes de proseguir.
-> Texto principal que identifica la sección (por ejemplo, "ESTADISTICAS").
-> Texto adicional o subtitulo que aclara que está sucediendo en esa seccion.
*/
void mostrarSeccion(string, string);
// Mostrara la seccion de Creditos, quienes desarrollaron Enfrendados

void bannerJugadorDos();

void bannerJugadoresRegistrados(string, string);

void bannerSorteo();

void mostrarCreditos();

/*
 --> Imprime en consola un recuadro con el texto recibido en 'mensaje'
 --> seguido de "(S/N):", lee un caracter de la entrada estandar
 --> y lo retorna. Se utiliza para preguntas de confirmacion.
 */
char pedirLetra(string mensaje);

// La función mostrarEstadisticas muestra las estadísticas del juego, evaluando
// los puntos acumulados por los jugadores y actualizando el historial del jugador
// con mayor puntaje y el puntaje del perdedor si aún no se han registrado.
void mostrarEstadisticas(const string jugadores[], const int puntos[],
                         string &historialjugGanador, int &historialPuntPerdedor);

/*
--> Pregunta al usuario si desea salir del programa, pidiendo confirmacion en dos pasos:
--> 1) "¿Quieres salir del programa?" (S/N)
--> 2) Si responde 'S', pregunta "¿Estás seguro?" (S/N)
-> Segun las respuestas, imprime mensajes de salida, cancelacion o
-> seguimiento, hace una pausa y devuelve true (para salir) o false.
 */
bool confirmarSalida();

#endif