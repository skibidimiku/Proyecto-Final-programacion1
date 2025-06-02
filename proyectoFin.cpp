#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <windows.h>

#define TAM 1

using namespace std;

typedef enum { //Cuatro enum diferentes para intentar borrarlos despues de que salga uno para evitar cartas repetidas
    Picas2 = 2, Picas3, Picas4, Picas5, Picas6, Picas7, Picas8,
    Picas9, Picas10, PicasJ = 11, PicasQ = 12, PicasK = 13, PicasAs = 1
} PaloP;

typedef enum { 
    Coraz2 = 2, Coraz3, Coraz4, Coraz5, Coraz6, Coraz7, Coraz8,
    Coraz9, Coraz10, CorazJ = 11, CorazQ = 12, CorazK = 13, CorazAs = 1
} PaloC;

typedef enum { 
    Trebol2 = 2, Trebol3, Trebol4, Trebol5, Trebol6, Trebol7, Trebol8,
    Trebol9, Trebol10, TrebolJ = 11, TrebolQ = 12, TrebolK = 13, TrebolAs = 1
} PaloT;

typedef enum { 
    Diaman2 = 2, Diaman3, Diaman4, Diaman5, Diaman6, Diaman7, Diaman8,
    Diaman9, Diaman10, DiamanJ = 11, DiamanQ = 12, DiamanK = 13, DiamanAs = 1
} PaloD;//aqui termina los enum

struct Partida{//aqui inicia la parte para la funcion de guardae en un archivo la partida
    char jugador[50];
    char fecha[20];
    char ganador[15];
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

void generarCarta(int& valorSumar, int& sumTot){//aqui se genera la carta, creo que aqui va la condicion de 21
	
    int palo=0; 
    int val=0; 
    int auxAs=0;
    int auxAs2=0;
    int valCam=0;
    
    if(sumTot<21){
    palo = rand()%4;
     val = rand()%13+1; 

    string nomPal;
    switch(palo){
        case 0: nomPal = "Picas"; break;
        case 1: nomPal = "Corazones"; break;
        case 2: nomPal = "Treboles"; break;
        case 3: nomPal = "Diamantes"; break;
    }

    string nomVal;
    obtenerNomCar(val, nomVal);

    cout << "Carta generada: " << nomVal << " de " << nomPal << endl;//aqui se imprime el numero de la carta y se acompaña con su palo

    
    	
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
    

} 
else {
    // 
    if (val >= 11 && val <= 13) {
        valorSumar = 10;
    } else if (val >= 2 && val <= 10) {
        valorSumar = val;
    }
}
	 

    sumTot += valorSumar;

    cout << "Valor sumado: " << valorSumar << endl;
    cout << "Total acumulado: " << sumTot << endl;
}else{if(sumTot>21){

	//supongo que aqui directamente pierde, pero la vamos a comparar con la maquina para despues saber el valor de la variable ganador
}
}
}

void jugarCartas(int& SumJug){
    char op;
    int valorSumar;

    SumJug = 0;

    cout << "\n--- Repartiendo tus dos primeras cartas ---" << endl;
    generarCarta(valorSumar, SumJug);
    generarCarta(valorSumar, SumJug);

    do {
        cout << "Quieres sacar otra carta? (s/n): ";
        cin >> op;

        if (op == 's' || op == 'S') {
            generarCarta(valorSumar, SumJug);
         }

    } while(op == 's' || op == 'S');
}

void generarDatosPartida(Partida partida[]){
    cout << "Ingresa tu nombre (sin espacios): ";
    cin >> partida[0].jugador;

    cout << "Ingresa la fecha (DD/MM/AAAA): ";
    cin >> partida[0].fecha;
}

int main(){
    srand(time(0));
    Partida partida[TAM];
    int SumJug;

    generarDatosPartida(partida);
    jugarCartas(SumJug);

    cout << "\n " << partida[0].jugador << endl;
    cout << "Juego terminado. Total final acumulado: " << SumJug << endl;

    return 0;
}