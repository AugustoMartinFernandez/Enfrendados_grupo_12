#include "funciones.h"
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
string pedirNombre(string mensaje)
{
  string nombre;
  while (nombre.empty()){
    cout << mensaje;
    getline(cin, nombre);
    if (nombre.empty())
    {
      cout << "Debes ingresar un nombre valido. Intenta de nuevo.\n";
    }
  }
  return nombre;
}

// Función para imprimir el banner en ASCII
void imprimirBanner()
{
    cout << "\n";
    cout << " _____ _   _ _____ ____  _____ _   _ ____   _    ____   ___  ____  \n";
    cout << "| ____| \\ | |  ___|  _ \\| ____| \\ | |  _ \\ / \\  |  _ \\ / _ \\/ ___| \n";
    cout << "|  _| |  \\| | |_  | |_) |  _| |  \\| | | | / _ \\ | | | | | | \\___ \\ \n";
    cout << "| |___| |\\  |  _| |  _ <| |___| |\\  | |_| / ___ \\| |_| | |_| |___) |\n";
    cout << "|_____|_| \\_|_|   |_| \\_\\_____|_| \\_|____/_/   \\_\\____/ \\___/|____/ \n";
    cout << "\n";
}

/*
 - Muestra en pantalla el menu principal del juego con las opciones disponibles.
 - Solicita al usuario que ingrese una opcion numerica y la retorna.
*/
int mostrarMenu()
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
  cout << "---------------------------------------" << endl;

  return opcionMenu;
}

/*
 --> Imprime en consola un recuadro con el texto recibido en 'mensaje'
 --> seguido de "(S/N):", lee un caracter de la entrada estandar
 --> y lo retorna. Se utiliza para preguntas de confirmacion.
 */
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
/*
--> Pregunta al usuario si desea salir del programa, pidiendo confirmacion en dos pasos:
--> 1) "¿Quieres salir del programa?" (S/N)
--> 2) Si responde 'S', pregunta "¿Estás seguro?" (S/N)
-> Segun las respuestas, imprime mensajes de salida, cancelacion o
-> seguimiento, hace una pausa y devuelve true (para salir) o false.
 */
bool confirmarSalida()
{
  char letra = pedirLetra("Quieres salir del programa?");
  if (letra == 'S' || letra == 's')
  {
    // Segunda confirmacion
    char confirmacion = pedirLetra("Estas seguro?");
    if (confirmacion == 'S' || confirmacion == 's')
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
  }
  else if (letra == 'N' || letra == 'n')
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
/*
--> Imprime en consola un recuadro con el 'titulo' pasado como parametro, centrado entre bordes,
--> seguido de un texto explicativo proporcionado en 'mensaje'. Luego llama a system("pause")
--> para que el usuario pueda leer el contenido antes de proseguir.
-> Texto principal que identifica la sección (por ejemplo, "ESTADISTICAS").
-> Texto adicional o subtitulo que aclara que está sucediendo en esa seccion.
*/
void mostrarSeccion(string titulo, string mensaje)
{
  cout << "+=====================================+" << endl;
  cout << "|------ " << titulo << " -------->" << endl;
  cout << "+=====================================+" << endl;
  cout << mensaje << endl;
   // Pausa para que el usuario lea la seccion antes de continuar
}


int tirarDados6Caras(){
    return rand()%6+1;
}

int tirarDados12Caras(){
    return rand()%12+1;
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
  cout << "--> Fernandez, Augusto Martin - Legajo: 12345    " << endl;
  cout << "--> Apellido, Nombre - Legajo: 12346    " << endl;
  cout << "--> Apellido, Nombre - Legajo: 12347    " << endl;
  cout << "--> Apellido, Nombre - Legajo: 12348    " << endl;
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
  system("pause");
}
