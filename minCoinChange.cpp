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
    int denom[4] ={1,3,5,7};
    int matrix[numDenom+1][vuelto+2];
    int darVuelto[vuelto+1];
    
    for(int k = 0; k<vuelto+1;k++){
        darVuelto[k] = k;
    }
    for (int i = 0; i < numDenom + 1; i++){
        for(int j = 0; j< vuelto+2; j++){
            matrix[0][0] = 0;
            if (i == 0 && j > 0) matrix[0][j] = darVuelto[j-1]; //solo es el encabezado del vuelto
            if (i == 1 && j > 0) matrix[1][j] = darVuelto[j-1]; //caso trivial de la primer fila
            if (j == 0 && i > 0) matrix[i][0] = denom[i-1]; //columna de las denominaciones
            if (j == 1 && i>0) matrix[i][1] = 0;            //es para la columna de ceros
            if (j > 1 && i > 1) {
                matrix[i][j] = 9;           //todas las comparaciones
            }
        }
    }
    
    for (int i = 0; i < numDenom+1; i++){
        for(int j = 0; j< vuelto+2; j++){
            cout<<matrix[i][j]<<" " ;
            if (j == vuelto+1) cout<<"\n";
            if (i == 0 && j == vuelto+1) cout <<"*******************"<<endl;
        }
    }
    return 0;
}