#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, saldo = 0, ultimoVencedor=0, empate = 1, virada = 0, sequencia = 1, last = 0;
    vector<int> gols(3,0);
    vector<int> triste;
    bool flag = true;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        gols[a]++;
        a = (a==1) ? 1 : -1;
        if(flag){
            ultimoVencedor = a;
            flag = false;
        }
        triste.push_back(a);

        saldo+=a;
        if(saldo==0){
            empate++;
        }
        
        if(a==last){
            sequencia++;
        }
        if(a!=last || n==0){
            if(last!=ultimoVencedor && saldo*last>0){
                virada = max(virada,sequencia);
                ultimoVencedor = last;
            }
            sequencia = 1;
        }

        last = a;
        
    }

    cout << gols[1] << " " << gols[2] <<"\n";
    cout << empate <<"\n";

    saldo = 0;  
    for(int i=0;i<triste.size();i++){
        int j = 0;
        for(;i+j<triste.size() && triste[i]==triste[i+j];j++);
        if(saldo*(saldo+triste[i]*j)<0){
            virada = max(virada,j);
        }
        saldo += triste[i];
    }

    cout << virada<<"\n";

    return 0;
}