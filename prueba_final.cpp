#include <iostream>
#include <string>
using namespace std;

void mostrar_reglas() {
    cout << "\nREGLAS DEL JUEGO:\n";
    cout << "1. El juego consiste en turnos alternados entre dos jugadores.\n";
    cout << "2. En cada turno, un jugador puede quitar uno o mas objetos de una sola fila.\n";
    cout << "3. El jugador que quite el ultimo objeto pierde.\n";
    cout << "4. Si un jugador quita todos los objetos restantes, es empate y se da un punto a cada jugador.\n";
    cout << "5. El ganador recibe 3 puntos.\n\n";
}

bool menu_continuar() {
    int eleccion_menu;
    cout << "Continuar? 1.Si 2.No: ";
    cin >> eleccion_menu;
    switch (eleccion_menu) {
    case 1: {
        cout << "Reiniciando el tablero..." << endl
            << "..................." << endl
            << ".." << endl;
        return true;
    }
    case 2: {
        cout << "Volviendo al menu principal..." << endl
            << "..................." << endl
            << ".." << endl;
        return false;
    }
    default: {
        cout << "Opcion no valida, por favor elija 1 o 2." << endl;
        return menu_continuar();
    }
    }
}

void reiniciar_tablero(
    string& objeto_1, string& objeto_2, string& objeto_3, string& objeto_4,
    string& objeto_5, string& objeto_6, string& objeto_7, string& objeto_8,
    string& objeto_9, string& objeto_10, string& objeto_11, string& objeto_12,
    string& objeto_13, string& objeto_14, string& objeto_15) {

    objeto_1 = "[1]"; objeto_2 = "[2]"; objeto_3 = "[3]"; objeto_4 = "[4]";
    objeto_5 = "[5]"; objeto_6 = "[6]"; objeto_7 = "[7]"; objeto_8 = "[8]";
    objeto_9 = "[9]"; objeto_10 = "[10]"; objeto_11 = "[11]"; objeto_12 = "[12]";
    objeto_13 = "[13]"; objeto_14 = "[14]"; objeto_15 = "[15]";
}

void codigo_principal(
    int& turno, string& jugador_1, string& jugador_2,
    int& punteo_jugador_1, int& punteo_jugador_2) {

    string objeto_1 = "[1]", objeto_2 = "[2]", objeto_3 = "[3]", objeto_4 = "[4]";
    string objeto_5 = "[5]", objeto_6 = "[6]", objeto_7 = "[7]", objeto_8 = "[8]";
    string objeto_9 = "[9]", objeto_10 = "[10]", objeto_11 = "[11]", objeto_12 = "[12]";
    string objeto_13 = "[13]", objeto_14 = "[14]", objeto_15 = "[15]";

    bool partida_terminada = false;

    while (!partida_terminada) {
        int eleccion_objeto = 0, cantidad_objetos = 0, fila = 0;
        int disponibles_fila1 = (objeto_1 != "   ") + (objeto_2 != "   ") + (objeto_3 != "   ");
        int disponibles_fila2 = (objeto_4 != "   ") + (objeto_5 != "   ") + (objeto_6 != "   ") + (objeto_7 != "   ") + (objeto_8 != "   ");
        int disponibles_fila3 = (objeto_9 != "   ") + (objeto_10 != "   ") + (objeto_11 != "   ") + (objeto_12 != "   ") + (objeto_13 != "   ") + (objeto_14 != "   ") + (objeto_15 != "   ");

        int total_objetos = disponibles_fila1 + disponibles_fila2 + disponibles_fila3;

        if (jugador_1.empty() && jugador_2.empty()) {
            cout << "Ingrese nombre para jugador 1: ";
            cin >> jugador_1;
            cout << "Ingrese nombre para jugador 2: ";
            cin >> jugador_2;
        } else {
            cout << "Turno de " << (turno == 1 ? jugador_1 : jugador_2) << endl;
        }

        cout << endl << "Objetos disponibles:" << endl << endl;
        cout << "         " << objeto_1 << objeto_2 << objeto_3 << endl;
        cout << "      " << objeto_4 << objeto_5 << objeto_6 << objeto_7 << objeto_8 << endl;
        cout << objeto_9 << objeto_10 << objeto_11 << objeto_12 << objeto_13 << objeto_14 << objeto_15 << endl << endl;

        bool seleccion_valida = false;
        while (!seleccion_valida) {
            cout << "De que fila quieres quitar objetos? (1: Primera, 2: Segunda, 3: Tercera): ";
            cin >> fila;

            int disponibles = 0;
            if (fila == 1) disponibles = disponibles_fila1;
            else if (fila == 2) disponibles = disponibles_fila2;
            else if (fila == 3) disponibles = disponibles_fila3;

            if (disponibles > 0) {
                cout << "Cuantos objetos retirara (disponible " << disponibles << ")? ";
                cin >> cantidad_objetos;
                if (cantidad_objetos > 0 && cantidad_objetos <= disponibles) {
                    seleccion_valida = true;
                }
            }

            if (!seleccion_valida) {
                cout << "Cantidad no valida o fila incorrecta. Intente de nuevo." << endl;
            }
        }

        for (int j = 0; j < cantidad_objetos; j++) {
            bool objeto_valido = false;
            while (!objeto_valido) {
                cout << "Elija un objeto para quitar de la fila " << fila << ": ";
                cin >> eleccion_objeto;
                if (fila == 1) {
                    if (eleccion_objeto == 1 && objeto_1 != "   ") { objeto_1 = "   "; objeto_valido = true; }
                    else if (eleccion_objeto == 2 && objeto_2 != "   ") { objeto_2 = "   "; objeto_valido = true; }
                    else if (eleccion_objeto == 3 && objeto_3 != "   ") { objeto_3 = "   "; objeto_valido = true; }
                } else if (fila == 2) {
                    if (eleccion_objeto == 4 && objeto_4 != "   ") { objeto_4 = "   "; objeto_valido = true; }
                    else if (eleccion_objeto == 5 && objeto_5 != "   ") { objeto_5 = "   "; objeto_valido = true; }
                    else if (eleccion_objeto == 6 && objeto_6 != "   ") { objeto_6 = "   "; objeto_valido = true; }
                    else if (eleccion_objeto == 7 && objeto_7 != "   ") { objeto_7 = "   "; objeto_valido = true; }
                    else if (eleccion_objeto == 8 && objeto_8 != "   ") { objeto_8 = "   "; objeto_valido = true; }
                } else if (fila == 3) {
                    if (eleccion_objeto == 9 && objeto_9 != "   ") { objeto_9 = "   "; objeto_valido = true; }
                    else if (eleccion_objeto == 10 && objeto_10 != "   ") { objeto_10 = "   "; objeto_valido = true; }
                    else if (eleccion_objeto == 11 && objeto_11 != "   ") { objeto_11 = "   "; objeto_valido = true; }
                    else if (eleccion_objeto == 12 && objeto_12 != "   ") { objeto_12 = "   "; objeto_valido = true; }
                    else if (eleccion_objeto == 13 && objeto_13 != "   ") { objeto_13 = "   "; objeto_valido = true; }
                    else if (eleccion_objeto == 14 && objeto_14 != "   ") { objeto_14 = "   "; objeto_valido = true; }
                    else if (eleccion_objeto == 15 && objeto_15 != "   ") { objeto_15 = "   "; objeto_valido = true; }
                }
                if (!objeto_valido) {
                    cout << "Objeto no disponible. Intente de nuevo." << endl;
                }
            }
        }

        disponibles_fila1 = (objeto_1 != "   ") + (objeto_2 != "   ") + (objeto_3 != "   ");
        disponibles_fila2 = (objeto_4 != "   ") + (objeto_5 != "   ") + (objeto_6 != "   ") + (objeto_7 != "   ") + (objeto_8 != "   ");
        disponibles_fila3 = (objeto_9 != "   ") + (objeto_10 != "   ") + (objeto_11 != "   ") + (objeto_12 != "   ") + (objeto_13 != "   ") + (objeto_14 != "   ") + (objeto_15 != "   ");
        total_objetos = disponibles_fila1 + disponibles_fila2 + disponibles_fila3;

        if (total_objetos == 0) {
            if (cantidad_objetos == 1) {
                if (turno == 1) {
                    cout << "Gana " << jugador_2;
                    punteo_jugador_2 += 3;
                } else {
                    cout << "Gana " << jugador_1;
                    punteo_jugador_1 += 3;
                }
            } else {
                cout << "Empate" << endl;
                punteo_jugador_1++;
                punteo_jugador_2++;
            }

            cout << endl << "Marcador final de la partida:" << endl;
            cout << jugador_1 << ": " << punteo_jugador_1 << " puntos" << endl;
            cout << jugador_2 << ": " << punteo_jugador_2 << " puntos" << endl;
            partida_terminada = true;
            break;
        }

        turno = (turno == 1) ? 2 : 1;
    }
}

int main() {
    int turno = 1;
    int opcion_menu;
    string jugador_1 = "", jugador_2 = "";
    int punteo_jugador_1 = 0, punteo_jugador_2 = 0;

    cout << endl << "            ..oo$00ooo..                    ..ooo00$oo.." << endl;
    cout << "                .o$$$$$$$$$'                          '$$$$$$$$$o." << endl;
    cout << "             .o$$$$$$$$$\"             .   .              \"$$$$$$$$$o." << endl;
    cout << "           .o$$$$$$$$$$~             /$   $\\              ~$$$$$$$$$$o." << endl;
    cout << "         .{$$$$$$$$$$$.              $\\___/$               .$$$$$$$$$$$}." << endl;
    cout << "        o$$$$$$$$$$$$8              .$$$$$$$.               8$$$$$$$$$$$$o" << endl;
    cout << "       $$$$$$$$$$$$$$$              $$$$$$$$$               $$$$$$$$$$$$$$$" << endl;
    cout << "      o$$$$$$$$$$$$$$$.             o$$$$$$$o              .$$$$$$$$$$$$$$$o" << endl;
    cout << "      $$$$$$$$$$$$$$$$$.           o{$$$$$$$}o            .$$$$$$$$$$$$$$$$$" << endl;
    cout << "     ^$$$$$$$$$$$$$$$$$$.         J$$$$$$$$$$$L          .$$$$$$$$$$$$$$$$$$^" << endl;
    cout << "     !$$$$$$$$$$$$$$$$$$$$oo..oo$$$$$$$$$$$$$$$$$oo..oo$$$$$$$$$$$$$$$$$$$$$!" << endl;
    cout << "     {$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$}" << endl;
    cout << "     6$$$$$$$$$$$$$$$$$$$$$$$    BIENVENIDOS AL JUEGO   $$$$$$$$$$$$$$$$$$$$?" << endl;
    cout << "     '$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'" << endl;
    cout << "      o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o" << endl;
    cout << "       $$$$$$$$$$$$$$;'~`^Y$$$7^''o$$$$$$$$$$$o''^Y$$$7^`~';$$$$$$$$$$$$$$$" << endl;
    cout << "       '$$$$$$$$$$$'       `$'    `'$$$$$$$$$'     `$'       '$$$$$$$$$$$$'" << endl;
    cout << "        !$$$$$$$$$7         !       '$$$$$$$'       !         V$$$$$$$$$!" << endl;
    cout << "         ^o$$$$$$!                   '$$$$$'                   !$$$$$$o^" << endl;
    cout << "           ^$$$$$\"                    $$$$$                    \"$$$$$^" << endl;
    cout << "             'o$$$`                   ^$$$'                   '$$$o'" << endl;
    cout << "               ~$$$.                   $$$.                  .$$$~" << endl;
    cout << "                 '$;.                  `$'                  .;$'" << endl;
    cout << "                    '.                  !                  .`" << endl;


    do {
        cout << "-----------------------" << endl;
        cout << "| 1. Iniciar juego    |" << endl;
        cout << "| 2. Reglas del juego |" << endl;
        cout << "| 3. Salir del juego  |" << endl;
        cout << "_______________________" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion_menu;

        switch (opcion_menu) {
            case 1: {
                bool continuar_jugando = true;
                do {
                    codigo_principal(turno, jugador_1, jugador_2, punteo_jugador_1, punteo_jugador_2);
                    continuar_jugando = menu_continuar();
                } while (continuar_jugando);
                break;
            }
            case 2: {
                mostrar_reglas();
                break;
            }
            case 3: {
                cout << "Saliendo del juego..." << endl;
                return 0;
            }
            default: {
                cout << "Opcion no valida. Por favor ingrese 1, 2 o 3." << endl;
                break;
            }
        }
    } while (true);

    return 0;
}