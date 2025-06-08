#ifndef FUNCIONESLOGICAJUEGO_H
#define FUNCIONESLOGICAJUEGO_H
#include <iostream>
#include <string>

using namespace std;

int tirarDados6Caras();

int tirarDados12Caras();

int contarDadosStock(int dados[], int sizeMax);

void mostrarDados(const int dados[], int cantidad);

bool yaSeleccionado(int indices[], int usados, int index);

void seleccionarDados(const int dados[], int cantidadStockJugador,
                      int indicesSeleccionados[], int &cantidadATomar,
                      int &suma);

void agregarDadosSeleccionados(int dadosStockJugador[],
                               int indicesSeleccionados[], int cantidadATomar,
                               int dadosElegidosJugador[],
                               int &cantidadElegidosJugador);

void eliminarDadosSeleccionados(int dadosStockJugador[], int &cantidadStock,
                                int indicesSeleccionados[], int cantidadATomar);

void procesarResultado(int suma, int numeroObjetivo, int cantidadATomar,
                       int dadosJugador[], int &cantidadStockJugador,
                       int dadosElegidosJugador[], int &cantidadElegidos,
                       int dadosOponente[], int &cantidadStockOponente,
                       int &puntosJugador, int &puntosOponente);

void jugarRonda(int dadosJugador[], int &cantidadStockJugador,
                int dadosOponente[], int &cantidadStockOponente,
                int dadosElegidos[], int &cantidadElegidos, int &puntosJugador,
                int &puntosOponente, int numeroObjetivo);

// void ordenDePartida(string jugadores[2], string turnoJugador[2]);

int estadoDelJuego(int rondaActual, string jugadorActual,
                   int dadosStockJugador1[], int &cantDadosJugador1,
                   int dadosStockJugador2[], int &cantDadosJugador2,
                   int numeroObjetivo,
                   int puntosAcumulados[]);

void realizarSorteo(const string jugadores[], string &primero, string &segundo);
int obtenerNumeroObjetivo();
void registrarJugadores(string jugadores[]);
void comienzoDelJuego(string jugadores[]);
void tirarYMostrarDado(const string &jugador, int &resultado);
string ordenDePartida(const string jugadores[], string &turno);
void obtenerDadosStock(int dadosJugador1[]);

#endif
