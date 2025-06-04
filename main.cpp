#include <iostream>
#include <ctime>
#include <string>
#include "rlutil.h"
#include "funciones.h"
#include "funcionesLogicaJuego.h"

using namespace std;

int main()
{
    /**
se declara srand(time(nullptr)) para que no repita el mismo num
y cambie con la hora, entonces siempre da un num diferente
se declara una sola vez
*/
    srand(time(nullptr));

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

    cout << "+---------------------------------------------------------------------------------------+" << endl;
    cout << "| Bienvenido, " << jugador1 << " Preparate para tirar los dados y demostrar tu suerte.  |" << endl;
    cout << "+---------------------------------------------------------------------------------------+" << endl;
    system("pause"); // Pausa despues de mostrar bienvenida
    rlutil::cls();
        // Imprimir el banner de bienvenida
    imprimirBanner();


    do
    {
        // Mostramos el menu y obtenemos opcion del usuario
        opcionMenu = mostrarMenu();
        // Ejecutamos la accion segun la opcion del menu

        switch (opcionMenu)
        {
        case 1:
        {
            int resultadoUno = 0, resultadoDos = 0; //  Los inicializo en 0 para hacer el bucle
            string primero, segundo;
            rlutil::cls();
            imprimirBanner();
            mostrarSeccion("Enfrendados de a Dos", "Has seleccionado jugar con 2 jugadores.\n");

            // Pedimos el nombre del jugador nro 2
            rlutil::cls();
            imprimirBanner();
            cout << "+=====================================+" << endl;
            cout << "|   INGRESE NOMBRE DEL JUGADOR 2      |" << endl;
            cout << "+=====================================+" << endl;
            jugador2 = pedirNombre("-> ");

            // Mostramos los jugadores
            rlutil::cls();
            imprimirBanner();
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
            rlutil::cls();
            imprimirBanner();
            cout << endl;
            cout << "Sorteo" << endl;
            cout << "=======" << endl
                 << endl;

            while (resultadoUno == resultadoDos)
            { //  El bucle es para que si da numeros iguales se repita
                cout << jugador1 << " tire dado." << endl
                     << endl;
                system("pause");
                rlutil::cls();
                imprimirBanner();
                resultadoUno = tirarDados6Caras();
                cout << "Su numero es: " << resultadoUno << endl
                     << endl;
                system("pause");
                rlutil::cls();
                imprimirBanner();
                cout << jugador2 << " tire dado." << endl
                     << endl;
                system("pause");
                rlutil::cls();
                imprimirBanner();
                resultadoDos = tirarDados6Caras();
                cout << "Su numero es: " << resultadoDos << endl
                     << endl;
                system("pause");
                rlutil::cls();
            }
            rlutil::cls();
            imprimirBanner();
            cout << "El primero en jugar es: ";

            if (resultadoUno > resultadoDos)
            {
                primero = jugador1;
                segundo = jugador2;
            }
            else
            {
                primero = jugador2;
                segundo = jugador1;
            }
            cout << primero << endl
                 << endl;
            system("pause");
            rlutil::cls();
            imprimirBanner();

            int dadosPrimero[11], dadosSegundo[11];
            int primerDado, segundoDado, numeroObjetivo = 0;

            cout << "Tire los dados de doce caras para saber su numero objetivo" << endl
                 << endl;
            system("pause");
            rlutil::cls();

            primerDado = tirarDados12Caras();
            segundoDado = tirarDados12Caras();
            numeroObjetivo = primerDado + segundoDado;
            cout << endl
                 << primerDado << "    " << segundoDado << endl
                 << endl;
            cout << "El numero objetivo es: " << numeroObjetivo << endl
                 << endl;
            system("pause"); // Pausa antes de regresar al menu
            rlutil::cls();
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
