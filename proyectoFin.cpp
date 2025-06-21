#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <windows.h>

#define TAM 1

using namespace std;

enum Tipo {Picas = 1, Corazones, Treboles, Diamantes};

struct baraja{
    Tipo hello;
    string NomVal;
    int valcar;
};

struct Partida{//aqui inicia la parte para la funcion de guardae en un archivo la partida
    char jugador[50];
    char fecha[20];
    char ganador[15];
    baraja* barjug;
    int nca=2;
};

void obtenerNomCar(int val, string& nombre){//se enitende que esto procesa el numero del enum y para poder mostrar las cartas de fugura
    switch(val){                            //por cuestiones de falta de conocimientos tambien pongo los demas numeros como casos
        case 1: nombre = "As"; break;       //habra que preguntarle al profe irving como simplificar los casos numericos
        case 2: nombre = "2"; break; 
        case 3: nombre = "3"; break;
        case 4: nombre = "4"; break;
        case 5: nombre = "5"; break;
        case 6: nombre = "6"; break;
        case 7: nombre = "7"; break;
        case 8: nombre = "8"; break;
        case 9: nombre = "9"; break;
        case 10: nombre = "10"; break;
        case 11: nombre = "J"; break;
        case 12: nombre = "Q"; break;
        case 13: nombre = "K"; break;
     }
}

void ValAs(int& val){//esta funcion manda a preguntar que valor quiere darle al As
    do{
        cout << "Elige el valor del As (1 o 11): ";
        cin >> val;
    } while(val != 1 && val != 11);
}

void generarCarta(int& valorSumar, int& sumTot, struct Partida* jug){//aqui se genera la carta, creo que aqui va la condicion de 21
    int palo=0; 
    int val=0; 
    int auxAs=0;
    int auxAs2=0;
    int valCam=0;
    
    if(sumTot<21){
        for (int i = 0; i < jug->nca; i++){
            struct baraja *cart = &(jug->barjug[i]);
            palo = 1+rand()%(4-1+1);
            val = 1+rand()%(13-1+1);

            switch(palo){
                case 1: cart->hello = Picas; break;
                case 2: cart->hello = Corazones; break;
                case 3: cart->hello = Treboles; break;
                case 4: cart->hello = Diamantes; break;
            }

            string nomVal;
            obtenerNomCar(val, nomVal);
            switch(jug->barjug[i].hello){ 
                case Picas: cout << "Carta generada: " << nomVal << " de Picas"<< endl; break;//aqui se imprime el numero de la carta y se acompaña con su palo
                case Corazones: cout << "Carta generada: " << nomVal << " de Corazones"<< endl; break;//aqui se imprime el numero de la carta y se acompaña con su palo
                case Treboles: cout << "Carta generada: " << nomVal << " de Treboles" << endl; break;//aqui se imprime el numero de la carta y se acompaña con su palo
                case Diamantes: cout << "Carta generada: " << nomVal << " de Diamantes" << endl; break;//aqui se imprime el numero de la carta y se acompaña con su palo
            }

	        if(val==1){
		        valorSumar += val;
		        auxAs=val;
	        }
	
	
            if (auxAs == 1){
    
                if (val >= 11 && val <= 13){
                    valorSumar += 10; 
                    ValAs(valCam);
                    auxAs2=valCam;
                    valorSumar+= -auxAs+auxAs2;
        
                } else if (val >= 2 && val <= 10){
                    valorSumar += val;
                    ValAs(valCam);
                    auxAs2=valCam;
                    valorSumar=valorSumar -auxAs+ auxAs2;
                }
            
            } else {
                if (val >= 11 && val <= 13) {
                    valorSumar = 10;
                }else if (val >= 2 && val <= 10) {
                    valorSumar = val;
                }
            }
	 

            sumTot += valorSumar;

            cout << "Valor sumado: " << valorSumar << endl;
            cout << "Total acumulado: " << sumTot << endl;
        }
    }
}
    

void jugarCartas(int& SumJug, struct Partida* jug){
    char op;
    int valorSumar;

    SumJug = 0;

    cout << "\n--- Repartiendo tus dos primeras cartas ---" << endl;
    generarCarta(valorSumar, SumJug, jug);

    do {
        cout << "Hit o Stand (H/S):";
        cin >> op;

        if (op == 'h' || op == 'H') {
            generarCarta(valorSumar, SumJug, jug);
         }else if(op == 's' || op == 'S'){
            cout<<"¿Quieres abandonar (s/n)?";
            cin>>op;
            if (op == 's' || op == 'S'){
                break;
            }
         }else{
            cout<<"Esta opcion no existe intente de nuevo"<<endl;
         }

    } while(SumJug<21);
}

void generarDatosPartida(Partida* partida){
    cout << "Ingresa tu nombre (sin espacios): ";
    cin >> partida[0].jugador;

    cout << "Ingresa la fecha (DD/MM/AAAA): ";
    cin >> partida[0].fecha;
}

int main(){
    srand(time(0));
    Partida partida;
    int SumJug;

    generarDatosPartida(&partida);
    jugarCartas(SumJug, &partida);

    cout << "\n " << partida.jugador << endl;
    cout << "Juego terminado. Total final acumulado: " << SumJug << endl;

    return 0;
}