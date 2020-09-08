#include<bits/stdc++.h>
#define ld long double
using namespace std;

vector<int> v; int n;
int simular(int x){
    vector<bool> contaminado(n,0);
    priority_queue<pair<ld,int>> pq;
    pair<ld,int> p;
    int i;
    ld tempo = 0;

    contaminado[x] = 0;
    pq.push({-tempo,x});
    
    while(pq.size()){
        p = pq.top(); pq.pop();
        tempo = -p.first; i = p.second;
        //cout << tempo << ' ';
        if(!contaminado[i]){
            contaminado[i] = 1;
            for(int j=0;j<n;j++){
                if(v[i]!=v[j] && tempo<=(i-j)/(1.0*(v[j]-v[i]))){
                    pq.push({-(i-j)/(1.0*(v[j]-v[i])),j});
                }
            }
        }
    }//cout <<'\n';

    int answ=0;
    for(int i=0;i<n;i++){
        answ+=contaminado[i];
    }

    return answ;
}


int main(){
    int t;

    cin >> t;
    while(t--){
        
        cin >> n;

        v.assign(n,0);

        for(int i=0;i<n;i++)
            cin >> v[i];
        
        int menor = 100, maior = 0;
        for(int i=0;i<n;i++){
            int answ = simular(i);
            menor = min(answ,menor);
            maior = max(answ,maior);
        }
        cout << menor << " " << maior << '\n';
    }
    return 0;
    
}
