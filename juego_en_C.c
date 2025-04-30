#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void mostrar_reglas() {
    printf("\nREGLAS DEL JUEGO:\n");
    printf("1. El juego consiste en turnos alternados entre dos jugadores.\n");
    printf("2. En cada turno, un jugador puede quitar uno o mas objetos de una sola fila.\n");
    printf("3. El jugador que quite el ultimo objeto pierde.\n");
    printf("4. Si un jugador quita todos los objetos restantes, es empate y se da un punto a cada jugador.\n");
    printf("5. El ganador recibe 3 puntos.\n\n");
}

bool menu_continuar() {
    int eleccion_menu;
    printf("Continuar? 1.Si 2.No: ");
    scanf("%d", &eleccion_menu);
    switch (eleccion_menu) {
    case 1: {
        printf("Reiniciando el tablero...\n");
        printf("...................\n");
        printf("..\n");
        return true;
    }
    case 2: {
        printf("Volviendo al menu principal...\n");
        printf("...................\n");
        printf("..\n");
        return false;
    }
    default: {
        printf("Opcion no valida, por favor elija 1 o 2.\n");
        return menu_continuar();
    }
    }
}

void reiniciar_tablero(
    char objeto_1[], char objeto_2[], char objeto_3[], char objeto_4[],
    char objeto_5[], char objeto_6[], char objeto_7[], char objeto_8[],
    char objeto_9[], char objeto_10[], char objeto_11[], char objeto_12[],
    char objeto_13[], char objeto_14[], char objeto_15[]) {

    strcpy(objeto_1, "[1]"); strcpy(objeto_2, "[2]"); strcpy(objeto_3, "[3]"); strcpy(objeto_4, "[4]");
    strcpy(objeto_5, "[5]"); strcpy(objeto_6, "[6]"); strcpy(objeto_7, "[7]"); strcpy(objeto_8, "[8]");
    strcpy(objeto_9, "[9]"); strcpy(objeto_10, "[10]"); strcpy(objeto_11, "[11]"); strcpy(objeto_12, "[12]");
    strcpy(objeto_13, "[13]"); strcpy(objeto_14, "[14]"); strcpy(objeto_15, "[15]");
}

void codigo_principal(
    int* turno, char jugador_1[], char jugador_2[],
    int* punteo_jugador_1, int* punteo_jugador_2) {

    char objeto_1[5], objeto_2[5], objeto_3[5], objeto_4[5];
    char objeto_5[5], objeto_6[5], objeto_7[5], objeto_8[5];
    char objeto_9[5], objeto_10[5], objeto_11[5], objeto_12[5];
    char objeto_13[5], objeto_14[5], objeto_15[5];

    strcpy(objeto_1, "[1]"); strcpy(objeto_2, "[2]"); strcpy(objeto_3, "[3]"); strcpy(objeto_4, "[4]");
    strcpy(objeto_5, "[5]"); strcpy(objeto_6, "[6]"); strcpy(objeto_7, "[7]"); strcpy(objeto_8, "[8]");
    strcpy(objeto_9, "[9]"); strcpy(objeto_10, "[10]"); strcpy(objeto_11, "[11]"); strcpy(objeto_12, "[12]");
    strcpy(objeto_13, "[13]"); strcpy(objeto_14, "[14]"); strcpy(objeto_15, "[15]");

    bool partida_terminada = false;

    while (!partida_terminada) {
        int eleccion_objeto = 0, cantidad_objetos = 0, fila = 0;
        int disponibles_fila1 = (strcmp(objeto_1, "   ") != 0) + (strcmp(objeto_2, "   ") != 0) + (strcmp(objeto_3, "   ") != 0);
        int disponibles_fila2 = (strcmp(objeto_4, "   ") != 0) + (strcmp(objeto_5, "   ") != 0) + (strcmp(objeto_6, "   ") != 0) + 
                               (strcmp(objeto_7, "   ") != 0) + (strcmp(objeto_8, "   ") != 0);
        int disponibles_fila3 = (strcmp(objeto_9, "   ") != 0) + (strcmp(objeto_10, "   ") != 0) + (strcmp(objeto_11, "   ") != 0) + 
                               (strcmp(objeto_12, "   ") != 0) + (strcmp(objeto_13, "   ") != 0) + 
                               (strcmp(objeto_14, "   ") != 0) + (strcmp(objeto_15, "   ") != 0);

        int total_objetos = disponibles_fila1 + disponibles_fila2 + disponibles_fila3;

        if (strlen(jugador_1) == 0 && strlen(jugador_2) == 0) {
            printf("Ingrese nombre para jugador 1: ");
            scanf("%s", jugador_1);
            printf("Ingrese nombre para jugador 2: ");
            scanf("%s", jugador_2);
        } else {
            printf("Turno de %s\n", (*turno == 1 ? jugador_1 : jugador_2));
        }

        printf("\nObjetos disponibles:\n\n");
        printf("         %s%s%s\n", objeto_1, objeto_2, objeto_3);
        printf("      %s%s%s%s%s\n", objeto_4, objeto_5, objeto_6, objeto_7, objeto_8);
        printf("%s%s%s%s%s%s%s\n\n", objeto_9, objeto_10, objeto_11, objeto_12, objeto_13, objeto_14, objeto_15);

        bool seleccion_valida = false;
        while (!seleccion_valida) {
            printf("De que fila quieres quitar objetos? (1: Primera, 2: Segunda, 3: Tercera): ");
            scanf("%d", &fila);

            int disponibles = 0;
            if (fila == 1) disponibles = disponibles_fila1;
            else if (fila == 2) disponibles = disponibles_fila2;
            else if (fila == 3) disponibles = disponibles_fila3;

            if (disponibles > 0) {
                printf("Cuantos objetos retirara (disponible %d)? ", disponibles);
                scanf("%d", &cantidad_objetos);
                if (cantidad_objetos > 0 && cantidad_objetos <= disponibles) {
                    seleccion_valida = true;
                }
            }

            if (!seleccion_valida) {
                printf("Cantidad no valida o fila incorrecta. Intente de nuevo.\n");
            }
        }

        for (int j = 0; j < cantidad_objetos; j++) {
            bool objeto_valido = false;
            while (!objeto_valido) {
                printf("Elija un objeto para quitar de la fila %d: ", fila);
                scanf("%d", &eleccion_objeto);
                if (fila == 1) {
                    if (eleccion_objeto == 1 && strcmp(objeto_1, "   ") != 0) { strcpy(objeto_1, "   "); objeto_valido = true; }
                    else if (eleccion_objeto == 2 && strcmp(objeto_2, "   ") != 0) { strcpy(objeto_2, "   "); objeto_valido = true; }
                    else if (eleccion_objeto == 3 && strcmp(objeto_3, "   ") != 0) { strcpy(objeto_3, "   "); objeto_valido = true; }
                } else if (fila == 2) {
                    if (eleccion_objeto == 4 && strcmp(objeto_4, "   ") != 0) { strcpy(objeto_4, "   "); objeto_valido = true; }
                    else if (eleccion_objeto == 5 && strcmp(objeto_5, "   ") != 0) { strcpy(objeto_5, "   "); objeto_valido = true; }
                    else if (eleccion_objeto == 6 && strcmp(objeto_6, "   ") != 0) { strcpy(objeto_6, "   "); objeto_valido = true; }
                    else if (eleccion_objeto == 7 && strcmp(objeto_7, "   ") != 0) { strcpy(objeto_7, "   "); objeto_valido = true; }
                    else if (eleccion_objeto == 8 && strcmp(objeto_8, "   ") != 0) { strcpy(objeto_8, "   "); objeto_valido = true; }
                } else if (fila == 3) {
                    if (eleccion_objeto == 9 && strcmp(objeto_9, "   ") != 0) { strcpy(objeto_9, "   "); objeto_valido = true; }
                    else if (eleccion_objeto == 10 && strcmp(objeto_10, "   ") != 0) { strcpy(objeto_10, "   "); objeto_valido = true; }
                    else if (eleccion_objeto == 11 && strcmp(objeto_11, "   ") != 0) { strcpy(objeto_11, "   "); objeto_valido = true; }
                    else if (eleccion_objeto == 12 && strcmp(objeto_12, "   ") != 0) { strcpy(objeto_12, "   "); objeto_valido = true; }
                    else if (eleccion_objeto == 13 && strcmp(objeto_13, "   ") != 0) { strcpy(objeto_13, "   "); objeto_valido = true; }
                    else if (eleccion_objeto == 14 && strcmp(objeto_14, "   ") != 0) { strcpy(objeto_14, "   "); objeto_valido = true; }
                    else if (eleccion_objeto == 15 && strcmp(objeto_15, "   ") != 0) { strcpy(objeto_15, "   "); objeto_valido = true; }
                }
                if (!objeto_valido) {
                    printf("Objeto no disponible. Intente de nuevo.\n");
                }
            }
        }

        disponibles_fila1 = (strcmp(objeto_1, "   ") != 0) + (strcmp(objeto_2, "   ") != 0) + (strcmp(objeto_3, "   ") != 0);
        disponibles_fila2 = (strcmp(objeto_4, "   ") != 0) + (strcmp(objeto_5, "   ") != 0) + (strcmp(objeto_6, "   ") != 0) + 
                           (strcmp(objeto_7, "   ") != 0) + (strcmp(objeto_8, "   ") != 0);
        disponibles_fila3 = (strcmp(objeto_9, "   ") != 0) + (strcmp(objeto_10, "   ") != 0) + (strcmp(objeto_11, "   ") != 0) + 
                           (strcmp(objeto_12, "   ") != 0) + (strcmp(objeto_13, "   ") != 0) + 
                           (strcmp(objeto_14, "   ") != 0) + (strcmp(objeto_15, "   ") != 0);
        total_objetos = disponibles_fila1 + disponibles_fila2 + disponibles_fila3;

        if (total_objetos == 0) {
            if (cantidad_objetos == 1) {
                if (*turno == 1) {
                    printf("Gana %s", jugador_2);
                    (*punteo_jugador_2) += 3;
                } else {
                    printf("Gana %s", jugador_1);
                    (*punteo_jugador_1) += 3;
                }
            } else {
                printf("Empate\n");
                (*punteo_jugador_1)++;
                (*punteo_jugador_2)++;
            }

            printf("\nMarcador final de la partida:\n");
            printf("%s: %d puntos\n", jugador_1, *punteo_jugador_1);
            printf("%s: %d puntos\n", jugador_2, *punteo_jugador_2);
            partida_terminada = true;
            break;
        }

        *turno = (*turno == 1) ? 2 : 1;
    }
}

int main() {
    int turno = 1;
    int opcion_menu;
    char jugador_1[50] = "";
    char jugador_2[50] = "";
    int punteo_jugador_1 = 0, punteo_jugador_2 = 0;

    printf("\n            ..oo$00ooo..                    ..ooo00$oo..\n");
    printf("                .o$$$$$$$$$'                          '$$$$$$$$$o.\n");
    printf("             .o$$$$$$$$$\"             .   .              \"$$$$$$$$$o.\n");
    printf("           .o$$$$$$$$$$~             /$   $\\              ~$$$$$$$$$$o.\n");
    printf("         .{$$$$$$$$$$$.              $\\___/$               .$$$$$$$$$$$}.\n");
    printf("        o$$$$$$$$$$$$8              .$$$$$$$.               8$$$$$$$$$$$$o\n");
    printf("       $$$$$$$$$$$$$$$              $$$$$$$$$               $$$$$$$$$$$$$$$\n");
    printf("      o$$$$$$$$$$$$$$$.             o$$$$$$$o              .$$$$$$$$$$$$$$$o\n");
    printf("      $$$$$$$$$$$$$$$$$.           o{$$$$$$$}o            .$$$$$$$$$$$$$$$$$\n");
    printf("     ^$$$$$$$$$$$$$$$$$$.         J$$$$$$$$$$$L          .$$$$$$$$$$$$$$$$$$^\n");
    printf("     !$$$$$$$$$$$$$$$$$$$$oo..oo$$$$$$$$$$$$$$$$$oo..oo$$$$$$$$$$$$$$$$$$$$$!\n");
    printf("     {$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$}\n");
    printf("     6$$$$$$$$$$$$$$$$$$$$$$$    BIENVENIDOS AL JUEGO   $$$$$$$$$$$$$$$$$$$$?\n");
    printf("     '$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'\n");
    printf("      o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o\n");
    printf("       $$$$$$$$$$$$$$;'~`^Y$$$7^''o$$$$$$$$$$$o''^Y$$$7^`~';$$$$$$$$$$$$$$$\n");
    printf("       '$$$$$$$$$$$'       `$'    `'$$$$$$$$$'     `$'       '$$$$$$$$$$$$'\n");
    printf("        !$$$$$$$$$7         !       '$$$$$$$'       !         V$$$$$$$$$!\n");
    printf("         ^o$$$$$$!                   '$$$$$'                   !$$$$$$o^\n");
    printf("           ^$$$$$\"                    $$$$$                    \"$$$$$^\n");
    printf("             'o$$$`                   ^$$$'                   '$$$o'\n");
    printf("               ~$$$.                   $$$.                  .$$$~\n");
    printf("                 '$;.                  `$'                  .;$'\n");
    printf("                    '.                  !                  .`\n");

    do {
        printf("-----------------------\n");
        printf("| 1. Iniciar juego    |\n");
        printf("| 2. Reglas del juego |\n");
        printf("| 3. Salir del juego  |\n");
        printf("_______________________\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion_menu);

        switch (opcion_menu) {
            case 1: {
                bool continuar_jugando = true;
                do {
                    codigo_principal(&turno, jugador_1, jugador_2, &punteo_jugador_1, &punteo_jugador_2);
                    continuar_jugando = menu_continuar();
                } while (continuar_jugando);
                break;
            }
            case 2: {
                mostrar_reglas();
                break;
            }
            case 3: {
                printf("Saliendo del juego...\n");
                return 0;
            }
            default: {
                printf("Opcion no valida. Por favor ingrese 1, 2 o 3.\n");
                break;
            }
        }
    } while (true);

    return 0;
}