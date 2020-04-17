#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct conjunto{ //estructura con las caracteristicas de cada conjunto
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

//imprime cualquier arreglo
void imprime(int arr[], int tamanyo){
    for(int j=1;j<=tamanyo;j++){
        cout<<arr[j];
        if(j!=tamanyo)cout<<",";;
    }
}

// VARIABLES PARA LAS OPERACIONES
int unio[22]; //conjunto de union
int posuni=1; //guarda la cardinalidad de la union

int inter[22]; //conjunto de interseccion
int posinter=1; //guardara la cardinalidad de la interseccion

int dif_ab[22];
int posdif_ab=1;

int dif_ba[22];
int posdif_ba=1;

int compa[22];
int poscompa=1;

int poscompb=1;
int compb[22];

int posdifsim=1;
int difesim[22];

void difsim(){
     for(int i=0;i<=10;i++){
        if((cA.bucket[i]>=1 && cB.bucket[i]==0) || (cB.bucket[i]>=1 && cA.bucket[i]==0)){ //recorre la cubeta de ambos arreglos viendo si el valor solo esta en A
            difesim[posdifsim]=i; //guarda los valores en el conjunto de interseccion
            posdifsim++;
        }
    }
    posdifsim--;
    cout<<"La diferencia simetrica es:"<<endl;
    if(posdifsim!=0){
        cout<<"{";
        for(int i=1;i<=posdifsim;i++){
            cout<<difesim[i];
            if(i<posdifsim)cout<<",";
        }
        cout<<"}";
        cout<<endl;
    } else {
        cout<<" VACIO"<<endl;
    }
}

void compA(){
int universe = 0;
    for(int i=0;i<10;i++){
    universe++;
        if(cA.bucket[i]>=1 != universe>=1){ //recorre la cubeta de ambos arreglos viendo si en ambos está el valor
            compa[poscompa]=i; //guarda los valores en el conjunto de interseccion
            poscompa++;
        }
    }
    poscompa--;
    //imprime el conjunto interseccion
    printf(" El complemento del conjunto A es: \n");

    if(poscompa!=0){
        cout<<"{";
        for(int i=1;i<=poscompa;i++){
            cout<<compa[i];
            if(i<poscompa)cout<<",";
        }
        cout<<"}";
        cout<<endl;
    } else {
        cout<<" VACIO"<<endl;
    }

}

void compB(){
int universe = 0;
    for(int i=0;i<10;i++){
    universe++;
        if(cB.bucket[i]>=1 != universe>=1){ //recorre la cubeta de ambos arreglos viendo si en ambos está el valor
            compb[poscompb]=i; //guarda los valores en el conjunto de interseccion
            poscompb++;
        }
    }
    poscompb--;
    //imprime el conjunto interseccion
    printf(" El complemento del conjunto B es: \n");

    if(poscompb!=0){
        cout<<"{";
        for(int i=1;i<=poscompb;i++){
            cout<<compb[i];
            if(i<poscompb)cout<<",";
        }
        cout<<"}";
        cout<<endl;
    } else {
        cout<<" VACIO"<<endl;
    }

}

void diferab(){
    for(int i=0;i<=10;i++){
        if(cA.bucket[i]>=1 && cB.bucket[i]==0){ //recorre la cubeta de ambos arreglos viendo si el valor solo esta en A
            dif_ab[posdif_ab]=i; //guarda los valores en el conjunto de interseccion
            posdif_ab++;
        }
    }
    posdif_ab--;
    cout<<"La diferencia de A con B"<<endl;
    if(posdif_ab!=0){
        cout<<"{";
        for(int i=1;i<=posdif_ab;i++){
            cout<<dif_ab[i];
            if(i<posdif_ab)cout<<",";
        }
        cout<<"}";
        cout<<endl;
    } else {
        cout<<" VACIO"<<endl;
    }

}
void diferba(){
    for(int i=0;i<=10;i++){
        if(cB.bucket[i]>=1 && cA.bucket[i]==0){ //recorre la cubeta de ambos arreglos viendo si el valor solo esta en B
            dif_ba[posdif_ba]=i; //guarda los valores en el conjunto de interseccion
            posdif_ba++;
        }
    }
    posdif_ba--;
    cout<<"La diferencia de B con A"<<endl;
    if(posdif_ba!=0){
        cout<<"{";
        for(int i=1;i<=posdif_ba;i++){
            cout<<dif_ba[i];
            if(i<posdif_ba)cout<<",";
        }
        cout<<"}";
        cout<<endl;
    } else {
        cout<<" VACIO"<<endl;
    }

}

void intersec(){
    //hace la union de dos conjuntos
    for(int i=0;i<=10;i++){
        if(cA.bucket[i]>=1 && cB.bucket[i]>=1){ //recorre la cubeta de ambos arreglos viendo si en ambos está el valor
            inter[posinter]=i; //guarda los valores en el conjunto de interseccion
            posinter++;
        }
    }
    posinter--;
    //imprime el conjunto interseccion
    printf(" La interseccion del conjunto A con el conjunto B es: \n");

    if(posinter!=0){
        cout<<"{";
        for(int i=1;i<=posinter;i++){
            cout<<inter[i];
            if(i<posinter)cout<<",";
        }
        cout<<"}";
        cout<<endl;
    } else {
        cout<<" VACIO"<<endl;
    }

}
void uni(){
    //hace la union de dos conjuntos
    for(int i=0;i<=10;i++){
        if(cA.bucket[i]>=1 || cB.bucket[i]>=1){ //recorre la cubeta de ambos arreglos viendo si en alguno está el valor
            unio[posuni]=i; //guarda los valores en el conjunto de union
            posuni++;
        }
    }
    posuni--;

    //imprime el conjunto union
    cout<<"La union del conjunto A con el conjunto B es: "<<endl;

    if(posuni!=0){
        cout<<"{";
        for(int i=1;i<=posuni;i++){
            cout<<unio[i];
            if(i<posuni)cout<<",";
        }
        cout<<"}";
        cout<<endl;
    } else {
        cout<<"VACIO"<<endl;
    }

}

void conjuntopotenciaA(){
    int cantidad=pow(2,(cA.posabsoluto));
    for(int i=0;i<cantidad;i++)
    {

        cout<<"{";
        for(int j=0;j<cA.tam;j++){
          if(i & (1<<j)) cout<<cA.conjuntoabsoluto[j+1]<<" ";
        }
        cout<<"} "; if(i+1<cantidad) cout<<", ";
    }
}
void conjuntopotenciaB(){
    int cantidad=pow(2,(cB.posabsoluto));
    for(int i=0;i<cantidad;i++)
    {

        cout<<"{";
        for(int j=0;j<cB.tam;j++){
            if(i & (1<<j))
                cout<<cB.conjuntoabsoluto[j+1]<<" ";
        }
        cout<<"} "; if(i+1<cantidad) cout<<", ";

    }

}
void productocartesianoAB(){
    for(int i=0;i<cA.posabsoluto;i++){
        for(int j=0;j<cB.posabsoluto;j++){
            cout<<"("<<cA.conjuntoabsoluto[i+1]<<","<<cB.conjuntoabsoluto[j+1]<<"),";
        }
    }
}
int main()
{
    puts("Escribe cuantos elementos aleatorios para el conjunto A");
    cin>>cA.tam;
    puts("Escribe cuantos elementos aleatorios para el conjunto B");
    cin>>cB.tam;

    system("cls");

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
    cA.posabsoluto--;
    cout<<"El conjunto A aleatorio es: {";
    imprime(cA.conjuntoconrepetidos,cA.tam); cout<<"}"<<endl;  //imprime el conjunto original

    cout<<"El conjunto A sin repetidos es: {";
    imprime(cA.conjuntoabsoluto,cA.posabsoluto); cout<<"}"<<endl; //imprime el conjunto sin repetir elementos

    cout<<"Cuya cardinalidad es:"<<cA.posabsoluto<<endl; //imprimer la cardinalidad

    //conjunto potencia A
    cout<<"El conjunto Potencia de A es: P(A){ ";
    conjuntopotenciaA();
    cout<<"}\n\n";

    //Conjunto B
    rango=rand()%10+1; //genera un rango aleatorio entre 1 y 10
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
    cB.posabsoluto--;
    cout<<"El conjunto B aleatorio es: {";
    imprime(cB.conjuntoconrepetidos,cB.tam); cout<<"}"<<endl;  //imprime el conjunto original

    cout<<"El conjunto B sin repetidos es: {";
    imprime(cB.conjuntoabsoluto,cB.posabsoluto); cout<<"}"<<endl; //imprime el conjunto sin repetir elementos

    cout<<"Cuya cardinalidad es:"<<cB.posabsoluto<<endl; //imprimer la cardinalidad

    //conjunto Potencia B
    cout<<"El conjunto Potencia de B es: P(B){ ";
    conjuntopotenciaB();
    cout<<"}\n\n";
    cout<<endl<<endl;
    cout<<"El producto cartesiano de A y B es: { ";
    productocartesianoAB();
    cout<<"}\n\n";


        system("pause");
        system("cls");

        uni();
        cout<<endl;
        intersec();
        cout<<endl;
        compA();
        cout<<endl;
        compB();
        cout<<endl;
        diferab();
        cout<<endl;
        diferba();
        cout<<endl;
        difsim();


    return 0;
}
