#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int main(){
    fastio();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        vector<pair<ll,ll>> aux, eventos;
        cin >> n >> k;
        for(int i=0;i<n;i++){
            int a, b, v;
            cin >> a >> b >> v;
            aux.push_back({a,v});
            aux.push_back({b+1,-v});
        }

        sort(aux.begin(),aux.end());
        eventos.push_back(aux[0]);
        for(int i=1;i<aux.size();i++){
            if(aux[i].first==aux[i-1].first)
                eventos.back().second+=aux[i].second;
            else
                eventos.push_back(aux[i]);
        }

        
        n = eventos.size();
        ll answ = 0;
        for(int iter=0;iter<2;iter++){
            int l = 0, r = 0; 
            ll incL = eventos[0].second, incR = eventos[0].second, soma = incL;
            for(;l<n;l++){
                while(r+1<n && eventos[r+1].first-eventos[l].first+1<=k){
                    soma += (eventos[r+1].first - eventos[r].first-1)*incR;
                    r++;
                    incR += eventos[r].second;
                    soma += incR;
                }
                ll lim = min((ll)eventos[l].first+k-1,(ll)1e9);
                if(r+1<n)
                    lim = min(lim,eventos[r+1].first-1);
                /*cout << eventos[l].first << " " << eventos[r].first << " " << soma <<"\n";
                cout << eventos[l].first << " " <<  lim << " " <<  soma+(lim-eventos[r].first)*incR <<"\n";
                cout <<"\n";*/
                answ = max(answ,soma+(lim-eventos[r].first)*incR);
                if(l+1<n){
                    soma -= (eventos[l+1].first - eventos[l].first)*incL;
                    incL += eventos[l+1].second;
                }
            }
            for(auto &p:eventos){
                p.first = -p.first, p.second = -p.second;
            }
            reverse(eventos.begin(),eventos.end());
        }

        cout << answ <<"\n";
    }

    return 0;
}