#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int answ = 0;
    for(int i=0;i<=a;i++){
        answ = max(answ, min(i,d)*e + min({d-i,b,c})*f);
    }

    cout << answ <<"\n";

    return 0;
}