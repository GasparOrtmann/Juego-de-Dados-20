#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#include "funciones.h"
#include "rlutil.h"

int main(){
    int i, j, x, y, w, l,z, opcion, rondas,CRondas, lanzamiento,apuesta,apuestaJ1,apuestaJ2,tirada=1, pos, puntosGenerados=0, sumaDados, puntaje=0,puntajeJ1=0,puntajeJ2=0,rondasCeroPuntos=0,rondaNegativa=0;
    int valorApostado,valorApostadoJ1,valorApostadoJ2, numGeneradorPuntos, puntuacionTotal=0,puntuacionTotalJ1=0,puntuacionTotalJ2=0,rondasJ1=0,rondasJ2=0;
    int puntuacionGanador=0,puntuacionGanadorJ1=0,puntuacionGanadorJ2=0,puntuacionMasAlta=0,puntuacionMasAlta2;
    bool unJugador=false,dosJugadores=false,ganadorJ1=false,ganadorJ2=false,empate=false,maxPuntuacion=false,maxPuntuacion2=false;
    int dados[5],maximos[5]={0}, puntuaciones[3]={0},dadoSim[5]={0};
    int ciclomenu=true;
    char nombre[20],jugador1[20],jugador2[20],ganador[20],ganador2[20];
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    while(ciclomenu){
        opcion=MenuPrincipal();
        switch(opcion){
        case 13: system("cls");
            ciclomenu=false; rondaNegativa=0; rondasCeroPuntos=0;

            rlutil::setColor(rlutil::WHITE);
            cout<<"------------------------------------------------------------------------------------"<<endl;
            cout<<"Ingrese su nombre: "; cin>>nombre;
            cout<<"------------------------------------------------------------------------------------"<<endl;
            cout<<"Ingrese la cantidad de rondas que va a jugar: "; cin>>rondas;
            cout<<"------------------------------------------------------------------------------------"<<endl;
            rlutil::setColor(rlutil::GREEN); cout<<endl<<"Presione ENTER para comenzar el juego"; getch(); system("cls"); rlutil::setColor(rlutil::WHITE);
            system("cls");
            for(j=1;j<=rondas;j++){ ///RONDAS
                sumaDados=0; tirada=1;
                for(z=0;z<5;z++){
                        maximos[z]={0};
                            }
                if(j==1){
                    puntuacionTotal=0;
                }
                cout<<"Ronda : "<<j<<"\t"<<"Jugador: "<<nombre<<"\t"<<"\t"<<"Puntuacion: "<<puntuacionTotal<<endl;
                cout<<"Apuesta: ";
                cin>>apuesta;
                valorApostado=apuesta;
                rlutil::setColor(rlutil::GREEN); cout<<endl<<"Presione ENTER para comenzar la tirada de dados"; rlutil::setColor(rlutil::WHITE);
                getch(); system("cls");
                for(i=0;i<5;i++){ ///TIRADAS DE DADOS
                if(i==0){
                cout<<endl<<"\t"<<"Tiramos los primeros 5 dados"<<endl; cargarAleatorio(dados,6,6);
                MenuDe5Dados(dados);
                pos=maximoVector(dados,5);
                cout<<endl<<endl<<endl<<endl; cout<<"Maximo tirada "<<tirada<<": "<<dados[pos]<<endl; maximos[i]=dados[pos];
                rlutil::setColor(rlutil::GREEN); cout<<endl<<"Presione ENTER para continuar"<<endl; rlutil::setColor(rlutil::WHITE); getch(); system("cls");
                }
                else{
                    cout<<endl;
                    cargarAleatorio(dados,6-i,6);
                        if(i==1){
                            cout<<"\t"<<"\t"<<"Tirada 2";
                            MenuDe4Dados(dados);
                        }
                        else{
                            if(i==2){
                                cout<<"\t"<<"Tirada 3";
                                MenuDe3Dados(dados);
                            }
                            else{
                                if(i==3){
                                    cout<<"\t"<<"Tirada 4";
                                    MenuDe2Dados(dados);
                                }
                                else{
                                    if(i==4){
                                        cout<<"Tirada 5";
                                        MenuDe1Dados(dados);
                                    }
                                }
                            }
                        }
                    pos=maximoVector(dados,5-i);
                    cout<<endl<<endl<<endl<<"Maximo tirada "<<tirada<<": "<<dados[pos]<<endl; maximos[i]=dados[pos];
                    for(z=0;z<5;z++){
                        if(z==0){
                            cout<<"Maximos: "<<maximos[z]<<"\t";
                        }
                        else{
                           cout<<maximos[z]<<"\t";
                        }
                    }
                    rlutil::setColor(rlutil::GREEN); cout<<endl<<endl<<"Presione ENTER para continuar"<<endl; rlutil::setColor(rlutil::WHITE);
                    getch(); system("cls");
                }
                    tirada++; sumaDados+=dados[pos];
                    }
                system("cls");

                cout<<endl<<"Suma de los dados: "<<sumaDados<<endl<<endl;
                if(sumaDados<20){
                    rondaNegativa++;
                    rlutil::setColor(rlutil::RED); cout<<"No llegaste a los puntos minimos, perdiste los puntos que apostaste"<<endl<<endl;  std::cin.get(); rlutil::setColor(rlutil::WHITE);
                        puntuacionTotal=puntuacionTotal-valorApostado;
                }
                else{
                    cout<<"Numero generador de puntos: "<<generadorPuntos(sumaDados)<<endl<<endl;
                    rlutil::setColor(rlutil::GREEN); cout<<"PRESIONE ENTER PARA EL TIRO DE PUNTAJE"<<endl; rlutil::setColor(rlutil::WHITE);
                    getch(); std:cin.get(); system("cls");
                    cargarAleatorio(dados,6,6);
                    cout << "\n" << "\n" << endl << endl << endl;
                    MenuDe5Dados(dados); cout << "\n" << "\n" << endl << endl;
                    cout<<"Veces que se repite el numero generador de puntos: "<<contarNumerosRepetidos(dados,generadorPuntos(sumaDados),5)<<endl;
                    puntaje=valorApostado*(contarNumerosRepetidos(dados,generadorPuntos(sumaDados),5));
                    cout<<"Puntaje: "<<puntaje<<endl<<endl;
                    if(puntaje==0){
                        rondasCeroPuntos++;
                        }
                        puntuacionTotal+=puntaje;
                    }
                rlutil::setColor(rlutil::GREEN); cout<<"Presione ENTER para pasar a la siguiente ronda"<<endl; rlutil::setColor(rlutil::WHITE);
                puntuaciones[0]={puntuacionTotal};
                std::cin.get();     system("cls");
                }
                if(unJugador==false){
                    puntuacionMasAlta=puntuacionTotal;
                    strcpy(ganador,nombre);
                }
                else{
                    if(puntuacionTotal>puntuacionMasAlta){
                        puntuacionMasAlta=puntuacionTotal;
                        strcpy(ganador,nombre);
                    }
                }
                rlutil::setColor(rlutil::RED); cout<<"\t"<<"TERMINASTE LA PARTIDA"<<endl<<endl; rlutil::setColor(rlutil::WHITE);
                cout<<"Jugador: "<<nombre<<"\t"<<"\t"<<"Puntuacion: "<<puntuacionTotal<<endl;
                cout<<"Rondas sin puntos: "<<rondasCeroPuntos<<"\t"<<"\t"<<"Rondas con perdida de puntos: "<<rondaNegativa<<endl;
                rlutil::setColor(rlutil::GREEN); cout<<endl<<"APRETA UNA TECLA PARA VOLVER A INICIO"; unJugador=true; getch();
                system("cls"); ciclomenu=true;
                break;
        case 14: system("cls");
            ciclomenu=false; rondasJ1=0; rondasJ2=0;
            rlutil::setColor(rlutil::WHITE);
            cout<<"------------------------------------------------------------------------------------"<<endl;
            cout<<"Jugador 1: "; cin>>jugador1;
            cout<<"------------------------------------------------------------------------------------"<<endl;
            cout<<"Jugador 2: "; cin>>jugador2;
            cout<<"------------------------------------------------------------------------------------"<<endl;
            cout<<"Ingrese la cantidad de rondas que va a jugar: "; cin>>rondas;
            cout<<"------------------------------------------------------------------------------------"<<endl;
            rlutil::setColor(rlutil::GREEN); cout<<endl<<"Presione ENTER para comenzar el juego"; getch(); system("cls"); rlutil::setColor(rlutil::WHITE);
            system("cls");
            for(y=1;y<=rondas*2;y++){
            if(y%2!=0){
                if(y==1){
                    puntuacionTotalJ1=0;
                }
                rondasJ1++; sumaDados=0; tirada=1;
                for(z=0;z<5;z++){
                        maximos[z]={0};
                            }
                cout<<"Ronda : "<<rondasJ1<<"\t"<<"Jugador: "<<jugador1<<"\t"<<"\t"<<"Puntuacion: "<<puntuacionTotalJ1<<endl;
                cout<<"Apuesta: ";
                cin>>apuestaJ1;
                valorApostadoJ1=apuestaJ1;
                rlutil::setColor(rlutil::GREEN); cout<<endl<<"Presione ENTER para comenzar la tirada de dados"; rlutil::setColor(rlutil::WHITE);
                getch(); system("cls");
                for(i=0;i<5;i++){ ///TIRADAS DE DADOS
                if(i==0){
                cout<<endl<<"\t"<<"Tiramos los primeros 5 dados"<<endl; cargarAleatorio(dados,6,6);
                MenuDe5Dados(dados);
                pos=maximoVector(dados,5);
                cout<<endl<<endl<<endl<<endl; cout<<"Maximo tirada "<<tirada<<": "<<dados[pos]<<endl; maximos[i]=dados[pos];
                rlutil::setColor(rlutil::GREEN); cout<<endl<<"Presione ENTER para continuar"<<endl; rlutil::setColor(rlutil::WHITE); getch(); system("cls");
                }
                else{
                    cout<<endl; cargarAleatorio(dados,6-i,6);
                        if(i==1){
                            cout<<"\t"<<"\t"<<"Tirada 2";
                            MenuDe4Dados(dados);
                        }
                        else{
                            if(i==2){
                                cout<<"\t"<<"Tirada 3";
                                MenuDe3Dados(dados);
                            }
                            else{
                                if(i==3){
                                    cout<<"\t"<<"Tirada 4";
                                    MenuDe2Dados(dados);
                                }
                                else{
                                    if(i==4){
                                        cout<<"Tirada 5";
                                        MenuDe1Dados(dados);
                                    }
                                }
                            }
                        }
                    pos=maximoVector(dados,5-i);
                    cout<<endl<<endl<<endl<<"Maximo tirada "<<tirada<<": "<<dados[pos]<<endl<<endl; maximos[i]=dados[pos];
                    for(z=0;z<5;z++){
                        if(z==0){
                            cout<<"Maximos: "<<maximos[z]<<"\t";
                        }
                        else{
                           cout<<maximos[z]<<"\t";
                        }
                    }
                    rlutil::setColor(rlutil::GREEN); cout<<endl<<endl<<"Presione ENTER para continuar"<<endl; rlutil::setColor(rlutil::WHITE);
                    getch(); system("cls");
                }
                tirada++;
                sumaDados+=dados[pos];
                    }
                system("cls");
                cout<<"Suma de los dados: "<<sumaDados<<endl<<endl;
                if(sumaDados<20){
                    rlutil::setColor(rlutil::RED); cout<<"No llegaste a los puntos minimos, perdiste los puntos que apostaste"<<endl<<endl; rlutil::setColor(rlutil::WHITE);
                        puntuacionTotalJ1=puntuacionTotalJ1-valorApostadoJ1;
                }
                else{
                    cout<<"Numero generador de puntos: "<<generadorPuntos(sumaDados)<<endl;
                    rlutil::setColor(rlutil::GREEN); cout<<endl<<"PRESIONE ENTER PARA EL TIRO DE PUNTAJE"<<endl; rlutil::setColor(rlutil::WHITE);
                    std::cin.get(); getch(); system("cls");
                    cargarAleatorio(dados,6,6);
                    cout << "\n" << "\n" << endl << endl << endl;
                    MenuDe5Dados(dados); cout << "\n" << "\n" << endl << endl;
                    cout<<"Veces que se repite el numero generador de puntos: "<<contarNumerosRepetidos(dados,generadorPuntos(sumaDados),5)<<endl;
                    puntajeJ1=valorApostadoJ1*(contarNumerosRepetidos(dados,generadorPuntos(sumaDados),5));
                    cout<<"Puntaje: "<<puntajeJ1<<endl<<endl;
                    }
                rlutil::setColor(rlutil::GREEN); cout<<"Presione ENTER para pasar a la siguiente ronda"<<endl; rlutil::setColor(rlutil::WHITE);
                puntuacionTotalJ1+=puntajeJ1;
                puntuaciones[1]={puntuacionTotalJ1};
                std::cin.get(); system("cls");
            }
            else{ ///RONDAS J2
            if(y==2){
                puntuacionTotalJ2=0;
                }
            rondasJ2++; sumaDados=0; tirada=1;
            for(z=0;z<5;z++){
                        maximos[z]={0};
                            }
            cout<<"Ronda : "<<rondasJ2<<"\t"<<"Jugador: "<<jugador2<<"\t"<<"\t"<<"Puntuacion: "<<puntuacionTotalJ2<<endl;
            cout<<"Apuesta: "; cin>>apuestaJ2;
            valorApostadoJ2=apuestaJ2;
            rlutil::setColor(rlutil::GREEN); cout<<endl<<"Presione ENTER para comenzar la tirada de dados"; getch(); system("cls"); rlutil::setColor(rlutil::WHITE);
            for(x=0;x<5;x++){ ///TIRADAS DE DADOS
            if(x==0){
            cout<<endl<<"\t"<<"Tiramos los primeros 5 dados"<<endl; cargarAleatorio(dados,6,6);
            MenuDe5Dados(dados);
            pos=maximoVector(dados,5);
            cout<<endl<<endl<<endl<<endl; cout<<"Maximo tirada "<<tirada<<": "<<dados[pos]<<endl<<endl; maximos[x]=dados[pos];
            rlutil::setColor(rlutil::GREEN); cout<<endl<<"Presione ENTER para continuar"<<endl; rlutil::setColor(rlutil::WHITE);
            getch(); system("cls");
            }
            else{
                cout<<endl; cargarAleatorio(dados,6-x,6);
                    if(x==1){
                        cout<<"\t"<<"\t"<<"Tirada 2";
                        MenuDe4Dados(dados);
                    }
                    else{
                        if(x==2){
                            cout<<"\t"<<"Tirada 3";
                            MenuDe3Dados(dados);
                        }
                        else{
                            if(x==3){
                                cout<<"\t"<<"Tirada 4";
                                MenuDe2Dados(dados);
                            }
                            else{
                                if(x==4){
                                    cout<<"Tirada 5";
                                    MenuDe1Dados(dados);
                                }
                            }
                        }
                    }
                pos=maximoVector(dados,5-x);
                cout<<endl<<endl<<endl<<"Maximo tirada "<<tirada<<": "<<dados[pos]<<endl; maximos[x]=dados[pos];
                for(z=0;z<5;z++){
                        if(z==0){
                            cout<<"Maximos: "<<maximos[z]<<"\t";
                        }
                        else{
                           cout<<maximos[z]<<"\t";
                        }
                    }
                rlutil::setColor(rlutil::GREEN); cout<<endl<<endl<<"Presione ENTER para continuar"<<endl; rlutil::setColor(rlutil::WHITE);
                getch(); system("cls");
            }
                tirada++; sumaDados+=dados[pos];
                }
                system("cls");
                cout<<"Suma de los dados: "<<sumaDados<<endl<<endl;
                if(sumaDados<20){
                    rlutil::setColor(rlutil::RED); cout<<"No llegaste a los puntos minimos, perdiste los puntos que apostaste"<<endl<<endl;  std::cin.get(); rlutil::setColor(rlutil::WHITE);
                    puntuacionTotalJ2=puntuacionTotalJ2-valorApostadoJ2;
                }
            else{
                cout<<"Numero generador de puntos: "<<generadorPuntos(sumaDados)<<endl;
                rlutil::setColor(rlutil::GREEN); cout<<endl<<"PRESIONE ENTER PARA EL TIRO DE PUNTAJE"<<endl; rlutil::setColor(rlutil::WHITE);
                cout<<endl<<endl;
                getch();
                std::cin.get();
                system("cls");
                cargarAleatorio(dados,6,6);
                cout << "\n" << "\n" << endl << endl << endl;
                MenuDe5Dados(dados); cout << "\n" << "\n" << endl << endl;
                cout<<"Veces que se repite el numero generador de puntos: "<<contarNumerosRepetidos(dados,generadorPuntos(sumaDados),5)<<endl;
                puntajeJ2=valorApostadoJ2*(contarNumerosRepetidos(dados,generadorPuntos(sumaDados),5));
                cout<<"Puntaje: "<<puntajeJ2<<endl<<endl;
                }
                rlutil::setColor(rlutil::GREEN); cout<<"Presione ENTER para pasar a la siguiente ronda"<<endl; rlutil::setColor(rlutil::WHITE);
                puntuacionTotalJ2+=puntajeJ2;
                std::cin.get(); system("cls");
                    }
            }
                if(puntuacionTotalJ1==puntuacionTotalJ2){
                    rlutil::setColor(rlutil::RED); cout<<"\t"<<"TERMINARON LA PARTIDA"<<endl<<endl; rlutil::setColor(rlutil::WHITE);
                    cout<<"FUE UN EMPATE"<<endl;
                    rlutil::setColor(rlutil::GREEN); cout<<endl<<"APRETA UNA TECLA PARA VOLVER A INICIO"; std::cin.get(); empate=true; system("cls");
                }
                else{
                if(puntuacionTotalJ1>puntuacionTotalJ2){
                    rlutil::setColor(rlutil::RED); cout<<"\t"<<"TERMINARON LA PARTIDA"<<endl<<endl; rlutil::setColor(rlutil::WHITE);
                    cout<<"Ganador: "<<jugador1<<"\t"<<"\t"<<"Puntuacion: "<<puntuacionTotalJ1<<endl;
                    rlutil::setColor(rlutil::GREEN); cout<<endl<<"APRETA UNA TECLA PARA VOLVER A INICIO";
                    if(dosJugadores==false){
                        strcpy(ganador2,jugador1); puntuacionMasAlta2=puntuacionTotalJ1;
                        dosJugadores=true; ganadorJ1=true; std::cin.get(); system("cls");
                    }
                    else{
                        if(puntuacionTotalJ1>puntuacionMasAlta2){
                            strcpy(ganador2,jugador1); puntuacionMasAlta2=puntuacionTotalJ1;
                                }
                            std::cin.get(); system("cls");
                            }
                        }
                else{
                    rlutil::setColor(rlutil::RED); cout<<"\t"<<"TERMINARON LA PARTIDA"<<endl<<endl; rlutil::setColor(rlutil::WHITE);
                    cout<<"Ganador: "<<jugador2<<"\t"<<"\t"<<"Puntuacion: "<<puntuacionTotalJ2<<endl;
                    rlutil::setColor(rlutil::GREEN); cout<<endl<<"APRETA UNA TECLA PARA VOLVER A INICIO";
                    if(dosJugadores==false){
                        strcpy(ganador2,jugador2); puntuacionMasAlta2=puntuacionTotalJ2;
                        dosJugadores=true; ganadorJ2=true;
                        std::cin.get();; system("cls");
                    }
                    else{
                        if(puntuacionTotalJ2>puntuacionMasAlta2){
                            strcpy(ganador2,jugador2); puntuacionMasAlta2=puntuacionTotalJ2;
                            }
                            std::cin.get(); system("cls");
                        }
                    }
                }
                ciclomenu=true;
                break;
        case 15: system("cls");
                ciclomenu=false;
                recuadro(); rlutil::setColor(rlutil::WHITE);
                if(unJugador==true){
                    rlutil::locate(38,10); cout<<"-------------------------------------------------------"<<endl;
                    rlutil::locate(50,11); cout<<"\t"<<"MODO UN JUGADOR"<<endl;
                    rlutil::locate(45,12); cout<<"JUGADOR: "<<ganador<<"\t"<<"PUNTUACION MAS ALTA: "<<puntuacionMasAlta<<endl;
                    rlutil::locate(38,13); cout<<"-------------------------------------------------------"<<endl;
                }
                else{
                    rlutil::locate(38,11);cout<<"-------------------------------------------------------"<<endl;
                    rlutil::locate(50,12);cout<<"NO HUBO PARTIDAS EN MODO 1 JUGADOR"<<endl;
                    rlutil::locate(38,13);cout<<"-------------------------------------------------------"<<endl;
                }
                if(dosJugadores==true){
                        if(ganadorJ1==true){
                                rlutil::locate(49,14); cout<<"\t"<<"MODO 2 JUGADORES"<<endl;
                                rlutil::locate(49,15); cout<<"JUGADOR: "<<ganador2<<"\t"<<"PUNTUACION MAS ALTA: "<<puntuacionMasAlta2<<endl;
                                rlutil::locate(38,16); cout<<"-------------------------------------------------------"<<endl;
                                }
                        else{
                            if(ganadorJ2==true){
                                rlutil::locate(49,14); cout<<"\t"<<"MODO 2 JUGADORES"<<endl;
                                rlutil::locate(49,15); cout<<"JUGADOR: "<<ganador2<<"\t"<<"PUNTUACION MAS ALTA: "<<puntuacionMasAlta2<<endl;
                                rlutil::locate(38,16); cout<<"-------------------------------------------------------"<<endl;
                        }
                    }
                }
                else{
                    if(empate==true){
                        rlutil::locate(49,14); cout<<"\t"<<"MODO 2 JUGADORES"<<endl;
                        rlutil::locate(48,15); cout<<"\t"<<"\t"<<"LA PARTIDA FUE UN EMPATE"<<endl;
                        rlutil::locate(38,16); cout<<"-------------------------------------------------------"<<endl;
                    }
                    else{
                        rlutil::locate(49,14); cout<<"NO HUBO PARTIDAS EN MODO 2 JUGADORES"<<endl;
                        rlutil::locate(38,15); cout<<"-------------------------------------------------------"<<endl;
                            }
                }
                rlutil::locate(38,18); cout<<"-------------------------------------------------------"<<endl;
                rlutil::setColor(rlutil::GREEN);
                rlutil::locate(50,20); cout<<"PRESIONE ENTER PARA VOLVER AL MENU";
                rlutil::setColor(rlutil::WHITE);
                rlutil::locate(38,22); cout<<"-------------------------------------------------------"<<endl; std::cin.get();
                ciclomenu=true; system("cls");
                break;
        case 16: system("cls");
            ciclomenu=false; rondaNegativa=0; rondasCeroPuntos=0;
            rlutil::setColor(rlutil::WHITE);
            cout<<"------------------------------------------------------------------------------------"<<endl;
            cout<<"Ingrese su nombre: "; cin>>nombre;
            cout<<"------------------------------------------------------------------------------------"<<endl;
            cout<<"Ingrese la cantidad de rondas que va a jugar: "; cin>>rondas;
            cout<<"------------------------------------------------------------------------------------"<<endl;
            rlutil::setColor(rlutil::GREEN); cout<<endl<<"Presione ENTER para comenzar el juego"; getch(); system("cls"); rlutil::setColor(rlutil::WHITE);
            system("cls");
            for(w=1;w<=rondas;w++){ ///RONDAS
                sumaDados=0; tirada=1;
                if(w==1){
                    puntuacionTotal=0;
                }
                cout<<"Ronda : "<<w<<"\t"<<"Jugador: "<<nombre<<"\t"<<"\t"<<"Puntuacion: "<<puntuacionTotal<<endl;
                cout<<"Apuesta: "; cin>>apuesta;
                valorApostado=apuesta;
                rlutil::setColor(rlutil::GREEN); cout<<endl<<"Presione ENTER para comenzar la tirada de dados"; rlutil::setColor(rlutil::WHITE);
                getch(); system("cls");
                for(l=0;l<5;l++){   ///TIRADAS DE DADOS
                        if(l==0){
                            cout<<endl<<"Cargue los primeros 5 dados (maximo 6): "; cargarDados(dadoSim,5); system("cls"); MenuDe5Dados(dadoSim);
                            pos=maximoVector(dadoSim,5);
                            cout<<endl<<endl<<endl<<endl; cout<<"Maximo tirada "<<tirada<<": "<<dadoSim[pos]<<endl;
                            rlutil::setColor(rlutil::GREEN); cout<<endl<<"Presione ENTER para continuar"<<endl; rlutil::setColor(rlutil::WHITE);
                            getch(); std::cin.get(); system("cls");
                        }
                        else{
                            if(l==1){
                                cout<<endl<<"Cargue los 4 dados (maximo 6): "<<endl; cargarDados(dadoSim,4); system("cls"); MenuDe4Dados(dadoSim);
                                pos=maximoVector(dadoSim,4);
                                cout<<endl<<endl<<endl<<endl; cout<<"Maximo tirada "<<tirada<<": "<<dadoSim[pos]<<endl;
                                rlutil::setColor(rlutil::GREEN); cout<<endl<<"Presione ENTER para continuar"<<endl; rlutil::setColor(rlutil::WHITE);
                                getch(); std::cin.get(); system("cls");
                            }
                            else{
                                if(l==2){
                                    cout<<endl<<"Cargue los 3 dados (maximo 6): "<<endl; cargarDados(dadoSim,3); system("cls"); MenuDe3Dados(dadoSim);
                                    pos=maximoVector(dadoSim,3);
                                    cout<<endl<<endl<<endl<<endl; cout<<"Maximo tirada "<<tirada<<": "<<dadoSim[pos]<<endl;
                                    rlutil::setColor(rlutil::GREEN); cout<<endl<<"Presione ENTER para continuar"<<endl; rlutil::setColor(rlutil::WHITE);
                                    getch(); std::cin.get(); system("cls");
                                }
                                else{
                                    if(l==3){
                                        cout<<endl<<"Cargue los 2 dados (maximo 6): "<<endl; cargarDados(dadoSim,2); system("cls"); MenuDe2Dados(dadoSim);
                                        pos=maximoVector(dadoSim,2);
                                        cout<<endl<<endl<<endl<<endl; cout<<"Maximo tirada "<<tirada<<": "<<dadoSim[pos]<<endl;
                                        rlutil::setColor(rlutil::GREEN); cout<<endl<<"Presione ENTER para continuar"<<endl; rlutil::setColor(rlutil::WHITE);
                                        getch(); std::cin.get(); system("cls");
                                    }
                                    else{
                                        if(l==4){
                                            cout<<endl<<"Cargue el ultimo dado (maximo 6): "<<endl; cargarDados(dadoSim,1); system("cls"); MenuDe1Dados(dadoSim);
                                            pos=maximoVector(dadoSim,1);
                                            cout<<endl<<endl<<endl<<endl; cout<<"Maximo tirada "<<tirada<<": "<<dadoSim[pos]<<endl;
                                            rlutil::setColor(rlutil::GREEN); cout<<endl<<"Presione ENTER para continuar"<<endl; rlutil::setColor(rlutil::WHITE);
                                            getch(); std::cin.get(); system("cls");
                                        }
                                    }
                                }
                            }
                        }
                tirada++; sumaDados+=dadoSim[pos]; cout<<endl;
                }
                system("cls");
                cout<<"Suma de los dados: "<<sumaDados<<endl<<endl;
                if(sumaDados<20){
                    rondaNegativa++;
                    rlutil::setColor(rlutil::RED); cout<<"No llegaste a los puntos minimos, perdiste los puntos que apostaste"<<endl; rlutil::setColor(rlutil::WHITE);
                        puntuacionTotal=puntuacionTotal-valorApostado;
                }
                else{
                    cout<<"Numero generador de puntos: "<<generadorPuntos(sumaDados)<<endl;
                    rlutil::setColor(rlutil::GREEN); cout<<endl<<"PRESIONE ENTER PARA EL TIRO DE PUNTAJE"<<endl; rlutil::setColor(rlutil::WHITE);
                    std::cin.get(); system("cls");
                    cout<<"Cargue el Tiro de Puntaje (maximo 6): "; cargarDados(dadoSim,5); system("cls");
                    cout << "\n" << "\n" << endl << endl << endl;
                    MenuDe5Dados(dadoSim); cout << "\n" << "\n" << endl << endl;
                    cout<<"Veces que se repite el numero generador de puntos: "<<contarNumerosRepetidos(dadoSim,generadorPuntos(sumaDados),5)<<endl;
                    puntaje=valorApostado*(contarNumerosRepetidos(dadoSim,generadorPuntos(sumaDados),5));
                    cout<<"Puntaje: "<<puntaje<<endl<<endl;
                    if(puntaje==0){
                        rondasCeroPuntos++;
                        }
                    puntuacionTotal+=puntaje;
                    }
                rlutil::setColor(rlutil::GREEN); cout<<endl<<"Presione ENTER para pasar a la siguiente ronda"<<endl; rlutil::setColor(rlutil::WHITE);
                puntuaciones[0]={puntuacionTotal};
                std::cin.get(); system("cls");
                }
                rlutil::setColor(rlutil::RED); cout<<"\t"<<"TERMINARON LA PARTIDA"<<endl<<endl; rlutil::setColor(rlutil::WHITE);
                cout<<"Jugador: "<<nombre<<"\t"<<"\t"<<"Puntuacion: "<<puntuacionTotal<<endl;
                cout<<"Rondas sin puntos: "<<rondasCeroPuntos<<"\t"<<"\t"<<"Rondas con perdida de puntos: "<<rondaNegativa<<endl;
                rlutil::setColor(rlutil::GREEN); cout<<endl<<"APRETA UNA TECLA PARA VOLVER A INICIO";
                getch(); system("cls"); ciclomenu=true;
                break;
        case 17: fin();
                break;
        default:
        rlutil::anykey();
            }
        }
    system("pause");
    return 0;
}
