#include <bits/stdc++.h>

using namespace std;

#define maxk 1010

int n, k, num;
int v[maxk];
map<int, vector<int>> mapa;

int main(){
    cin >> k >> n;
    for(int i = 1; i <= n; i++){
        cin >> num;
        ++v[num];
    }
    for(int i = 1; i <= k; i++){
        //if(v[i]) mapa[v[i]].emplace_back(i);
        mapa[v[i]].emplace_back(i);
    }
    bool ok = false;
    if(mapa.size() == 3){
        array<int, 3> vec[3];
        int c = 0;
        for(auto par:mapa){
            vec[c][0] = par.second.size(); //tamanho
            vec[c][1] = par.first; //frequencia
            vec[c][2] = par.second[0]; //primeiro elemento
            c++;
        }  
        sort(vec, vec+3);   
        array<int, 3> aux;
        if(vec[0][0] == vec[1][0] && vec[1][0] == vec[2][0]){
            aux = vec[2];
            vec[2] = vec[1];
            vec[1] = aux;
        }
        if(vec[0][0] > 1 || vec[1][0] > 1 || (abs(vec[2][1] - vec[0][1]) != 1) || (abs(vec[2][1] - vec[1][1]) != 1)){
            cout << "*\n";
        }else{
            cout << "-" << vec[1][2] << " +" << vec[0][2] << "\n";
        }
    }else if(mapa.size() == 2){
        array<int, 3> vec[2];
        int c = 0;
        for(auto par:mapa){
            vec[c][0] = par.second.size(); //tamanho
            vec[c][1] = par.first; //frequencia
            vec[c][2] = par.second[0]; //primeiro elemento
            c++;
        }  
        sort(vec, vec+2);   
        if(vec[0][0] == 1 && vec[1][0] == 1 && (vec[1][1] - vec[0][1]) == 2){
            cout << "-" << vec[1][2] << " +" << vec[0][2] << "\n";
            return 0;
        }
        if(vec[0][0] > 1 || (abs(vec[1][1] - vec[0][1]) != 1)){
            cout << "*\n";
        }else{
            if(vec[0][1] > vec[1][1]){
                cout << "-" << vec[0][2] << "\n";
            }else{
                cout << "+" << vec[0][2] << "\n";
            }
        }
    }else{
        cout << "*\n";
    }
    return 0;
}