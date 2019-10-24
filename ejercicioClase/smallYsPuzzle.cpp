#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

//Funcion que dados los identificadores de dos postes, retorna
//el identificador del tercer poste
int op(int a, int b){
    if((a == 0 && b == 1) || (b == 0 && a == 1)) return 2;
    if((a == 0 && b == 2) || (b == 0 && a == 2)) return 1;
    if((a == 2 && b == 1) || (b == 2 && a == 1)) return 0;
}

int main()
{
    int T[3][3],n,n2;
    
    //Se lee la matriz de costos
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin >> T[i][j];
    
    //Se lee la cantidad de discos
    cin >> n;
    
    //Se prepara la estructura para DP
	//Se utiliza un arreglo tridimensional ya que se tienen que tomar en cuenta todos
	//los casos desde el trivial hasta el solicitado (desde 1 disco hasta n discos), y 
	//ademas para cada caso, hay que tomar todas las direcciones posibles:
	//		desde el poste 1 al 2, del 1 al 3, del 2 al 1 ...
	//Lo que genera dos variables adicionales: el poste origen y el poste destino.
	//Resumiendo, necesitamos una estructura para controlar cada combinacion de:
	//			[ numero de discos, poste origen, poste destino ]
    int M[n][3][3];
    //Se llena la matriz para el caso de 1 disco
    //(Caso trivial: es igual a la matriz de costos)
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            M[0][i][j] = T[i][j];
    
    //Se llenan las matrices para todos los casos desde 2 discos hasta
    // n-1 discos
    for(int e=1;e<n-1;e++)            //Indice para la cantidad de discos
        for(int i=0;i<3;i++)          //Indice para poste de origen
            for(int j=0;j<3;j++)      //Indice para poste de destino
                if(i!=j){             //Las diagonales no interesan
                    //Se obtiene el identificador del 3er poste
                    int k = op(i,j);
                    //Se calcula el resultado:
                    //1 movimiento de 1 disco: el disco mas grande desde el origen al destino
                    //(este costo se saca de la primera matriz)
                    //  +
                    //la respuesta para el caso anterior desde el origen al 3er poste
                    //  + 
                    //la respuesta para el caso anterior desde el 3er poste al destino
                    //[Para esto hay dos casos:
                    //      a) Ir directo desde el 3er poste hasta el destino
                    //      b) Regresar primero al poste origen, y luego al destino ]
                    M[e][i][j] = M[0][i][j] + M[e-1][i][k]
                                  + min(M[e-1][k][j], M[e-1][k][i] + M[e-1][i][j]);
                }
    
    //Para la matriz del caso objetivo, solo se necesita la primera fila
    //Se coloca en la primera celda de la fila un valor que nunca sera la respuesta
    M[n-1][0][0] = INT_MAX;
    //Se llena el resto de la fila
    for(int j=1;j<n;j++){
        //Se obtiene el identificador del 3er poste
        int k = op(0,j);
        //La respuesta es lo mas pequeño entre la celda anterior y el calculo antes descrito
        M[n-1][0][j] = min(
            
                        M[n-1][0][j-1] ,
                        
                        M[0][0][j] + M[n-2][0][k]
                            + min(M[n-2][k][j], M[n-2][k][0] + M[n-2][0][j])
                        
                        );
    }
    
	//La respuesta queda en la esquina superior derecha de la ultima matriz
    cout << M[n-1][0][2] <<"\n";
    
    return 0;
}