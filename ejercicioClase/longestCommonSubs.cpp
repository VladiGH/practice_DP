#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string cad1, cad2;
 
    //Se leen ambas cadenas   
    cin >> cad1;
    cin >> cad2;
    
    //Se obtienen sus longitudes
    int m = cad1.length(), n = cad2.length();
    //Se prepara la estructura para DP
    int M[m+1][n+1];
    
    //Primera columna en cero como columna auxiliar
    for(int i=0;i<m+1;i++)
        M[i][0] = 0;
    //Primera fila en cero como fila auxiliar
    for(int i=1;i<n+1;i++)
        M[0][i] = 0;
    
    //Se llena el resto de la matriz
    for(int i=1;i<m+1;i++)
        for(int j=1;j<n+1;j++)
            //Se verifica si el caracter actual de la primera cadena
            //es igual al caracter actual de la segunda cadena
            if(cad1[i-1] == cad2[j-1])
                //Si son iguales, va 1 mas la respuesta retrocediendo
                //un caracter en ambas cadenas
                M[i][j] = 1 + M[i-1][j-1];
            else
                //Si no son iguales, la respuesta es el maximo entre
                //retroceder un caracter en la primera cadena y
                //retroceder un caracter en la segunda cadena
                M[i][j] = max(M[i-1][j],M[i][j-1]);
    
    //La respuesta queda en la esquina inferior derecha
    cout<< M[m][n] << "\n";

    return 0;
}
