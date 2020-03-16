#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct conjunto { //estructura con las caracteristicas de cada conjunto
        int tam; //cardinalidad de numeros aleatorios
        int bucket[12]; //este arreglo nos permite llevar a cabo el ordenamiento por bucketsort
        int conjuntoconrepetidos[102]; //guardara todos los numeros aleatorios generados
        int conjuntoabsoluto [102]; // guardará los numeros sin repetir
        int posabsoluto=1; // cardinalidad de numeros distintos
};
conjunto cA; //tipo de dato de cada conjunto
conjunto cB; //tipo de dato de cada conjunto

int aleatorio; //variable para guardar valor aleatorio
int rango; // indica el inicio de un rango aleatorio

void imprime(int arr[], int tamanyo){
    for(int j=1;j<=tamanyo;j++){
        cout<<arr[j];
        if(j!=tamanyo)cout<<",";;
    }
}

// VARIABLES PARA LAS OPERACIONES
int unio[22];
int posuni=1; //guarda la cardinalidad de la union

int inter[22];
int posinter=1; //guardara la cardinalidad de la interseccion


void intersec(){
    //hace la union de dos conjuntos
    for(int i=0;i<=10;i++){
        if(cA.bucket[i]>=1 && cB.bucket[i]>=1){ //recorre la cubeta de ambos arreglos viendo si en ambos está el valor
            inter[posinter]=i;
            posinter++;
        }
    }
    posinter--;
    //imprime
    printf(" La interseccion del conjunto A con el conjunto B es: \n");
    if(posinter==0){
        for(int i=1;i<=posinter;i++){
            cout<<inter[i]<<" ";
        }
        cout<<endl;
    }

}

void uni(){
    //hace la union de dos conjuntos
    for(int i=0;i<=10;i++){
        if(cA.bucket[i]>=1 || cB.bucket[i]>=1){ //recorre la cubeta de ambos arreglos viendo si en alguno está el valor
            unio[posuni]=i;
            posuni++;
        }
    }
    posuni--;
    //imprime
    printf(" La union del conjunto A con el conjunto B es: \n");
    for(int i=1;i<=posuni;i++){
        cout<<unio[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    puts("Escribe cuantos elementos aleatorios para el conjunto A");
    cin>>cA.tam;
    puts("Escribe cuantos elementos aleatorios para el conjunto B");
    cin>>cB.tam;

    srand (time(NULL)); //inicializa seed
    rango=rand()%10+1; //genera un rango aleatorio entre 1 y 10

    for(int i=1;i<=cA.tam;i++){
            aleatorio=rand()%rango+0; //genera un numero aleatorio en un rango aleatorio
            cA.conjuntoconrepetidos[i]=aleatorio; //manda el valor aleatorio actual a un arreglo
            cA.bucket[aleatorio]+=1; //se va al arreglo bucet en la posicion "aleatorio" y escribe cuantos elementos hay de ese numero
    }

    //ordenamientocubeta(); //ordena los numeros y deja un solo elemento de cada numero
    for(int i=0;i<=10;i++){
            if(cA.bucket[i]>=1){
                cA.conjuntoabsoluto[cA.posabsoluto]=i;
                cA.posabsoluto++;
            }
    }

    cout<<"El conjunto A aleatorio es: {";
    imprime(cA.conjuntoconrepetidos,cA.tam); cout<<"}"<<endl;  //imprime el conjunto original

    cout<<"El conjunto A sin repetidos es: {";
    imprime(cA.conjuntoabsoluto,cA.posabsoluto-1); cout<<"}"<<endl; //imprime el conjunto sin repetir elementos

    cout<<"Cuya cardinalidad es:"<<cA.posabsoluto-1<<endl; //imprimer la cardinalidad
    cout<<endl;
    //Conjunto B
    //rango=rand()%10+1; //genera un rango aleatorio entre 1 y 10
    for(int i=1;i<=cB.tam;i++){
            aleatorio=rand()%rango+0; //genera un numero aleatorio en un rango aleatorio
            cB.conjuntoconrepetidos[i]=aleatorio; //manda el valor aleatorio actual a un arreglo
            cB.bucket[aleatorio]+=1; //se va al arreglo bucet en la posicion "aleatorio" y escribe cuantos elementos hay de ese numero
    }

    //ordenamientocubeta(); //ordena los numeros y deja un solo elemento de cada numero
    for(int i=0;i<=10;i++){
            if(cB.bucket[i]>=1){
                cB.conjuntoabsoluto[cB.posabsoluto]=i;
                cB.posabsoluto++;
            }
    }

    cout<<"El conjunto B aleatorio es: {";
    imprime(cB.conjuntoconrepetidos,cB.tam); cout<<"}"<<endl;  //imprime el conjunto original

    cout<<"El conjunto B sin repetidos es: {";
    imprime(cB.conjuntoabsoluto,cB.posabsoluto-1); cout<<"}"<<endl; //imprime el conjunto sin repetir elementos

    cout<<"Cuya cardinalidad es:"<<cB.posabsoluto-1<<endl; //imprimer la cardinalidad
/*
    ERICK, SI TE CONFUNDES DESCOMENTA ESTE PEDAZO DE CODIGO Y PUEDES VER COMO ESTÁ LA CUBETA DE CADA UNO
    printf(" LA CUBETA DE A ES :\n");
    for(int i=0;i<=10;i++){
       cout<< cA.bucket[i]<<" ";
    }
    cout<<endl;
    printf(" LA CUBETA DE B ES :\n");
    for(int i=0;i<=10;i++){
        cout<<cB.bucket[i]<<" ";
    }
    cout<<endl;
*/
    uni();
    intersec();

    return 0;
}
