#include<bits/stdc++.h>
#define ll long long
using namespace std;

int diff(int x, int y){
    int answ = 0;
    for(;x || y;x/=10, y/=10){
        answ+=(x%10!=y%10);
    }
    return answ;
}

int dumb(int x){
    int answ=0;
    for(int i=1;i<=x;i++){
        answ+=diff(i,i-1);
    }
    return answ;
}

ll smart(int x){
    ll answ = 0;
    for(;x;x%10){
        answ +=x;
        x/=10;
    }
    return answ;
}

int main(){
    int t, l, r;
    /*(for(int i=1256;i<=1260;i++){
        cout << i << ": " << dumb(i) << " " << smart(i) << "\n";
    }*/
    cin >> t;
    while(t--){
        ll answ=0;
        cin >> l >> r;
        cout << smart(r)-smart(l) << "\n";
        
    }

    return 0;
}