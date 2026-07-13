#include <iostream>
#include <ctime>
#include <string>
#include "rlutil.h"
#include "funcionesInterfazUsuario.h"
#include "funcionesLogicaJuego.h"
using namespace std;

int main()
{
    srand(time(nullptr));
    //------VARIABLES---------
    string jugadores[2];
    bool salir = false;
    // El estado vive aca, en main, para que dure toda la sesion
    int puntos[2] = {0, 0};

    mostrarBienvenida();
    jugadores[0] = pedirNombre("-> ");
    imprimirBannerBienvenida(jugadores[0]);
    imprimirBanner();

    do {
      salir = mostrarMenu(jugadores, puntos);
    } while (!salir);

    return 0;
}
