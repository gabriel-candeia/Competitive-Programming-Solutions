#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define ull unsigned long long
using namespace std;


bitset<64> st;
ull solve1(){
    ull a=1, b=1, c=2;
    int i = 63;
    for(;i>=0 && st[i]==0;i--);

    for(i--;i>=0;i--){
        if(st[i]==1){
            a = 2*a*b;
            c = 2*b*c;
            b = b*b;
        }
        else{
            c = b*b;
            b = 2*a*b;
            a = a*a;
        }
    }
    return b;
}

int main(){
    fastio();
    int t;
    cin >> t;
    while(t--){
        ull n;
        cin >> n;
        st = bitset<64>(n);
        cout << solve1() <<"\n";
    }

    return 0;
}