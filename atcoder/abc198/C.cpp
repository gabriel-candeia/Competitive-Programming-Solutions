#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll r, x, y, dist=0;
    cin >> r >> x >> y;
    dist = x*x + y*y;
    if(dist<r*r)
        cout << 2 <<"\n";
    else
        cout << ceil(sqrt(dist)/r) << '\n';
    return 0;   
}
