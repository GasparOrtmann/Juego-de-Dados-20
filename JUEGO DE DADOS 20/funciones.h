#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "rlutil.h"
#include <windows.h>

using namespace std;
#define ABAJO 80
#define ARRIBA 72
#define ENTER 13

/// DECLARACIÓN/PROTOTIPO DE FUNCIONES
void menu();
void fin();
void unJugador();
void dosJugadores();

void recuadro();
void PasoDeTurno();
void tituloAnimado();
int MenuPrincipalGenerala();
void cargarAleatorio();
void mostrarVector();
int maximoVector();
void generadorPuntos();
int cargarDados();

/// Desarrollo de funciones / Definiciones


///MENU PRINCIPAL y DISEÑO DEL JUEGO
void PasoDeTurno() { ///Recuadro de informacíon
    int i, j;
    rlutil::setColor(rlutil::BLUE);
    for (i = 30; i <= 100; i++) {
        rlutil::locate(i, 5); printf("%c", 205);
        rlutil::locate(i, 25); printf("%c", 205);
        for (j = 5; j <= 25; j++) {
            rlutil::locate(30, j); printf("%c", 186);
            rlutil::locate(100, j); printf("%c", 186);
        }
    }
    rlutil::locate(30, 25); printf("%c", 200); //ABAJO A LA IZQUIERDA
    rlutil::locate(30, 5); printf("%c", 201); //ARRIBA A LA IZQUIERDA
    rlutil::locate(100, 5); printf("%c", 187); //ARRIBA A LA DERECHA
    rlutil::locate(100, 25); printf("%c", 188); //ABAJO A LA DERECHA
    cout << endl;
    cout << endl;
}

void recuadro() { ///Recuadro de informacíon
    int i, j;
    rlutil::setColor(rlutil::BLUE);
    for (i = 30; i <= 100; i++) {
        rlutil::locate(i, 5); printf("%c", 205);
        rlutil::locate(i, 25); printf("%c", 205);
        for (j = 5; j <= 25; j++) {
            rlutil::locate(30, j); printf("%c", 186);
            rlutil::locate(100, j); printf("%c", 186);
        }
    }
    /* rlutil::locate(30, 30); printf("%c", 200); //ABAJO A LA IZQUIERDA
    rlutil::locate(30, 10); printf("%c", 201); //ARRIBA A LA IZQUIERDA
    rlutil::locate(100, 10); printf("%c", 187); //ARRIBA A LA DERECHA
    rlutil::locate(100, 30); printf("%c", 188); //ABAJO A LA DERECHA */
    cout << endl;
    cout << endl;
}

void tituloAnimado() {
    int xcol;
    /// SEGUNDA LINEA
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(14, 2); printf("%c", 201);
    rlutil::locate(14, 3); printf("%c", 186);
    rlutil::locate(14, 4); printf("%c", 200);

    for (xcol = 15; xcol <= 116; xcol++) {
        rlutil::locate(xcol, 2); printf("%c", 205);
        rlutil::locate(xcol, 4); printf("%c", 205);
        Sleep(1);
    }
    rlutil::locate(116, 2); printf("%c", 187);
    rlutil::locate(116, 3); printf("%c", 186);
    rlutil::locate(116, 4); printf("%c", 188);
    ///SEGUNDA LINEA
    char vtitulo[] = "JUEGO DE DADOS 20";
    int vlongitud;
    vlongitud = strlen(vtitulo);
    int vcentro = (((80 - vlongitud) / 2) + 1);

    for (xcol = 55; xcol <= vcentro; xcol++) {
    }
        rlutil::locate(xcol, 3); printf(vtitulo);
    }

int MenuPrincipal() {
    int x = 55, y = 13;
    tituloAnimado();
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::RED);
    rlutil::locate(50, 12); cout << endl;
    rlutil::locate(50, 13); cout << "      1. Juego nuevo para un jugador." << endl;
    rlutil::locate(50, 14); cout << "      2. Juego nuevo para dos jugadores." << endl;
    rlutil::locate(50, 15); cout << "      3. Mostrar puntuacion mas alta." << endl;
    rlutil::locate(50, 16); cout << "      4. Modo simulado (carga de dados manual)." << endl;
    rlutil::locate(50, 17); cout << "      0. Salir del juego." << endl;
    rlutil::locate(31, 23); cout << "Hecho por: Gaspar Ortmann";
    rlutil::locate(31, 24); cout << "Estudiante de TUP en UTN FRGP";
    PasoDeTurno();

  rlutil::locate(x, y); printf("*"); ///funcionamiento de las flechas del teclado
    bool elegir = false;
    while (!elegir) {
        if (_kbhit()) {
            rlutil::locate(x, y); printf(" ");
            char tecla = _getch();
            if (tecla == ENTER) { elegir = true; return y; }
            if (tecla == ARRIBA && y > 13) rlutil::locate(x, y--);
            if (tecla == ABAJO && y < 17) rlutil::locate(x, y++);
            rlutil::locate(x, y); printf("*");
        }
    }
}

void dadouno() { /// la funcion que dibuja al dado en la primera posicion

    /// HORIZONTAL
    for (int i = 2; i < 10; i++) {
        rlutil::locate(i, 3); printf("%c", 205);
        rlutil::locate(i, 7); printf("%c", 205);
    }
    /// VERTICAL
    for (int i = 4; i < 7; i++) {
        rlutil::locate(2, i); printf("%c", 186);
        rlutil::locate(10, i); printf("%c", 186);
    }
    ///ESQUINAS
        rlutil::locate(2, 3); printf("%c", 201);
        rlutil::locate(2, 7); printf("%c", 200);
        rlutil::locate(10, 3); printf("%c", 187);
        rlutil::locate(10, 7); printf("%c", 188);
}

void dadoDos() {// la funcion que dibuja al dado en la segunda posicion

    // HORIZONTAL
    for (int i = 13; i < 20; i++) {
        rlutil::locate(i, 3); printf("%c", 205);
        rlutil::locate(i, 7); printf("%c", 205);
    }
    // VERTICAL
    for (int i = 4; i < 7; i++) {
        rlutil::locate(12, i); printf("%c", 186);
        rlutil::locate(20, i); printf("%c", 186);
    }
    //ESQUINAS
    rlutil::locate(12, 3); printf("%c", 201);
    rlutil::locate(12, 7); printf("%c", 200);
    rlutil::locate(20, 3); printf("%c", 187);
    rlutil::locate(20, 7); printf("%c", 188);
}

void dadoTres() {// la funcion que dibuja al dado en la tercera posicion

    // HORIZONTAL
    for (int i = 23; i < 30; i++) {
        rlutil::locate(i, 3); printf("%c", 205);
        rlutil::locate(i, 7); printf("%c", 205);
    }
    // VERTICAL
    for (int i = 4; i < 7; i++) {
        rlutil::locate(22, i); printf("%c", 186);
        rlutil::locate(30, i); printf("%c", 186);
    }
    //ESQUINAS
    rlutil::locate(22, 3); printf("%c", 201);
    rlutil::locate(22, 7); printf("%c", 200);
    rlutil::locate(30, 3); printf("%c", 187);
    rlutil::locate(30, 7); printf("%c", 188);
}

void dadoCuatro() {// la funcion que dibuja al dado en la cuarta posicion

    // HORIZONTAL
    for (int i = 32; i < 40; i++) {
        rlutil::locate(i, 3); printf("%c", 205);
        rlutil::locate(i, 7); printf("%c", 205);
    }
    // VERTICAL
    for (int i = 4; i < 7; i++) {
        rlutil::locate(32, i); printf("%c", 186);
        rlutil::locate(40, i); printf("%c", 186);
    }
    //ESQUINAS
    rlutil::locate(32, 3); printf("%c", 201);
    rlutil::locate(32, 7); printf("%c", 200);
    rlutil::locate(40, 3); printf("%c", 187);
    rlutil::locate(40, 7); printf("%c", 188);
}

void dadoCinco() {// la funcion que dibuja al dado en la quinta posicion

    // HORIZONTAL
    for (int i = 42; i < 50; i++) {
        rlutil::locate(i, 3); printf("%c", 205);
        rlutil::locate(i, 7); printf("%c", 205);
    }
    // VERTICAL
    for (int i = 4; i < 7; i++) {
        rlutil::locate(42, i); printf("%c", 186);
        rlutil::locate(50, i); printf("%c", 186);
    }
    //ESQUINAS
    rlutil::locate(42, 3); printf("%c", 201);
    rlutil::locate(42, 7); printf("%c", 200);
    rlutil::locate(50, 3); printf("%c", 187);
    rlutil::locate(50, 7); printf("%c", 188);
}

void MenuDe5Dados(int dados[]) {    // dibujalos dados respecto a los valores que se le entreguen en las distintas posiciones
    int i;
    dadouno(); dadoDos(); dadoTres(); dadoCuatro(); dadoCinco(); /// contorno de los dados
    for (i = 0; i <5; i++) {
        switch (dados[i]) {
        /*dado 1*/ case 1:
            if (i == 0) { rlutil::locate(6, 5); printf("%c", 254); }
            if (i == 1) { rlutil::locate(16, 5); printf("%c", 254); }
            if (i == 2) { rlutil::locate(26, 5); printf("%c", 254); }
            if (i == 3) { rlutil::locate(36, 5); printf("%c", 254); }
            if (i == 4) { rlutil::locate(46, 5); printf("%c", 254); }
            ; break;

        /*dado 2*/ case 2:
            if (i == 0) {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
                }
            if (i == 1) {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }
            if (i == 2) {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            ; break;
        /*numero 3*/  case 3:
            if (i == 0) {
                rlutil::locate(6, 5); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
            }

            if (i == 1) {
                rlutil::locate(16, 5); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
            }

            if (i == 2) {
                rlutil::locate(26, 5); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
            }

            if (i == 3) {
                rlutil::locate(36, 5); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
            }

            if (i == 4) {
                rlutil::locate(46, 5); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
            }
            ; break;

        /*numero 4*/ case 4:
            if (i == 0) {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
            }

            if (i == 1) {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }

            if (i == 2){
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }

            if (i == 3){
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            break;

        /*numero 5*/ case 5:
            if (i == 0){
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(6, 5); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
            }
            if (i == 1){
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(16, 5); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }
            if (i == 2){
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(26, 5); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(36, 5); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4){
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(46, 5); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            break;

        /*numero 6 */ case 6:
            if (i == 0) {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(4, 5); printf("%c", 254);
                rlutil::locate(8, 5); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
            }
            if (i == 1) {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(14, 5); printf("%c", 254);
                rlutil::locate(18, 5); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }
            if (i == 2) {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(24, 5); printf("%c", 254);
                rlutil::locate(28, 5); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(34, 5); printf("%c", 254);
                rlutil::locate(38, 5); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(44, 5); printf("%c", 254);
                rlutil::locate(48, 5); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            ; break;
        }
    }
    getch;
}

void MenuDe4Dados(int dados[]) {    // dibujalos dados respecto a los valores que se le entreguen en las distintas posiciones
    int i;
    dadouno(); dadoDos(); dadoTres(); dadoCuatro(); /// contorno de los dados
    for (i = 0; i <4; i++) {
        switch (dados[i]) {
        /*dado 1*/ case 1:
            if (i == 0) { rlutil::locate(6, 5); printf("%c", 254); }
            if (i == 1) { rlutil::locate(16, 5); printf("%c", 254); }
            if (i == 2) { rlutil::locate(26, 5); printf("%c", 254); }
            if (i == 3) { rlutil::locate(36, 5); printf("%c", 254); }
            if (i == 4) { rlutil::locate(46, 5); printf("%c", 254); }
            ; break;

        /*dado 2*/ case 2:
            if (i == 0) {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
                }
            if (i == 1) {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
                }
            if (i == 2) {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
                }
            if (i == 3) {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
                }
            if (i == 4) {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
                }
            ; break;
        /*numero 3*/  case 3:
            if (i == 0) {
                rlutil::locate(6, 5); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
            }

            if (i == 1) {
                rlutil::locate(16, 5); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
            }

            if (i == 2) {
                rlutil::locate(26, 5); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
            }

            if (i == 3) {
                rlutil::locate(36, 5); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
            }

            if (i == 4) {
                rlutil::locate(46, 5); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
            }
            ; break;

        /*numero 4*/ case 4:
            if (i == 0) {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
            }

            if (i == 1) {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }

            if (i == 2)

            {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }


            if (i == 3)

            {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            break;

        /*numero 5*/ case 5:
            if (i == 0)
            {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(6, 5); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
            }
            if (i == 1)
            {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(16, 5); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }
            if (i == 2)
            {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(26, 5); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(36, 5); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4)
            {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(46, 5); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            break;

        /*numero 6 */ case 6:
            if (i == 0) {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(4, 5); printf("%c", 254);
                rlutil::locate(8, 5); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
            }
            if (i == 1) {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(14, 5); printf("%c", 254);
                rlutil::locate(18, 5); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }
            if (i == 2) {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(24, 5); printf("%c", 254);
                rlutil::locate(28, 5); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(34, 5); printf("%c", 254);
                rlutil::locate(38, 5); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(44, 5); printf("%c", 254);
                rlutil::locate(48, 5); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            ; break;
        }
    }
    getch;
}

void MenuDe3Dados(int dados[]) {    // dibujalos dados respecto a los valores que se le entreguen en las distintas posiciones
    int i;
    dadouno(); dadoDos(); dadoTres(); /// contorno de los dados
    for (i = 0; i <3; i++) {
        switch (dados[i]) {
        /*dado 1*/ case 1:
            if (i == 0) { rlutil::locate(6, 5); printf("%c", 254); }
            if (i == 1) { rlutil::locate(16, 5); printf("%c", 254); }
            if (i == 2) { rlutil::locate(26, 5); printf("%c", 254); }
            if (i == 3) { rlutil::locate(36, 5); printf("%c", 254); }
            if (i == 4) { rlutil::locate(46, 5); printf("%c", 254); }

            ; break;

        /*dado 2*/ case 2:
            if (i == 0) {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
                }
            if (i == 1) {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }
            if (i == 2) {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            ; break;
        /*numero 3*/  case 3:
            if (i == 0) {
                rlutil::locate(6, 5); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
            }

            if (i == 1) {
                rlutil::locate(16, 5); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
            }

            if (i == 2) {
                rlutil::locate(26, 5); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
            }

            if (i == 3) {
                rlutil::locate(36, 5); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
            }

            if (i == 4) {
                rlutil::locate(46, 5); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
            }
            ; break;

        /*numero 4*/ case 4:
            if (i == 0) {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
            }

            if (i == 1) {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }

            if (i == 2)

            {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }


            if (i == 3)

            {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            break;

        /*numero 5*/ case 5:
            if (i == 0)
            {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(6, 5); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
            }
            if (i == 1)
            {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(16, 5); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }
            if (i == 2)
            {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(26, 5); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(36, 5); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4)
            {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(46, 5); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            break;

        /*numero 6 */ case 6:
            if (i == 0) {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(4, 5); printf("%c", 254);
                rlutil::locate(8, 5); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
            }
            if (i == 1) {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(14, 5); printf("%c", 254);
                rlutil::locate(18, 5); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }
            if (i == 2) {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(24, 5); printf("%c", 254);
                rlutil::locate(28, 5); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(34, 5); printf("%c", 254);
                rlutil::locate(38, 5); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(44, 5); printf("%c", 254);
                rlutil::locate(48, 5); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            ; break;
        }
    }
    getch;
}

void MenuDe2Dados(int dados[]) {    // dibujalos dados respecto a los valores que se le entreguen en las distintas posiciones
    int i;
    dadouno(); dadoDos(); /// contorno de los dados
    for (i = 0; i <2; i++) {
        switch (dados[i]) {
        /*dado 1*/ case 1:
            if (i == 0) { rlutil::locate(6, 5); printf("%c", 254); }
            if (i == 1) { rlutil::locate(16, 5); printf("%c", 254); }
            if (i == 2) { rlutil::locate(26, 5); printf("%c", 254); }
            if (i == 3) { rlutil::locate(36, 5); printf("%c", 254); }
            if (i == 4) { rlutil::locate(46, 5); printf("%c", 254); }

            ; break;

        /*dado 2*/ case 2:
            if (i == 0) {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
                }
            if (i == 1) {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }
            if (i == 2) {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            ; break;
        /*numero 3*/  case 3:
            if (i == 0) {
                rlutil::locate(6, 5); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
            }

            if (i == 1) {
                rlutil::locate(16, 5); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
            }

            if (i == 2) {
                rlutil::locate(26, 5); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
            }

            if (i == 3) {
                rlutil::locate(36, 5); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
            }

            if (i == 4) {
                rlutil::locate(46, 5); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
            }
            ; break;

        /*numero 4*/ case 4:
            if (i == 0) {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
            }

            if (i == 1) {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }

            if (i == 2)

            {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }


            if (i == 3)

            {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            break;

        /*numero 5*/ case 5:
            if (i == 0)
            {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(6, 5); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
            }
            if (i == 1)
            {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(16, 5); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }
            if (i == 2)
            {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(26, 5); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(36, 5); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4)
            {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(46, 5); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            break;

        /*numero 6 */ case 6:
            if (i == 0) {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(4, 5); printf("%c", 254);
                rlutil::locate(8, 5); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
            }
            if (i == 1) {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(14, 5); printf("%c", 254);
                rlutil::locate(18, 5); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }
            if (i == 2) {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(24, 5); printf("%c", 254);
                rlutil::locate(28, 5); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(34, 5); printf("%c", 254);
                rlutil::locate(38, 5); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(44, 5); printf("%c", 254);
                rlutil::locate(48, 5); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            ; break;
        }
    }
    getch;
}

void MenuDe1Dados(int dados[]) {    // dibujalos dados respecto a los valores que se le entreguen en las distintas posiciones
    int i;
    dadouno(); /// contorno de los dados
    for (i = 0; i <1; i++) {
        switch (dados[i]) {
        /*dado 1*/ case 1:
            if (i == 0) { rlutil::locate(6, 5); printf("%c", 254); }
            if (i == 1) { rlutil::locate(16, 5); printf("%c", 254); }
            if (i == 2) { rlutil::locate(26, 5); printf("%c", 254); }
            if (i == 3) { rlutil::locate(36, 5); printf("%c", 254); }
            if (i == 4) { rlutil::locate(46, 5); printf("%c", 254); }

            ; break;

        /*dado 2*/ case 2:
            if (i == 0) {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
                }
            if (i == 1) {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }
            if (i == 2) {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            ; break;
        /*numero 3*/  case 3:
            if (i == 0) {
                rlutil::locate(6, 5); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
            }

            if (i == 1) {
                rlutil::locate(16, 5); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
            }

            if (i == 2) {
                rlutil::locate(26, 5); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
            }

            if (i == 3) {
                rlutil::locate(36, 5); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
            }

            if (i == 4) {
                rlutil::locate(46, 5); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
            }
            ; break;

        /*numero 4*/ case 4:
            if (i == 0) {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
            }

            if (i == 1) {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }

            if (i == 2)

            {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }


            if (i == 3)

            {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            break;

        /*numero 5*/ case 5:
            if (i == 0)
            {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(6, 5); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
            }
            if (i == 1)
            {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(16, 5); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }
            if (i == 2)
            {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(26, 5); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(36, 5); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4)
            {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(46, 5); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            break;

        /*numero 6 */ case 6:
            if (i == 0) {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(4, 5); printf("%c", 254);
                rlutil::locate(8, 5); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
            }
            if (i == 1) {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(14, 5); printf("%c", 254);
                rlutil::locate(18, 5); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }
            if (i == 2) {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(24, 5); printf("%c", 254);
                rlutil::locate(28, 5); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(34, 5); printf("%c", 254);
                rlutil::locate(38, 5); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(44, 5); printf("%c", 254);
                rlutil::locate(48, 5); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            ; break;
        }
    }
    getch;
}

void MenuDeUltimaTirada(int dados[]) {    // dibujalos dados respecto a los valores que se le entreguen en las distintas posiciones
    int i;
    dadouno(); dadoDos(); dadoTres(); dadoCuatro(); dadoCinco(); /// contorno de los dados
    for (i = 0; i <5; i++) {
        switch (dados[i]) {
        /*dado 1*/ case 1:
            if (i == 0) { rlutil::locate(6, 5); printf("%c", 254); }
            if (i == 1) { rlutil::locate(16, 5); printf("%c", 254); }
            if (i == 2) { rlutil::locate(26, 5); printf("%c", 254); }
            if (i == 3) { rlutil::locate(36, 5); printf("%c", 254); }
            if (i == 4) { rlutil::locate(46, 5); printf("%c", 254); }

            ; break;

        /*dado 2*/ case 2:
            if (i == 0) {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
                }
            if (i == 1) {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }
            if (i == 2) {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            ; break;
        /*numero 3*/  case 3:
            if (i == 0) {
                rlutil::locate(6, 5); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
            }

            if (i == 1) {
                rlutil::locate(16, 5); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
            }

            if (i == 2) {
                rlutil::locate(26, 5); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
            }

            if (i == 3) {
                rlutil::locate(36, 5); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
            }

            if (i == 4) {
                rlutil::locate(46, 5); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
            }
            ; break;

        /*numero 4*/ case 4:
            if (i == 0) {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
            }

            if (i == 1) {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }

            if (i == 2)

            {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }


            if (i == 3)

            {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            break;

        /*numero 5*/ case 5:
            if (i == 0)
            {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(6, 5); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
            }
            if (i == 1)
            {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(16, 5); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }
            if (i == 2)
            {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(26, 5); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(36, 5); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4)
            {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(46, 5); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            break;

        /*numero 6 */ case 6:
            if (i == 0) {
                rlutil::locate(4, 4); printf("%c", 254);
                rlutil::locate(4, 6); printf("%c", 254);
                rlutil::locate(8, 4); printf("%c", 254);
                rlutil::locate(4, 5); printf("%c", 254);
                rlutil::locate(8, 5); printf("%c", 254);
                rlutil::locate(8, 6); printf("%c", 254);
            }
            if (i == 1) {
                rlutil::locate(14, 4); printf("%c", 254);
                rlutil::locate(14, 6); printf("%c", 254);
                rlutil::locate(18, 4); printf("%c", 254);
                rlutil::locate(14, 5); printf("%c", 254);
                rlutil::locate(18, 5); printf("%c", 254);
                rlutil::locate(18, 6); printf("%c", 254);
            }
            if (i == 2) {
                rlutil::locate(24, 4); printf("%c", 254);
                rlutil::locate(24, 6); printf("%c", 254);
                rlutil::locate(28, 4); printf("%c", 254);
                rlutil::locate(24, 5); printf("%c", 254);
                rlutil::locate(28, 5); printf("%c", 254);
                rlutil::locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                rlutil::locate(34, 4); printf("%c", 254);
                rlutil::locate(34, 6); printf("%c", 254);
                rlutil::locate(38, 4); printf("%c", 254);
                rlutil::locate(34, 5); printf("%c", 254);
                rlutil::locate(38, 5); printf("%c", 254);
                rlutil::locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                rlutil::locate(44, 4); printf("%c", 254);
                rlutil::locate(44, 6); printf("%c", 254);
                rlutil::locate(48, 4); printf("%c", 254);
                rlutil::locate(44, 5); printf("%c", 254);
                rlutil::locate(48, 5); printf("%c", 254);
                rlutil::locate(48, 6); printf("%c", 254);
            }
            ; break;
        }
    }
    getch;
}

/// JUEGO
void fin(){
        system("cls");
        exit(0);
}

void cargarAleatorio(int v[], int tam, int limite){ /// cargar los vectores/dados aleatoriamente
  int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
  }
}

void mostrarVector(int v[], int tam){ // muestra el valor de los dados
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\t";
    }
}

int maximoVector(int v[], int tam){
    int i, posMax=0;
    for(i=1;i<tam;i++){
        if(v[i]>v[posMax]) {
                posMax=i;
        }
    }
    return posMax;
}

int generadorPuntos(int sumaDados){
    int puntosGenerados=0,numGeneradorPuntos=0;
    if(sumaDados==20){
        puntosGenerados=1;
    }
    else{
        if(sumaDados==21){
            puntosGenerados=2;
        }
        else{
            if(sumaDados==22){
                puntosGenerados=3;
            }
            else{
                if(sumaDados==23){
                    puntosGenerados=4;
                }
                else{
                    if(sumaDados==24){
                        puntosGenerados=5;
                    }
                    else{
                        if(sumaDados>=25){
                            puntosGenerados=6;
                        }
                    }
                }
            }
        }
    }
    return puntosGenerados;
}

int contarNumerosRepetidos(int v[], int numero, int tam){
    int i, cant=0;
    for(i=0;i<tam;i++){
        if(v[i]==numero) cant++;
        }
    return cant;
}

int cargarDados(int v[],int tam){
    int i;
    for(i=0;i<tam;i++){
        cin>>v[i];
    }
}
#endif // FUNCIONES_H_INCLUDED

