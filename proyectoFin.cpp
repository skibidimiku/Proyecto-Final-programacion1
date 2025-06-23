#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <windows.h>

using namespace std;

enum Tipo {Picas = 1, Corazones, Treboles, Diamantes};

struct baraja{
    Tipo hello;
    string NomVal;
    int valcar;
    int puntj=0;
};

struct Partida{//aqui inicia la parte para la funcion de guardae en un archivo la partida
    char jugador[50];
    char fecha[20];
    baraja* barjug;
    int nca=2;
};

struct Partidacasa{//aqui inicia la parte para la funcion de guardae en un archivo la partida
    baraja* barcas;
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

void generarCarta(int& valorSumar, int& sumTot, struct Partida* jug, int& gan ){//aqui se genera la carta, creo que aqui va la condicion de 21
    int palo=0; 
    int val=0; 
    int auxAs=0;
    int auxAs2=0;
    int valCam=0;
    
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
        cout << "Total acumulado: " << sumTot << "\n" << endl;
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
        cout << "Total acumulado: " << sumTot << "\n" << endl;
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
        jug->barjug[i].puntj=sumTot;

        if(sumTot<21){
            cout << "Valor sumado: " << valorSumar << endl;
            cout << "Total acumulado: " << sumTot << "\n" << endl;
        }else if(sumTot==21){
            gan=1;
        }else{
            cout << "Valor sumado: " << valorSumar << endl;
            cout << "Total acumulado: " << sumTot << "\n" << endl;
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
            cout << "Total acumulado: " << sumTot << "\n" << endl;
        }else if(sumTot==21){
            gan=2;
        }else{
            cout << "Valor sumado: " << valorSumar << endl;
            cout << "Total acumulado: " << sumTot << "\n" << endl;
            gan=1;
        } 
    } 
}
        
void piensaIA(struct Partidacasa* cas, struct Partida* jug, int& valorSumar, int& gan,int& SumCas ){
    if(SumCas<17){
        generarCartaNuevaCas(valorSumar, SumCas, cas, gan, jug);
    }
}
    

void jugarCartas(int& SumJug, struct Partida* jug, struct Partidacasa* cas, int& SumCas, int& gan){
    char op;
    int valorSumar;
    

    SumJug = 0;
    gan=0;

    cout << "\n--- Repartiendo tus dos primeras cartas ---" << endl;
    generarCarta(valorSumar, SumJug, jug, gan);
    if (gan==0){
        generarCartaCas(valorSumar, SumCas, cas, gan, jug);
    }
    
    


    while(gan==0){
        cout << "Hit o Stand (H/S):";
        cin >> op;

        if (op == 'h' || op == 'H') {
            generarCartaNueva(valorSumar, SumJug, jug, gan, cas);
            if (gan==0){
                piensaIA(cas, jug, valorSumar, gan, SumCas);
            }
         }else if(op == 's' || op == 'S'){
            piensaIA(cas, jug, valorSumar, gan, SumCas);
            if (gan==0){
                cout<<"¿Quieres abandonar (s/n)?";
                cin>>op;
                if (op == 's' || op == 'S'){
                    break;
                }
            }else{
                break;
            }
         }else{
            cout<<"Esta opcion no existe intente de nuevo"<<endl;
         }

    } 
}

void declararganador(struct Partida* jug, struct Partidacasa* cas, int& gan){
    if(gan==1 && jug->barjug->puntj==21){
        cout << "\n Felicidades " << jug->jugador << endl;
        cout << "--- Haz ganado por 21 ---"<<endl;
    }else if(gan==2 && cas->barcas->puntj==21 ){
        cout << "---Perdiste por 21 de parte de la banca ---"<<endl;
    }else{
        if (jug->barjug->puntj > cas->barcas->puntj && gan==1){
            cout << "\n Felicidades " << jug->jugador << endl;
            cout << "--- Haz ganado con un puntaje de: "<<jug->barjug->puntj<< " ---"<<endl;
            cout << "--- Sobre el puntaje de la casa: "<<cas->barcas->puntj<< " ---"<<endl;
        }else if (jug->barjug->puntj < cas->barcas->puntj && gan==2){
            cout << "--- Haz perdido contra la casa con un puntaje de: "<<cas->barcas->puntj<< " ---"<<endl;
            cout << "--- Sobre tu puntaje : "<<jug->barjug->puntj<< " ---"<<endl;
        }else if(jug->barjug->puntj == cas->barcas->puntj || (jug->barjug->puntj>21 && cas->barcas->puntj>21)){
            cout << "--- Haz perdido contra la casa por empate ---"<<endl;
            cout << "--- Sus puntajes : "<<jug->barjug->puntj<< " y " << cas->barcas->puntj << " ---"<<endl;
        }
        
    }
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
    Partidacasa partcasa;
    int SumJug=0;
    int SumCas=0;
    int gan=0;

    generarDatosPartida(&partida);
    jugarCartas(SumJug, &partida, &partcasa, SumCas, gan);

    cout << "\n los resultados de:" << partida.jugador << " Son: " << endl;
    declararganador(&partida, &partcasa, gan);


    return 0;
}