#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll a, b, c, answ = 0;
    cin >> a >> b >> c;
    for(int i=1;true;i++){
        if((i/7)*b+a*i>=c){
            answ = i;
            break;
        }
    }

    cout << answ <<"\n";

    return 0;
}