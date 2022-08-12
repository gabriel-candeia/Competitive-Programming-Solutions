#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;

ll binpow(ll x, ll y){
    ll answ = 1;
    for(;y;y/=2){
        if(y&1){
            answ = (answ*x)%mod;
        }
        x = (x*x)%mod;
    }
    return answ;
}

ll inv(ll x){
    return binpow(x,mod-2);
}

int main(){
    int t;

    cin >> t; 
    while(t--){
        int n, m, cx, cy, lx, ly, dx=1, dy=1, tempo=0;
        ll p, notp, x, aux, invaux;
        vector<int> fst;  
        vector<vector<vector<vector<int>>>> visited;
        cin >> n >> m >> cx >> cy >> lx >> ly >> p;
        visited.assign(n+1,vector<vector<vector<int>>>(m+1,vector<vector<int>>(2,vector<int>(2,0))));

        notp = 100-p;

        while(true){
            if(cx+dx>n || cx+dx<1) dx = -dx;
            if(cy+dy>m || cy+dy<1) dy = -dy;
            if(cx==lx || cy==ly){
                //cout << cx << " " << cy << " " << dx << " " << dy<<"\n";
                fst.push_back(tempo);
                if(visited[cx][cy][(dx==1)][(dy==1)]){
                    break;
                }
                visited[cx][cy][(dx==1)][(dy==1)] = 1;
            }   
            tempo++;
            cx += dx;
            cy += dy;
        }

        ll ciclo = fst.size()-1;
        x = fst.back()-fst[0];
        //cout << (256*inv(175))%mod <<"\n";
        //cout << (175*inv(256))%mod <<"\n";

        //cout <<  inv(((1-binpow((notp*inv(100))%mod,4))%mod+mod)%mod) <<"\n";
        aux = inv(((1-binpow((notp*inv(100))%mod,ciclo))%mod+mod)%mod);

        /*cout << ciclo <<"\n";
        for(auto x:fst)
            cout << x << " ";
        cout <<"\n";*/

        ll base1, base2;
        base1 = aux;
        base2 = ((binpow((notp*inv(100))%mod,ciclo))*((aux*aux)%mod))%mod;

        ll premul = (p*inv(100))%mod, answ = 0;
        for(int i=0;i<fst.size()-1;i++){
            answ = (answ + (premul*((fst[i]*base1)%mod))%mod)%mod;
            answ = (answ + (premul*((x*base2)%mod))%mod)%mod;
            premul = (premul*((notp*inv(100))%mod) )%mod;
        }
        
        cout << answ <<"\n";
    }

    return 0;
}