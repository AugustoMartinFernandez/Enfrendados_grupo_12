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

    string jugador1, jugador2; // Variable para guardar nombre del usuario1 y 2

    int opcionMenu; // Variable para opcion de menu

    bool salir = false; // Variable bandera para controlar el ciclo del menu cambia a true cuando el usuario decide salir






    mostrarBienvenida();

    jugador1 = pedirNombre("-> "); // Pedir nombre del jugador 1

    imprimirBannerBienvenida(jugador1);

    imprimirBanner();


    do
    {
        /// Mostramos el menu y obtenemos opcion del usuario
        opcionMenu = mostrarMenu();
        /// Ejecutamos la accion segun la opcion del menu

        switch (opcionMenu)
        {
        case 1:
        {
            int resultadoUno = 0, resultadoDos = 0; //  Los inicializo en 0 para hacer el bucle while por si la tirada de dado en el sorteo da el mismo numero
            string primero, segundo;
            imprimirBanner();
            mostrarSeccion("Enfrendados de a Dos", "Has seleccionado jugar con 2 jugadores.\n");

            /// Pedimos el nombre del jugador nro 2
            imprimirBanner();
            bannerJugadorDos();
            jugador2 = pedirNombre("-> ");

            imprimirBanner();

            /// Mostramos los jugadores
            bannerJugadoresRegistrados(jugador1,jugador2);
            system("pause"); /// Pausa para que el usuario vea los nombres antes de continuar
        /// Aca va la funcion del compañero designado
            imprimirBanner();

//////////////////////////SORTEO/////////////////////////////////////////

            bannerSorteo();

            while (resultadoUno == resultadoDos)
            { //  El bucle es para que si da numeros iguales se repita
                cout << jugador1 << " tire dado." << endl<< endl;

                system("pause");
                imprimirBanner();
                resultadoUno = tirarDados6Caras(); ///tomo el retorno de la funcion en una variable asi los puedo comparar

                cout << "Su numero es: " << resultadoUno << endl<< endl;

                system("pause");
                imprimirBanner();

                cout << jugador2 << " tire dado." << endl<< endl;

                system("pause");
                imprimirBanner();
                resultadoDos = tirarDados6Caras(); ///tomo el retorno de la funcion en una variable asi los puedo comparar
                cout << "Su numero es: " << resultadoDos << endl<< endl;
                system("pause");
            }
            imprimirBanner();
            cout << "El primero en jugar es: ";

            if (resultadoUno > resultadoDos){
                primero = jugador1;
                segundo = jugador2;
            }
            else{
                primero = jugador2;
                segundo = jugador1;
            }
            cout << primero << endl<< endl;
            system("pause");

///////////////////////////JUEGO/////////////////////////////////////////////////

            imprimirBanner();

            int dadosPrimero[11], dadosSegundo[11];
            int primerDado, segundoDado, numeroObjetivo = 0;

            cout << "Tire los dados de doce caras para saber su numero objetivo" << endl<< endl;
            system("pause");

            imprimirBanner();

            primerDado = tirarDados12Caras();
            segundoDado = tirarDados12Caras();
            numeroObjetivo = primerDado + segundoDado;
            cout << endl << primerDado << "    " << segundoDado << endl << endl;
            cout << "El numero objetivo es: " << numeroObjetivo << endl << endl;
            system("pause"); // Pausa antes de regresar al menu

            imprimirBanner();

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
