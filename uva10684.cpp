#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    if (N<0 || N>10000) return 0 ;
    while (N != 0){
        vector <int> sequences;
        int seq;
        
        vector <int> juegos;
        juegos.push_back(0);//primer elemento trivial

        for (int i = 0; i<N; i++){
            cin>> seq;
            sequences.push_back(seq);
        }
        for (int i = 0; i<N; i++){
            if(sequences[i] > 0) juegos.push_back(juegos[i] + sequences[i]); 
            if(sequences[i] < 0) juegos.push_back(juegos[i] + sequences[i]);
        }

        int streak = *max_element(juegos.begin(), juegos.end());
        if(streak <= 0) cout<< "Losing streak."<<endl;
        else cout<<"The maximum winning streak is " <<streak<<endl;

        cin >> N;
        if (N<0 || N>10000) return 0 ;
        if (N==0) return 0;
    }

    return 0 ;
}