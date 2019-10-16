#include <iostream>

using namespace std;

/*
    Dado un número n, pueden realizarse tres operaciones: restar un 1, 
    dividir entre 2 (si es divisible entre 2), o dividir entre 3 (si es divisible entre 3). 
    Determinar la cantidad mínima de operaciones para reducir el número n a 1.
    y luego el maximo
*/


int minM(int num1, int num2, int num3){
    if((num1 == num2) && num1 < num3  ) return num1;
    if((num2 == num3) && num2 < num1 ) return num2;
    if((num3 == num1) && num3 < num2 ) return num3;
    
    if(num1 < num2 && num1 < num3) return num1;
    if(num2 < num1 && num2 < num3) return num2;
    if(num3 < num1 && num3 < num2) return num3;
}

int maxM(int num1, int num2, int num3){
    if((num1 == num2) && num1 > num3  ) return num1;
    if((num2 == num3) && num2 > num1 ) return num2;
    if((num3 == num1) && num3 > num2 ) return num3;
    
    if(num1 > num2 && num1 > num3) return num1;
    if(num2 > num1 && num2 > num3) return num2;
    if(num3 > num1 && num3 > num2) return num3;
}

int main(){
    int num = 12;
    int respuesta[num + 1];
    long numero = -100000000; //si se quiere el min cambiarlo a positivo
    int tamannio = sizeof(respuesta)/ sizeof(respuesta[0]);
    respuesta[0] = 12345;
    respuesta[1] = 0;
    for (int i = 2; i < num + 1; i++){
        
        int restaUno = i-1;
        int divDos = i/2;
        int divTres = i/3;
        respuesta[i] = (1+ maxM(respuesta[i-1], 
                        (i % 2 == 0)? respuesta[i/2]: numero, 
                        (i % 3 == 0)? respuesta[i/3]: numero )
                        );
    }
    
    cout<<"El max es: "<<respuesta[num]<<endl;
    return 0;
}