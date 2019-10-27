#include <iostream>

using namespace std;
/*
    Minimun coin change se tienen 4 denominaciones de monedas 1c, 3c, 5c, 7c
    y se quiere dar un vuelto P, se necesita la minima cantidad de monedas
    para dar el vuelto
*/
int main(){
    int vuelto = 8;
    int numDenom = 4;

    int denom[numDenom] ={1,3,5,7};
    int matrix[numDenom+1][vuelto+2]; //se le suma uno a las filas de denom por la fila del vuelto
                                    // a las columnas se le suma 2 al vuelto por la columna de denoms y la columna de ceros
    int darVuelto[vuelto+1];// arreglo que contiene los vueltos de 0 hasta vuelto
    
    for(int k = 0; k<vuelto+1;k++){
        darVuelto[k] = k;
    }
    matrix[0][0] = 0;
    for (int i = 0; i < numDenom + 1; i++){
        for(int j = 0; j< vuelto+2; j++){
            
            if (i == 0 && j > 0) matrix[0][j] = darVuelto[j-1]; //solo es el encabezado del vuelto
            if (i == 1 && j > 0) matrix[1][j] = darVuelto[j-1]; //caso trivial de la primer fila
            if (j == 0 && i > 0) matrix[i][0] = denom[i-1]; //columna de las denominaciones
            if (j == 1 && i>0) matrix[i][1] = 0;            //es para la columna de ceros
            if (j > 1 && i > 1) {
                //cout<< "vuelto: "<<  darVuelto[j-1]<<" denom: "<<denom[i-1]<<endl;
                if( darVuelto[j-1] < denom[i-1]) matrix[i][j] = matrix[i-1][j];
                //si el vuelto es menor que la denominacion se toma el valor de arriba
                if(darVuelto[j-1] == denom[i-1]) matrix[i][j] = 1 + matrix[i][darVuelto[j-1]-denom[i-1]+1];
                                    //matrix[i][darVuelto[j-1]-denom[i-1] +1] ese +1 es por la columna de denom
                                    //si el vuelto es igual a la denominacion será 1 + 0 = 1
                else  matrix[i][j] = min( 1+ matrix[i][darVuelto[j-1]-denom[i-1] + 1],
                                            matrix[i-1][j]);           //todas las comparaciones
            }
        }
    }
    
    /*
    PARA IMPRIMIR LA MATRIZ CON TODAS LAS RESPUESTAS
    for (int i = 0; i < numDenom+1; i++){
        for(int j = 0; j< vuelto+2; j++){
            cout<<matrix[i][j]<<" " ;
            if (j == vuelto+1) cout<<"\n";
            if (i == 0 && j == vuelto+1) cout <<"**********************"<<endl;
            if (i >= 0 && j == 0) cout<<"* ";
        }
    }*/
    cout<<"MIN: "<<matrix[numDenom][vuelto+1]<<endl;
    return 0;
}