#include "funcionesLogicaJuego.h"
#include <iostream>
#include <string>

using namespace std;

// Constantes generales
const int MAX_DADOS = 11;
const int RONDAS = 3;

int contarDadosStock(int dados[], int sizeMax) {
  int cantidad = 0;
  for (int i = 0; i < sizeMax; i++)
  {
    if (dados[i] != 0)
      cantidad++;
  }
  return cantidad;
}

void mostrarDados(const int dados[], int cantidad) {
  for (int i = 0; i < cantidad; i++)
  {
    cout << "[" << i << "]:" << dados[i] << " ";
  }
  cout << endl;
}

bool yaSeleccionado(int indices[], int usados, int index) {
  for (int i = 0; i < usados; i++)
  {
    if (indices[i] == index)
      return true;
  }
  return false;
}

void seleccionarDados(const int dados[], int cantidadStockJugador,
                      int indicesSeleccionados[], int &cantidadATomar,
                      int &suma) {
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
    cout << "Selecciona el índice del dado #" << i + 1 << ": ";
    cin >> index;

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
}

void agregarDadosSeleccionados(int dadosStockJugador[],
                               int indicesSeleccionados[], int cantidadATomar,
                               int dadosElegidosJugador[],
                               int &cantidadElegidosJugador) {
  for (int i = 0; i < cantidadATomar; i++)
  {
    int idx = indicesSeleccionados[i];
    dadosElegidosJugador[cantidadElegidosJugador++] = dadosStockJugador[idx];
  }
}

void eliminarDadosSeleccionados(int dadosStockJugador[], int &cantidadStock,
                                int indicesSeleccionados[],
                                int cantidadATomar) {
  int stock[MAX_DADOS];
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
                       int &puntosJugador, int &puntosOponente) {
  if (suma == numeroObjetivo)
  {
    int puntaje = cantidadATomar * numeroObjetivo;
    puntosJugador += puntaje;
    cout << "¡Suma correcta! Has ganado " << puntaje
         << " puntos. Puntaje total: " << puntosJugador << endl;

    for (int i = 0; i < cantidadElegidos; i++)
    {
      dadosOponente[cantidadStockOponente++] = dadosElegidosJugador[i];
    }
    cantidadElegidos = 0;

    if (cantidadStockJugador == 0)
    {
      cout << "¡Te quedaste sin dados! Has ganado la ronda y 10.000 puntos "
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
                int &puntosOponente, int numeroObjetivo) {
  cout << "Tus dados stock son: ";
  mostrarDados(dadosJugador, cantidadStockJugador);

  int cantidadATomar = 0;
  int indicesSeleccionados[MAX_DADOS] = {};
  int suma = 0;

  seleccionarDados(dadosJugador, cantidadStockJugador, indicesSeleccionados,
                   cantidadATomar, suma);

  cout << "La suma de los dados seleccionados es: " << suma << endl;

  if (suma == numeroObjetivo)
  {
    agregarDadosSeleccionados(dadosJugador, indicesSeleccionados,
                              cantidadATomar, dadosElegidos, cantidadElegidos);
    int dummyStock = cantidadStockJugador;
    eliminarDadosSeleccionados(dadosJugador, dummyStock, indicesSeleccionados,
                               cantidadATomar);
    cantidadStockJugador = dummyStock;
  }

  procesarResultado(suma, numeroObjetivo, cantidadATomar, dadosJugador,
                    cantidadStockJugador, dadosElegidos, cantidadElegidos,
                    dadosOponente, cantidadStockOponente, puntosJugador,
                    puntosOponente);
}


void nombreJugadores(string jugadores[2]){
    cout << "Ingrese nombre de jugador 1: ";
    cin >> jugadores[0];
    cout << "Ingrese nombre de jugador 2: ";
    cin >> jugadores[1];
    system("cls");
}





void ordenDePartida(string jugadores[], string turnoJugador[]) {
    int dadoJugador1, dadoJugador2;

    do {
        dadoJugador1 = rand() % 6 + 1;
        dadoJugador2 = rand() % 6 + 1;
        cout << jugadores[0] << " tira dado: " << dadoJugador1 << endl;
        cout << jugadores[1] << " tira dado: " << dadoJugador2 << endl;

        if (dadoJugador1 > dadoJugador2) {
            turnoJugador[0] = jugadores[0];
            turnoJugador[1] = jugadores[1];
            cout << turnoJugador[0] << " comienza la partida." << endl;
        } else if (dadoJugador2 > dadoJugador1) {
            turnoJugador[0] = jugadores[1];
            turnoJugador[1] = jugadores[0];
            cout << turnoJugador[0] << " comienza la partida." << endl;
        } else {
            cout << "Empate, vuelvan a tirar." << endl;
        }
    } while (dadoJugador1 == dadoJugador2);


}

int estadoDelJuego(int rondaActual, string jugadorActual, int dadosStockJugador1[], int dadosStockJugador2[], int numeroObjetivo, int puntosAcumulados[2],int cantDadosJugador1,int cantDadosJugador2) {
    // Arrancamos la ronda actual en 1 si es que viene cero o menos
    if (rondaActual < 1) {
        rondaActual = 1;
    }

    // El jugador que comienza es el jugadorActual que recibimos, que debería venir de turnoJugador[0]
    cout << "Ronda actual: " << rondaActual << endl;
    cout << "Turno del jugador: " << jugadorActual << endl;



    return rondaActual;
}
