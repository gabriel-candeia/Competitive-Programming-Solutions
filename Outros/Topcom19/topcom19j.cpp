#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

uint f(uint curr){
    return (curr + (curr>>20) + 12345);
}

int main(){
    fastio();
    ll n;
    cin >> n;

    ll acm = 0;
    uint curr = 1611516670;

    ll primeiroCiclo = 1980157;
    ll tamanhoCiclo = 15623712;
    ll valorCiclo = 7772153;

    for(int i=0;n && i<primeiroCiclo;i++, n--){
        acm += (1-(curr&1));
        curr = (curr + (curr>>20) + 12345);
    }

    //cout << n/tamanhoCiclo <<"\n";

    acm += (n/tamanhoCiclo)*valorCiclo;
    n = n%tamanhoCiclo;

    while(n){
        acm += (1-(curr&1));
        curr = (curr + (curr>>20) + 12345);
        n--;
    }

    cout << acm <<"\n";

    return 0;
}
