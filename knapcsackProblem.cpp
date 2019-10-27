#include <iostream>
#include <vector>
using namespace std;

/*
    Cada objeto tiene un valor y un peso
    cual es la combinacion de objetos que al sumar sus pesos provoquen la maxima capacidad
    que soporta el knapsck
*/
int main(){
    int numObj = 3, pesoMax = 5;
    int valores[numObj] = {60,100,120};
    int pesos[numObj] = {1,2,3};
    
    int matrix[numObj+1][pesoMax+1];

    for(int i=0; i<pesoMax+1;i++){
        //llenar la primer fila de ceros
        matrix[0][i] = 0;
    }
    for(int i = 0; i<numObj+1;i++){
        //llenando la primer fila de 0
        matrix[i][0] = 0;
    }
    for (int i = 1; i<numObj+1;i++){
        for (int j = 1; j<pesoMax+1;j++){
            if(j < pesos[i-1]){
                matrix[i][j] = matrix[i-1][j];
            }else{
                matrix[i][j] = max(valores[i-1] + matrix[i-1][j-pesos[i-1]],matrix[i][j] = matrix[i-1][j]);
            }
        }    
    }
//IMPRIMIENDO LA MATRIX
    for (int i = 0; i<numObj+1;i++){
        for (int j = 0; j<pesoMax+1;j++){
            cout<<matrix[i][j]<<" | ";
        }   
        cout<<endl;    
    }
    cout<<"Max: "<<matrix[numObj][pesoMax]<<endl;

    return 0;
}