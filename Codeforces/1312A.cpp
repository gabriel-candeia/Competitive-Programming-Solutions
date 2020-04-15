#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << ((n%m==0) ? "YES" : "NO") << '\n';
    }

    return 0;
}