#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << ((n%4==0) ? "YES" : "NO") << '\n';
    }
    return 0;
}