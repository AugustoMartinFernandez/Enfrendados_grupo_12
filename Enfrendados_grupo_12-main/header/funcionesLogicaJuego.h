#ifndef FUNCIONESLOGICAJUEGO_H
#define FUNCIONESLOGICAJUEGO_H
#include <iostream>
#include <string>

using namespace std;

// La funcion rand() da un numero random esto complementado con el srand(time(nullptr)) 
// devuelve un numero distinto por cada tirada ya que usa la hora del pc
// rand()%6 te da un num del 0 al 5 si se le suma 1 te da del 1 al 6
int tirarDados6Caras();

//Similar a funcion tirarDados6Caras pero maneja hasta 12 caras
int tirarDados12Caras();

//Funcion que carga en el vector de dadosJugador1 los dados stock
void obtenerDadosStock(int dadosJugador[]);

// Funcion para obtener el tamaño/longitud de los dados stock del jugador
int contarDadosStock(int dados[], int sizeMax);

//Funcion para listar los dados que tiene el jugador.
void mostrarDados(const int dados[], int cantidad);

//Funcion La función verifica si un índice específico (index) ya ha sido seleccionado previamente 
// en un conjunto de índices (indices[]). Esto es útil en la funcion seleccionarDados para evitar 
// que el mismo dado sea seleccionado más de una vez.
bool yaSeleccionado(int indices[], int usados, int index);

// La función seleccionarDados permite al jugador seleccionar un número específico de dados de su stock, 
// sumarlos y almacenar los índices de los dados seleccionados y también valida que los índices seleccionados 
// sean válidos y no se repitan.
void seleccionarDados(const int dados[], int cantidadStockJugador,
                      int indicesSeleccionados[], int &cantidadATomar,
                      int &suma);

// La función agregarDadosSeleccionados agrega los valores de los dados seleccionados por el jugador desde 
// su stock a un arreglo de dados elegidos. Esto permite que los dados seleccionados sean utilizados en 
// la funcion jugarRonda para agregar los dados elegidos para cumplir con el objetivo al contricante.
void agregarDadosSeleccionados(int dadosStockJugador[],
                               int indicesSeleccionados[], int cantidadATomar,
                               int dadosElegidosJugador[],
                               int &cantidadElegidosJugador);

// La función eliminarDadosSeleccionados elimina los dados seleccionados por el jugador de su stock. 
// Esto es útil para actualizar el stock de dados después de que el jugador haya utilizado algunos de ellos en su turno.
void eliminarDadosSeleccionados(int dadosStockJugador[], int &cantidadStock,
                                int indicesSeleccionados[], int cantidadATomar);

// La función procesarResultado evalúa el resultado de la selección de dados realizada por el jugador en su turno y 
// actualiza el estado del juego en función de si la suma de los dados seleccionados coincide con el número objetivo. 
// También gestiona el intercambio de dados entre jugadores y la asignación de puntos.
bool procesarResultado(int suma, int numeroObjetivo, int cantidadATomar,
                       int dadosJugador[], int &cantidadStockJugador,
                       int dadosElegidosJugador[], int &cantidadElegidos,
                       int dadosOponente[], int &cantidadStockOponente,
                       int &puntosJugador, int &puntosOponente, bool &finDelJuego);

// La función jugarRonda representa el flujo de una ronda en el juego para un jugador. 
// Permite al jugador seleccionar dados, calcular la suma de los valores seleccionados, 
// verificar si la suma coincide con el número objetivo, y actualizar el estado del juego 
// (dados, puntos, etc.) en función del resultado.

bool jugarRonda(int dadosJugador[], int &cantidadStockJugador,
                int dadosOponente[], int &cantidadStockOponente,
                int dadosElegidos[], int &cantidadElegidos, int &puntosJugador,
                int &puntosOponente, int numeroObjetivo, bool &finDelJuego);

//No se la esta usando esta incompleta.
int estadoDelJuego(int rondaActual, string jugadorActual,
                   int dadosStockJugador1[], int &cantDadosJugador1,
                   int dadosStockJugador2[], int &cantDadosJugador2,
                   int numeroObjetivo,
                   int puntosAcumulados[]);

// La función registrarJugadores solicita los nombres de los jugadores y los almacena en un arreglo.
void registrarJugadores(string jugadores[]);

// La función bannerJugadorDos muestra un mensaje de bienvenida para el segundo jugador.
void tirarYMostrarDado(const string &jugador, int &resultado);

// La función bannerJugadoresRegistrados muestra un mensaje indicando que los jugadores han sido registrados.
string ordenDePartida(const string jugadores[], string &turno);

// La función obtenerNumeroObjetivo solicita a los jugadores que tiren dados de 12 caras para determinar el número objetivo del juego.
int obtenerNumeroObjetivo();

// La función confirmarSalida pregunta al usuario si desea salir del programa y devuelve true o false según la respuesta.
void comienzoDelJuego(string jugadores[], int puntos[]);

#endif
