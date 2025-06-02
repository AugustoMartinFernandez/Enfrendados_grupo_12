#include "funciones.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Variable para guardar nombre del usuario1 y 2
    string jugador1, jugador2;
    // Variable para opcion de menu
    int opcionMenu;
    bool salir = false; // Variable bandera para controlar el ciclo del menu cambia a true cuando el usuario decide salir
    // Pantalla de bienvenida inicial con estilo
    cout << "+=====================================+" << endl;
    cout << "|         BIENVENIDOS A ENFRENDADOS    |" << endl;
    cout << "|           EL JUEGO DE DADOS         |" << endl;
    cout << "+=====================================+" << endl;
    cout << "|  Por favor, ingresa tu nombre para  |" << endl;
    cout << "|           comenzar a jugar          |" << endl;
    cout << "+-------------------------------------+" << endl;
    // Pedir nombre del jugador 1
    jugador1 = pedirNombre("-> ");
    cout << endl;
    cout << endl;
    // Imprimir el banner de bienvenida
    imprimirBanner();
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "+---------------------------------------------------------------------------------------+" << endl;
    cout << "| Bienvenido, " << jugador1 << " Preparate para tirar los dados y demostrar tu suerte.  |" << endl;
    cout << "+---------------------------------------------------------------------------------------+" << endl;
    system("pause"); // Pausa despues de mostrar bienvenida

    do
    {
        // Mostramos el menu y obtenemos opcion del usuario
        opcionMenu = mostrarMenu();
        // Ejecutamos la accion segun la opcion del menu
        switch (opcionMenu)
        {
        case 1:
        {
            mostrarSeccion("Enfrendados de a Dos", "Has seleccionado jugar con 2 jugadores.\n");

            // Pedimos el nombre del jugador nro 2
            cout << "+=====================================+" << endl;
            cout << "|   INGRESE NOMBRE DEL JUGADOR 2      |" << endl;
            cout << "+=====================================+" << endl;
            jugador2 = pedirNombre("-> ");

            // Mostramos los jugadores
            cout << "\n";
            cout << "+=====================================+" << endl;
            cout << "|      JUGADORES REGISTRADOS          |" << endl;
            cout << "|-------------------------------------|" << endl;
            cout << "--> Jugador 1: " << jugador1 << endl;
            cout << "--> Jugador 2: " << jugador2 << endl;
            cout << "+=====================================+" << endl
                 << endl;

            system("pause"); // Pausa para que el usuario vea los nombres antes de continuar
            // Aca va la funcion del compañero designado
            cout << "\nLOGICA DE MIS COMPAS A CODIFICAR!!!\n";
            system("pause"); // Pausa antes de regresar al menu
            break;
        }
        case 2:
            mostrarSeccion("ESTADISTICAS", "Cargando estadisticas...\n");
            break;
        case 3:
            mostrarCreditos();
            break;
        case 0:
            salir = confirmarSalida();
            break;
        default:
            cout << "Opcion invalida. Intenta de nuevo." << endl;
            system("pause"); // Pausa para que el usuario vea el mensaje de error
        }
        // Continuar mostrando el menu hasta que salir sea true
    } while (!salir);

    return 0;
}