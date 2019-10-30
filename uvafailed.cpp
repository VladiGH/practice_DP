#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    if (N<0 || N>10000) return 0 ;
    while (N != 0){
        vector <int> sequences;
        int seq;
        struct juego {
            int contRacha;
            int dinero;
            juego (int contRacha_, int dinero_){
                contRacha = contRacha_;
                dinero = dinero_;
            }
        };
        vector <juego> Juegos;
        Juegos.push_back(juego(0,0));//primer elemento trivial

        for (int i = 0; i<N; i++){
            cin>> seq;
            sequences.push_back(seq);
        }
        for (int i = 0; i<N; i++){
            if(sequences[i] < 0) Juegos.push_back(juego(0,0));
            if(sequences[i] > 0) Juegos.push_back(juego(Juegos[i].contRacha + 1, Juegos[i].dinero + sequences[i])); 
        }

        for (int i =1; i<N+1; i++){
            cout<<"RACHA: "<<  Juegos[i].contRacha<< " Dinero: "<<Juegos[i].dinero<<endl;
            //sequences.push_back(seq);
        }
        
        cout<<endl;
        cin >> N;
        if (N<0 || N>10000) return 0 ;
        if (N==0) return 0;
    }

    return 0 ;
}