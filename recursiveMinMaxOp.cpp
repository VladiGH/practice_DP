#include <iostream>

using namespace std;

/*
    Dado un número n, pueden realizarse tres operaciones: restar un 1, 
    dividir entre 2 (si es divisible entre 2), o dividir entre 3 (si es divisible entre 3). 
    Determinar la cantidad mínima de operaciones para reducir el número n a 1.
    y luego el maximo
*/

int minM(int num1, int num2, int num3){
    if(num1 < num2 && num1 < num3) return num1;
    if(num2 < num1 && num2 < num3) return num2;
    else return num3; 
}

int maxM(int num1, int num2, int num3){
    if(num1 > num2 && num1 > num3) return num1;
    if(num2 > num1 && num2 > num3) return num2;
    else return num3;
}
int tresOperacionesMin(int num){
    if(num == 1) return 0;
    else return (1 +
    minM(tresOperacionesMin(num-1), 
    (num % 2 == 0)? tresOperacionesMin(num / 2): 10000000000, 
    (num % 3 == 0)? tresOperacionesMin(num / 3): 10000000000 )
    );
}


int tresOperacionesMax(int num){
    if(num == 1) return 0;
    else return (1 +
    maxM(tresOperacionesMax(num-1), 
    (num % 2 == 0)? tresOperacionesMax(num / 2): -10000000000, 
    (num % 3 == 0)? tresOperacionesMax(num / 3): -10000000000 )
    );
}
int main(){
    cout<<"Minimo de operaciones: "<<tresOperacionesMin(3)<<endl;
    cout<<"Máximo de operaciones: "<<tresOperacionesMax(12)<<endl;

    return 0;
}