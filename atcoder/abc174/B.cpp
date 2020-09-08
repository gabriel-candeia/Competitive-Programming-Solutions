#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll d, n, x, y, cnt=0;

    cin >> n >> d;
    d*=d;
    while(n--){
        cin >> x >> y;
        cnt += ((x*x+y*y)<=d);
    }

    cout << cnt <<'\n';
    
}