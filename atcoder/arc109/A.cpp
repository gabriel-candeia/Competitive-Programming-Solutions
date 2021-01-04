#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, x, y, answ=1<<20;

    cin >> a >> b >> x >> y;
    if(a>b){
        answ = min(x+(a-b-1)*y,2*x*(a-b)-x);
    }
    else{
        answ = min(x+(b-a)*y,2*x*(b-a)+x);
    }
    
    cout << answ <<'\n';

    return 0;
}