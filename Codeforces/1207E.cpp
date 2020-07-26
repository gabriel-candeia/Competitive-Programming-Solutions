#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll l, r, answ=0;

    cout << "? ";
    for(int i=1;i<=100;i++){
        cout << (i<<7) << " ";
    }cout <<endl;
    cin >> l;

    cout << "? ";
    for(int i=1;i<=100;i++){
        cout << i << " ";
    }cout <<endl;
    cin >> r;

    ll pot = 1;
    for(int i=0;i<7;i++,pot*=2){
        answ  += (l%2)*pot;
        l/=2;
        r/=2;
    }

    for(int i=0;i<7;i++,pot*=2){
        answ  += (r%2)*pot;
        l/=2;
        r/=2;
    }

    cout << "! " << answ << '\n';

    return 0;
}