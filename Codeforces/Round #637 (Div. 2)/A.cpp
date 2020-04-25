#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, c, d, t;

    cin >> t;
    while(t--){
        cin >> n >> a >> b >> c >> d;
        if((a+b)*n<c-d || (a-b)*n>c+d){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }

    return 0;
}