#include <bits/stdc++.h>

using namespace std;

#define maxn 200005

int n;
int v[maxn];
vector<int> sla;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        if(v[i] == i){
            sla.emplace_back(i);
        }
    }
    int tam = sla.size();
    int entrar = -1;
    if(tam%2){
        --tam;
        entrar = sla[tam];
    }
    cout << (tam/2)+(entrar != -1) << "\n";
    for(int i = 0; i < tam; i+=2){
        cout << sla[i] << " " << sla[i+1] << "\n";
        swap(sla[i], sla[i+1]);
    }
    if(entrar != -1){
        if(entrar == n)
            cout << entrar-1 << " " << entrar << "\n";
        else
            cout << entrar+1 << " " << entrar << "\n";
    
    } 
    return 0;
}