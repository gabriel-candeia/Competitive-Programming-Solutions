#include <bits/stdc++.h>

using namespace std;

bool valor(int n, int i, int p){
    while(n || i){
        if(n%p<i%p) return 1;
        n/=p, i/=p;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p; 
    string s;

    cin >> n >> p;
    cin >> s;
    for(int i =0; i <= n; i++) {
        cout << valor(n,i,p);
    }
    cout<<'\n';

    //cout << s << endl;
    return 0;
}