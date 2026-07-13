#include "funcionesInterfazUsuario.h"
#include "funcionesLogicaJuego.h"
#include <iostream>
#include <string>
#include "../rlutil.h"
using namespace std;

// Pausa portable: reemplaza a system("pause"), que es solo de Windows.
void pausar()
{
  cout << "\nPresione ENTER para continuar...";
  if (cin.rdbuf()->in_avail() > 0) // solo si quedo algo en el buffer, lo descartamos
    cin.ignore(10000, '\n');
  cin.get(); // un unico ENTER, siempre
}

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
  pausar(); // Pausa despues de mostrar bienvenida
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

bool mostrarMenu(string jugadores[], int puntos[])
{
  int opcionMenu;

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

  // Si el usuario escribio algo que no es un numero, limpiamos el error
  // para no entrar en un bucle infinito y forzamos una opcion invalida.
  if (cin.fail())
  {
    cin.clear();             // saca el estado de error del cin
    cin.ignore(10000, '\n'); // descarta lo que quedo en el buffer de entrada
    opcionMenu = -1;         // valor invalido -> cae en el "default" del switch
  }

  cout << "---------------------------------------" << endl;

  switch (opcionMenu)
  {
  case 1:
    comienzoDelJuego(jugadores, puntos);
    break;
  case 2:
    mostrarEstadisticas(jugadores, puntos);
    break;
  case 3:
    mostrarCreditos();
    break;
  case 0:
    return confirmarSalida(); // ← devuelve true si el usuario confirma salir
    break;

  default:
    cout << "Opcion invalida. Intenta de nuevo." << endl;
    pausar();
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

  // Si no responde S, cancelamos directo (cualquier otra tecla = no salir)
  if (letra != 'S' && letra != 's')
  {
    cout << "+---------------------------------------+" << endl;
    cout << "|  Salida cancelada. Continuamos...     |" << endl;
    cout << "+---------------------------------------+" << endl;
    pausar();
    return false;
  }

  // Segunda confirmacion
  char seguro = pedirLetra("Estas seguro?");
  if (seguro == 'S' || seguro == 's')
  {
    cout << "+---------------------------------------+" << endl;
    cout << "|     Saliendo de Enfrendados...        |" << endl;
    cout << "+---------------------------------------+" << endl;
    pausar();
    return true;
  }

  cout << "+---------------------------------------+" << endl;
  cout << "|  Salida cancelada. Continuamos...     |" << endl;
  cout << "+---------------------------------------+" << endl;
  pausar();
  return false;
}

void mostrarSeccion(string titulo, string mensaje)
{
  cout << "+=====================================+" << endl;
  cout << "|------ " << titulo << " -------->" << endl;
  cout << "+=====================================+" << endl;
  cout << mensaje << endl;
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

void mostrarEstadisticas(const string jugadores[], const int puntos[])
{
  cout << "+=====================================+" << endl;
  cout << "|           ESTADISTICAS             |" << endl;
  cout << "+=====================================+" << endl;

  if (puntos[0] == 0 && puntos[1] == 0)
  {
    cout << "Todavia no se jugo ninguna partida." << endl;
    pausar();
    return;
  }

  cout << jugadores[0] << ": " << puntos[0] << " puntos" << endl;
  cout << jugadores[1] << ": " << puntos[1] << " puntos" << endl;
  cout << "-------------------------------------" << endl;

  if (puntos[0] > puntos[1])
    cout << "Va ganando: " << jugadores[0] << endl;
  else if (puntos[1] > puntos[0])
    cout << "Va ganando: " << jugadores[1] << endl;
  else
    cout << "Van empatados." << endl;

  pausar();
}

void mostrarCreditos()
{
  cout << "+=====================================+" << endl;
  cout << "|             CREDITOS                |" << endl;
  cout << "+=====================================+" << endl;
  cout << "|    DESARROLLADO POR EL EQUIPO:      |" << endl;
  cout << "|              '12'                   |" << endl;
  cout << "+-------------------------------------+" << endl;
  cout << "|           INTEGRANTES:              |" << endl;
  cout << "+-------------------------------------+" << endl;
  cout << "--> Fernandez, Augusto Martin - Legajo: 32592-    " << endl;
  cout << "--> Canela, Gabriela Maribel - Legajo: 33157-    " << endl;
  cout << "--> Gimenez, Lautaro Nehuen - Legajo: 32432-    " << endl;
  cout << "--> Lavini, Ignacio German - Legajo: 31988-    " << endl;
  cout << "+-------------------------------------+" << endl;
  cout << "|    DISTRIBUCION DEL TRABAJO:        |" << endl;
  cout << "+-------------------------------------+" << endl;
  cout << "-> Menu y Creditos: Fernandez Augusto Martin        " << endl;
  cout << "-> Logica del Juego: Apellido2       " << endl;
  cout << "-> Funciones de Dados: Apellido3     " << endl;
  cout << "-> Validaciones: Apellido4           " << endl;
  cout << "+-------------------------------------+" << endl;
  cout << "|    MATERIA: Programacion I          |" << endl;
  cout << "|    ANIO: 2025 - Primer Cuatrimestre |" << endl;
  cout << "+-------------------------------------+" << endl;
  cout << endl;
  pausar();
}
