#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    string s;

    cin >> t;
    while(t--){
        cin >> n >> s;
        cout << string(n,s[n-1]) << '\n';
    }

    return 0;
}