#include<bits/stdc++.h>
#define ll __int128
using namespace std;

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

ll bb1(ll x){
    ll l = 0, r = x, answ = 0, med, cmp;
    while(l<=r){
        med = l + (r-l)/2;
        cmp = ((med%2==0) ? ((med)/2)*(med+1) : ((med+1)/2)*(med));
        if(cmp<=x){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    return answ;
}

ll bb2(ll a, ll b, ll x){
    ll l = 0, r = b, answ = 0, med, cmp1, cmp2;
    while(l<=r){
        med = l+(r-l)/2;
        cmp1 = (med/2+med%2)*(x+1+med/2+med%2);
        cmp2 = (med/2)*(x+2+med/2);
        if(cmp1<=b && cmp2<=a){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    return answ;
}

int main(){
    int t, caso=0;

    cin >> t;
    while(t--){
        ll l, r, x=0, turno=0;
        bool flag = false;
        l = read(), r = read();
        
        if(l>=r) flag=true, swap(l,r);
        x = bb1(r-l);
        r -= (x)*(x+1)/2;
        if(r>=(x+1)){
            if(r==l) flag = true;
            r-=x+1;
            turno = bb2(r,l,x);
            l -= (turno/2+turno%2)*(x+1+turno/2+turno%2);
            r -= (turno/2)*(x+2+turno/2);
            turno++;
        }
        if(flag) swap(l,r);
        
        cout << "Case #" << ++caso << ": ";
        print(x+turno);
        cout << " ";
        print(l);
        cout << " ";
        print(r);
        cout << "\n";
    }

    return 0;   
}