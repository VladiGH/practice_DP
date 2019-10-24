#include <iostream>

using namespace std;

int main()
{
    int n;
 
    //Se lee el número de discos   
    cin >> n;
    
    //Se prepara la estructura para DP
    int H[n];
    
    //Se llena la primera casilla con 1 por caso trivial de 1 disco
    H[0] = 1;
    //Se llena el resto del arreglo
    for(int i=1;i<n;i++)
        //Cada caso se resuelve con 2 instancias del caso anterior mas
        //un movimiento adicional
        H[i] = 2*H[i-1] + 1;
    
    //La respuesta queda en la ultima casilla
    cout << H[n-1] << "\n";

    return 0;
}
