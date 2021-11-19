#include<bits/stdc++.h>
#define ld double
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
#define ll long long
const ld raiz = 1.73205080757;

int main(){
    fastio();
    int t;
    
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll answ = 0;

        vector<pair<ll,ll>> intervalos;
        for(int i=0;i<n;i++){
            ll c, l;
            cin >> c >> l;
            intervalos.push_back({10*c-5*l,10*c+5*l});
            answ += l*10*l*10;
        }

        sort(intervalos.begin(),intervalos.end());
        for(int i=0, j=0;i<intervalos.size()-1;){
            j = i+1;
            for(;j<intervalos.size() && intervalos[i].second>=intervalos[j].second;j++){
                if((intervalos[j].second-intervalos[j].first)<)
                answ -= (intervalos[j].second-intervalos[j].first)*(intervalos[j].second-intervalos[j].first);
            }
            if(j<intervalos.size() && intervalos[i].second > intervalos[j].first)
                answ -= (intervalos[i].second-intervalos[j].first)*(intervalos[i].second-intervalos[j].first);
            i = j;
        }
        answ = answ;
        ll resp = ((answ/100.0)*raiz/4.0)*100;
        cout << fixed << setprecision(2) <<answ*raiz/400.0<<"\n";
        //cout << fixed << setprecision(2) << resp/100.0 <<"\n";
    }

    return 0;
}