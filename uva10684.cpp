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
        
        for (int i = 0; i<N; i++){
            cin>> seq;
            sequences.push_back(seq);
        }
        int maxN = 0, acum=0;
        for (int i = 0; i<N; i++){
            acum += sequences[i];
            
            if(acum > maxN) maxN = acum ;
            if(acum < 0) acum = 0;
                
        }
        
        if(acum <= 0) cout<< "Losing streak."<<endl;
        else cout<<"The maximum winning streak is " <<maxN<<endl;

        cin >> N;
        if (N<0 || N>10000) return 0 ;
        if (N==0) return 0;
    }

    return 0 ;
}