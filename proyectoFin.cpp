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
<<<<<<< Updated upstream
=======
    int puntj=0;
>>>>>>> Stashed changes
};

struct Partida{//aqui inicia la parte para la funcion de guardae en un archivo la partida
    char jugador[50];
    char fecha[20];
<<<<<<< Updated upstream
    char ganador[15];
    baraja* barjug;
    int nca=2;
=======
    baraja* barjug;
    int nca=2;
};

struct Partidacasa{//aqui inicia la parte para la funcion de guardae en un archivo la partida
    baraja* barcas;
    int nca=2;
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
void generarCarta(int& valorSumar, int& sumTot, struct Partida* jug){//aqui se genera la carta, creo que aqui va la condicion de 21
=======
void generarCarta(int& valorSumar, int& sumTot, struct Partida* jug, int& gan ){//aqui se genera la carta, creo que aqui va la condicion de 21
>>>>>>> Stashed changes
    int palo=0; 
    int val=0; 
    int auxAs=0;
    int auxAs2=0;
    int valCam=0;
    
<<<<<<< Updated upstream
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
=======
 
    for (int i = 0; i < 2; i++){
        palo = rand()%4+1;
        val = rand()%13+1; 
        jug->barjug[i].valcar=val;
        while(i==1 && palo == jug->barjug[i-1].hello && jug->barjug[i-1].valcar==val){
            palo = rand()%4+1;
            val = rand()%13+1; 
            jug->barjug[i].valcar=val;
        }
        
        switch(palo){
            case 1: jug->barjug[i].hello = Picas; break;
            case 2: jug->barjug[i].hello = Corazones; break;
            case 3: jug->barjug[i].hello = Treboles; break;
            case 4: jug->barjug[i].hello = Diamantes; break;
        }

        string nomVal;
        obtenerNomCar(val, nomVal);

        switch(jug->barjug[i].hello){
            case 1: cout << "Carta generada: " << nomVal << " de Picas" << endl; break;//aqui se imprime el numero de la carta y se acompaña con su palo
            case 2: cout << "Carta generada: " << nomVal << " de Corazones" << endl; break;
            case 3: cout << "Carta generada: " << nomVal << " de Treboles" << endl; break;
            case 4: cout << "Carta generada: " << nomVal << " de Diamantes" << endl; break;
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
        }else {
            if (val >= 11 && val <= 13) {
                valorSumar = 10;
            } else if (val >= 2 && val <= 10) {
                valorSumar = val;
            }
        }
	 

        sumTot += valorSumar;

        cout << "Valor sumado: " << valorSumar << endl;
        cout << "Total acumulado: " << sumTot << endl;
        jug->barjug->puntj=sumTot;


            if(jug->barjug->puntj==21){
                cout << "\n--- Haz ganado ---"<<endl;
                gan=1;
            }
    } 
}

void generarCartaCas(int& valorSumar, int& sumTot, struct Partidacasa* cas, int& gan, struct Partida* jug ){
    int palo=0; 
    int val=0; 
    int auxAs=0;
    int auxAs2=0;
    int valCam=0;
    
 
    for (int i = 0; i < 2; i++){
        palo = rand()%4+1;
        val = rand()%13+1; 
        cas->barcas[i].valcar=val;
        for (int j = 0; j < 2; j++){
            while((j==1 && palo == cas->barcas[j-1].hello && cas->barcas[j-1].valcar==val) || 
            (jug->barjug[j].hello==palo && jug->barjug[j].valcar==val) ){
                palo = rand()%4+1;
                val = rand()%13+1; 
                cas->barcas[i].valcar=val;
            }
        }
        
        
        
        switch(palo){
            case 1: cas->barcas[i].hello = Picas; break;
            case 2: cas->barcas[i].hello = Corazones; break;
            case 3: cas->barcas[i].hello = Treboles; break;
            case 4: cas->barcas[i].hello = Diamantes; break;
        }

        string nomVal;
        obtenerNomCar(val, nomVal);

        switch(cas->barcas[i].hello){
            case 1: cout << "Carta de casa generada: " << nomVal << " de Picas" << endl; break;//aqui se imprime el numero de la carta y se acompaña con su palo
            case 2: cout << "Carta de casa generada: " << nomVal << " de Corazones" << endl; break;
            case 3: cout << "Carta de casa generada: " << nomVal << " de Treboles" << endl; break;
            case 4: cout << "Carta de casa generada: " << nomVal << " de Diamantes" << endl; break;
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
        }else {
            if (val >= 11 && val <= 13) {
                valorSumar = 10;
            } else if (val >= 2 && val <= 10) {
                valorSumar = val;
            }
        }
	 

        sumTot += valorSumar;

        cout << "Valor sumado: " << valorSumar << endl;
        cout << "Total acumulado: " << sumTot << endl;
        cas->barcas->puntj=sumTot;


            if(cas->barcas->puntj==21){
                cout << "\n--- ha ganado la casa ---"<<endl;
                gan=1;
            }
    } 
}

void generarCartaNueva(int& valorSumar, int& sumTot, struct Partida* jug, int& gan, struct Partidacasa* cas){//aqui se genera la carta, creo que aqui va la condicion de 21

    int palo=0; 
    int val=0; 
    int auxAs=0;
    int auxAs2=0;
    int valCam=0;
    jug->nca++;

    for (int i = jug->nca-1; i < jug->nca; i++){
       palo = rand()%4+1;
        val = rand()%13+1; 
        jug->barjug[i].valcar=val;
        if(jug->nca>=cas->nca){
            for ( int j=0 ; j < jug->nca; j++){
                while((palo == jug->barjug[i-1].hello && jug->barjug[i-1].valcar == val) || 
                        (cas->barcas[j].valcar == val && cas->barcas[i].hello == palo)){
                    palo = rand()%4+1;
                    val = rand()%13+1; 
                    jug->barjug[i].valcar=val;
                    j=-1;
                }
            }
        }else if (jug->nca<cas->nca){
            for ( int j=0 ; j < cas->nca; j++){
                while((palo == jug->barjug[i-1].hello && jug->barjug[i-1].valcar == val) || 
                        (cas->barcas[j].valcar == val && cas->barcas[i].hello == palo)){
                    palo = rand()%4+1;
                    val = rand()%13+1; 
                    jug->barjug[i].valcar=val;
                    j=-1;
                }
            }
        }
        
        
        switch(palo){
            case 1: jug->barjug[i].hello = Picas; break;
            case 2: jug->barjug[i].hello = Corazones; break;
            case 3: jug->barjug[i].hello = Treboles; break;
            case 4: jug->barjug[i].hello = Diamantes; break;
        }

        string nomVal;
        obtenerNomCar(val, nomVal);

        switch(jug->barjug[i].hello){
            case 1: cout << "Carta generada: " << nomVal << " de Picas" << endl; break;//aqui se imprime el numero de la carta y se acompaña con su palo
            case 2: cout << "Carta generada: " << nomVal << " de Corazones" << endl; break;
            case 3: cout << "Carta generada: " << nomVal << " de Treboles" << endl; break;
            case 4: cout << "Carta generada: " << nomVal << " de Diamantes" << endl; break;
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
        }else {
            if (val >= 11 && val <= 13) {
                valorSumar = 10;
            } else if (val >= 2 && val <= 10) {
                valorSumar = val;
            }
        }
	 

        sumTot += valorSumar;

        if(sumTot<21){
            cout << "Valor sumado: " << valorSumar << endl;
            cout << "Total acumulado: " << sumTot << endl;
        }else if(sumTot==21){
            cout << "\n--- Haz ganado ---";
            gan=1;
        }else{
            cout << "Valor sumado: " << valorSumar << endl;
            cout << "Total acumulado: " << sumTot << endl;
            cout << "\n--- Haz Perdido ---"<<endl;
            gan=2;
        } 
    } 
}
    
void generarCartaNuevaCas(int& valorSumar, int& sumTot, struct Partidacasa* cas, int& gan, struct Partida* jug){//aqui se genera la carta, creo que aqui va la condicion de 21

    int palo=0; 
    int val=0; 
    int auxAs=0;
    int auxAs2=0;
    int valCam=0;
    cas->nca++;

    for (int i = cas->nca-1; i < cas->nca; i++){
       palo = rand()%4+1;
        val = rand()%13+1; 
        cas->barcas[i].valcar=val;
        if(jug->nca>=cas->nca){
            for ( int j=0 ; j < jug->nca; j++){
                while((palo == cas->barcas[i-1].hello && cas->barcas[i-1].valcar == val) || 
                        (jug->barjug[j].valcar == val && jug->barjug[i].hello == palo)){
                    palo = rand()%4+1;
                    val = rand()%13+1; 
                    jug->barjug[i].valcar=val;
                    j=-1;
                }
            }
        }else if (jug->nca<cas->nca){
            for ( int j=0 ; j < cas->nca; j++){
                while((palo == cas->barcas[i-1].hello && cas->barcas[i-1].valcar == val) || 
                        (jug->barjug[j].valcar == val && jug->barjug[i].hello == palo)){
                    palo = rand()%4+1;
                    val = rand()%13+1; 
                    jug->barjug[i].valcar=val;
                    j=-1;
                }
            }
        }
        
        switch(palo){
            case 1: cas->barcas[i].hello = Picas; break;
            case 2: cas->barcas[i].hello = Corazones; break;
            case 3: cas->barcas[i].hello = Treboles; break;
            case 4: cas->barcas[i].hello = Diamantes; break;
        }

        string nomVal;
        obtenerNomCar(val, nomVal);

        switch(cas->barcas[i].hello){
            case 1: cout << "Carta de casa generada: " << nomVal << " de Picas" << endl; break;//aqui se imprime el numero de la carta y se acompaña con su palo
            case 2: cout << "Carta de casa generada: " << nomVal << " de Corazones" << endl; break;
            case 3: cout << "Carta de casa generada: " << nomVal << " de Treboles" << endl; break;
            case 4: cout << "Carta de casa generada: " << nomVal << " de Diamantes" << endl; break;
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
        }else {
            if (val >= 11 && val <= 13) {
                valorSumar = 10;
            } else if (val >= 2 && val <= 10) {
                valorSumar = val;
            }
        }
	 

        sumTot += valorSumar;

        if(sumTot<21){
            cout << "Valor sumado: " << valorSumar << endl;
            cout << "Total acumulado: " << sumTot << endl;
        }else if(sumTot==21){
            cout << "\n--- ha ganado la casa ---";
            gan=2;
        }else{
            cout << "Valor sumado: " << valorSumar << endl;
            cout << "Total acumulado: " << sumTot << endl;
            cout << "\n--- Haz Perdido ---"<<endl;
            gan=1;
        } 
    } 
}
        
void piensaIA(struct Partidacasa* cas, struct Partida* jug, int& valorSumar, int& gan,int& SumCas ){
    if(SumCas<17){
        generarCartaNuevaCas(valorSumar, SumCas, cas, gan, jug);
    }
}
    

void jugarCartas(int& SumJug, struct Partida* jug, struct Partidacasa* cas, int& SumCas){
>>>>>>> Stashed changes
    char op;
    int valorSumar;
    int gan=0;

    SumJug = 0;

    cout << "\n--- Repartiendo tus dos primeras cartas ---" << endl;
<<<<<<< Updated upstream
    generarCarta(valorSumar, SumJug, jug);

    do {
=======
    generarCarta(valorSumar, SumJug, jug, gan);
    if (gan==0){
        generarCartaCas(valorSumar, SumCas, cas, gan, jug);
    }
    
    


    while(gan==0){
>>>>>>> Stashed changes
        cout << "Hit o Stand (H/S):";
        cin >> op;

        if (op == 'h' || op == 'H') {
<<<<<<< Updated upstream
            generarCarta(valorSumar, SumJug, jug);
=======
            generarCartaNueva(valorSumar, SumJug, jug, gan, cas);
            generarCartaNuevaCas(valorSumar, SumCas, cas, gan, jug);
>>>>>>> Stashed changes
         }else if(op == 's' || op == 'S'){
            cout<<"¿Quieres abandonar (s/n)?";
            cin>>op;
            if (op == 's' || op == 'S'){
                break;
            }
         }else{
            cout<<"Esta opcion no existe intente de nuevo"<<endl;
         }

<<<<<<< Updated upstream
    } while(SumJug<21);
=======
    } 
>>>>>>> Stashed changes
}

void generarDatosPartida(Partida* partida){
    cout << "Ingresa tu nombre (sin espacios): ";
    cin >> partida->jugador;

    cout << "Ingresa la fecha (DD/MM/AAAA): ";
    cin >> partida->fecha;
}

int main(){
    srand(time(0));
    Partida partida;
<<<<<<< Updated upstream
    int SumJug;

    generarDatosPartida(&partida);
    jugarCartas(SumJug, &partida);
=======
    Partidacasa partcasa;
    int SumJug=0;
    int SumCas=0;

    generarDatosPartida(&partida);
    jugarCartas(SumJug, &partida, &partcasa, SumCas);
>>>>>>> Stashed changes

    cout << "\n " << partida.jugador << endl;
    cout << "Juego terminado. Total final acumulado: " << SumJug << endl;

    return 0;
}