#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t, temp;

    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        if(a>b){
            temp = a;
            a = b;
            b = temp;
        }

        if(2*a<=b){
            cout << a << '\n';
        }
        else{
            cout << (a+b)/3 << '\n';
        }
    }

    return 0;
}