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

    string objs[numObj] = {"I1","I2", "I3"};
    string matrixAux[numObj+1][pesoMax+1];

    for(int i=0; i<pesoMax+1;i++){
        //llenar la primer fila de ceros
        matrix[0][i] = 0;
        matrixAux[0][i] = ".";
    }
    for(int i = 0; i<numObj+1;i++){
        //llenando la primer columna de 0
        matrix[i][0] = 0;
        matrixAux[i][0]=".";
    }
    //ESTA ES LA MATRIX CON LA RESPUESTA DEL MAXIMO DE VALORES
    for (int i = 1; i<numObj+1;i++){
        for (int j = 1; j<pesoMax+1;j++){
            if(j < pesos[i-1]){             //Si mi peso maximo actual es menor que el peso del objeto a meter
                matrix[i][j] = matrix[i-1][j];//agarro el objeto de arriba, ese es el que sí soporta 
            }else{
                matrix[i][j] = max(valores[i-1] + matrix[i-1][j-pesos[i-1]], matrix[i-1][j]); 
            }
        }    
    }

    //ESTA ES LA MATRIX CON CUALES OBJETOS SE COMBINARON
    for (int i = 1; i<numObj + 1 ;i++){
        for (int j = 1; j<pesoMax+1;j++){
            
            if(j < pesos[i-1]){
                matrixAux[i][j] = matrixAux[i-1][j];
            }else{
                if(valores[i-1] + matrix[i-1][j-pesos[i-1]] > matrix[i-1][j]){
                    matrixAux[i][j] = objs[i-1]+"-"+matrixAux[i-1][j-pesos[i-1]];
                }
                if(valores[i-1] + matrix[i-1][j-pesos[i-1]] < matrix[i-1][j]){
                    matrixAux[i][j] = matrixAux[i-1][j];
                }
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
    cout<<"***************************************************"<<endl;
    for (int i = 0; i<numObj+1;i++){
        for (int j = 0; j<pesoMax+1;j++){
            cout<<matrixAux[i][j]<<"    |    ";
        }   
        cout<<endl;    
    }
    cout<<"Max: "<<matrix[numObj][pesoMax]<<endl;
    cout<<"combinacion: "<<matrixAux[numObj][pesoMax]<<endl;
    return 0;
}