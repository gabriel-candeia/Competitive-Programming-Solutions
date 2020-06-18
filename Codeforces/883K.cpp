#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;
    vector<ll> s(n,0), g(n,0), x(n,0);
    bool poss=true;

    for(int i=0;i<n;i++){
        cin >> s[i];
        cin >> g[i];
    }

    x[0] = s[0]+g[0];
    for(int i=1;i<n;i++){
        x[i] = min(s[i]+g[i],x[i-1]+1);
    }

    x[n-1] = min(x[n-1],s[n-1]+g[n-1]);
    for(int i=1;i<n;i++){
        x[n-i-1] = min({x[n-i-1],s[n-i-1]+g[n-i-1],x[n-i]+1});
    }

    for(int i=0;i<n;i++){
        if(x[i]<s[i] || x[i] > s[i]+g[i]){
            poss = false;
            break;
        }
    }

    if(!poss){
        cout <<  -1 << '\n';
    }
    else{
        ll acm=0;
        for(int i=0;i<n;i++){
            acm+=x[i]-s[i];
            }
        cout << acm << '\n';
        for(int i=0;i<n;i++){
            cout << x[i] << ' ';
        }
        cout << '\n';
    }


    return 0;
}
