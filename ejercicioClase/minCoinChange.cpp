#include <iostream>
#include <vector>

using namespace std;

/*Probar este código inicialmente con:
    K = 49
    n = 4
    coins = {5,7,8,9}                   */

int main()
{
    int n,d,V;
    vector<int> coins;
    
    //Vuelto a dar
    cin >> V;
    //Cantidad de monedas
    cin >> n;
    for(int i=0;i<n;i++){
        //Se lee la denominacion de la moneda
        cin >> d;
        coins.push_back(d);
    }
    
    //Estructura para el DP
    int M[n+1][V+1];
    //Primera columna en cero por caso trivial
    for(int i=0;i<n+1;i++)
        M[i][0] = 0;
    //Primera fila en número grande como fila auxiliar
    for(int i=1;i<V+1;i++)
        M[0][i] = 9999;
    //Se llena el resto de la matriz
    for(int i=1;i<n+1;i++)
        for(int j=1;j<V+1;j++)
            //Se verifica que la denominacion actual no sobrepasa el vuelto actual
            if(coins.at(i-1) > j)
                //Si se pasa, se toma en cuenta solo las denominaciones anteriores
                M[i][j] = M[i-1][j];
            else
                //Si no se pasa, se estima el mínimo entre usar la moneda actual y no usarla
                M[i][j] = min(1+M[i][j-coins.at(i-1)],M[i-1][j]);
    
    //La respuesta queda en la esquina inferior derecha
    cout << M[n][V] << "\n";

    return 0;
}