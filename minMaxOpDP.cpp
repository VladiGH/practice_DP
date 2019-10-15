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

int main(){
    int num = 12;
    int respuesta[num];
    int tamannio = sizeof(respuesta)/ sizeof(respuesta[0]);
    respuesta[0] = 0;
    for (int i = 1; i < num; i++){
        int divDos = i/2;
        int divTres = i/3;
        if(i == 4) cout<<"A VER: "<< respuesta[2]<<endl;        
        respuesta[i] = (1 +
                        minM(respuesta[i-1], 
                        (i % 2 == 0)? respuesta[i / 2]: 10000000000, 
                        (i % 3 == 0)? respuesta[i / 3]: 10000000000 )
                        );
        if(i%2==0) cout<<"esto es i/2: "<< respuesta[divDos]<<"   "<<divDos<<"   "<<" iteracion: "<<i<<endl;
        if(i%3==0) cout<<"esto es i/3: "<< respuesta[divTres]<<"   "<<divTres<<"   "<<" iteracion: "<<i<<endl;
        
        
    
    }

    for(int i = 0; i< tamannio; i++){
        cout<< respuesta[i]<<"-";
    }
    cout<<endl;



    return 0;
}