#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main(){
    ll x, y;
    ld dist;    

    cin >> x >> y;
    dist = sqrt(x*x + y*y);

    cout << fixed << setprecision(10) <<  x/dist << " " << y/dist <<"\n";


    return 0;
}