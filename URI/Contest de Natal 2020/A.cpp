#include<bits/stdc++.h>
using namespace std;

int main(){
    int b, g, d;
    cin >> b >> g;
    d = g/2-b;
    if(d<=0)
        cout << "Amelia tem todas bolinhas!" << '\n';
    else{
        cout << "Faltam " << d << " bolinha(s)" << '\n';
    }
    return 0;
}
