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
    cout << "[Dado " << i +1 << "]:" << dados[i] << endl;
  }
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
    cout << "Cuantos dados quieres seleccionar? ";
    cin >> cantidadATomar;
    if (cantidadATomar > cantidadStockJugador)
    {
      cout << "No puedes seleccionar mas dados de los que tienes. Intenta "
              "nuevamente."
           << endl;
    }
  } while (cantidadATomar > cantidadStockJugador);

  suma = 0;
  for (int i = 0; i < cantidadATomar; i++)
  {
    int numero;
    cout << "Elige el numero del dado #" << i + 1 << ": ";
    cin >> numero;
    int index = numero - 1; // el usuario ve 1..N, internamente usamos 0..N-1

    if (index >= 0 && index < cantidadStockJugador &&
        !yaSeleccionado(indicesSeleccionados, i, index))
    {
      indicesSeleccionados[i] = index;
      suma += dados[index];
    }
    else
    {
      cout << "Indice invalido o ya seleccionado. Intenta de nuevo." << endl;
      i--;
    }
  }
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

void procesarResultado(int suma, int numeroObjetivo, int cantidadATomar,
                       int dadosJugador[], int &cantidadStockJugador,
                       int dadosElegidosJugador[], int &cantidadElegidos,
                       int dadosOponente[], int &cantidadStockOponente,
                       int &puntosJugador, int &puntosOponente)
{
  if (suma == numeroObjetivo)
  {
    int puntaje = cantidadATomar * numeroObjetivo;
    puntosJugador += puntaje;
    cout << "Suma correcta! Has ganado " << puntaje
         << " puntos. Puntaje total: " << puntosJugador << endl;

    for (int i = 0; i < cantidadElegidos; i++)
    {
      dadosOponente[cantidadStockOponente++] = dadosElegidosJugador[i];
    }
    cantidadElegidos = 0;

    if (cantidadStockJugador == 0)
    {
      cout << "Te quedaste sin dados! Has ganado la ronda y 10.000 puntos "
              "extra."
           << endl;
      puntosJugador += 10000;
    }
  }
  else
  {
    cout << "La suma no coincide " << endl;
    if (cantidadStockOponente > 1)
    {
      int dado = dadosOponente[--cantidadStockOponente];
      dadosJugador[cantidadStockJugador++] = dado;
      cout << "El rival te da el dado de valor: " << dado << endl;
    }
    else
    {
      cout << "El rival no tiene suficientes dados para darte uno." << endl;
    }
  }
}

void jugarRonda(int dadosJugador[], int &cantidadStockJugador,
                int dadosOponente[], int &cantidadStockOponente,
                int dadosElegidos[], int &cantidadElegidos, int &puntosJugador,
                int &puntosOponente, int numeroObjetivo)
{

  cout << "Tus dados stock son: " << endl;
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
                    puntosOponente);
}

void registrarJugadores(string jugadores[])
{ cin.ignore();///para que no quede resto del cin anterior
  jugadores[1] = pedirNombre("->");

  bannerJugadoresRegistrados(jugadores[0], jugadores[1]);
  pausar();
}

void tirarYMostrarDado(const string &jugador, int &resultado)
{
  cout << jugador << " tire dado." << endl
       << endl;
  pausar();
  imprimirBanner();
  resultado = tirarDados6Caras();
  cout << "Su numero es: " << resultado << endl
       << endl;
  pausar();
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

  cout << "El primero en jugar es: " << turno << endl
       << endl;
  pausar();

  return turno;
}

int obtenerNumeroObjetivo()
{
  imprimirBanner();
  cout << "Tire los dados de doce caras para saber su numero objetivo" << endl
       << endl;
  pausar();
  imprimirBanner();

  int primerDado = tirarDados12Caras();
  int segundoDado = tirarDados12Caras();
  int objetivo = primerDado + segundoDado;

  cout << endl
       << primerDado << "    " << segundoDado << endl
       << endl;
  cout << "El numero objetivo es: " << objetivo << endl
       << endl;
  pausar();

  return objetivo;
}

void comienzoDelJuego(string jugadores[], int puntos[])
{
  const int maxDados = 11;
  int numeroObjetivo[2] = {0, 0};
  int dadosJugador1[maxDados] = {};
  int dadosJugador2[maxDados] = {};
  int dadosElegidos1[maxDados];
  int dadosElegidos2[maxDados];
  int cantidadElegidos1 = 0;
  int cantidadElegidos2 = 0;
  string turno;

  // Cada partida arranca desde cero
  puntos[0] = 0;
  puntos[1] = 0;

  imprimirBanner();
  mostrarSeccion("Enfrendados de a Dos", "Has seleccionado jugar con 2 jugadores.\n");
  registrarJugadores(jugadores);                                                        ///////////
  ordenDePartida(jugadores, turno);

  for (int ronda = 1; ronda <= 3; ronda++)
  {
    cout << "\n--- Ronda " << ronda << " ---" << endl;

    obtenerDadosStock(dadosJugador1);
    obtenerDadosStock(dadosJugador2);
    int cantidadStock1 = contarDadosStock(dadosJugador1, maxDados);
    int cantidadStock2 = contarDadosStock(dadosJugador2, maxDados);

    if (turno == jugadores[0])
    {
      // Turno del jugador 0
      numeroObjetivo[0] = obtenerNumeroObjetivo();
      cout << "\nTurno de " << jugadores[0] << endl;
      jugarRonda(dadosJugador1, cantidadStock1, dadosJugador2, cantidadStock2,
                 dadosElegidos1, cantidadElegidos1, puntos[0], puntos[1],
                 numeroObjetivo[0]);

      // Turno del jugador 1
      numeroObjetivo[1] = obtenerNumeroObjetivo();
      cout << "\nTurno de " << jugadores[1] << endl;
      jugarRonda(dadosJugador2, cantidadStock2, dadosJugador1, cantidadStock1,
                 dadosElegidos2, cantidadElegidos2, puntos[1], puntos[0],
                 numeroObjetivo[1]);
    }
    else
    {
      // Turno del jugador 1
      numeroObjetivo[1] = obtenerNumeroObjetivo();
      cout << "\nTurno de " << jugadores[1] << endl;
      jugarRonda(dadosJugador2, cantidadStock2, dadosJugador1, cantidadStock1,
                 dadosElegidos2, cantidadElegidos2, puntos[1], puntos[0],
                 numeroObjetivo[1]);

      // Turno del jugador 0
      numeroObjetivo[0] = obtenerNumeroObjetivo();
      cout << "\nTurno de " << jugadores[0] << endl;
      jugarRonda(dadosJugador1, cantidadStock1, dadosJugador2, cantidadStock2,
                 dadosElegidos1, cantidadElegidos1, puntos[0], puntos[1],
                 numeroObjetivo[0]);
    }
  }

  // Resultado final de la partida
  cout << "\n+=====================================+" << endl;
  cout << "|         RESULTADO FINAL             |" << endl;
  cout << "+=====================================+" << endl;
  cout << jugadores[0] << ": " << puntos[0] << " puntos" << endl;
  cout << jugadores[1] << ": " << puntos[1] << " puntos" << endl;
  cout << "-------------------------------------" << endl;

  if (puntos[0] > puntos[1])
    cout << "Gano " << jugadores[0] << "!" << endl;
  else if (puntos[1] > puntos[0])
    cout << "Gano " << jugadores[1] << "!" << endl;
  else
    cout << "Empate!" << endl;

  pausar();
}
