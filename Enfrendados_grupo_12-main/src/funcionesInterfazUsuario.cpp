#include "funcionesInterfazUsuario.h"
#include "funcionesLogicaJuego.h"
#include <iostream>
#include <string>
#include "../rlutil.h"
using namespace std;

string pedirNombre(string mensaje)
{
  string nombre;
  do
  {
    cout << mensaje;
    getline(cin, nombre);
    if (nombre.empty())
    {
      cout << "Debes ingresar un nombre valido. Intenta de nuevo.\n";
    }
  } while (nombre.empty());
  return nombre;
}

void mostrarBienvenida()
{
  cout << "+=====================================+" << endl;
  cout << "|         BIENVENIDOS A ENFRENDADOS   |" << endl;
  cout << "|           EL JUEGO DE DADOS         |" << endl;
  cout << "+=====================================+" << endl;
  cout << "|  Por favor, ingresa tu nombre para  |" << endl;
  cout << "|           comenzar a jugar          |" << endl;
  cout << "+-------------------------------------+" << endl;
}

void imprimirBannerBienvenida(string jugador)
{
  cout << endl;
  cout << endl;
  cout << "+---------------------------------------------------------------------------------------+" << endl;
  cout << "| Bienvenido, " << jugador << " Preparate para tirar los dados y demostrar tu suerte.  |" << endl;
  cout << "+---------------------------------------------------------------------------------------+" << endl;
  system("pause"); // Pausa despues de mostrar bienvenida
  rlutil::cls();
}

void imprimirBanner()
{
  rlutil::cls();
  cout << "\n";
  cout << " _____ _   _ _____ ____  _____ _   _ ____     _    ____   ___  ____  \n";
  cout << "| ____| \\ | |  ___|  _ \\| ____| \\ | |  _ \\   / \\  |  _ \\ / _ \\/ ___| \n";
  cout << "|  _| |  \\| | |_  | |_) |  _| |  \\| | | ||  / _ \\ | | | | | | \\___ \\ \n";
  cout << "| |___| |\\  |  _| |  _ <| |___| |\\  | |_|| / ___ \\| |_| | |_| |___) |\n";
  cout << "|_____|_| \\_|_|   |_| \\_\\_____|_| \\_|____//_/   \\_\\____/ \\___/|____/ \n";
  cout << "\n";
}

bool mostrarMenu(string jugadores[])
{
  int opcionMenu;
  int puntos[2] = {0, 0};
  string historialjugGanador;
  int historialPuntPerdedor = 0;

  cout << endl;
  cout << "+=====================================+" << endl;
  cout << "|      MENU PRINCIPAL DEL JUEGO       |" << endl;
  cout << "|-------------------------------------|" << endl;
  cout << "|   1) --> Jugar con 2 jugadores      |" << endl;
  cout << "|   2) --> Estadisticas               |" << endl;
  cout << "|   3) --> Creditos                   |" << endl;
  cout << "|-------------------------------------|" << endl;
  cout << "|   0) --> Salir                      |" << endl;
  cout << "+=====================================+" << endl;
  cout << "Seleccione una opcion con numeros: ";
  cin >> opcionMenu;
  cout << "---------------------------------------" << endl;

  switch (opcionMenu)
  {
  case 1:
    comienzoDelJuego(jugadores, puntos);
    break;
  case 2:
    mostrarEstadisticas(jugadores, puntos, historialjugGanador, historialPuntPerdedor);
    break;
  case 3:
    mostrarCreditos();
    break;
  case 0:
    return confirmarSalida(); // ← devuelve true si el usuario confirma salir
    break;

  default:
    cout << "Opcion invalida. Intenta de nuevo." << endl;
    system("pause");
  }

  return false; // ← seguir en el menú
}

char pedirLetra(string mensaje)
{
  char letra;
  cout << "+---------------------------------------+" << endl;
  cout << "|  " << mensaje << "  (S/N):     |" << endl;
  cout << "+---------------------------------------+" << endl;
  cout << "-> ";
  cin >> letra;
  return letra;
}

bool confirmarSalida()
{
  char letra = pedirLetra("Quieres salir del programa?");
  if (letra == 'S' || letra == 's')
  {
    cout << "+---------------------------------------+" << endl;
    cout << "|     Saliendo de Enfrendados...        |" << endl;
    cout << "+---------------------------------------+" << endl;
    system("pause");
    return true; // Confirma dos veces que quiere salir
  }
  else
  {
    cout << "+---------------------------------------+" << endl;
    cout << "|  Salida cancelada. Continuamos...     |" << endl;
    cout << "+---------------------------------------+" << endl;
    system("pause");
    return false; // Cancela en la segunda confirmacion
  }
  if (letra == 'N' || letra == 'n')
  {
    cout << "+---------------------------------------+" << endl;
    cout << "|No te preocupes seguimos en Enfrendados|" << endl;
    cout << "+---------------------------------------+" << endl;
    system("pause");
    return false; // No quiere salir
  }
  else
  {
    cout << "+---------------------------------------+" << endl;
    cout << "|  Entrada invalida. Preciona 's' o 'n'.|" << endl;
    cout << "+---------------------------------------+" << endl;
    system("pause");
    return false; // Entrada invalida, no sale
  }
}

void mostrarSeccion(string titulo, string mensaje)
{
  cout << "+=====================================+" << endl;
  cout << "|------ " << titulo << " -------->" << endl;
  cout << "+=====================================+" << endl;
  if (mensaje != "")
  {
    cout << mensaje << endl;
  }
  // Pausa para que el usuario lea la seccion antes de continuar
}

void bannerJugadorDos()
{
  cout << "+=====================================+" << endl;
  cout << "|   INGRESE NOMBRE DEL JUGADOR 2      |" << endl;
  cout << "+=====================================+" << endl;
}

void bannerJugadoresRegistrados(string jugador1, string jugador2)
{
  cout << "\n";
  cout << "+=====================================+" << endl;
  cout << "|      JUGADORES REGISTRADOS          |" << endl;
  cout << "|-------------------------------------|" << endl;
  cout << "--> Jugador 1: " << jugador1 << endl;
  cout << "--> Jugador 2: " << jugador2 << endl;
  cout << "+=====================================+" << endl
       << endl;
}

void bannerSorteo()
{
  cout << endl;
  cout << "+=====================================+" << endl;
  cout << "|               SORTEO                |" << endl;
  cout << "+=====================================+" << endl;
}

void finalDelJuego(string jugadores[], int puntos[])
{
  cout << endl;
  cout << "+=====================================+" << endl;
  cout << "|            FIN DEL JUEGO            |" << endl;
  cout << "+=====================================+" << endl;

  cout << endl;

  if (puntos[0] > puntos[1])
  {
    cout << "El ganador es: " << jugadores[0] << " con " << puntos[0] << " puntos." << endl;
  }
  else if (puntos[1] > puntos[0])
  {
    cout << "El ganador es: " << jugadores[1] << " con " << puntos[1] << " puntos." << endl;
  }
  else
  {
    cout << "Empate entre " << jugadores[0] << " y " << jugadores[1]
         << " con " << puntos[0] << " puntos." << endl;
  }
  system("pause");
}

void mostrarEstadisticas(const string jugadores[], const int puntos[],
                         string &historialjugGanador, int &historialPuntGanador)
{
  imprimirBanner();
  cout << "+=====================================+" << endl;
  cout << "|           ESTADISTICAS              |" << endl;
  cout << "+=====================================+" << endl;

  if (historialjugGanador != "")
  {
    // Determinar el jugador con mayor puntaje
    int indiceGanador = (puntos[0] > puntos[1]) ? 0 : 1;
    historialjugGanador = jugadores[indiceGanador];
    historialPuntGanador = puntos[1 - indiceGanador]; // Puntaje del perdedor
  }

  cout << "Jugador con mayor puntaje histórico: " << historialjugGanador << endl;
  cout << "Puntaje del jugador: " << historialPuntGanador << endl;
  cout << "+=====================================+" << endl;

  system("pause");
}

void mostrarCreditos()
{
  imprimirBanner();
  cout << "+===============================================+" << endl;
  cout << "|                    CREDITOS                   |" << endl;
  cout << "+===============================================+" << endl;
  cout << "|           DESARROLLADO POR EL EQUIPO:         |" << endl;
  cout << "|                     '12'                      |" << endl;
  cout << "+-----------------------------------------------+" << endl;
  cout << "|                   INTEGRANTES:                |" << endl;
  cout << "+-----------------------------------------------+" << endl;
  cout << "-> Fernandez, Augusto Martin - Legajo: 32592-    " << endl;
  cout << "-> Canela, Gabriela Maribel  - Legajo: 33157-    " << endl;
  cout << "-> Gimenez, Lautaro Nehuen   - Legajo: 32432-    " << endl;
  cout << "-> Lavini, Ignacio German    - Legajo: 31988-    " << endl;
  cout << "+-----------------------------------------------+" << endl;
  cout << "|            DISTRIBUCION DEL TRABAJO:          |" << endl;
  cout << "+-----------------------------------------------+" << endl;
  cout << "-> Menu y Creditos: Fernandez Augusto Martin     " << endl;
  cout << "-> Logica del Juego: Apellido2                   " << endl;
  cout << "-> Funciones de Dados: Apellido3                 " << endl;
  cout << "-> Validaciones: Apellido4                       " << endl;
  cout << "+-----------------------------------------------+" << endl;
  cout << "|            MATERIA: Programacion I            |" << endl;
  cout << "|         ANIO: 2025 - Primer Cuatrimestre      |" << endl;
  cout << "+-----------------------------------------------+" << endl;
  cout << endl;
  system("pause");
}
