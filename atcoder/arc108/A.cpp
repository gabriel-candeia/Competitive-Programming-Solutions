#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll s, p;
    cin >> s >> p;

    ll lim=sqrt(p);
    bool poss = false;
    for(int i=1;i<=lim && !poss;i++){
        if(p%i==0 && i+p/i == s){
            poss = true;
        }
    }

    cout << ((poss) ? "Yes" : "No") <<'\n';

    return 0;
}