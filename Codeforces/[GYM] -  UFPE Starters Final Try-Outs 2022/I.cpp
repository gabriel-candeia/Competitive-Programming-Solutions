#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll d1, d2, d3, d4;
        ll x=0, y;
        cout << 0 << " " << 1 <<endl;
        cin >> d1;
        if(d1==0) continue;

        cout << 0 << " " << -1 <<endl;
        cin >> d2;
        if(d2==0) continue;

        y = (d2-d1)/4;
        cout << 1 << " " << 0 <<endl;
        cin >> d3;
        if(d3==0) continue;

        d3-=y*y;
        ll modX = sqrt(d1-(y-1)*(y-1)), modXsub = sqrt(d3);
        
        if(modX>modXsub){
            x = modX;
        }
        else{
            x = -modX;
        }

        cout << x << " " << y<< endl;
        cin >> d4;
        if(d4!=0) assert(1==-1);
    }
    return 0;
}
