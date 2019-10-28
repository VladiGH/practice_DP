#include <iostream>

using namespace std;

int main(){
    string cad1, cad2 ;
    cad1 ="ACBDFG";
    cad2 ="AHCDBGF";
    int c1 = cad1.length(), c2 = cad2.length();
    int matrix[c1+1][c2+1];
    
    //llenando la fila aux de ceros
    for(int i = 0; i<c2+1;i++){
        matrix[0][i] = 0;
    }
    //llenando la col aux de ceros
    for(int i = 1; i<c1+1;i++){
        matrix[i][0] = 0;
    }

    for(int i = 1; i<c1+1; i++){
        for(int j = 1; j<c2+1; j++ ){
            if(cad1[i-1] == cad2[j-1]){//si el caracter actual de mi cad1 es igual
            //al caracter actual de mi cad2 voy a sumar 1 a la respuesta en diagonal a la izq 
                matrix[i][j] = 1 + matrix[i-1][j-1];
            }else{
                matrix[i][j] = max(matrix[i][j-1], matrix[i-1][j]);//sino, agarraré el maximo da la izq con el de arriba
            }
        }
    }
    //imprimir matrix
    for (int k = 0; k<c1+1;k++){
        for (int l = 0; l<c2+1;l++){
            cout<<matrix[k][l]<<"    |    ";
        }   
        cout<<endl;    
    }

    cout<<"LCS: "<<matrix[c1][c2]<<endl;
    return 0;
}