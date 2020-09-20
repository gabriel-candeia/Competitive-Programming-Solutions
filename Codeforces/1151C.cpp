#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;
int main(){
    vector<ll> l(100,0), r(100,0), pos(100,0);

    l[0] = r[0] = 1; pos[0] = 1;
    l[1] = 2; r[1] = 4; pos[1] = 2;
    for(int i=2;i<61;i++){
        pos[i] = pos[i-1] + (1ll<<(i-1));
        l[i] = l[i-2]+(1ll<<(i-1));
        r[i] = l[i]+(1ll<<(i+1))-2;
    }

    /*for(int i=0;i<10;i++){
        cout << "("<< l[i] << " " << r[i] << " " << pos[i] << ") ";
    }cout <<'\n';*/

    ll x, y, i, acm = 0;

    cin >> x >> y;
    for(i=0;i<61;i++){
        if(pos[i]<=x && x<pos[i+1]){
            ll start = l[i] + 2*(x-pos[i]);
            ll end = min(l[i] + 2*(y-pos[i]),r[i]);
            //cout << "começo: " << start << " "<<l[i]<< "\n";
            //cout << "começo: " << end << " "<<r[i]<< "\n";
            acm = (acm+(((start+(min(r[i],end)-start)/2))%mod)*(((min(r[i],end)-start+2)/2)%mod)%mod)%mod;
        }
        else if(pos[i]<=y && y<pos[i+1]){
            ll end = l[i] + 2*(y-pos[i]);
            //cout <<"fim: "<< end << "\n";
            acm = (acm+(((l[i]+(end-l[i])/2)%mod)*(((end-l[i]+2)/2)%mod)%mod))%mod;
            //acm = (acm+(end+l[i])*(end-l[i]+2)/4)%mod;
        }
        else if(x<pos[i] && pos[i]<y){
            acm = (acm+(((l[i]+(r[i]-l[i])/2)%mod)*(((r[i]-l[i]+2)/2)%mod)%mod))%mod;
            //acm = (acm + (l[i]+r[i])*(r[i]-l[i]+2)/4)%mod;
        }
    }
    cout << acm << '\n';

    return 0;
}