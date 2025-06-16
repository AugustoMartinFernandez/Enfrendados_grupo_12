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
    imprimirBanner();
    mostrarBienvenida();
    jugadores[0] = pedirNombre("-> ");
    imprimirBannerBienvenida(jugadores[0]);
    imprimirBanner();

    do {
      salir = mostrarMenu(jugadores);
    } while (!salir);

    return 0;
}
