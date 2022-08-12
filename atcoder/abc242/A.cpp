#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, x;
    cin >> a >> b >> c >> x;

    double answ;
    if(x>b) answ = 0;
    else if(x<=a) answ = 1;
    else answ = c*1.0/(b-(a+1)+1);

    cout << fixed << setprecision(10) << answ <<"\n";

    return 0;
}