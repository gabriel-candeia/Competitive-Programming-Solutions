#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        ll a, b, c;
        cin >> a >> b >> c;
        if(b>c)
            swap(b,c);
        if(a>c)
            swap(a,c);
        if(a>b)
            swap(a,b);
        ll d = ceil(sqrt(b*b+(c-b)*(c-b)));
        cout << d <<'\n';
    }

    return 0;
}