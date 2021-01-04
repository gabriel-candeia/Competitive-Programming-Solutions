#include<bits/stdc++.h>
#define maxn int(4e5+5)
#define ll long long
using namespace std;

ll answ[maxn];

int main(){
    ll n;
    cin >> n;

    for(int j=n;j;j--){
        ll x = n/j - 1;
        answ[j] = 1 + 2*x + x*x;
        for(int k=2*j;k<=n;k+=j){
            answ[j]-=answ[k];
        }
    }

    for(int j=1;j<=n;j++){
        cout << answ[j] << " ";
    }cout<<'\n';

    return 0;
}