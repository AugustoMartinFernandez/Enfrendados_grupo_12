#include "funcionesLogicaJuego.h"
#include "funcionesInterfazUsuario.h"
#include <iostream>
#include <string>
using namespace std;

int tirarDados6Caras()
{

  return rand() % 6 + 1;
}

int tirarDados12Caras()
{
  return rand() % 12 + 1;
}

void obtenerDadosStock(int dadosJugador[])
{
  for (int i = 0; i < 6; i++)
  {
    dadosJugador[i] = tirarDados6Caras();
  }
}

int contarDadosStock(int dados[], int sizeMax)
{
  int cantidad = 0;
  for (int i = 0; i < sizeMax; i++)
  {
    if (dados[i] != 0)
      cantidad++;
  }
  return cantidad;
}

void mostrarDados(const int dados[], int cantidad)
{
  for (int i = 0; i < cantidad; i++)
  {
    cout << "[Dado " << i + 1 << "]:" << dados[i] << endl;
  }
  cout << endl;
}

bool yaSeleccionado(int indices[], int usados, int index)
{
  for (int i = 0; i < usados; i++)
  {
    if (indices[i] == index)
      return true;
  }
  return false;
}

void seleccionarDados(const int dados[], int cantidadStockJugador,
                      int indicesSeleccionados[], int &cantidadATomar,
                      int &suma)
{
  do
  {
    cout << "¿Cuántos dados quieres seleccionar? ";
    cin >> cantidadATomar;
    if (cantidadATomar > cantidadStockJugador)
    {
      cout << "No puedes seleccionar más dados de los que tienes. Intenta "
              "nuevamente."
           << endl;
    }
  } while (cantidadATomar > cantidadStockJugador);

  suma = 0;
  for (int i = 0; i < cantidadATomar; i++)
  {
    int index;
    cout << "Selecciona el dado #" << (i + 1) << ": ";
    cin >> index;
    index -= 1;

    if (index >= 0 && index < cantidadStockJugador &&
        !yaSeleccionado(indicesSeleccionados, i, index))
    {
      indicesSeleccionados[i] = index;
      suma += dados[index];
    }
    else
    {
      cout << "Índice inválido o ya seleccionado. Intenta de nuevo." << endl;
      i--;
    }
  }
  cout << endl;
}

void agregarDadosSeleccionados(int dadosStockJugador[],
                               int indicesSeleccionados[], int cantidadATomar,
                               int dadosElegidosJugador[],
                               int &cantidadElegidosJugador)
{
  for (int i = 0; i < cantidadATomar; i++)
  {
    int idx = indicesSeleccionados[i];
    dadosElegidosJugador[cantidadElegidosJugador++] = dadosStockJugador[idx];
  }
}

void eliminarDadosSeleccionados(int dadosStockJugador[], int &cantidadStock,
                                int indicesSeleccionados[],
                                int cantidadATomar)
{
  int stock[11];
  int j = 0;
  for (int i = 0; i < cantidadStock; i++)
  {
    bool esSeleccionado = false;
    for (int k = 0; k < cantidadATomar; k++)
    {
      if (i == indicesSeleccionados[k])
      {
        esSeleccionado = true;
        break;
      }
    }
    if (!esSeleccionado)
    {
      stock[j++] = dadosStockJugador[i];
    }
  }
  for (int i = 0; i < j; i++)
  {
    dadosStockJugador[i] = stock[i];
  }
  cantidadStock = j;
}

bool procesarResultado(int suma, int numeroObjetivo, int cantidadATomar,
                       int dadosJugador[], int &cantidadStockJugador,
                       int dadosElegidosJugador[], int &cantidadElegidos,
                       int dadosOponente[], int &cantidadStockOponente,
                       int &puntosJugador, int &puntosOponente, bool &finDelJuego)
{
  if (suma == numeroObjetivo)
  {
    int puntaje = cantidadATomar * numeroObjetivo;
    puntosJugador += puntaje;
    cout << "¡Suma correcta! Has ganado " << puntaje
         << " puntos. Puntaje total: " << puntosJugador << endl;

    return finDelJuego;

    if (cantidadStockJugador == 0)
    {
      cout << "¡Te quedaste sin dados! Has ganado la ronda y 10.000 puntos "
              "extra."
           << endl;
      puntosJugador += 10000;
      finDelJuego = true;
      return finDelJuego;
    }
  }
  else
  {
    cout << "La suma no coincide " << endl;
    mostrarSeccion("Se penzaliza la jugada", "");
    cout << endl;

    if (cantidadStockOponente > 1)
    {
      int dado = dadosOponente[--cantidadStockOponente];
      dadosJugador[cantidadStockJugador++] = dado;
      cout << "El rival te da un dado de valor: " << dado << endl;
      return finDelJuego;
    }
    else
    {
      cout << "El rival no tiene suficientes dados para darte uno." << endl;
      return finDelJuego;
    }
  }
}

bool jugarRonda(int dadosJugador[], int &cantidadStockJugador,
                int dadosOponente[], int &cantidadStockOponente,
                int dadosElegidos[], int &cantidadElegidos, int &puntosJugador,
                int &puntosOponente, int numeroObjetivo, bool &finDelJuego)
{

  cout << "Tus dados stock son: " << endl
       << endl;
  mostrarDados(dadosJugador, cantidadStockJugador);

  int indicesSeleccionados[11] = {};
  int cantidadATomar = 0;
  int suma = 0;

  seleccionarDados(dadosJugador, cantidadStockJugador, indicesSeleccionados,
                   cantidadATomar, suma);

  cout << "La suma de los dados seleccionados es: " << suma << endl;

  if (suma == numeroObjetivo)
  {
    agregarDadosSeleccionados(dadosJugador, indicesSeleccionados,
                              cantidadATomar, dadosElegidos, cantidadElegidos);
    int cantidadDeDadosUsados = cantidadStockJugador;
    eliminarDadosSeleccionados(dadosJugador, cantidadDeDadosUsados, indicesSeleccionados,
                               cantidadATomar);
    cantidadStockJugador = cantidadDeDadosUsados;
  }

  procesarResultado(suma, numeroObjetivo, cantidadATomar, dadosJugador,
                    cantidadStockJugador, dadosElegidos, cantidadElegidos,
                    dadosOponente, cantidadStockOponente, puntosJugador,
                    puntosOponente, finDelJuego);
  
  return finDelJuego;
}

int estadoDelJuego(int rondaActual, string jugadorActual, int dadosStockJugador1[], int dadosStockJugador2[], int numeroObjetivo, int puntosAcumulados[2], int cantDadosJugador1, int cantDadosJugador2)
{
  // Arrancamos la ronda actual en 1 si es que viene cero o menos
  if (rondaActual < 1)
  {
    rondaActual = 1;
  }

  // El jugador que comienza es el jugadorActual que recibimos, que debería venir de turnoJugador[0]
  cout << "Ronda actual: " << rondaActual << endl;
  cout << "Turno del jugador: " << jugadorActual << endl;

  return rondaActual;
}

void registrarJugadores(string jugadores[])
{
  cin.ignore(); /// para que no quede resto del cin anterior

  cout << "|---- Ingrese nombre jugador 2° ---- |" << endl;
  jugadores[1] = pedirNombre("->");

  bannerJugadoresRegistrados(jugadores[0], jugadores[1]);
  system("pause");
}

void tirarYMostrarDado(const string &jugador, int &resultado)
{
  imprimirBanner();
  cout << jugador << " tire dado." << endl
       << endl;
  system("pause");
  resultado = tirarDados6Caras();
  cout << "Su numero es: " << resultado << endl
       << endl;
  system("pause");
}

string ordenDePartida(const string jugadores[], string &turno)
{
  int resultadoUno = 0, resultadoDos = 0;

  bannerSorteo();

  do
  {
    tirarYMostrarDado(jugadores[0], resultadoUno);
    imprimirBanner();
    tirarYMostrarDado(jugadores[1], resultadoDos);
  } while (resultadoUno == resultadoDos);

  imprimirBanner();
  if (resultadoUno > resultadoDos)
  {
    turno = jugadores[0];
  }
  else
  {
    turno = jugadores[1];
  }

  cout << "El primero en jugar es: " << endl
       << endl;
  mostrarSeccion(turno, "");
  system("pause");

  return turno;
}

int obtenerNumeroObjetivo()
{
  cout << "Tire los dados de doce caras para saber su numero objetivo" << endl
       << endl;
  system("pause");
  // imprimirBanner();

  int primerDado = tirarDados12Caras();
  int segundoDado = tirarDados12Caras();
  int objetivo = primerDado + segundoDado;

  cout << endl
       << primerDado << "    " << segundoDado << endl
       << endl;
  cout << "El numero objetivo es: " << objetivo << endl
       << endl;
  system("pause");

  return objetivo;
}

void comienzoDelJuego(string jugadores[], int puntos[])
{
  const int maxDados = 11;
  int numeroObjetivo[2];
  int dadosJugador1[maxDados] = {};
  int dadosJugador2[maxDados] = {};
  int dadosElegidos1[maxDados];
  int dadosElegidos2[maxDados];
  int cantidadElegidos1 = 0;
  int cantidadElegidos2 = 0;
  string turno;
  bool finDelJuego = false;

  imprimirBanner();
  mostrarSeccion("Enfrendados de a Dos", "Has seleccionado jugar con 2 jugadores.\n");
  registrarJugadores(jugadores); ///////////
  ordenDePartida(jugadores, turno);

  for (int ronda = 1; ronda <= 3; ronda++)
  {
    cout << "\n+============== Ronda " << ronda << " ==============+" << endl;

    obtenerDadosStock(dadosJugador1);
    obtenerDadosStock(dadosJugador2);
    int cantidadStock1 = contarDadosStock(dadosJugador1, maxDados);
    int cantidadStock2 = contarDadosStock(dadosJugador2, maxDados);

    if (turno == jugadores[0])
    {
      // Turno del jugador 0
      cout << "\nTurno de " << jugadores[0] << endl;
      numeroObjetivo[0] = obtenerNumeroObjetivo();
      jugarRonda(dadosJugador1, cantidadStock1, dadosJugador2, cantidadStock2,
                 dadosElegidos1, cantidadElegidos1, puntos[0], puntos[1],
                 numeroObjetivo[0], finDelJuego);
      if (finDelJuego) break;

      // Turno del jugador 1
      cout << "\nTurno de " << jugadores[1] << endl;
      numeroObjetivo[1] = obtenerNumeroObjetivo();
      jugarRonda(dadosJugador2, cantidadStock2, dadosJugador1, cantidadStock1,
                 dadosElegidos2, cantidadElegidos2, puntos[1], puntos[0],
                 numeroObjetivo[1], finDelJuego);
      if (finDelJuego) break;
    }
    else
    {
      // Turno del jugador 1
      cout << "\nTurno de " << jugadores[1] << endl;
      numeroObjetivo[1] = obtenerNumeroObjetivo();
      jugarRonda(dadosJugador2, cantidadStock2, dadosJugador1, cantidadStock1,
                 dadosElegidos2, cantidadElegidos2, puntos[1], puntos[0],
                 numeroObjetivo[1], finDelJuego);
      if (finDelJuego) break;

      // Turno del jugador 0
      cout << "\nTurno de " << jugadores[0] << endl;
      numeroObjetivo[0] = obtenerNumeroObjetivo();
      jugarRonda(dadosJugador1, cantidadStock1, dadosJugador2, cantidadStock2,
                 dadosElegidos1, cantidadElegidos1, puntos[0], puntos[1],
                 numeroObjetivo[0], finDelJuego);
      if (finDelJuego) break;
    }
  }

  imprimirBanner();
  finalDelJuego(jugadores, puntos);
}
